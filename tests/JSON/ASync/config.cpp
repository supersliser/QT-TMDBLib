//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "ASync/QTMDB.h"

TEST(aQtmdb_JSON_Config_Test, details)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb, &finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("change_keys").toArray()[0].toString().toStdString().c_str(), "adult");
        finished = true;
    });
    aQtmdb.config_details();
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Config_Test, countries)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb, &finished](void* response)
    {
        QJsonArray data = *static_cast<QJsonArray*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data[0].toObject().value("iso_3166_1").toString().toStdString().c_str(), "AD");
        finished = true;
    });
    aQtmdb.config_countries("en-GB");
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Config_Test, jobs)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonArray data = *static_cast<QJsonArray*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data[0].toObject().value("jobs").toArray()[0].isString());
        finished = true;
    });
    aQtmdb.config_jobs();
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Config_Test, languages)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonArray data = *static_cast<QJsonArray*>(response);
        EXPECT_FALSE(data.isEmpty());
        QJsonObject temp;
        temp.insert("iso_639_1", "xx");
        temp.insert("english_name", "No Language");
        temp.insert("name", "No Language");
        EXPECT_TRUE(data.contains(temp));
        finished = true;
    });
    aQtmdb.config_languages();
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Config_Test, primaryTranslations)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonArray data = *static_cast<QJsonArray*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data[0].toString().toStdString().c_str(), "af-ZA");
        finished = true;
    });
    aQtmdb.config_primaryTranslations();
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Config_Test, timezones)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonArray data = *static_cast<QJsonArray*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data[0].toObject().value("iso_3166_1").toString().toStdString().c_str(), "AD");
        finished = true;
    });
    aQtmdb.config_timezones();
    while (!finished)
    {
        QApplication::processEvents();
    }
}
