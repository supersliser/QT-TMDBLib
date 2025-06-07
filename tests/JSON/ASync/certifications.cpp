//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "QTMDB.h"

TEST(Qtmdb_JSON_Certifications_Test, movie)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.certifications_movie();
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("certifications").toObject().value("GB").toArray()[0].toObject().value("certification").toString().toStdString().c_str(), "15");
}

TEST(Qtmdb_JSON_Certifications_Test, tv)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.certifications_tv();
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("certifications").toObject().value("GB").toArray()[0].toObject().value("certification").toString().toStdString().c_str(), "U");
}