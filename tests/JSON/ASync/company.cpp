//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "aQTMDB.h"

TEST(aQtmdb_JSON_Company_Test, details)
{
    aQtmdb aqtmdb(std::getenv("API_KEY"));
    aqtmdb.company_details(1);
    QObject::connect(&aqtmdb, &aQtmdb::finishedLoadingData, [&aqtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("name").toString().toStdString().c_str(), "Lucasfilm Ltd.");
    });
}

TEST(aQtmdb_JSON_Company_Test, images)
{
    aQtmdb aqtmdb(std::getenv("API_KEY"));
    aqtmdb.company_images(1);
    QObject::connect(&aqtmdb, &aQtmdb::finishedLoadingData, [&aqtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("logos").toArray()[0].toObject().value("width").toInt(), 1000);
    });
}

TEST(aQtmdb_JSON_Company_Test, alternativeNames)
{
    aQtmdb aqtmdb(std::getenv("API_KEY"));
    aqtmdb.company_alternativeNames(1);
    QObject::connect(&aqtmdb, &aQtmdb::finishedLoadingData, [&aqtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("results").toArray()[1].toObject()["name"].toString().toStdString().c_str(),
                     "Lucasfilm Ltd. LLC");
    });
}
