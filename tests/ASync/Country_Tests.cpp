//
// Created by t on 13/06/25.
//

#include <QApplication>
#include <QJsonObject>

#include "ASync/Country.h"
#include "ASync/QTMDB.h"
#include <gtest/gtest.h>

using namespace tmdb::ASync;

TEST(CountryASyncTests, DefaultConstructor)
{
    Country country;
    EXPECT_STREQ(country.isoCountryCode().toStdString().c_str(), QString().toStdString().c_str());
    EXPECT_STREQ(country.englishName().toStdString().c_str(), QString().toStdString().c_str());
    EXPECT_STREQ(country.nativeName().toStdString().c_str(), QString().toStdString().c_str());
}

TEST(CountryASyncTests, APIGetter)
{
    bool f = false;
    Country *country = new Country(std::getenv("API_KEY"));
    QObject::connect(country, &Country::finishedLoadingCountry, [&f](Country* c) {
        EXPECT_STREQ(c->isoCountryCode().toStdString().c_str(), "GB");
        EXPECT_STREQ(c->englishName().toStdString().c_str(), "United Kingdom");
        EXPECT_STREQ(c->nativeName().toStdString().c_str(), "United Kingdom");
        f = true;
    });
    country->loadCountry("GB");
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(CountryASyncTests, APIAllGetter)
{
    bool f = false;
    Country *country = new Country(std::getenv("API_KEY"));
    QObject::connect(country, &Country::finishedLoadingAllCountries, [&f](std::vector<Country*> cs) {
        for (const auto& c : cs)
        {
            EXPECT_FALSE(c->isoCountryCode().isEmpty());
            EXPECT_FALSE(c->englishName().isEmpty());
            EXPECT_FALSE(c->nativeName().isEmpty());
        }
        f = true;
    });
    country->loadAllCountries();
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(CountryASyncTests, APIJSON)
{
    bool f = false;
    aQtmdb q(std::getenv("API_KEY"));
    QObject::connect(&q, &aQtmdb::finishedLoadingData, [&f](void* response) {
        QJsonArray data = *static_cast<QJsonArray*>(response);
        EXPECT_FALSE(data.isEmpty());
        QJsonObject testData;
        for (const QJsonValue& value : data) {
            QJsonObject obj = value.toObject();
            EXPECT_TRUE(obj.contains("iso_3166_1"));
            EXPECT_TRUE(obj.contains("english_name"));
            EXPECT_TRUE(obj.contains("native_name"));
            if (obj["iso_3166_1"].toString() == "GB") {
                testData = obj;
            }
        }
        Country* c = new Country(testData, std::getenv("API_KEY"));
        EXPECT_STREQ(c->isoCountryCode().toStdString().c_str(), "GB");
        EXPECT_STREQ(c->englishName().toStdString().c_str(), "United Kingdom");
        EXPECT_STREQ(c->nativeName().toStdString().c_str(), "United Kingdom");
        f = true;
    });
    q.config_countries();
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(CountryASyncTests, setGetters)
{
    Country country;
    country.setISOCountryCode("FR");
    country.setEnglishName("France");
    country.setNativeName("France");

    EXPECT_STREQ(country.isoCountryCode().toStdString().c_str(), "FR");
    EXPECT_STREQ(country.englishName().toStdString().c_str(), "France");
    EXPECT_STREQ(country.nativeName().toStdString().c_str(), "France");
}