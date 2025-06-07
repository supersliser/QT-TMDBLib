//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "QTMDB.h"

TEST(Qtmdb_JSON_Network_Test, details)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.network_details(49);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("name").toString().toStdString().c_str(), "HBO");
}

TEST(Qtmdb_JSON_Network_Test, alternativeNames)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.network_alternativeNames(49);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("results").toArray()[0].toObject().value("name").toString().toStdString().c_str(), "Home Box Office");
}

TEST(Qtmdb_JSON_Network_Test, images)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.network_images(49);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("logos").toArray()[0].toObject().value("width").toInt(), 422);
}