//
// Created by t on 30/05/25.
//

#include "Sync/Network.h"

#include "Sync/QTMDB.h"

void tmdb::TV::Network::setHeadquarters(const QString &i_headquarters) {
    m_headquarters = i_headquarters;
}

QString tmdb::TV::Network::headquarters() const {
    return m_headquarters;
}

void tmdb::TV::Network::setHomepage(const QString &i_homepage) {
    m_homepage = i_homepage;
}

QString tmdb::TV::Network::homepage() const {
    return m_homepage;
}

void tmdb::TV::Network::setId(int i_id) {
    m_id = i_id;
}

int tmdb::TV::Network::id() const {
    return m_id;
}

void tmdb::TV::Network::setLogoPath(const QString &i_logoPath) {
    m_logoPath = i_logoPath;
}

QString tmdb::TV::Network::logoPath() const {
    return m_logoPath;
}

void tmdb::TV::Network::setName(const QString &i_name) {
    m_name = i_name;
}

QString tmdb::TV::Network::name() const {
    return m_name;
}

void tmdb::TV::Network::setOriginCountry(const tmdb::config::country &i_originCountry) {
    m_originCountry = i_originCountry;
}

tmdb::config::country tmdb::TV::Network::originCountry() const {
    return m_originCountry;
}

tmdb::TV::Network::Network(const QString &i_headquarters, const QString &i_homepage, int id,
                            const QString &i_logoPath, const QString &i_name,
                            const tmdb::config::country &i_originCountry)
    : m_headquarters(i_headquarters), m_homepage(i_homepage), m_id(id),
      m_logoPath(i_logoPath), m_name(i_name), m_originCountry(i_originCountry) {}

tmdb::TV::Network::Network(const QString& i_access_token, int32_t i_networkID)
{
    *this = getNetwork(i_access_token, i_networkID);
}

tmdb::TV::Network::Network(const QJsonObject &i_json, const QString& i_accessToken) {
    m_headquarters = i_json["headquarters"].toString();
    m_homepage = i_json["homepage"].toString();
    m_id = i_json["id"].toInt();
    m_logoPath = i_json["logo_path"].toString();
    m_name = i_json["name"].toString();
    m_originCountry = tmdb::config::getCountry(i_json["origin_country"].toString(), i_accessToken);
}

tmdb::TV::Network tmdb::TV::Network::getNetwork(const QString& i_access_token, int32_t i_networkID)
{
    Qtmdb q(i_access_token.toStdString());
    return Network(q.network_details(i_networkID), i_access_token);
}
