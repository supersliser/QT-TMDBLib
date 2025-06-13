//
// Created by t on 09/06/25.
//

#include "ASync/Language.h"

#include <QJsonObject>

tmdb::ASync::Language::Language()
    : m_q("")
{
    m_q.setParent(this);
}

tmdb::ASync::Language::Language(const QString& i_access_token, const QString& i_iso_639_1)
    : m_q(i_access_token.toStdString())
{
    m_q.setParent(this);
    loadLanguage(i_iso_639_1);
}

void tmdb::ASync::Language::setIso6391(const QString& i_iso_639_1)
{
    m_iso_639_1 = i_iso_639_1;
}
QString tmdb::ASync::Language::iso6391() const
{
    return m_iso_639_1;
}

void tmdb::ASync::Language::setEnglishName(const QString& i_english_name)
{
    m_english_name = i_english_name;
}
QString tmdb::ASync::Language::englishName() const
{
    return m_english_name;
}

void tmdb::ASync::Language::setNativeName(const QString& i_native_name)
{
    m_native_name = i_native_name;
}
QString tmdb::ASync::Language::nativeName() const
{
    return m_native_name;
}

tmdb::ASync::Language* tmdb::ASync::Language::fromJSON(const QJsonObject& i_json)
{
    m_iso_639_1 = i_json["iso_639_1"].toString();
    m_english_name = i_json["english_name"].toString();
    m_native_name = i_json["native_name"].toString();
    return this;
}

void tmdb::ASync::Language::loadLanguage(const QString& i_iso_639_1)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &tmdb::ASync::Language::startedLoadingLanguageReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &tmdb::ASync::Language::finishedLoadingLanguageReceived);
    m_iso_639_1 = i_iso_639_1;
    m_q.config_languages();
}

void tmdb::ASync::Language::loadAllLanguages()
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &tmdb::ASync::Language::startedLoadingAllLanguagesReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &tmdb::ASync::Language::finishedLoadingAllLanguagesReceived);
    m_q.config_languages();
}

void tmdb::ASync::Language::startedLoadingLanguageReceived()
{
    emit startedLoadingLanguage();
}

void tmdb::ASync::Language::finishedLoadingLanguageReceived(void* i_data)
{
    QJsonArray json = *static_cast<QJsonArray*>(i_data);
    auto Language = new tmdb::ASync::Language();
    for (int i = 0; i < json.count(); i++)
    {
        if (json[i].toObject()["iso_639_1"].toString() == m_iso_639_1)
        {
            Language = fromJSON(json[i].toObject());
            break;
        }
    }
    emit finishedLoadingLanguage(Language);
}

void tmdb::ASync::Language::startedLoadingAllLanguagesReceived()
{
    emit startedLoadingAllLanguages();
}

void tmdb::ASync::Language::finishedLoadingAllLanguagesReceived(void* i_data)
{
    QJsonArray jsonArray = *static_cast<QJsonArray*>(i_data);
    std::vector<Language*> languages;
    for (const QJsonValue& value : jsonArray) {
        QJsonObject json = value.toObject();
        languages.push_back(fromJSON(json));
    }
    emit finishedLoadingAllLanguages(languages);
}