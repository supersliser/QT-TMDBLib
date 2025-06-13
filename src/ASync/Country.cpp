//
// Created by t on 08/06/25.
//

#include "ASync/Country.h"
#include <QJsonObject>

tmdb::ASync::Country::Country() : m_q("")
{
    m_q.setParent(this);
}

tmdb::ASync::Country::Country(const QString& i_access_token, const QString& i_iso_3166_1): m_q(i_access_token.toStdString())
{
    loadCountry(i_iso_3166_1);
}

tmdb::ASync::Country* tmdb::ASync::Country::fromJSON(const QJsonObject& i_json)
{
    auto country = new Country();
    country->m_iso_3166_1 = i_json.value("iso_3166_1").toString();
    country->m_native_name = i_json.value("native_name").toString();
    country->m_english_name = i_json.value("english_name").toString();
    return country;
}

void tmdb::ASync::Country::setISOCountryCode(const QString& i_isoCountryCode)
{
    m_iso_3166_1 = i_isoCountryCode;
}
QString tmdb::ASync::Country::isoCountryCode() const
{
    return m_iso_3166_1;
}

void tmdb::ASync::Country::setNativeName(const QString& i_nativeName)
{
    m_native_name = i_nativeName;
}
QString tmdb::ASync::Country::nativeName() const
{
    return m_native_name;
}

void tmdb::ASync::Country::setEnglishName(const QString& i_englishName)
{
    m_english_name = i_englishName;
}
QString tmdb::ASync::Country::englishName() const
{
    return m_english_name;
}

void tmdb::ASync::Country::loadCountry(const QString& i_iso_3166_1)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Country::startedLoadingCountryReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Country::finishedLoadingCountryReceived);
    m_iso_3166_1 = i_iso_3166_1;
    m_q.config_countries();
}

void tmdb::ASync::Country::startedLoadingCountryReceived()
{
    emit startedLoadingCountry();
}

void tmdb::ASync::Country::finishedLoadingCountryReceived(void* i_data)
{
    QJsonArray json = *static_cast<QJsonArray*>(i_data);
    auto country = new Country();
    for (int i = 0; i < json.size(); i++)
    {
        if (json[i].toObject().value("iso_3166_1").toString() == m_iso_3166_1) {
            country = fromJSON(json[i].toObject());
            break;
        }
    }
    emit finishedLoadingCountry(country);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Country::startedLoadingCountryReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Country::finishedLoadingCountryReceived);
}

void tmdb::ASync::Country::loadAllCountries()
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Country::startedLoadingAllCountriesReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Country::finishedLoadingAllCountriesReceived);
    m_q.config_countries();
}

void tmdb::ASync::Country::startedLoadingAllCountriesReceived()
{
    emit startedLoadingAllCountries();
}

void tmdb::ASync::Country::finishedLoadingAllCountriesReceived(void* i_data)
{
    auto jsonArray = static_cast<QJsonArray*>(i_data);
    std::vector<Country*> countries;
    for (const auto& item : *jsonArray) {
        countries.push_back(fromJSON(item.toObject()));
    }
    emit finishedLoadingAllCountries(countries);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Country::startedLoadingAllCountriesReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Country::finishedLoadingAllCountriesReceived);
}