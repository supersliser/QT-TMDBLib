//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "Async/QTMDB.h"

TEST(aQtmdb_JSON_Certifications_Test, movie)
{
    aQtmdb qtmdb(std::getenv("API_KEY"));
    qtmdb.certifications_movie();
    QObject::connect(&qtmdb, &aQtmdb::finishedLoadingData, [&qtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);

        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(
            data.value("certifications").toObject().value("GB").toArray()[0].toObject().value("certification").
            toString().toStdString().c_str(), "15");
    });
}

TEST(aQtmdb_JSON_Certifications_Test, tv)
{
    aQtmdb qtmdb(std::getenv("API_KEY"));
    qtmdb.certifications_tv();
    QObject::connect(&qtmdb, &aQtmdb::finishedLoadingData, [&qtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);

        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(
            data.value("certifications").toObject().value("GB").toArray()[0].toObject().value("certification").
            toString().toStdString().c_str(), "U");
    });
}
