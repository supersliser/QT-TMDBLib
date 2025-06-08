//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "Async/QTMDB.h"

TEST(aQtmdb_JSON_Get_Test, collection)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.get_collection("Avengers");
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("results").toArray()[0].toObject()["id"].toInt(), 482721);
    });
}

TEST(aQtmdb_JSON_Get_Test, company)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.get_company("HBO");
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("results").toArray()[0].toObject()["id"].toInt(), 3268);
    });
}

TEST(aQtmdb_JSON_Get_Test, keyword)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.get_keyword("lost");
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("results").toArray()[0].toObject()["id"].toInt(), 262419);
    });
}

TEST(aQtmdb_JSON_Get_Test, movie)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.get_movie("Fight Club");
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("results").toArray()[0].toObject()["id"].toInt(), 550);
    });
}

TEST(aQtmdb_JSON_Get_Test, person)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.get_person("Tom Hanks");
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("results").toArray()[0].toObject()["id"].toInt(), 31);
    });
}

TEST(aQtmdb_JSON_Get_Test, tv)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.get_tv("Breaking Bad");
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("results").toArray()[0].toObject()["id"].toInt(), 1396);
    });
}
