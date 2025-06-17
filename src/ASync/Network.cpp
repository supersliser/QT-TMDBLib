//
// Created by t on 30/05/25.
//

#include "ASync/Network.h"

#include <QJsonObject>

#include "ASync/Country.h"
#include "ASync/QTMDB.h"

void tmdb::ASync::TV::Network::setHeadquarters(const QString& i_headquarters)
{
    m_headquarters = i_headquarters;
}

QString tmdb::ASync::TV::Network::headquarters() const
{
    return m_headquarters;
}

void tmdb::ASync::TV::Network::setHomepage(const QString& i_homepage)
{
    m_homepage = i_homepage;
}

QString tmdb::ASync::TV::Network::homepage() const
{
    return m_homepage;
}

void tmdb::ASync::TV::Network::setId(int i_id)
{
    m_id = i_id;
}

int tmdb::ASync::TV::Network::id() const
{
    return m_id;
}

void tmdb::ASync::TV::Network::setLogoPath(const QString& i_logoPath)
{
    m_logoPath = i_logoPath;
}

QString tmdb::ASync::TV::Network::logoPath() const
{
    return m_logoPath;
}

void tmdb::ASync::TV::Network::setName(const QString& i_name)
{
    m_name = i_name;
}

QString tmdb::ASync::TV::Network::name() const
{
    return m_name;
}

void tmdb::ASync::TV::Network::setOriginCountry(tmdb::ASync::Country* i_originCountry)
{
    m_originCountry = i_originCountry;
}

tmdb::ASync::Country* tmdb::ASync::TV::Network::originCountry() const
{
    return m_originCountry;
}

tmdb::ASync::TV::Network::Network() : m_q("")
{
    m_q.setParent(this);
}

tmdb::ASync::TV::Network::Network(const QString& i_access_token, int32_t i_networkID) : Network(i_access_token)
{
    loadNetwork(i_networkID);
}

tmdb::ASync::TV::Network::Network(const QString& i_access_token) : m_q(i_access_token.toStdString())
{
    m_q.setParent(this);
}

tmdb::ASync::TV::Network::Network(const QJsonObject& i_json, const QString& i_access_token) : Network(i_access_token)
{
    parseJson(i_json, i_access_token);
}

void tmdb::ASync::TV::Network::parseJson(const QJsonObject& i_json, const QString& i_access_token)
{
    setId(i_json["id"].toInt());
    setName(i_json["name"].toString());
    setLogoPath(i_json["logo_path"].toString());
    setHomepage(i_json["homepage"].toString());
    setHeadquarters(i_json["headquarters"].toString());
    if (!i_json.contains("origin_country") || i_json["origin_country"].toString().isEmpty())
    {
        return;
    }
    bool countrySet = false;
    auto temp = new Country(i_access_token);
    connect(temp, &tmdb::ASync::Country::finishedLoadingCountry, this, [this, &countrySet](tmdb::ASync::Country* i_country)
    {
        countrySet = true;
    });
    temp->loadCountry(i_json["origin_country"].toString());
    while (!countrySet)
    {
        QCoreApplication::processEvents();
    }
    setOriginCountry(new Country(i_access_token, i_json["origin_country"].toString()));
}

void tmdb::ASync::TV::Network::loadNetwork(int32_t i_networkID)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &tmdb::ASync::TV::Network::startedLoadingNetworkReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &tmdb::ASync::TV::Network::finishedLoadingNetworkReceived);
    m_q.network_details(i_networkID);
}

void tmdb::ASync::TV::Network::startedLoadingNetworkReceived()
{
    emit startedLoadingNetwork();
}

void tmdb::ASync::TV::Network::finishedLoadingNetworkReceived(void* i_data)
{
    parseJson(*static_cast<QJsonObject*>(i_data), m_q.accessToken().c_str());
    emit finishedLoadingNetwork(this);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &tmdb::ASync::TV::Network::startedLoadingNetworkReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &tmdb::ASync::TV::Network::finishedLoadingNetworkReceived);
}
