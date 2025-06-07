//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "aQTMDB.h"

TEST(aQtmdb_JSON_Collection_Test, details)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.collection_details(10);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("name").toString().toStdString().c_str(), "Star Wars Collection");
    });
}

TEST(aQtmdb_JSON_Collection_Test, images)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.collection_images(10);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("backdrops").toArray()[0].toObject().value("width").toInt(), 1920);
    });
}

TEST(aQtmdb_JSON_Collection_Test, translations)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.collection_translations(10);
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("translations").toArray()[0].toObject().value("iso_639_1").isString());
    });
}
