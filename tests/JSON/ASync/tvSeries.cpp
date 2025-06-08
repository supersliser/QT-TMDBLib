//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "Async/QTMDB.h"

TEST(aQtmdb_JSON_TV_Series_Test, airingToday)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_series_airingToday();
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("results").isArray());
    });
}

TEST(aQtmdb_JSON_TV_Series_Test, onTheAir)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_series_onTheAir();
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("results").isArray());
    });
}

TEST(aQtmdb_JSON_TV_Series_Test, popular)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_series_popular();
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("results").isArray());
    });
}

TEST(aQtmdb_JSON_TV_Series_Test, topRated)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_series_topRated();
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("results").isArray());
    });
}

TEST(aQtmdb_JSON_TV_Series_Test, details)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_series_details(1399);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("name").toString().toStdString().c_str(), "Game of Thrones");
    });
}

TEST(aQtmdb_JSON_TV_Series_Test, aggregateCredits)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_series_aggregateCredits(1399);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("cast").isArray());
    });
}

TEST(aQtmdb_JSON_TV_Series_Test, alternativeTitles)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_series_alternativeTitles(1399);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("results").toArray()[0].toObject().value("iso_3166_1").toString().toStdString().c_str(),
                     "AL");
    });
}

TEST(aQtmdb_JSON_TV_Series_Test, changes)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_series_changes(1399);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("changes").isArray());
    });
}

TEST(aQtmdb_JSON_TV_Series_Test, contentRatings)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_series_contentRatings(1399);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("results").toArray()[0].toObject().value("iso_3166_1").toString().toStdString().c_str(),
                     "FR");
    });
}

TEST(aQtmdb_JSON_TV_Series_Test, credits)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_series_credits(1399);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("cast").isArray());
    });
}

TEST(aQtmdb_JSON_TV_Series_Test, episodeGroups)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_series_episodeGroups(1399);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("results").toArray()[0].toObject().value("name").toString().toStdString().c_str(),
                     "Aired Order");
    });
}

TEST(aQtmdb_JSON_TV_Series_Test, externalIDs)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_series_externalIDs(1399);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("facebook_id").toString().toStdString().c_str(), "GameOfThrones");
    });
}

TEST(aQtmdb_JSON_TV_Series_Test, images)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_series_images(1399, "en");
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("backdrops").toArray()[0].toObject().value("width"), 3840);
    });
}

TEST(aQtmdb_JSON_TV_Series_Test, keywords)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_series_keywords(1399);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("results").toArray()[0].toObject().value("id"), 818);
    });
}

TEST(aQtmdb_JSON_TV_Series_Test, latest)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_series_latest();
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("name").isString());
    });
}

TEST(aQtmdb_JSON_TV_Series_Test, lists)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_series_lists(1399);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("results").isArray());
    });
}

TEST(aQtmdb_JSON_TV_Series_Test, recommendations)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_series_recommendations(1399);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("results").isArray());
    });
}

TEST(aQtmdb_JSON_TV_Series_Test, reviews)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_series_reviews(1399);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("results").toArray()[0].toObject().value("author").toString().toStdString().c_str(),
                     "lmao7");
    });
}

TEST(aQtmdb_JSON_TV_Series_Test, screenedTheatrically)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_series_screenedTheatrically(1399);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("results").isArray());
    });
}

TEST(aQtmdb_JSON_TV_Series_Test, similar)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_series_similar(1399);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("results").isArray());
    });
}

TEST(aQtmdb_JSON_TV_Series_Test, translations)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_series_translations(1399);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("translations").isArray());
    });
}

TEST(aQtmdb_JSON_TV_Series_Test, videos)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_series_videos(1399);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("results").toArray()[0].toObject().value("type").toString().toStdString().c_str(),
                     "Trailer");
    });
}

TEST(aQtmdb_JSON_TV_Series_Test, watchProviders)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.tv_series_watchProviders(1399);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(
            data.value("results").toObject().value("GB").toObject().value("flatrate").toArray()[0].toObject().value(
                "provider_id").toInt(), 39);
    });
}
