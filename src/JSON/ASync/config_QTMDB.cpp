//
// Created by t on 21/05/25.
//

#include "Async/QTMDB.h"
#include <QJsonObject>
#include <QJsonArray>

void aQtmdb::config_details()
{
    std::string request = "configuration";
    _runGetRequest(request);
}

void aQtmdb::config_countries(std::string language)
{
    std::string request = "configuration/countries";
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    _runGetRequest(request, params);
}

void aQtmdb::config_jobs()
{
    std::string request = "configuration/jobs";
    _runGetRequest(request);
}

void aQtmdb::config_languages()
{
    std::string request = "configuration/languages";
    _runGetRequest(request);
}

void aQtmdb::config_primaryTranslations()
{
    std::string request = "configuration/primary_translations";
    _runGetRequest(request);
}

void aQtmdb::config_timezones()
{
    std::string request = "configuration/timezones";
    _runGetRequest(request);
}
