//
// Created by t on 23/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "ASync/QTMDB.h"

TEST(aQtmdb_JSON_TV_Season_Test, details)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_seasons_details(1399, 1);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("name").toString().toStdString().c_str(), "Season 1");
    });
}

TEST(aQtmdb_JSON_TV_Season_Test, aggregateCredits)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_seasons_aggregateCredits(1399, 1);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("cast").toArray()[0].toObject().value("id").isDouble());
    });
}

TEST(aQtmdb_JSON_TV_Season_Test, changes)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_seasons_changes(3624);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("changes").isArray());
    });
}

TEST(aQtmdb_JSON_TV_Season_Test, credits)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_seasons_credits(1399, 1);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("cast").toArray()[0].toObject().value("id").toInt(), 22970);
    });
}

TEST(aQtmdb_JSON_TV_Season_Test, images)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_seasons_images(1399, 1);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("posters").toArray()[0].toObject().value("width").toInt(), 1000);
    });
}

TEST(aQtmdb_JSON_TV_Season_Test, videos)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_seasons_videos(1399, 1);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("results").toArray()[0].toObject().value("site").isString());
    });
}

TEST(aQtmdb_JSON_TV_Season_Test, translations)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_seasons_translations(1399, 1);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("translations").toArray()[0].toObject().value("name").toString().toStdString().c_str(),
                     "English");
    });
}

TEST(aQtmdb_JSON_TV_Season_Test, watchProviders)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_seasons_watchProviders(1399, 1);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(
            data.value("results").toObject().value("GB").toObject().value("buy").toArray()[0].toObject().value(
                "provider_name").toString().toStdString().c_str(), "Apple TV");
    });
}
