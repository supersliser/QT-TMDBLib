//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "ASync/QTMDB.h"

TEST(aQtmdb_JSON_Certifications_Test, movie)
{
    bool finished = false;
    aQtmdb qtmdb(std::getenv("API_KEY"));
    QObject::connect(&qtmdb, &aQtmdb::finishedLoadingData, [&qtmdb, &finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);

        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(
            data.value("certifications").toObject().value("GB").toArray()[0].toObject().value("certification").
            toString().toStdString().c_str(), "15");
        finished = true;
    });
    qtmdb.certifications_movie();
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Certifications_Test, tv)
{
    bool finished = false;
    aQtmdb qtmdb(std::getenv("API_KEY"));
    QObject::connect(&qtmdb, &aQtmdb::finishedLoadingData, [&qtmdb, &finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);

        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(
            data.value("certifications").toObject().value("GB").toArray()[0].toObject().value("certification").
            toString().toStdString().c_str(), "U");
        finished = true;
    });
    qtmdb.certifications_tv();
    while (!finished)
    {
        QApplication::processEvents();
    }
}
