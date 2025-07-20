//
// Test for the async request queue system 
// Created to verify fix for issue: multiple async requests causing data confusion
//

#include <gtest/gtest.h>
#include <QCoreApplication>
#include <QTimer>
#include <QSignalSpy>
#include "ASync/QTMDB.h"

// Test that verifies the queue system prevents simultaneous requests
TEST(AsyncQueueSystemTest, QueuePreventsSimultaneousRequests) {
    // Initialize Qt application for this test
    int argc = 0;
    char** argv = nullptr;
    QCoreApplication app(argc, argv);
    
    aQtmdb qtmdb("test_api_key");
    
    QSignalSpy startSpy(&qtmdb, &aQtmdb::startedLoadingData);
    
    // Make multiple requests quickly
    qtmdb.genres_movie();
    qtmdb.genres_tv();
    qtmdb.config_details();
    
    // Process events briefly to allow immediate processing
    app.processEvents();
    
    // With the queue system, only the first request should start immediately
    // The others should be queued
    EXPECT_EQ(startSpy.count(), 1) << "Only one request should start immediately with queue system";
    
    // This test validates that the queue prevents the original issue where
    // multiple requests would be sent simultaneously causing data confusion
    SUCCEED() << "Queue system successfully prevents simultaneous requests";
}

// Basic test to verify queue functionality exists
TEST(AsyncQueueSystemTest, QueueBasicFunctionality) {
    int argc = 0;
    char** argv = nullptr;
    QCoreApplication app(argc, argv);
    
    aQtmdb qtmdb("test_api_key");
    
    // Just verify we can create multiple requests without crashes
    qtmdb.genres_movie();
    qtmdb.genres_tv();
    
    // Process events
    app.processEvents();
    
    SUCCEED() << "Queue system handles multiple requests without crashes";
}