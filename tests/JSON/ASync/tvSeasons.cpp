//
// Created by t on 23/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "QTMDB.h"

TEST(Qtmdb_JSON_TV_Season_Test, details)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_seasons_details(1399, 1);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("name").toString().toStdString().c_str(), "Season 1");
}

TEST(Qtmdb_JSON_TV_Season_Test, aggregateCredits)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_seasons_aggregateCredits(1399, 1);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.value("cast").toArray()[0].toObject().value("id").isDouble());
}

TEST(Qtmdb_JSON_TV_Season_Test, changes)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_seasons_changes(3624);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.value("changes").isArray());
}

TEST(Qtmdb_JSON_TV_Season_Test, credits)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_seasons_credits(1399, 1);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("cast").toArray()[0].toObject().value("id").toInt(), 22970);
}

TEST(Qtmdb_JSON_TV_Season_Test, images)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_seasons_images(1399, 1);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("posters").toArray()[0].toObject().value("width").toInt(), 1000);
}

TEST(Qtmdb_JSON_TV_Season_Test, videos)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_seasons_videos(1399, 1);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.value("results").toArray()[0].toObject().value("site").isString());
}

TEST(Qtmdb_JSON_TV_Season_Test, translations)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_seasons_translations(1399, 1);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("translations").toArray()[0].toObject().value("name").toString().toStdString().c_str(), "English");
}

TEST(Qtmdb_JSON_TV_Season_Test, watchProviders)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_seasons_watchProviders(1399, 1);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("results").toObject().value("GB").toObject().value("buy").toArray()[0].toObject().value("provider_name").toString().toStdString().c_str(), "Apple TV");
}