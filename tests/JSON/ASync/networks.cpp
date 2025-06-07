//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "aQTMDB.h"

TEST(aQtmdb_JSON_Network_Test, details)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.network_details(49);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("name").toString().toStdString().c_str(), "HBO");
    });
}

TEST(aQtmdb_JSON_Network_Test, alternativeNames)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.network_alternativeNames(49);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("results").toArray()[0].toObject().value("name").toString().toStdString().c_str(),
                     "Home Box Office");
    });
}

TEST(aQtmdb_JSON_Network_Test, images)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.network_images(49);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("logos").toArray()[0].toObject().value("width").toInt(), 422);
    });
}
