//
// Created by t on 25/05/25.
//

#ifndef ASYNC_COMPANY_H
#define ASYNC_COMPANY_H
#include <QJsonObject>
#include <QString>

#include "Country.h"
#include "QTMDB.h"
#include "Sync/Config.h"

namespace tmdb::ASync
{
    class Company : public QObject
    {
        Q_OBJECT

    public:
        void setDescription(const QString& i_description);
        [[nodiscard]] QString description() const;
        void setHeadquarters(const QString& i_headquarters);
        [[nodiscard]] QString headquarters() const;
        void setHomepage(const QString& i_homepage);
        [[nodiscard]] QString homepage() const;
        void setName(const QString& i_name);
        [[nodiscard]] QString name() const;
        void setOriginCountry(Country* i_originCountry);
        [[nodiscard]] Country* originCountry() const;
        void setParentCompany(const QString& i_parentCompany);
        [[nodiscard]] QString parentCompany() const;
        void setLogoPath(const QString& i_logoPath);
        [[nodiscard]] QString logoPath() const;
        void setID(int32_t i_id);
        [[nodiscard]] int32_t id() const;

        Company();
        explicit Company(const QString& i_access_token);
        Company(const QString& i_access_token, int32_t i_companyID);
        ~Company() override = default;

        Company(const QJsonObject& i_json, const QString& i_access_token);
    protected:
        void parseJson(const QJsonObject& i_json, const QString& i_access_token);
    public slots:
        void loadCompany(int32_t i_companyID);

    private slots:
        void startedLoadingCompanyReceived();
        void finishedLoadingCompanyReceived(void* i_data);

    signals:
        void startedLoadingCompany();
        void finishedLoadingCompany(tmdb::ASync::Company* i_company);

    protected:
        aQtmdb m_q;
        QString m_description = "BLANK_DESCRIPTION";
        QString m_headquarters = "BLANK_HEADQUARTERS";
        QString m_homepage = "BLANK_HOMEPAGE";
        QString m_name = "BLANK_NAME";
        Country* m_originCountry = Country::US();
        QString m_parentCompany = "BLANK_PARENT_COMPANY";
        QString m_logoPath = "BLANK_LOGO_PATH";
        int32_t m_id = 0;
    };
}

#endif //COMPANY_H
