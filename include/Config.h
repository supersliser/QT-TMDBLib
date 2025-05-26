//
// Created by t on 26/05/25.
//

#ifndef CONFIG_H
#define CONFIG_H
#include <map>
#include <QString>
#include <vector>


namespace tmdb::config
{
    struct country
    {
        QString native_name;
        QString english_name;
        QString country_code;
    };
    std::vector<country> getSupportedCountries();
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
    std::vector<QString> getSupportedTranslations();
    std::vector<QString> getSupportedTimezones();
}


#endif //CONFIG_H
