//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "QTMDB.h"

TEST(Qtmdb_JSON_Changes_Test, movie)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.changes_movie(QDate(2025, 5, 20), QDate(2025, 5, 19));
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("results").toArray()[0].toObject().value("id").toInt(), 1441234);
}

TEST(Qtmdb_JSON_Changes_Test, people)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.changes_people(QDate(2025, 5, 20), QDate(2025, 5, 19));
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("results").toArray()[0].toObject().value("id").toInt(), 5447571);
}

TEST(Qtmdb_JSON_Changes_Test, tv)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.changes_tv(QDate(2025, 5, 20), QDate(2025, 5, 19));
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("results").toArray()[0].toObject().value("id").toInt(), 2734);
}