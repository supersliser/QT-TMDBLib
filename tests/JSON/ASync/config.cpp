//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "aQTMDB.h"

TEST(aQtmdb_JSON_Config_Test, details)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.config_details();
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("change_keys").toArray()[0].toString().toStdString().c_str(), "adult");
    });
}

TEST(aQtmdb_JSON_Config_Test, countries)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.config_countries("en-GB");
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonArray data = *static_cast<QJsonArray*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data[0].toObject().value("iso_3166_1").toString().toStdString().c_str(), "AD");
    });
}

TEST(aQtmdb_JSON_Config_Test, jobs)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.config_jobs();
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonArray data = *static_cast<QJsonArray*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data[0].toObject().value("jobs").toArray()[0].isString());
    });
}

TEST(aQtmdb_JSON_Config_Test, languages)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.config_languages();
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonArray data = *static_cast<QJsonArray*>(response);
        EXPECT_FALSE(data.isEmpty());
        QJsonObject temp;
        temp.insert("iso_639_1", "xx");
        temp.insert("english_name", "No Language");
        temp.insert("name", "No Language");
        EXPECT_TRUE(data.contains(temp));
    });
}

TEST(aQtmdb_JSON_Config_Test, primaryTranslations)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.config_primaryTranslations();
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonArray data = *static_cast<QJsonArray*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data[0].toString().toStdString().c_str(), "af-ZA");
    });
}

TEST(aQtmdb_JSON_Config_Test, timezones)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.config_timezones();
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonArray data = *static_cast<QJsonArray*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data[0].toObject().value("iso_3166_1").toString().toStdString().c_str(), "AD");
    });
}
