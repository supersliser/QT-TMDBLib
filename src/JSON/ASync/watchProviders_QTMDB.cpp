//
// Created by t on 21/05/25.
//

#include "aQTMDB.h"
#include <QJsonObject>

void aQtmdb::watchProviders_regions(std::string language)
{
    std::string request = "watch/providers/regions";
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    _runGetRequest(request, params);
}

void aQtmdb::watchProviders_movie(std::string language)
{
    std::string request = "watch/providers/movie";
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    _runGetRequest(request, params);
}

void aQtmdb::watchProviders_tv(std::string language)
{
    std::string request = "watch/providers/tv";
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    _runGetRequest(request, params);
}
