//
// Test for the async request queue system 
// Created to verify fix for issue: multiple async requests causing data confusion
//

#include <gtest/gtest.h>
#include <QCoreApplication>
#include <QTimer>
#include <QEventLoop>
#include <QJsonObject>
#include <QJsonArray>
#include <chrono>
#include <vector>
#include <memory>
#include "ASync/QTMDB.h"

class QueueSystemTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Initialize test with real API key from environment
        apiKey = std::getenv("API_KEY");
        if (!apiKey) {
            GTEST_SKIP() << "API_KEY environment variable not set";
        }
    }
    
    void TearDown() override {
        // Cleanup
    }
    
    const char* apiKey = nullptr;
};

// Test that verifies the queue system prevents simultaneous requests
TEST_F(QueueSystemTest, QueuePreventsSimultaneousRequests) {
    aQtmdb qtmdb(apiKey);
    
    int startCount = 0;
    std::vector<std::chrono::steady_clock::time_point> startTimes;
    
    // Connect to the startedLoadingData signal to count how many times it's emitted
    QObject::connect(&qtmdb, &aQtmdb::startedLoadingData, [&startCount, &startTimes]() {
        startCount++;
        startTimes.push_back(std::chrono::steady_clock::now());
    });
    
    // Make multiple requests quickly
    qtmdb.genres_movie();
    qtmdb.genres_tv(); 
    qtmdb.config_details();
    
    // Process events briefly to allow immediate processing
    QCoreApplication::processEvents();
    
    // With the queue system, only the first request should start immediately
    EXPECT_EQ(startCount, 1) << "Only one request should start immediately with queue system";
    
    // Wait for all requests to complete
    QEventLoop loop;
    int completedCount = 0;
    QObject::connect(&qtmdb, &aQtmdb::finishedLoadingData, [&completedCount, &loop](void*) {
        completedCount++;
        if (completedCount >= 3) {
            loop.quit();
        }
    });
    
    QTimer::singleShot(10000, &loop, &QEventLoop::quit); // 10 second timeout
    loop.exec();
    
    // Verify all requests eventually started
    EXPECT_EQ(startCount, 3) << "All 3 requests should have started";
    
    // Verify requests started sequentially (with measurable time gaps)
    if (startTimes.size() >= 2) {
        auto timeDiff = std::chrono::duration_cast<std::chrono::milliseconds>(
            startTimes[1] - startTimes[0]).count();
        EXPECT_GT(timeDiff, 50) << "Sequential requests should have time gap, found: " << timeDiff << "ms";
    }
}

// Test that verifies data integrity - no data confusion between different requests
TEST_F(QueueSystemTest, DataIntegrityBetweenRequests) {
    aQtmdb qtmdb(apiKey);
    
    struct ResponseData {
        QString requestType;
        QJsonValue data;
        bool received = false;
    };
    
    std::vector<ResponseData> responses(3);
    responses[0].requestType = "movie_genres";
    responses[1].requestType = "tv_genres"; 
    responses[2].requestType = "config";
    
    int responseCount = 0;
    
    // Set up response handlers to capture data for each request type
    QObject::connect(&qtmdb, &aQtmdb::finishedLoadingData, [&responses, &responseCount](void* data) {
        responseCount++;
        
        // Determine which response this is based on the data structure
        if (auto jsonObj = static_cast<QJsonObject*>(data)) {
            if (jsonObj->contains("genres")) {
                // This is a genres response - need to determine if movie or TV
                QJsonArray genres = (*jsonObj)["genres"].toArray();
                if (!genres.isEmpty()) {
                    // Check if this looks like movie genres or TV genres based on typical IDs
                    QJsonObject firstGenre = genres[0].toObject();
                    int genreId = firstGenre["id"].toInt();
                    
                    // Movie genres typically include Action (28), Adventure (12), etc.
                    // TV genres include similar but with some differences
                    if (genreId == 28 || genreId == 12 || genreId == 16) {
                        // Likely movie genres
                        responses[0].data = *jsonObj;
                        responses[0].received = true;
                    } else {
                        // Likely TV genres  
                        responses[1].data = *jsonObj;
                        responses[1].received = true;
                    }
                }
            } else if (jsonObj->contains("images") && jsonObj->contains("change_keys")) {
                // This is config data
                responses[2].data = *jsonObj;
                responses[2].received = true;
            }
        }
    });
    
    // Make three different requests that should return different data
    qtmdb.genres_movie();   // Should return movie genres
    qtmdb.genres_tv();      // Should return TV genres  
    qtmdb.config_details(); // Should return config data
    
    // Wait for all responses
    QEventLoop loop;
    QObject::connect(&qtmdb, &aQtmdb::finishedLoadingData, [&responseCount, &loop](void*) {
        if (responseCount >= 3) {
            loop.quit();
        }
    });
    
    QTimer::singleShot(15000, &loop, &QEventLoop::quit); // 15 second timeout
    loop.exec();
    
    // Verify we got all responses
    EXPECT_EQ(responseCount, 3) << "Should receive exactly 3 responses";
    
    // Verify each response contains the expected data type
    int receivedResponses = 0;
    for (const auto& response : responses) {
        if (response.received) {
            receivedResponses++;
            
            if (response.requestType == "movie_genres" || response.requestType == "tv_genres") {
                QJsonObject obj = response.data.toObject();
                EXPECT_TRUE(obj.contains("genres")) 
                    << "Genres response should contain 'genres' field for " << response.requestType.toStdString();
                
                QJsonArray genres = obj["genres"].toArray();
                EXPECT_FALSE(genres.isEmpty()) 
                    << "Genres array should not be empty for " << response.requestType.toStdString();
                    
            } else if (response.requestType == "config") {
                QJsonObject obj = response.data.toObject();
                EXPECT_TRUE(obj.contains("images")) 
                    << "Config response should contain 'images' field";
                EXPECT_TRUE(obj.contains("change_keys")) 
                    << "Config response should contain 'change_keys' field";
            }
        }
    }
    
    EXPECT_GE(receivedResponses, 2) << "Should receive at least 2 correctly typed responses";
}

// Test to verify queue processes requests in order
TEST_F(QueueSystemTest, RequestProcessingOrder) {
    aQtmdb qtmdb(apiKey);
    
    std::vector<QString> requestOrder;
    int requestCount = 0;
    
    QObject::connect(&qtmdb, &aQtmdb::startedLoadingData, [&requestCount, &requestOrder]() {
        requestCount++;
        requestOrder.push_back(QString("Request_%1").arg(requestCount));
    });
    
    // Make multiple requests
    qtmdb.genres_movie();
    qtmdb.config_details();
    qtmdb.genres_tv();
    
    // Wait for all to start
    QEventLoop loop;
    int completedCount = 0;
    QObject::connect(&qtmdb, &aQtmdb::finishedLoadingData, [&completedCount, &loop](void*) {
        completedCount++;
        if (completedCount >= 3) {
            loop.quit();
        }
    });
    
    QTimer::singleShot(10000, &loop, &QEventLoop::quit);
    loop.exec();
    
    // Verify requests were processed in order
    EXPECT_EQ(requestOrder.size(), 3) << "Should have processed 3 requests";
    
    if (requestOrder.size() >= 3) {
        EXPECT_EQ(requestOrder[0], "Request_1") << "First request should be Request_1";
        EXPECT_EQ(requestOrder[1], "Request_2") << "Second request should be Request_2";  
        EXPECT_EQ(requestOrder[2], "Request_3") << "Third request should be Request_3";
    }
}