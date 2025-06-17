//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "Sync/QTMDB.h"

TEST(Qtmdb_JSON_Collection_Test, details)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.collection_details(10);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("name").toString().toStdString().c_str(), "Star Wars Collection");
}

TEST(Qtmdb_JSON_Collection_Test, images)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.collection_images(10);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("backdrops").toArray()[0].toObject().value("width").toInt(), 1920);
}

TEST(Qtmdb_JSON_Collection_Test, translations)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.collection_translations(10);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.value("translations").toArray()[0].toObject().value("iso_639_1").isString());
}