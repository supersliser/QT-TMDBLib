//
// Created by t on 23/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "ASync/QTMDB.h"

TEST(aQtmdb_JSON_WatchProviders_Test, regions)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.watchProviders_regions();
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(
            data.value("results").toArray()[0].toObject().value("english_name").toString().toStdString().c_str(),
            "Andorra");
    });
}

TEST(aQtmdb_JSON_WatchProviders_Test, movie)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.watchProviders_movie();
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(
            data.value("results").toArray()[0].toObject().value("display_priorities").toObject().value("GB").toInt(),
            4);
    });
}

TEST(aQtmdb_JSON_WatchProviders_Test, tv)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.watchProviders_tv();
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(
            data.value("results").toArray()[0].toObject().value("display_priorities").toObject().value("GB").toInt(),
            4);
    });
}
