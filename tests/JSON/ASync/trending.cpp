//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "aQTMDB.h"

TEST(aQtmdb_JSON_Trending_Test, movies)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.trending_movies(tmdb::timeWindow::timeWindow::day);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("results").isArray());
    });
}

TEST(aQtmdb_JSON_Trending_Test, people)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.trending_people(tmdb::timeWindow::timeWindow::day);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("results").isArray());
    });
}

TEST(aQtmdb_JSON_Trending_Test, tv)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.trending_tv(tmdb::timeWindow::timeWindow::day);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("results").isArray());
    });
}
