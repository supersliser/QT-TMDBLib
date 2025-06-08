//
// Created by t on 25/05/25.
//

#include "ASync/Account.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

#include "ASync/QTMDB.h"

void tmdb::ASync::Account::setAvatar(const tmdb::ASync::Avatar* i_avatar)
{
    m_avatar = *i_avatar;
}

tmdb::ASync::Avatar* tmdb::ASync::Account::avatar() const
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

tmdb::ASync::Account::Account(const QString& i_access_token, int32_t i_accountID) : m_q(new aQtmdb(i_access_token.toStdString()))
{
    connect(m_q, &aQtmdb::startedLoadingData, this, &tmdb::ASync::Account::startedLoadingAccountReceived);
    connect(m_q, &aQtmdb::finishedLoadingData, this, &tmdb::ASync::Account::finishedLoadingAccountReceived);
    m_q->setParent(this);
    loadAccount(i_accountID);
}

tmdb::ASync::Account* tmdb::ASync::Account::fromJSON(const QJsonObject& i_json)
{
    auto *output = new Account();
    output->setID(i_json.value("id").toInt());
    output->setISO6391(i_json.value("iso_639_1").toString());
    output->setISO31661(i_json.value("iso_3166_1").toString());
    output->setName(i_json.value("name").toString());
    output->setUsername(i_json.value("username").toString());
    output->setIncludeAdult(i_json.value("include_adult").toBool());
    output->setAvatar(new Avatar(
        Gravatar(i_json.value("avatar").toObject().value("gravatar").toObject().value("hash").toString()),
        Tmdb(i_json.value("avatar").toObject().value("tmdb").toObject().value("path").toString())));
    return output;
}

tmdb::ASync::Account tmdb::ASync::Account::getAccount(const QString& i_access_token, int32_t i_accountID)
{
    return Account(i_access_token, i_accountID);
}

void tmdb::ASync::Account::startedLoadingAccountReceived()
{
    emit startedLoadingAccount();
}

void tmdb::ASync::Account::finishedLoadingAccountReceived(void* i_data)
{
    auto var = static_cast<QJsonObject*>(i_data);
    emit finishedLoadingAccount(
        tmdb::ASync::Account::fromJSON(*var)
    );
}


void tmdb::ASync::Account::loadAccount(int32_t i_accountID)
{
    connect(m_q, &aQtmdb::startedLoadingData, this, &tmdb::ASync::Account::startedLoadingAccountReceived);
    connect(m_q, &aQtmdb::finishedLoadingData, this, &tmdb::ASync::Account::finishedLoadingAccountReceived);
    m_q->account_details(i_accountID);
}