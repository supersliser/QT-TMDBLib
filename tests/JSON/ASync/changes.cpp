//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "ASync/QTMDB.h"

TEST(aQtmdb_JSON_Changes_Test, movie)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.changes_movie(QDate(2025, 5, 20), QDate(2025, 5, 19));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("results").toArray()[0].toObject().value("id").toInt(), 1441234);
    });
}

TEST(aQtmdb_JSON_Changes_Test, people)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.changes_people(QDate(2025, 5, 20), QDate(2025, 5, 19));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("results").toArray()[0].toObject().value("id").toInt(), 5447571);
    });
}

TEST(aQtmdb_JSON_Changes_Test, tv)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.changes_tv(QDate(2025, 5, 20), QDate(2025, 5, 19));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("results").toArray()[0].toObject().value("id").toInt(), 2734);
    });
}
