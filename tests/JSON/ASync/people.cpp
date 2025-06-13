//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "ASync/QTMDB.h"

TEST(aQtmdb_JSON_People_Test, popular)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.people_popular("en-GB");
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("results").isArray());
    });
}

TEST(aQtmdb_JSON_People_Test, details)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.people_details(31);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("name").toString(), "Tom Hanks");
    });
}

TEST(aQtmdb_JSON_People_Test, changes)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.people_changes(31);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("changes").isArray());
    });
}

TEST(aQtmdb_JSON_People_Test, combinedCredits)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.people_combinedCredits(31, "en-GB");
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("cast").toArray()[0].toObject().value("title"), "Forrest Gump");
    });
}

TEST(aQtmdb_JSON_People_Test, externalIDs)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.people_externalIDs(31);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("instagram_id").toString(), "tomhanks");
    });
}

TEST(aQtmdb_JSON_People_Test, images)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.people_images(31);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("profiles").toArray()[0].toObject().value("width").toInt(), 800);
    });
}

TEST(aQtmdb_JSON_People_Test, latest)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.people_latest();
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("name").isString());
    });
}

TEST(aQtmdb_JSON_People_Test, movieCredits)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.people_movieCredits(31, "en-GB");
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("cast").toArray()[0].toObject().value("title").toString().toStdString().c_str(),
                     "Forrest Gump");
    });
}

TEST(aQtmdb_JSON_People_Test, tvCredits)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.people_tvCredits(31, "en-GB");
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("cast").toArray()[0].toObject().value("name").toString().toStdString().c_str(),
                     "Family Ties");
    });
}

TEST(aQtmdb_JSON_People_Test, translations)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.people_translations(31);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(
            data.value("translations").toArray()[0].toObject().value("iso_639_1").toString().toStdString().c_str(),
            "en");
    });
}
