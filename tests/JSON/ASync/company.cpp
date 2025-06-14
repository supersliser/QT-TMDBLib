//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "ASync/QTMDB.h"

TEST(aQtmdb_JSON_Company_Test, details)
{
    bool finished = false;
    aQtmdb aqtmdb(std::getenv("API_KEY"));
    QObject::connect(&aqtmdb, &aQtmdb::finishedLoadingData, [&aqtmdb, &finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("name").toString().toStdString().c_str(), "Lucasfilm Ltd.");
        finished = true;
    });
    aqtmdb.company_details(1);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Company_Test, images)
{
    bool finished = false;
    aQtmdb aqtmdb(std::getenv("API_KEY"));
    QObject::connect(&aqtmdb, &aQtmdb::finishedLoadingData, [&aqtmdb, &finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("logos").toArray()[0].toObject().value("width").toInt(), 1000);
        finished = true;
    });
    aqtmdb.company_images(1);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Company_Test, alternativeNames)
{
    bool finished = false;
    aQtmdb aqtmdb(std::getenv("API_KEY"));
    QObject::connect(&aqtmdb, &aQtmdb::finishedLoadingData, [&aqtmdb, &finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("results").toArray()[1].toObject()["name"].toString().toStdString().c_str(),
                     "Lucasfilm Ltd. LLC");
        finished = true;
    });
    aqtmdb.company_alternativeNames(1);
    while (!finished)
    {
        QApplication::processEvents();
    }
}
