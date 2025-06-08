//
// Created by t on 23/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "Sync/QTMDB.h"

TEST(Qtmdb_JSON_WatchProviders_Test, regions)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.watchProviders_regions();
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("results").toArray()[0].toObject().value("english_name").toString().toStdString().c_str(), "Andorra");
}

TEST(Qtmdb_JSON_WatchProviders_Test, movie)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.watchProviders_movie();
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("results").toArray()[0].toObject().value("display_priorities").toObject().value("GB").toInt(), 4);
}

TEST(Qtmdb_JSON_WatchProviders_Test, tv)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.watchProviders_tv();
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("results").toArray()[0].toObject().value("display_priorities").toObject().value("GB").toInt(), 4);
}