//
// Created by t on 26/05/25.
//

#include "Sync/Config.h"
#include "Sync/QTMDB.h"
#include <gtest/gtest.h>

TEST(ConfigSyncTests, SupportedCountries) {
    auto countries = tmdb::config::getSupportedCountries(std::getenv("API_KEY"));
    ASSERT_FALSE(countries.empty());
    bool passed = false;
    for (const auto& country : countries) {
        if (country.english_name == "United Kingdom" && country.iso_3166_1 == "GB") {
            passed = true;
            break;
        }
    }
    ASSERT_TRUE(passed);
}

TEST(ConfigSyncTests, GetCountry) {
    auto country = tmdb::config::getCountry("GB", std::getenv("API_KEY"));
    ASSERT_STREQ(country.english_name.toStdString().c_str(), "United Kingdom");
    ASSERT_STREQ(country.iso_3166_1.toStdString().c_str(), "GB");

    // Test with an invalid country code
    auto invalidCountry = tmdb::config::getCountry("XX", std::getenv("API_KEY"));
    ASSERT_TRUE(invalidCountry.english_name.isEmpty());
    ASSERT_TRUE(invalidCountry.iso_3166_1.isEmpty());
}

TEST(ConfigSyncTests, GetCountryFromJson) {
    QJsonObject countryJson;
    countryJson["native_name"] = "United Kingdom";
    countryJson["english_name"] = "United Kingdom";
    countryJson["iso_3166_1"] = "GB";

    auto country = tmdb::config::getCountry(countryJson);
    ASSERT_STREQ(country.english_name.toStdString().c_str(), "United Kingdom");
    ASSERT_STREQ(country.iso_3166_1.toStdString().c_str(), "GB");
}

TEST(ConfigSyncTests, SupportedJobs) {
    auto jobs = tmdb::config::getSupportedJobs(std::getenv("API_KEY"));
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

TEST(ConfigSyncTests, SupportedLanguages) {
    auto languages = tmdb::config::getSupportedLanguages(std::getenv("API_KEY"));
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

TEST(ConfigSyncTests, getLanguage)
{
    auto language = tmdb::config::getLanguage("en", std::getenv("API_KEY"));
    ASSERT_STREQ(language.english_name.toStdString().c_str(), "English");
    ASSERT_STREQ(language.iso_639_1.toStdString().c_str(), "en");

    // Test with an invalid language code
    auto invalidLanguage = tmdb::config::getLanguage("xx", std::getenv("API_KEY"));
    ASSERT_STREQ(invalidLanguage.english_name.toStdString().c_str(), "No Language");
    ASSERT_STREQ(invalidLanguage.iso_639_1.toStdString().c_str(), "xx");
}

TEST(ConfigSyncTests, SupportedTranslations) {
    auto translations = tmdb::config::getSupportedTranslations(std::getenv("API_KEY"));
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

TEST(ConfigSyncTests, SupportedTimezones) {
    auto timezones = tmdb::config::getSupportedTimezones(std::getenv("API_KEY"));
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