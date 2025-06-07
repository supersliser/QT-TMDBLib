//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "QTMDB.h"

TEST(Qtmdb_JSON_Credits_Test, details)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.credits_details("6024a814c0ae36003d59cc3c");
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("job").toString().toStdString().c_str(), "Actor");
}