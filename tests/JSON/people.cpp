//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "QTMDB.h"

TEST(Qtmdb_JSON_People_Test, popular)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.people_popular("en-GB");
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.value("results").isArray());
}

TEST(Qtmdb_JSON_People_Test, details)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.people_details(31);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("name").toString(), "Tom Hanks");
}

TEST(Qtmdb_JSON_People_Test, changes)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.people_changes(31);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.value("changes").isArray());
}

TEST(Qtmdb_JSON_People_Test, combinedCredits)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.people_combinedCredits(31, "en-GB");
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("cast").toArray()[0].toObject().value("title"), "Forrest Gump");
}

TEST(Qtmdb_JSON_People_Test, externalIDs)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.people_externalIDs(31);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("instagram_id").toString(), "tomhanks");
}

TEST(Qtmdb_JSON_People_Test, images)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.people_images(31);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("profiles").toArray()[0].toObject().value("width").toInt(), 800);
}

TEST(Qtmdb_JSON_People_Test, latest)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.people_latest();
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.value("name").isString());
}

TEST(Qtmdb_JSON_People_Test, movieCredits)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.people_movieCredits(31, "en-GB");
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("cast").toArray()[0].toObject().value("title").toString().toStdString().c_str(), "Forrest Gump");
}

TEST(Qtmdb_JSON_People_Test, tvCredits)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.people_tvCredits(31, "en-GB");
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("cast").toArray()[0].toObject().value("name").toString().toStdString().c_str(), "Family Ties");
}

TEST(Qtmdb_JSON_People_Test, translations)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.people_translations(31);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("translations").toArray()[0].toObject().value("iso_639_1").toString().toStdString().c_str(), "en");
}