//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "QTMDB.h"

TEST(Qtmdb_JSON_Config_Test, details)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonObject response = qtmdb.config_details();
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("change_keys").toArray()[0].toString().toStdString().c_str(), "adult");
}

TEST(Qtmdb_JSON_Config_Test, countries)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonArray response = qtmdb.config_countries("en-GB");
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response[0].toObject().value("iso_3166_1").toString().toStdString().c_str(), "AD");
}

TEST(Qtmdb_JSON_Config_Test, jobs)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonArray response = qtmdb.config_jobs();
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response[0].toObject().value("jobs").toArray()[0].isString());
}

TEST(Qtmdb_JSON_Config_Test, languages)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonArray response = qtmdb.config_languages();
    EXPECT_FALSE(response.isEmpty());
    QJsonObject temp;
    temp.insert("iso_639_1", "xx");
    temp.insert("english_name", "No Language");
    temp.insert("name", "No Language");
    EXPECT_TRUE(response.contains(temp));
}

TEST(Qtmdb_JSON_Config_Test, primaryTranslations)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonArray response = qtmdb.config_primaryTranslations();
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response[0].toString().toStdString().c_str(), "af-ZA");
}

TEST(Qtmdb_JSON_Config_Test, timezones)
{
    Qtmdb qtmdb(std::getenv("API_KEY"));
    QJsonArray response = qtmdb.config_timezones();
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response[0].toObject().value("iso_3166_1").toString().toStdString().c_str(), "AD");
}