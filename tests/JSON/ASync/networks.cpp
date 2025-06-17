//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "ASync/QTMDB.h"

TEST(aQtmdb_JSON_Network_Test, details)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("name").toString().toStdString().c_str(), "HBO");
        finished = true;
    });
    aQtmdb.network_details(49);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Network_Test, alternativeNames)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("results").toArray()[0].toObject().value("name").toString().toStdString().c_str(),
                     "Home Box Office");
        finished = true;
    });
    aQtmdb.network_alternativeNames(49);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Network_Test, images)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("logos").toArray()[0].toObject().value("width").toInt(), 422);
        finished = true;
    });
    aQtmdb.network_images(49);
    while (!finished)
    {
        QApplication::processEvents();
    }
}