//
// Created by t on 25/05/25.
//

#ifndef COMPANY_H
#define COMPANY_H
#include <QJsonObject>
#include <QString>

class Company
{
public:
    void setDescription(const QString &i_description);
    QString description() const;
    void setHeadquarters(const QString &i_headquarters);
    QString headquarters() const;
    void setHomepage(const QString &i_homepage);
    QString homepage() const;
    void setName(const QString &i_name);
    QString name() const;
    void setOriginCountry(const QString &i_originCountry);
    QString originCountry() const;
    void setParentCompany(const QString &i_parentCompany);
    QString parentCompany() const;
    void setLogoPath(const QString &i_logoPath);
    QString logoPath() const;
    void setID(int32_t i_id);
    int32_t id() const;

    Company() = default;
    Company(const QString &i_description, const QString &i_headquarters, const QString &i_homepage,
            const QString &i_name, const QString &i_originCountry, const QString &i_parentCompany,
            const QString &i_logoPath, int32_t i_id);
    Company(const QString& i_access_token, int32_t i_companyID);
    explicit Company(const QJsonObject &i_json);

    static Company getCompany(const QString& i_access_token, int32_t i_companyID);

protected:
    QString m_description;
    QString m_headquarters;
    QString m_homepage;
    QString m_name;
    QString m_originCountry;
    QString m_parentCompany;
    QString m_logoPath;
    int32_t m_id = 0;
};

#endif //COMPANY_H
