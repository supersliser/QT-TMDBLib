//
// Created by t on 21/05/25.
//

#include "Sync/QTMDB.h"
#include <QJsonObject>
#include <QJsonArray>

QJsonObject Qtmdb::config_details()
{
    std::string request = "configuration";
    return _runGetRequest(request);
}

QJsonArray Qtmdb::config_countries(std::string language)
{
    std::string request = "configuration/countries";
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    return _runGetRequestArray(request, params);
}

QJsonArray Qtmdb::config_jobs()
{
    std::string request = "configuration/jobs";
    return _runGetRequestArray(request);
}

QJsonArray Qtmdb::config_languages()
{
    std::string request = "configuration/languages";
    return _runGetRequestArray(request);
}

QJsonArray Qtmdb::config_primaryTranslations()
{
    std::string request = "configuration/primary_translations";
    return _runGetRequestArray(request);
}

QJsonArray Qtmdb::config_timezones()
{
    std::string request = "configuration/timezones";
    return _runGetRequestArray(request);
}