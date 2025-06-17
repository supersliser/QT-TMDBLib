//
// Created by t on 22/05/25.
//
#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "ASync/QTMDB.h"
#include <QTimer>

TEST(aQtmdb_JSON_Account_Test, details)
{
    bool finished = false;
    aQtmdb qtmdb(std::getenv("API_KEY"));
    QObject::connect(&qtmdb, &aQtmdb::finishedLoadingData, [&qtmdb, &finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("username").toString().toStdString().c_str(), "supersliser");
        finished = true;
    });
    qtmdb.account_details(22023427);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Account_Test, favoriteMovies)
{
    bool finished = false;
    aQtmdb qtmdb(std::getenv("API_KEY"));
    QObject::connect(&qtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("total_pages").toInt(), 0);
        finished = true;
    });
    qtmdb.account_favoriteMovies(22023427, "en-GB");
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Account_Test, favoriteTV)
{
    bool finished = false;
    aQtmdb qtmdb(std::getenv("API_KEY"));
    QObject::connect(&qtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("total_pages").toInt(), 0);
        finished = true;
    });
    qtmdb.account_favoriteTV(22023427, "en-GB");
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Account_Test, lists)
{
    bool testsCompleted = false;
    aQtmdb qtmdb(std::getenv("API_KEY"));
    QObject::connect(&qtmdb, &aQtmdb::finishedLoadingData, [&qtmdb, &testsCompleted](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("total_pages").toInt(), 0);
        testsCompleted = true;
    });
    qtmdb.account_lists(22023427);
    while (!testsCompleted)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Account_Test, ratedMovies)
{
    bool testsCompleted = false;
    aQtmdb qtmdb(std::getenv("API_KEY"));
    QObject::connect(&qtmdb, &aQtmdb::finishedLoadingData, [&qtmdb, &testsCompleted](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("total_pages").toInt(), 0);
        testsCompleted = true;
    });
    qtmdb.account_ratedMovies(22023427, "en-GB");
    while (!testsCompleted)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Account_Test, ratedTV)
{
    bool testsCompleted = false;
    aQtmdb qtmdb(std::getenv("API_KEY"));
    QObject::connect(&qtmdb, &aQtmdb::finishedLoadingData, [&qtmdb, &testsCompleted](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("total_pages").toInt(), 0);
        testsCompleted = true;
    });
    qtmdb.account_ratedTV(22023427, "en-GB");
    while (!testsCompleted)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Account_Test, ratedTVEpisodes)
{
    bool testsCompleted = false;
    aQtmdb qtmdb(std::getenv("API_KEY"));
    QObject::connect(&qtmdb, &aQtmdb::finishedLoadingData, [&qtmdb, &testsCompleted](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("total_pages").toInt(), 0);
        testsCompleted = true;
    });
    qtmdb.account_ratedTVEpisodes(22023427, "en-GB");
    while (!testsCompleted)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Account_Test, watchlistMovies)
{
    bool testsCompleted = false;
    aQtmdb qtmdb(std::getenv("API_KEY"));
    QObject::connect(&qtmdb, &aQtmdb::finishedLoadingData, [&qtmdb, &testsCompleted](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("total_pages").toInt(), 0);
        testsCompleted = true;
    });
    qtmdb.account_watchlistMovies(22023427, "en-GB");
    while (!testsCompleted)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Account_Test, watchlistTV)
{
    bool testsCompleted = false;
    aQtmdb qtmdb(std::getenv("API_KEY"));
    QObject::connect(&qtmdb, &aQtmdb::finishedLoadingData, [&qtmdb, &testsCompleted](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("total_pages").toInt(), 0);
        testsCompleted = true;
    });
    qtmdb.account_watchlistMovies(22023427, "en-GB");
    while (!testsCompleted)
    {
        QApplication::processEvents();
    }
}
