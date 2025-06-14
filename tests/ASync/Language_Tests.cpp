//
// Created by t on 14/06/25.
//
#include <QApplication>

#include "ASync/Language.h"
#include <QJsonObject>
#include <gtest/gtest.h>

#include "ASync/QTMDB.h"
using namespace tmdb::ASync;

TEST(LanguageASyncTests, DefaultConstructor)
{
    Language language;
    EXPECT_STREQ(language.iso6391().toStdString().c_str(), QString().toStdString().c_str());
    EXPECT_STREQ(language.englishName().toStdString().c_str(), QString().toStdString().c_str());
    EXPECT_STREQ(language.nativeName().toStdString().c_str(), QString().toStdString().c_str());
}

TEST(LanguageASyncTests, APIGetter)
{
    bool f = false;
    Language* l = new Language(std::getenv("API_KEY"));
    QObject::connect(l, &Language::finishedLoadingLanguage, [&f](Language* language) {
        EXPECT_STREQ(language->iso6391().toStdString().c_str(), "en");
        EXPECT_STREQ(language->englishName().toStdString().c_str(), "English");
        EXPECT_STREQ(language->nativeName().toStdString().c_str(), "English");
        f = true;
    });
    l->loadLanguage("en");
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(LanguageASyncTests, APIJSON)
{
    bool f = false;
    aQtmdb q(std::getenv("API_KEY"));
    QObject::connect(&q, &aQtmdb::finishedLoadingData, [&f](void* response) {
        QJsonArray data = *static_cast<QJsonArray*>(response);
        EXPECT_FALSE(data.isEmpty());
        for (const auto& item : data)
        {
            if (item.toObject()["iso_639_1"] == "en")
            {
                EXPECT_STREQ(item.toObject()["iso_639_1"].toString().toStdString().c_str(), "en");
                EXPECT_STREQ(item.toObject()["english_name"].toString().toStdString().c_str(), "English");
                EXPECT_STREQ(item.toObject()["name"].toString().toStdString().c_str(), "English");
            }
        }
        f = true;
    });
    q.config_languages();
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(LanguageASyncTests, APIAllLanguages)
{
    bool f = false;
    Language* l = new Language(std::getenv("API_KEY"));
    QObject::connect(l, &Language::finishedLoadingAllLanguages, [&f](std::vector<Language*> languages) {
        EXPECT_FALSE(languages.empty());
        for (const auto& language : languages)
        {
            EXPECT_FALSE(language->iso6391().isEmpty());
            EXPECT_FALSE(language->englishName().isEmpty());
            EXPECT_FALSE(language->nativeName().isEmpty());
        }
        f = true;
    });
    l->loadAllLanguages();
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(LanguageASyncTests, setGetters)
{
    Language l;
    l.setIso6391("fr");
    l.setEnglishName("French");
    l.setNativeName("Français");

    EXPECT_STREQ(l.iso6391().toStdString().c_str(), "fr");
    EXPECT_STREQ(l.englishName().toStdString().c_str(), "French");
    EXPECT_STREQ(l.nativeName().toStdString().c_str(), "Français");
}