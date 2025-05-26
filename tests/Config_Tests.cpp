//
// Created by t on 26/05/25.
//

#include "Config.h"
#include "QTMDB.h"
#include <gtest/gtest.h>

TEST(ConfigTests, SupportedCountries) {
    auto countries = tmdb::config::getSupportedCountries();
    ASSERT_FALSE(countries.empty());
    bool passed = false;
    for (const auto& country : countries) {
        if (country.english_name == "United Kingdom" && country.country_code == "GB") {
            passed = true;
            break;
        }
    }
    ASSERT_TRUE(passed);
}

TEST(ConfigTests, GetCountry) {
    auto country = tmdb::config::getCountry("GB");
    ASSERT_STREQ(country.english_name.toStdString().c_str(), "United Kingdom");
    ASSERT_STREQ(country.country_code.toStdString().c_str(), "GB");

    // Test with an invalid country code
    auto invalidCountry = tmdb::config::getCountry("XX");
    ASSERT_TRUE(invalidCountry.english_name.isEmpty());
    ASSERT_TRUE(invalidCountry.country_code.isEmpty());
}

TEST(ConfigTests, GetCountryFromJson) {
    QJsonObject countryJson;
    countryJson["native_name"] = "United Kingdom";
    countryJson["english_name"] = "United Kingdom";
    countryJson["iso_3166_1"] = "GB";

    auto country = tmdb::config::getCountry(countryJson);
    ASSERT_STREQ(country.english_name.toStdString().c_str(), "United Kingdom");
    ASSERT_STREQ(country.country_code.toStdString().c_str(), "GB");
}

TEST(ConfigTests, SupportedJobs) {
    auto jobs = tmdb::config::getSupportedJobs();
    ASSERT_FALSE(jobs.empty());
    bool passed = false;
    for (const auto& job : jobs) {
        if (job.dept_name == "Production" && std::find(job.job_titles.begin(), job.job_titles.end(), "Finance") != job.job_titles.end()) {
            passed = true;
            break;
        }
    }
    ASSERT_TRUE(passed);
}

TEST(ConfigTests, SupportedLanguages) {
    auto languages = tmdb::config::getSupportedLanguages();
    ASSERT_FALSE(languages.empty());
    bool passed = false;
    for (const auto& language : languages) {
        if (language.english_name == "English" && language.iso_639_1 == "en") {
            passed = true;
            break;
        }
    }
    ASSERT_TRUE(passed);
}

TEST(ConfigTests, getLanguage)
{
    auto language = tmdb::config::getLanguage("en");
    ASSERT_STREQ(language.english_name.toStdString().c_str(), "English");
    ASSERT_STREQ(language.iso_639_1.toStdString().c_str(), "en");

    // Test with an invalid language code
    auto invalidLanguage = tmdb::config::getLanguage("xx");
    ASSERT_STREQ(invalidLanguage.english_name.toStdString().c_str(), "No Language");
    ASSERT_STREQ(invalidLanguage.iso_639_1.toStdString().c_str(), "xx");
}

TEST(ConfigTests, SupportedTranslations) {
    auto translations = tmdb::config::getSupportedTranslations();
    ASSERT_FALSE(translations.empty());
    bool passed = false;
    for (const auto& translation : translations) {
        if (translation == "en-GB") {
            passed = true;
            break;
        }
    }
    ASSERT_TRUE(passed);
}

TEST(ConfigTests, SupportedTimezones) {
    auto timezones = tmdb::config::getSupportedTimezones();
    ASSERT_FALSE(timezones.empty());
    bool passed = false;
    for (const auto& timezone : timezones) {
        if (timezone == "Europe/London") {
            passed = true;
            break;
        }
    }
    ASSERT_TRUE(passed);
}