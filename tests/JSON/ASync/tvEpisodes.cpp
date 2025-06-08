//
// Created by t on 23/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "Async/QTMDB.h"

TEST(aQtmdb_JSON_TV_Episode_Test, details)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_episodes_details(1399, 1, 1);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("air_date").toString().toStdString().c_str(), "2011-04-17");
    });
}

TEST(aQtmdb_JSON_TV_Episode_Test, changes)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_episodes_changes(63056);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("changes").isArray());
    });
}

TEST(aQtmdb_JSON_TV_Episode_Test, credits)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_episodes_credits(1399, 1, 1);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("cast").toArray()[0].toObject().value("id").toInt(), 22970);
    });
}

TEST(aQtmdb_JSON_TV_Episode_Test, externalIDs)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_episodes_externalIDs(1399, 1, 1);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("imdb_id").toString().toStdString().c_str(), "tt1480055");
    });
}

TEST(aQtmdb_JSON_TV_Episode_Test, images)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_episodes_images(1399, 1, 1);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("id").toInt(), 63056);
    });
}

TEST(aQtmdb_JSON_TV_Episode_Test, translations)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_episodes_translations(1399, 1, 1);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("translations").toArray()[0].toObject().value("name").toString().toStdString().c_str(),
                     "English");
    });
}

TEST(aQtmdb_JSON_TV_Episode_Test, videos)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_episodes_videos(1399, 1, 1);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("results").isArray());
    });
}
