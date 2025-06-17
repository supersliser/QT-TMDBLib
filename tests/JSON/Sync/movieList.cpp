//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "Sync/QTMDB.h"

TEST(Qtmdb_JSON_MovieList_Test, nowPlaying)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.movieList_nowPlaying("GB");
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("results").isArray(), true);
}

TEST(Qtmdb_JSON_MovieList_Test, popular)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.movieList_popular("GB");
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("results").isArray(), true);
}

TEST(Qtmdb_JSON_MovieList_Test, topRated)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.movieList_topRated("GB");
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("results").isArray(), true);
}

TEST(Qtmdb_JSON_MovieList_Test, upcoming)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.movieList_upcoming("GB");
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("results").isArray(), true);
}