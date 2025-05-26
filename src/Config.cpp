//
// Created by t on 26/05/25.
//

#include "Config.h"

#include <QJsonArray>
#include <QJsonObject>

#include "QTMDB.h"

std::vector<tmdb::config::country> tmdb::config::getSupportedCountries()
{
    Qtmdb q("eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJmZWZjMDcwYTExNTZlZDExM2JjN2RhZDA1ZWM5OWMyOCIsIm5iZiI6MTc0Nzc2ODM5Mi44MDgsInN1YiI6IjY4MmNkNDQ4ODA2OTJiYWI1NTY0OTRiYyIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.4wbjpPC366q5YFsHnuo9g4bIQ2xgMB5hIHx84SejLMg");
    QJsonArray response = q.config_countries();
    std::vector<country> countries;
    for (const auto& item : response) {
        QJsonObject countryObj = item.toObject();
        country country;
        country.native_name = countryObj.value("native_name").toString();
        country.english_name = countryObj.value("english_name").toString();
        country.country_code = countryObj.value("iso_3166_1").toString();
        countries.push_back(country);
    }
    return countries;
}

std::vector<tmdb::config::jobDept> tmdb::config::getSupportedJobs()
{
    Qtmdb q("eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJmZWZjMDcwYTExNTZlZDExM2JjN2RhZDA1ZWM5OWMyOCIsIm5iZiI6MTc0Nzc2ODM5Mi44MDgsInN1YiI6IjY4MmNkNDQ4ODA2OTJiYWI1NTY0OTRiYyIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.4wbjpPC366q5YFsHnuo9g4bIQ2xgMB5hIHx84SejLMg");
    QJsonArray response = q.config_jobs();
    std::vector<tmdb::config::jobDept> jobs;
    for (const auto& item : response) {
        QJsonObject jobObj = item.toObject();
        tmdb::config::jobDept jobDept;
        jobDept.dept_name = jobObj.value("department").toString();
        QJsonArray jobTitlesArray = jobObj.value("jobs").toArray();
        for (const auto& title : jobTitlesArray) {
            jobDept.job_titles.push_back(title.toString());
        }
        jobs.push_back(jobDept);
    }
    return jobs;
}

std::vector<tmdb::config::language> tmdb::config::getSupportedLanguages()
{
    Qtmdb q("eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJmZWZjMDcwYTExNTZlZDExM2JjN2RhZDA1ZWM5OWMyOCIsIm5iZiI6MTc0Nzc2ODM5Mi44MDgsInN1YiI6IjY4MmNkNDQ4ODA2OTJiYWI1NTY0OTRiYyIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.4wbjpPC366q5YFsHnuo9g4bIQ2xgMB5hIHx84SejLMg");
    QJsonArray response = q.config_languages();
    std::vector<language> languages;
    for (const auto& item : response) {
        QJsonObject languageObj = item.toObject();
        language lang;
        lang.iso_639_1 = languageObj.value("iso_639_1").toString();
        lang.english_name = languageObj.value("english_name").toString();
        lang.native_name = languageObj.value("name").toString();
        languages.push_back(lang);
    }
    return languages;
}

std::vector<QString> tmdb::config::getSupportedTranslations()
{
    Qtmdb q("eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJmZWZjMDcwYTExNTZlZDExM2JjN2RhZDA1ZWM5OWMyOCIsIm5iZiI6MTc0Nzc2ODM5Mi44MDgsInN1YiI6IjY4MmNkNDQ4ODA2OTJiYWI1NTY0OTRiYyIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.4wbjpPC366q5YFsHnuo9g4bIQ2xgMB5hIHx84SejLMg");
    QJsonArray response = q.config_primaryTranslations();
    std::vector<QString> translations;
    for (const auto& item : response) {
        translations.push_back(item.toString());
    }
    return translations;
}

std::vector<QString> tmdb::config::getSupportedTimezones()
{
    Qtmdb q("eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJmZWZjMDcwYTExNTZlZDExM2JjN2RhZDA1ZWM5OWMyOCIsIm5iZiI6MTc0Nzc2ODM5Mi44MDgsInN1YiI6IjY4MmNkNDQ4ODA2OTJiYWI1NTY0OTRiYyIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.4wbjpPC366q5YFsHnuo9g4bIQ2xgMB5hIHx84SejLMg");
    QJsonArray response = q.config_timezones();
    std::vector<QString> timezones;
    for (const auto& item : response) {
        QJsonArray timezoneObj = item.toObject().value("zones").toArray();
        for (const auto& zone : timezoneObj) {
            bool contains = false;
            for (const auto& existing : timezones) {
                if (existing == zone.toString()) {
                    contains = true;
                    break;
                }
            }
            if (!contains) {
                timezones.push_back(zone.toString());
            }
        }
    }
    return timezones;
}