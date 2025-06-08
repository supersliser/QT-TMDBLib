//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "Async/QTMDB.h"

TEST(aQtmdb_JSON_MovieList_Test, nowPlaying)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.movieList_nowPlaying("GB");
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("results").isArray(), true);
    });
}

TEST(aQtmdb_JSON_MovieList_Test, popular)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.movieList_popular("GB");
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("results").isArray(), true);
    });
}

TEST(aQtmdb_JSON_MovieList_Test, topRated)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.movieList_topRated("GB");
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("results").isArray(), true);
    });
}

TEST(aQtmdb_JSON_MovieList_Test, upcoming)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.movieList_upcoming("GB");
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("results").isArray(), true);
    });
}
