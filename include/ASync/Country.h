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
        [[nodiscard]] QString isoCountryCode() const;
        void setNativeName(const QString& i_nativeName);
        [[nodiscard]] QString nativeName() const;
        void setEnglishName(const QString& i_englishName);
        [[nodiscard]] QString englishName() const;

        Country();
        explicit Country(const QString& i_access_token);
        Country(const QString& i_access_token, const QString& i_iso_3166_1);
        ~Country() override = default;

        Country(const QJsonObject& i_json, const QString& i_access_token);

        static Country* US();
    protected:
        void parseJson(const QJsonObject& i_json, const QString& i_access_token);
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
        QString m_iso_3166_1 = "BLANK_ISO31661";
        QString m_native_name = "BLANK_NATIVE_NAME";
        QString m_english_name = "BLANK_ENGLISH_NAME";
        aQtmdb m_q;
    };
}

#endif //COUNTRY_H
