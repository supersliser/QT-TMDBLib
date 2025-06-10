//
// Created by t on 30/05/25.
//

#include "ASync/Network.h"

#include <QJsonObject>

#include "ASync/Country.h"
#include "ASync/QTMDB.h"

void tmdb::ASync::TV::Network::setHeadquarters(const QString &i_headquarters) {
    m_headquarters = i_headquarters;
}

QString tmdb::ASync::TV::Network::headquarters() const {
    return m_headquarters;
}

void tmdb::ASync::TV::Network::setHomepage(const QString &i_homepage) {
    m_homepage = i_homepage;
}

QString tmdb::ASync::TV::Network::homepage() const {
    return m_homepage;
}

void tmdb::ASync::TV::Network::setId(int i_id) {
    m_id = i_id;
}

int tmdb::ASync::TV::Network::id() const {
    return m_id;
}

void tmdb::ASync::TV::Network::setLogoPath(const QString &i_logoPath) {
    m_logoPath = i_logoPath;
}

QString tmdb::ASync::TV::Network::logoPath() const {
    return m_logoPath;
}

void tmdb::ASync::TV::Network::setName(const QString &i_name) {
    m_name = i_name;
}

QString tmdb::ASync::TV::Network::name() const {
    return m_name;
}

void tmdb::ASync::TV::Network::setOriginCountry( tmdb::ASync::Country *i_originCountry) {
    m_originCountry = i_originCountry;
}

tmdb::ASync::Country* tmdb::ASync::TV::Network::originCountry() const {
    return m_originCountry;
}

tmdb::ASync::TV::Network::Network() : m_q("")
{
    m_q.setParent(this);
}

tmdb::ASync::TV::Network::Network(const QString& i_access_token, int32_t i_networkID) : m_q(i_access_token.toStdString())
{
    m_q.setParent(this);
    loadNetwork(i_networkID);
}

tmdb::ASync::TV::Network* tmdb::ASync::TV::Network::fromJSON(const QJsonObject& i_json) {
    auto* network = new Network();
    network->setId(i_json["id"].toInt());
    network->setName(i_json["name"].toString());
    network->setLogoPath(i_json["logo_path"].toString());
    network->setHomepage(i_json["homepage"].toString());
    network->setHeadquarters(i_json["headquarters"].toString());

    if (i_json.contains("origin_country")) {
        auto* country = tmdb::ASync::Country::fromJSON(i_json["origin_country"].toObject());
        network->setOriginCountry(country);
    }

    return network;
}

void tmdb::ASync::TV::Network::loadNetwork(int32_t i_networkID) {
    connect(&m_q, &aQtmdb::startedLoadingData, this, &tmdb::ASync::TV::Network::startedLoadingNetworkReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &tmdb::ASync::TV::Network::finishedLoadingNetworkReceived);
    m_q.network_details(i_networkID);
}
void tmdb::ASync::TV::Network::startedLoadingNetworkReceived() {
    emit startedLoadingNetwork();
}
void tmdb::ASync::TV::Network::finishedLoadingNetworkReceived(void* i_data) {
    auto* network = static_cast<QJsonObject*>(i_data);
    emit finishedLoadingNetwork(fromJSON(*network));
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &tmdb::ASync::TV::Network::startedLoadingNetworkReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &tmdb::ASync::TV::Network::finishedLoadingNetworkReceived);
}