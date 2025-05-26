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