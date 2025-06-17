//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "Sync/QTMDB.h"

TEST(Qtmdb_JSON_Genres_Test, movie)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.genres_movie();
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("genres").toArray()[0].toObject().value("name").toString().toStdString().c_str(), "Action");
}

TEST(Qtmdb_JSON_Genres_Test, tv)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.genres_tv();
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("genres").toArray()[0].toObject().value("name").toString().toStdString().c_str(), "Action & Adventure");
}