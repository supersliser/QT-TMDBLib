//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "QTMDB.h"

TEST(Qtmdb_JSON_Reviews_Test, details)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.reviews_details("640b2aeecaaca20079decdcc");
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("author").toString().toStdString().c_str(), "Ricardo Oliveira");
}