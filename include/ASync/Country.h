//
// Created by t on 08/06/25.
//

#ifndef COUNTRY_H
#define COUNTRY_H
#include <QObject>

#include "QTMDB.h"

namespace tmdb::ASync
{
    class Country : public QObject
    {
        Q_OBJECT

    public:
        void setISOCountryCode(const QString& i_isoCountryCode);
        QString isoCountryCode() const;
        void setNativeName(const QString& i_nativeName);
        QString nativeName() const;
        void setEnglishName(const QString& i_englishName);
        QString englishName() const;

        Country();
        Country(const QString& i_access_token, const QString& i_iso_3166_1);
        ~Country() override = default;

        static Country* fromJSON(const QJsonObject& i_json);

    public slots:
        void loadCountry(const QString& i_iso_3166_1);
        void loadAllCountries();

    private slots:
        void startedLoadingCountryReceived();
        void finishedLoadingCountryReceived(void* i_data);

        void startedLoadingAllCountriesReceived();
        void finishedLoadingAllCountriesReceived(void* i_data);

    signals:
        void startedLoadingCountry();
        void finishedLoadingCountry(tmdb::ASync::Country* i_country);

        void startedLoadingAllCountries();
        void finishedLoadingAllCountries(const std::vector<tmdb::ASync::Country*>& i_countries);

    protected:
        QString m_iso_3166_1;
        QString m_native_name;
        QString m_english_name;
        aQtmdb m_q;
    };
}

#endif //COUNTRY_H
