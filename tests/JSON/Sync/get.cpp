//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "Sync/QTMDB.h"

TEST(Qtmdb_JSON_Get_Test, collection)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.get_collection("Avengers");
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("results").toArray()[0].toObject()["id"].toInt(), 482721);
}

TEST(Qtmdb_JSON_Get_Test, company)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.get_company("HBO");
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("results").toArray()[0].toObject()["id"].toInt(), 3268);
}

TEST(Qtmdb_JSON_Get_Test, keyword)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.get_keyword("lost");
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("results").toArray()[0].toObject()["id"].toInt(), 262419);
}

TEST(Qtmdb_JSON_Get_Test, movie)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.get_movie("Fight Club");
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("results").toArray()[0].toObject()["id"].toInt(), 550);
}

TEST(Qtmdb_JSON_Get_Test, person)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.get_person("Tom Hanks");
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("results").toArray()[0].toObject()["id"].toInt(), 31);
}

TEST(Qtmdb_JSON_Get_Test, tv)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.get_tv("Breaking Bad");
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("results").toArray()[0].toObject()["id"].toInt(), 1396);
}