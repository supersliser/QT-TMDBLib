//
// Created by t on 26/05/25.
//

#include "ASync/Config.h"
#include "ASync/QTMDB.h"
#include <gtest/gtest.h>

using namespace tmdb::ASync::config;

TEST(ConfigASyncTests, SupportedTranslations) {
    auto translations = getSupportedTranslations(std::getenv("API_KEY"));
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

TEST(ConfigASyncTests, SupportedTimezones) {
    auto timezones = getSupportedTimezones(std::getenv("API_KEY"));
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