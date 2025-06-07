//
// Created by t on 22/05/25.
//
#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "aQTMDB.h"


TEST(aQtmdb_JSON_Account_Test, details)
{
    aQtmdb qtmdb(std::getenv("API_KEY"));
    qtmdb.account_details(22023427);
    QObject::connect(&qtmdb, &aQtmdb::finishedLoadingData, [&qtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("username").toString().toStdString().c_str(), "supersliser");
    });
}

TEST(aQtmdb_JSON_Account_Test, favoriteMovies)
{
    aQtmdb qtmdb(std::getenv("API_KEY"));
    qtmdb.account_favoriteMovies(22023427, "en-GB");
    QObject::connect(&qtmdb, &aQtmdb::finishedLoadingData, [&qtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("total_pages").toInt(), 0);
    });
}

TEST(aQtmdb_JSON_Account_Test, favoriteTV)
{
    aQtmdb qtmdb(std::getenv("API_KEY"));
    qtmdb.account_favoriteTV(22023427, "en-GB");
    QObject::connect(&qtmdb, &aQtmdb::finishedLoadingData, [&qtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("total_pages").toInt(), 0);
    });
}

TEST(aQtmdb_JSON_Account_Test, lists)
{
    aQtmdb qtmdb(std::getenv("API_KEY"));
    qtmdb.account_lists(22023427);
    QObject::connect(&qtmdb, &aQtmdb::finishedLoadingData, [&qtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("total_pages").toInt(), 0);
    });
}

TEST(aQtmdb_JSON_Account_Test, ratedMovies)
{
    aQtmdb qtmdb(std::getenv("API_KEY"));
    qtmdb.account_ratedMovies(22023427, "en-GB");
    QObject::connect(&qtmdb, &aQtmdb::finishedLoadingData, [&qtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("total_pages").toInt(), 0);
    });
}

TEST(aQtmdb_JSON_Account_Test, ratedTV)
{
    aQtmdb qtmdb(std::getenv("API_KEY"));
    qtmdb.account_ratedTV(22023427, "en-GB");
    QObject::connect(&qtmdb, &aQtmdb::finishedLoadingData, [&qtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("total_pages").toInt(), 0);
    });
}

TEST(aQtmdb_JSON_Account_Test, ratedTVEpisodes)
{
    aQtmdb qtmdb(std::getenv("API_KEY"));
    qtmdb.account_ratedTVEpisodes(22023427, "en-GB");
    QObject::connect(&qtmdb, &aQtmdb::finishedLoadingData, [&qtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("total_pages").toInt(), 0);
    });
}

TEST(aQtmdb_JSON_Account_Test, watchlistMovies)
{
    aQtmdb qtmdb(std::getenv("API_KEY"));
    qtmdb.account_watchlistMovies(22023427, "en-GB");
    QObject::connect(&qtmdb, &aQtmdb::finishedLoadingData, [&qtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("total_pages").toInt(), 0);
    });
}

TEST(aQtmdb_JSON_Account_Test, watchlistTV)
{
    aQtmdb qtmdb(std::getenv("API_KEY"));
    qtmdb.account_watchlistTV(22023427, "en-GB");
    QObject::connect(&qtmdb, &aQtmdb::finishedLoadingData, [&qtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("total_pages").toInt(), 0);
    });
}
