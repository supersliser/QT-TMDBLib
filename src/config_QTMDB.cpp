//
// Created by t on 21/05/25.
//

#include "QTMDB.h"
#include <QJsonObject>

QJsonObject Qtmdb::config_details()
{
    std::string_view request = "configuration";
    return _runGetRequest(request);
}

QJsonObject Qtmdb::config_countries(std::string_view language)
{
    std::string_view request = "configuration/countries";
    std::map<std::string_view, std::string_view> params = {
        {"language", language}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::config_jobs()
{
    std::string_view request = "configuration/jobs";
    return _runGetRequest(request);
}

QJsonObject Qtmdb::config_languages()
{
    std::string_view request = "configuration/languages";
    return _runGetRequest(request);
}

QJsonObject Qtmdb::config_primaryTranslations()
{
    std::string_view request = "configuration/primary_translations";
    return _runGetRequest(request);
}

QJsonObject Qtmdb::config_timezones()
{
    std::string_view request = "configuration/timezones";
    return _runGetRequest(request);
}