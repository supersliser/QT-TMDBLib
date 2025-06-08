//
// Created by t on 25/05/25.
//

#ifndef ASYNC_COMPANY_H
#define ASYNC_COMPANY_H
#include <QJsonObject>
#include <QString>

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
        void setOriginCountry(const config::country& i_originCountry);
        [[nodiscard]] config::country originCountry() const;
        void setParentCompany(const QString& i_parentCompany);
        [[nodiscard]] QString parentCompany() const;
        void setLogoPath(const QString& i_logoPath);
        [[nodiscard]] QString logoPath() const;
        void setID(int32_t i_id);
        [[nodiscard]] int32_t id() const;

        Company();
        Company(const QString& i_access_token, int32_t i_companyID);
        ~Company() override = default;

        static Company* fromJSON(const QJsonObject& i_json, const QString& i_access_token);

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
        QString m_description;
        QString m_headquarters;
        QString m_homepage;
        QString m_name;
        config::country m_originCountry;
        QString m_parentCompany;
        QString m_logoPath;
        int32_t m_id = 0;
    };
}

#endif //COMPANY_H
