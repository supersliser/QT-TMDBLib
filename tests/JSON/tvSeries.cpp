//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "QTMDB.h"

TEST(Qtmdb_JSON_TV_Series_Test, airingToday)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_series_airingToday();
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.value("results").isArray());
}

TEST(Qtmdb_JSON_TV_Series_Test, onTheAir)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_series_onTheAir();
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.value("results").isArray());
}

TEST(Qtmdb_JSON_TV_Series_Test, popular)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_series_popular();
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.value("results").isArray());
}

TEST(Qtmdb_JSON_TV_Series_Test, topRated)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_series_topRated();
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.value("results").isArray());
}

TEST(Qtmdb_JSON_TV_Series_Test, details)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_series_details(1399);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("name").toString().toStdString().c_str(), "Game of Thrones");
}

TEST(Qtmdb_JSON_TV_Series_Test, aggregateCredits)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_series_aggregateCredits(1399);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.value("cast").isArray());
}

TEST(Qtmdb_JSON_TV_Series_Test, alternativeTitles)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_series_alternativeTitles(1399);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("results").toArray()[0].toObject().value("iso_3166_1").toString().toStdString().c_str(), "AL");
}

TEST(Qtmdb_JSON_TV_Series_Test, changes)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_series_changes(1399);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.value("changes").isArray());
}

TEST(Qtmdb_JSON_TV_Series_Test, contentRatings)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_series_contentRatings(1399);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("results").toArray()[0].toObject().value("iso_3166_1").toString().toStdString().c_str(), "FR");
}

TEST(Qtmdb_JSON_TV_Series_Test, credits)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_series_credits(1399);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.value("cast").isArray());
}

TEST(Qtmdb_JSON_TV_Series_Test, episodeGroups)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_series_episodeGroups(1399);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("results").toArray()[0].toObject().value("name").toString().toStdString().c_str(), "Aired Order");
}

TEST(Qtmdb_JSON_TV_Series_Test, externalIDs)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_series_externalIDs(1399);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("facebook_id").toString().toStdString().c_str(), "GameOfThrones");
}

TEST(Qtmdb_JSON_TV_Series_Test, images)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_series_images(1399, "en");
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("backdrops").toArray()[0].toObject().value("width"), 3840);
}

TEST(Qtmdb_JSON_TV_Series_Test, keywords)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_series_keywords(1399);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("results").toArray()[0].toObject().value("id"), 818);
}

TEST(Qtmdb_JSON_TV_Series_Test, latest)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_series_latest();
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.value("name").isString());
}

TEST(Qtmdb_JSON_TV_Series_Test, lists)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_series_lists(1399);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.value("results").isArray());
}

TEST(Qtmdb_JSON_TV_Series_Test, recommendations)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_series_recommendations(1399);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.value("results").isArray());
}

TEST(Qtmdb_JSON_TV_Series_Test, reviews)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_series_reviews(1399);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("results").toArray()[0].toObject().value("author").toString().toStdString().c_str(), "lmao7");
}

TEST(Qtmdb_JSON_TV_Series_Test, screenedTheatrically)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_series_screenedTheatrically(1399);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.value("results").isArray());
}

TEST(Qtmdb_JSON_TV_Series_Test, similar)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_series_similar(1399);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.value("results").isArray());
}

TEST(Qtmdb_JSON_TV_Series_Test, translations)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_series_translations(1399);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.value("translations").isArray());
}

TEST(Qtmdb_JSON_TV_Series_Test, videos)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_series_videos(1399);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("results").toArray()[0].toObject().value("type").toString().toStdString().c_str(), "Trailer");
}

TEST(Qtmdb_JSON_TV_Series_Test, watchProviders)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.tv_series_watchProviders(1399);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("results").toObject().value("GB").toObject().value("flatrate").toArray()[0].toObject().value("provider_id").toInt(), 39);
}