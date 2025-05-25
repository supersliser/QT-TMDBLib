//
// Created by t on 25/05/25.
//

#include "Company.h"

#include "QTMDB.h"

void Company::setDescription(const QString& i_description)
{
    m_description = i_description;
}

QString Company::description() const
{
    return m_description;
}

void Company::setHeadquarters(const QString& i_headquarters)
{
    m_headquarters = i_headquarters;
}

QString Company::headquarters() const
{
    return m_headquarters;
}

void Company::setHomepage(const QString& i_homepage)
{
    m_homepage = i_homepage;
}

QString Company::homepage() const
{
    return m_homepage;
}

void Company::setName(const QString& i_name)
{
    m_name = i_name;
}

QString Company::name() const
{
    return m_name;
}

void Company::setOriginCountry(const QString& i_originCountry)
{
    m_originCountry = i_originCountry;
}

QString Company::originCountry() const
{
    return m_originCountry;
}

void Company::setParentCompany(const QString& i_parentCompany)
{
    m_parentCompany = i_parentCompany;
}

QString Company::parentCompany() const
{
    return m_parentCompany;
}

void Company::setLogoPath(const QString& i_logoPath)
{
    m_logoPath = i_logoPath;
}

QString Company::logoPath() const
{
    return m_logoPath;
}

void Company::setID(int32_t i_id)
{
    m_id = i_id;
}

int32_t Company::id() const
{
    return m_id;
}

Company::Company(const QString& i_description, const QString& i_headquarters, const QString& i_homepage,
                 const QString& i_name, const QString& i_originCountry, const QString& i_parentCompany,
                 const QString& i_logoPath, int32_t i_id)
    : m_description(i_description), m_headquarters(i_headquarters), m_homepage(i_homepage),
      m_name(i_name), m_originCountry(i_originCountry), m_parentCompany(i_parentCompany),
      m_logoPath(i_logoPath), m_id(i_id) {}

Company::Company(const QString& i_access_token, int32_t i_companyID)
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

Company::Company(const QJsonObject& i_json)
    : m_description(i_json.value("description").toString()),
      m_headquarters(i_json.value("headquarters").toString()),
      m_homepage(i_json.value("homepage").toString()),
      m_name(i_json.value("name").toString()),
      m_originCountry(i_json.value("origin_country").toString()),
      m_parentCompany(i_json.value("parent_company").toObject().value("name").toString()),
      m_logoPath(i_json.value("logo_path").toString()),
      m_id(i_json.value("id").toInt()) {}

Company Company::getCompany(const QString& i_access_token, int32_t i_companyID)
{
    Qtmdb q(i_access_token.toStdString());
    QJsonObject response = q.company_details(i_companyID);
    if (!response.isEmpty()) {
        return Company(response);
    }
    return Company();
}