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
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(
            data.value("results").toArray()[0].toObject().value("english_name").toString().toStdString().c_str(),
            "Andorra");
        finished = true;
    });
    aQtmdb.watchProviders_regions();
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_WatchProviders_Test, movie)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(
            data.value("results").toArray()[0].toObject().value("display_priorities").toObject().value("GB").toInt(),
            4);
        finished = true;
    });
    aQtmdb.watchProviders_movie();
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_WatchProviders_Test, tv)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(
            data.value("results").toArray()[0].toObject().value("display_priorities").toObject().value("GB").toInt(),
            4);
        finished = true;
    });
    aQtmdb.watchProviders_tv();
    while (!finished)
    {
        QApplication::processEvents();
    }
}
