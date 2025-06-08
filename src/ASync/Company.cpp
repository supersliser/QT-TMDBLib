//
// Created by t on 25/05/25.
//

#include "ASync/Company.h"
#include "ASync/Account.h"
#include "Sync/QTMDB.h"

void tmdb::ASync::Company::setDescription(const QString& i_description)
{
    m_description = i_description;
}

QString tmdb::ASync::Company::description() const
{
    return m_description;
}

void tmdb::ASync::Company::setHeadquarters(const QString& i_headquarters)
{
    m_headquarters = i_headquarters;
}

QString tmdb::ASync::Company::headquarters() const
{
    return m_headquarters;
}

void tmdb::ASync::Company::setHomepage(const QString& i_homepage)
{
    m_homepage = i_homepage;
}

QString tmdb::ASync::Company::homepage() const
{
    return m_homepage;
}

void tmdb::ASync::Company::setName(const QString& i_name)
{
    m_name = i_name;
}

QString tmdb::ASync::Company::name() const
{
    return m_name;
}

void tmdb::ASync::Company::setOriginCountry(const config::country& i_originCountry)
{
    m_originCountry = i_originCountry;
}

tmdb::config::country tmdb::ASync::Company::originCountry() const
{
    return m_originCountry;
}

void tmdb::ASync::Company::setParentCompany(const QString& i_parentCompany)
{
    m_parentCompany = i_parentCompany;
}

QString tmdb::ASync::Company::parentCompany() const
{
    return m_parentCompany;
}

void tmdb::ASync::Company::setLogoPath(const QString& i_logoPath)
{
    m_logoPath = i_logoPath;
}

QString tmdb::ASync::Company::logoPath() const
{
    return m_logoPath;
}

void tmdb::ASync::Company::setID(int32_t i_id)
{
    m_id = i_id;
}

int32_t tmdb::ASync::Company::id() const
{
    return m_id;
}

tmdb::ASync::Company::Company(const QString& i_access_token, int32_t i_companyID) : m_q(i_access_token.toStdString())
{
    loadCompany(i_companyID);
}

tmdb::ASync::Company* tmdb::ASync::Company::fromJSON(const QJsonObject& i_json, const QString& i_access_token)
{
    auto* output = new Company();
    output->setDescription(i_json.value("description").toString());
    output->setHeadquarters(i_json.value("headquarters").toString());
    output->setHomepage(i_json.value("homepage").toString());
    output->setName(i_json.value("name").toString());
    output->setOriginCountry(config::getCountry(i_json.value("origin_country").toString(), ""));
    output->setParentCompany(i_json.value("parent_company").toObject().value("name").toString());
    output->setLogoPath(i_json.value("logo_path").toString());
    output->setID(i_json.value("id").toInt());
    return output;
}

void tmdb::ASync::Company::loadCompany(int32_t i_companyID)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &tmdb::ASync::Company::startedLoadingCompanyReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &tmdb::ASync::Company::finishedLoadingCompanyReceived);
    m_q.company_details(i_companyID);
}

void tmdb::ASync::Company::startedLoadingCompanyReceived()
{
    emit startedLoadingCompany();
}

void tmdb::ASync::Company::finishedLoadingCompanyReceived(void* i_data)
{
    auto var = static_cast<QJsonObject*>(i_data);
    emit finishedLoadingCompany(tmdb::ASync::Company::fromJSON(*var, QString(m_q.accessToken().c_str())));
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &tmdb::ASync::Company::startedLoadingCompanyReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &tmdb::ASync::Company::finishedLoadingCompanyReceived);
}

tmdb::ASync::Company::Company() : m_q("")
{
    m_q.setParent(this);
}