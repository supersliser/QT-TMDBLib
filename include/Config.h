//
// Created by t on 26/05/25.
//

#ifndef CONFIG_H
#define CONFIG_H


#include <map>
#include <QJsonObject>
#include <QString>
#include <vector>



namespace tmdb::config
{
    struct LinkInfo {
        QString href;
        QString title;
    };
    std::vector<LinkInfo> extractLinksFromUrl(const QUrl& url);


    struct country
    {
        QString iso_3166_1;
        QString native_name;
        QString english_name;
    };
    std::vector<country> getSupportedCountries();
    country getCountry(const QString& country_code);
    country getCountry(const QJsonObject& i_json);
    struct jobDept
    {
        QString dept_name;
        std::vector<QString> job_titles;
    };
    std::vector<jobDept> getSupportedJobs();
    struct language
    {
        QString iso_639_1;
        QString english_name;
        QString native_name;
    };
    std::vector<language> getSupportedLanguages();
    language getLanguage(const QString& i_iso_639_1);
    std::vector<QString> getSupportedTranslations();
    std::vector<QString> getSupportedTimezones();

    QPixmap getPixmapFromUrl(const QUrl& url);
}


#endif //CONFIG_H
