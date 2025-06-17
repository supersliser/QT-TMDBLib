//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "Sync/QTMDB.h"

TEST(Qtmdb_JSON_Company_Test, details)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.company_details(1);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("name").toString().toStdString().c_str(), "Lucasfilm Ltd.");
}

TEST(Qtmdb_JSON_Company_Test, images)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.company_images(1);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_EQ(response.value("logos").toArray()[0].toObject().value("width").toInt(), 1000);
}

TEST(Qtmdb_JSON_Company_Test, alternativeNames)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.company_alternativeNames(1);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("results").toArray()[1].toObject()["name"].toString().toStdString().c_str(), "Lucasfilm Ltd. LLC");
}
