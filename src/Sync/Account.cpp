//
// Created by t on 25/05/25.
//

#include "Sync/Account.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

#include "Sync/QTMDB.h"

void tmdb::Account::setAvatar(const Avatar* i_avatar)
{
    m_avatar = *i_avatar;
}

tmdb::Avatar* tmdb::Account::avatar() const
{
    return const_cast<Avatar*>(&m_avatar);
}

void tmdb::Account::setID(const int i_id)
{
    m_id = i_id;
}

int tmdb::Account::id() const
{
    return m_id;
}

void tmdb::Account::setISO6391(const QString& i_iso_639_1)
{
    m_iso_639_1 = i_iso_639_1;
}

QString tmdb::Account::iso6391() const
{
    return m_iso_639_1;
}

void tmdb::Account::setISO31661(const QString& i_iso_3166_1)
{
    m_iso_3166_1 = i_iso_3166_1;
}

QString tmdb::Account::iso31661() const
{
    return m_iso_3166_1;
}

void tmdb::Account::setName(const QString& i_name)
{
    m_name = i_name;
}

QString tmdb::Account::name() const
{
    return m_name;
}

void tmdb::Account::setUsername(const QString& i_username)
{
    m_username = i_username;
}

QString tmdb::Account::username() const
{
    return m_username;
}

void tmdb::Account::setIncludeAdult(const bool i_include_adult)
{
    m_include_adult = i_include_adult;
}

bool tmdb::Account::includeAdult() const
{
    return m_include_adult;
}

tmdb::Account::Account(int i_id, const QString& i_iso_639_1, const QString& i_iso_3166_1, const QString& i_name,
                 const QString& i_username, bool i_include_adult)
    : m_id(i_id), m_iso_639_1(i_iso_639_1), m_iso_3166_1(i_iso_3166_1), m_name(i_name), m_username(i_username),
      m_include_adult(i_include_adult)
{
}

tmdb::Account::Account(const QString& i_access_token, int32_t i_accountID)
{
    Qtmdb tmdb(i_access_token.toStdString());
    QJsonObject response = tmdb.account_details(i_accountID);
    setID(response.value("id").toInt());
    setISO6391(response.value("iso_639_1").toString());
    setISO31661(response.value("iso_3166_1").toString());
    setName(response.value("name").toString());
    setUsername(response.value("username").toString());
    setIncludeAdult(response.value("include_adult").toBool());
    setAvatar(new Avatar(
        Gravatar(response.value("avatar").toObject().value("gravatar").toObject().value("hash").toString()),
        Tmdb(response.value("avatar").toObject().value("tmdb").toObject().value("path").toString())));
}

tmdb::Account::Account(const QJsonObject& i_json)
{
    setID(i_json.value("id").toInt());
    setISO6391(i_json.value("iso_639_1").toString());
    setISO31661(i_json.value("iso_3166_1").toString());
    setName(i_json.value("name").toString());
    setUsername(i_json.value("username").toString());
    setIncludeAdult(i_json.value("include_adult").toBool());
    setAvatar(new Avatar(
        Gravatar(i_json.value("avatar").toObject().value("gravatar").toObject().value("hash").toString()),
        Tmdb(i_json.value("avatar").toObject().value("tmdb").toObject().value("path").toString())));
}

tmdb::Account tmdb::Account::getAccount(const QString& i_access_token, int32_t i_accountID)
{
    return Account(i_access_token, i_accountID);
}