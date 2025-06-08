//
// Created by t on 23/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "Sync/QTMDB.h"

TEST(Qtmdb_JSON_TV_Episode_Test, details)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_episodes_details(1399, 1, 1);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("air_date").toString().toStdString().c_str(), "2011-04-17");
}

TEST(Qtmdb_JSON_TV_Episode_Test, changes)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_episodes_changes(63056);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.value("changes").isArray());
}

TEST(Qtmdb_JSON_TV_Episode_Test, credits)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_episodes_credits(1399, 1, 1);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("cast").toArray()[0].toObject().value("id").toInt(), 22970);
}

TEST(Qtmdb_JSON_TV_Episode_Test, externalIDs)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_episodes_externalIDs(1399, 1, 1);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("imdb_id").toString().toStdString().c_str(), "tt1480055");
}

TEST(Qtmdb_JSON_TV_Episode_Test, images)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_episodes_images(1399, 1, 1);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("id").toInt(), 63056);
}

TEST(Qtmdb_JSON_TV_Episode_Test, translations)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_episodes_translations(1399, 1, 1);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("translations").toArray()[0].toObject().value("name").toString().toStdString().c_str(), "English");
}

TEST(Qtmdb_JSON_TV_Episode_Test, videos)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_episodes_videos(1399, 1, 1);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.value("results").isArray());
}