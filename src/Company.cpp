//
// Created by t on 25/05/25.
//

#include "Sync/Company.h"

#include "Sync/QTMDB.h"

void tmdb::Company::setDescription(const QString& i_description)
{
    m_description = i_description;
}

QString tmdb::Company::description() const
{
    return m_description;
}

void tmdb::Company::setHeadquarters(const QString& i_headquarters)
{
    m_headquarters = i_headquarters;
}

QString tmdb::Company::headquarters() const
{
    return m_headquarters;
}

void tmdb::Company::setHomepage(const QString& i_homepage)
{
    m_homepage = i_homepage;
}

QString tmdb::Company::homepage() const
{
    return m_homepage;
}

void tmdb::Company::setName(const QString& i_name)
{
    m_name = i_name;
}

QString tmdb::Company::name() const
{
    return m_name;
}

void tmdb::Company::setOriginCountry(const QString& i_originCountry)
{
    m_originCountry = i_originCountry;
}

QString tmdb::Company::originCountry() const
{
    return m_originCountry;
}

void tmdb::Company::setParentCompany(const QString& i_parentCompany)
{
    m_parentCompany = i_parentCompany;
}

QString tmdb::Company::parentCompany() const
{
    return m_parentCompany;
}

void tmdb::Company::setLogoPath(const QString& i_logoPath)
{
    m_logoPath = i_logoPath;
}

QString tmdb::Company::logoPath() const
{
    return m_logoPath;
}

void tmdb::Company::setID(int32_t i_id)
{
    m_id = i_id;
}

int32_t tmdb::Company::id() const
{
    return m_id;
}

tmdb::Company::Company(const QString& i_description, const QString& i_headquarters, const QString& i_homepage,
                 const QString& i_name, const QString& i_originCountry, const QString& i_parentCompany,
                 const QString& i_logoPath, int32_t i_id)
    : m_description(i_description), m_headquarters(i_headquarters), m_homepage(i_homepage),
      m_name(i_name), m_originCountry(i_originCountry), m_parentCompany(i_parentCompany),
      m_logoPath(i_logoPath), m_id(i_id) {}

tmdb::Company::Company(const QString& i_access_token, int32_t i_companyID)
{
    Qtmdb q(i_access_token.toStdString());
    QJsonObject response = q.company_details(i_companyID);
    if (!response.isEmpty()) {
        setDescription(response.value("description").toString());
        setHeadquarters(response.value("headquarters").toString());
        setHomepage(response.value("homepage").toString());
        setName(response.value("name").toString());
        setOriginCountry(response.value("origin_country").toString());
        setParentCompany(response.value("parent_company").toObject().value("name").toString());
        setLogoPath(response.value("logo_path").toString());
        setID(response.value("id").toInt());
    }
}

tmdb::Company::Company(const QJsonObject& i_json)
    : m_description(i_json.value("description").toString()),
      m_headquarters(i_json.value("headquarters").toString()),
      m_homepage(i_json.value("homepage").toString()),
      m_name(i_json.value("name").toString()),
      m_originCountry(i_json.value("origin_country").toString()),
      m_parentCompany(i_json.value("parent_company").toObject().value("name").toString()),
      m_logoPath(i_json.value("logo_path").toString()),
      m_id(i_json.value("id").toInt()) {}

tmdb::Company tmdb::Company::getCompany(const QString& i_access_token, int32_t i_companyID)
{
    Qtmdb q(i_access_token.toStdString());
    QJsonObject response = q.company_details(i_companyID);
    if (!response.isEmpty()) {
        return Company(response);
    }
    return Company();
}