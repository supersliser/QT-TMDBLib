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
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("name").toString().toStdString().c_str(), "Season 1");
        finished = true;
    });
    aQtmdb.tv_seasons_details(1399, 1);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_TV_Season_Test, aggregateCredits)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("cast").toArray()[0].toObject().value("id").isDouble());
        finished = true;
    });
    aQtmdb.tv_seasons_aggregateCredits(1399, 1);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_TV_Season_Test, changes)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("changes").isArray());
        finished = true;
    });
    aQtmdb.tv_seasons_changes(3624);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_TV_Season_Test, credits)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("cast").toArray()[0].toObject().value("id").toInt(), 22970);
        finished = true;
    });
    aQtmdb.tv_seasons_credits(1399, 1);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_TV_Season_Test, images)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("posters").toArray()[0].toObject().value("width").toInt(), 1000);
        finished = true;
    });
    aQtmdb.tv_seasons_images(1399, 1);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_TV_Season_Test, videos)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("results").toArray()[0].toObject().value("site").isString());
        finished = true;
    });
    aQtmdb.tv_seasons_videos(1399, 1);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_TV_Season_Test, translations)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("translations").toArray()[0].toObject().value("name").toString().toStdString().c_str(),
                     "English");
        finished = true;
    });
    aQtmdb.tv_seasons_translations(1399, 1);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_TV_Season_Test, watchProviders)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(
            data.value("results").toObject().value("GB").toObject().value("buy").toArray()[0].toObject().value(
                "provider_name").toString().toStdString().c_str(), "Apple TV");
        finished = true;
    });
    aQtmdb.tv_seasons_watchProviders(1399, 1);
    while (!finished)
    {
        QApplication::processEvents();
    }
}
