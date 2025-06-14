//
// Created by t on 25/05/25.
//

#include "ASync/Account.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

#include "ASync/QTMDB.h"


void tmdb::ASync::Account::setAvatar(const tmdb::Avatar* i_avatar)
{
    m_avatar = *i_avatar;
}

tmdb::Avatar* tmdb::ASync::Account::avatar() const
{
    return const_cast<Avatar*>(&m_avatar);
}

void tmdb::ASync::Account::setID(const int i_id)
{
    m_id = i_id;
}

int tmdb::ASync::Account::id() const
{
    return m_id;
}

void tmdb::ASync::Account::setISO6391(const QString& i_iso_639_1)
{
    m_iso_639_1 = i_iso_639_1;
}

QString tmdb::ASync::Account::iso6391() const
{
    return m_iso_639_1;
}

void tmdb::ASync::Account::setISO31661(const QString& i_iso_3166_1)
{
    m_iso_3166_1 = i_iso_3166_1;
}

QString tmdb::ASync::Account::iso31661() const
{
    return m_iso_3166_1;
}

void tmdb::ASync::Account::setName(const QString& i_name)
{
    m_name = i_name;
}

QString tmdb::ASync::Account::name() const
{
    return m_name;
}

void tmdb::ASync::Account::setUsername(const QString& i_username)
{
    m_username = i_username;
}

QString tmdb::ASync::Account::username() const
{
    return m_username;
}

void tmdb::ASync::Account::setIncludeAdult(const bool i_include_adult)
{
    m_include_adult = i_include_adult;
}

bool tmdb::ASync::Account::includeAdult() const
{
    return m_include_adult;
}

tmdb::ASync::Account::Account() : m_q("")
{
    m_q.setParent(this);
}

tmdb::ASync::Account::Account(const QString& i_access_token, int32_t i_accountID) : Account(i_access_token)
{
    loadAccount(i_accountID);
}

tmdb::ASync::Account::Account(const QString& i_access_token) : m_q(i_access_token.toStdString())
{
    m_q.setParent(this);
}


tmdb::ASync::Account::Account(const QJsonObject& i_json, const QString& i_access_token) : Account(i_access_token)
{
    parseJson(i_json, i_access_token);
}

void tmdb::ASync::Account::startedLoadingAccountReceived()
{
    emit startedLoadingAccount();
}

void tmdb::ASync::Account::parseJson(const QJsonObject& i_json, const QString& i_access_token)
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


void tmdb::ASync::Account::finishedLoadingAccountReceived(void* i_data)
{
    auto var = static_cast<QJsonObject*>(i_data);
    parseJson(*var, m_q.accessToken().c_str());
    emit finishedLoadingAccount(
        this
    );

    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &tmdb::ASync::Account::startedLoadingAccountReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &tmdb::ASync::Account::finishedLoadingAccountReceived);
}

void tmdb::ASync::Account::loadAccount(int32_t i_accountID)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &tmdb::ASync::Account::startedLoadingAccountReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &tmdb::ASync::Account::finishedLoadingAccountReceived);
    m_q.account_details(i_accountID);
}