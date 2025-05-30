//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "QTMDB.h"

TEST(Qtmdb_JSON_Movie_Test, details)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.movie_details(550);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("title").toString().toStdString().c_str(), "Fight Club");
}

TEST(Qtmdb_JSON_Movie_Test, alternativeTitles)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.movie_alternativeTitles(550);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("titles").toArray()[0].toObject()["iso_3166_1"].toString().toStdString().c_str(), "IL");
}

TEST(Qtmdb_JSON_Movie_Test, changes)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.movie_changes(550, QDate(2025, 05, 19), QDate(2025, 05, 20));
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.value("changes").isArray());
}

TEST(Qtmdb_JSON_Movie_Test, credits)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.movie_credits(550);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("cast").toArray()[0].toObject().value("name").toString().toStdString().c_str(), "Edward Norton");
}

TEST(Qtmdb_JSON_Movie_Test, externalIDs)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.movie_externalIDs(550);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("imdb_id").toString().toStdString().c_str(), "tt0137523");
}

TEST(Qtmdb_JSON_Movie_Test, images)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.movie_images(550, "en");
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("backdrops").toArray()[0].toObject().value("width").toInt(), 1920);
}

TEST(Qtmdb_JSON_Movie_Test, keywords)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.movie_keywords(550);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("keywords").toArray()[0].toObject().value("name").toString().toStdString().c_str(), "dual identity");
}

TEST(Qtmdb_JSON_Movie_Test, latest)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.movie_latest();
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.value("adult").isBool());
}

TEST(Qtmdb_JSON_Movie_Test, lists)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.movie_lists(550);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.value("results").isArray());
}

TEST(Qtmdb_JSON_Movie_Test, recommendations)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.movie_recommendations(550);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("results").toArray()[0].toObject().value("title").toString().toStdString().c_str(), "Pulp Fiction");
}

TEST(Qtmdb_JSON_Movie_Test, releaseDates)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.movie_releaseDates(550);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("results").toArray()[0].toObject().value("release_dates").toArray()[0].toObject().value("note").toString().toStdString().c_str(), "Blu-ray");
}
TEST(Qtmdb_JSON_Movie_Test, reviews)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.movie_reviews(550, "en-GB");
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("results").toArray()[0].toObject().value("author").toString().toStdString().c_str(), "Goddard");
}
TEST(Qtmdb_JSON_Movie_Test, similar)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.movie_similar(550, "en-GB");
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.value("results").toArray()[0].isObject());
}
TEST(Qtmdb_JSON_Movie_Test, translations)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.movie_translations(550);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("translations").toArray()[0].toObject().value("iso_639_1").toString().toStdString().c_str(), "en");
}
TEST(Qtmdb_JSON_Movie_Test, videos)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.movie_videos(550, "en-GB");
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("results").toArray()[0].toObject()["iso_639_1"].toString().toStdString().c_str(), "en");
}
TEST(Qtmdb_JSON_Movie_Test, watchProviders)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.movie_watchProviders(550);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("results").toObject().value("GB").toObject().value("flatrate").toArray()[0].toObject().value("provider_name").toString().toStdString().c_str(), "Disney Plus");
}