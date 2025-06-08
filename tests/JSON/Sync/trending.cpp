//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "../../../include/Sync/QTMDB.h"

TEST(Qtmdb_JSON_Trending_Test, movies)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.trending_movies(tmdb::timeWindow::timeWindow::day);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.value("results").isArray());
}

TEST(Qtmdb_JSON_Trending_Test, people)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.trending_people(tmdb::timeWindow::timeWindow::day);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.value("results").isArray());
}

TEST(Qtmdb_JSON_Trending_Test, tv)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.trending_tv(tmdb::timeWindow::timeWindow::day);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.value("results").isArray());
}