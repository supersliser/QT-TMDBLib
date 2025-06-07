//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "aQTMDB.h"

TEST(aQtmdb_JSON_Movie_Test, details)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.movie_details(550);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("title").toString().toStdString().c_str(), "Fight Club");
    });
}

TEST(aQtmdb_JSON_Movie_Test, alternativeTitles)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.movie_alternativeTitles(550);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("titles").toArray()[0].toObject()["iso_3166_1"].toString().toStdString().c_str(), "IL");
    });
}

TEST(aQtmdb_JSON_Movie_Test, changes)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.movie_changes(550, QDate(2025, 05, 19), QDate(2025, 05, 20));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("changes").isArray());
    });
}

TEST(aQtmdb_JSON_Movie_Test, credits)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.movie_credits(550);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("cast").toArray()[0].toObject().value("name").toString().toStdString().c_str(),
                     "Edward Norton");
    });
}

TEST(aQtmdb_JSON_Movie_Test, externalIDs)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.movie_externalIDs(550);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("imdb_id").toString().toStdString().c_str(), "tt0137523");
    });
}

TEST(aQtmdb_JSON_Movie_Test, images)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.movie_images(550, "en");
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("backdrops").toArray()[0].toObject().value("width").toInt(), 1920);
    });
}

TEST(aQtmdb_JSON_Movie_Test, keywords)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.movie_keywords(550);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("keywords").toArray()[0].toObject().value("name").toString().toStdString().c_str(),
                     "dual identity");
    });
}

TEST(aQtmdb_JSON_Movie_Test, latest)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.movie_latest();
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("adult").isBool());
    });
}

TEST(aQtmdb_JSON_Movie_Test, lists)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.movie_lists(550);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("results").isArray());
    });
}

TEST(aQtmdb_JSON_Movie_Test, recommendations)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.movie_recommendations(550);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("results").toArray()[0].toObject().value("title").toString().toStdString().c_str(),
                     "Pulp Fiction");
    });
}

TEST(aQtmdb_JSON_Movie_Test, releaseDates)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.movie_releaseDates(550);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(
            data.value("results").toArray()[0].toObject().value("release_dates").toArray()[0].toObject().value("note").
            toString().toStdString().c_str(), "Blu-ray");
    });
}

TEST(aQtmdb_JSON_Movie_Test, reviews)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.movie_reviews(550, "en-GB");
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("results").toArray()[0].toObject().value("author").toString().toStdString().c_str(),
                     "Goddard");
    });
}

TEST(aQtmdb_JSON_Movie_Test, similar)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.movie_similar(550, "en-GB");
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("results").toArray()[0].isObject());
    });
}

TEST(aQtmdb_JSON_Movie_Test, translations)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.movie_translations(550);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(
            data.value("translations").toArray()[0].toObject().value("iso_639_1").toString().toStdString().c_str(),
            "en");
    });
}

TEST(aQtmdb_JSON_Movie_Test, videos)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.movie_videos(550, "en-GB");
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("results").toArray()[0].toObject()["iso_639_1"].toString().toStdString().c_str(), "en");
    });
}

TEST(aQtmdb_JSON_Movie_Test, watchProviders)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.movie_watchProviders(550);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(
            data.value("results").toObject().value("GB").toObject().value("flatrate").toArray()[0].toObject().value(
                "provider_name").toString().toStdString().c_str(), "Disney Plus");
    });
}
