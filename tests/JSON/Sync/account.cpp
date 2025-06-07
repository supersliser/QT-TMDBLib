//
// Created by t on 22/05/25.
//
#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "QTMDB.h"


TEST(Qtmdb_JSON_Account_Test, details)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.account_details(22023427);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("username").toString().toStdString().c_str(), "supersliser");
}

TEST(Qtmdb_JSON_Account_Test, favoriteMovies)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.account_favoriteMovies(22023427, "en-GB");
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("total_pages").toInt(), 0);
}

TEST(Qtmdb_JSON_Account_Test, favoriteTV)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.account_favoriteTV(22023427, "en-GB");
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("total_pages").toInt(), 0);
}

TEST(Qtmdb_JSON_Account_Test, lists)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.account_lists(22023427);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("total_pages").toInt(), 0);
}

TEST(Qtmdb_JSON_Account_Test, ratedMovies)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.account_ratedMovies(22023427, "en-GB");
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("total_pages").toInt(), 0);
}

TEST(Qtmdb_JSON_Account_Test, ratedTV)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.account_ratedTV(22023427, "en-GB");
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("total_pages").toInt(), 0);
}

TEST(Qtmdb_JSON_Account_Test, ratedTVEpisodes)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.account_ratedTVEpisodes(22023427, "en-GB");
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("total_pages").toInt(), 0);
}

TEST(Qtmdb_JSON_Account_Test, watchlistMovies)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.account_watchlistMovies(22023427, "en-GB");
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("total_pages").toInt(), 0);
}

TEST(Qtmdb_JSON_Account_Test, watchlistTV)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.account_watchlistTV(22023427, "en-GB");
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("total_pages").toInt(), 0);
}