//
// Created by t on 21/05/25.
//

#include "QTMDB.h"
#include <QJsonObject>

QJsonObject Qtmdb::config_details()
{
    std::string request = "configuration";
    return _runGetRequest(request);
}

QJsonObject Qtmdb::config_countries(std::string language)
{
    std::string request = "configuration/countries";
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::config_jobs()
{
    std::string request = "configuration/jobs";
    return _runGetRequest(request);
}

QJsonObject Qtmdb::config_languages()
{
    std::string request = "configuration/languages";
    return _runGetRequest(request);
}

QJsonObject Qtmdb::config_primaryTranslations()
{
    std::string request = "configuration/primary_translations";
    return _runGetRequest(request);
}

QJsonObject Qtmdb::config_timezones()
{
    std::string request = "configuration/timezones";
    return _runGetRequest(request);
}