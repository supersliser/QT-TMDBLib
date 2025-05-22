//
// Created by t on 21/05/25.
//

#include "QTMDB.h"
#include <QJsonObject>

QJsonObject Qtmdb::watchProviders_regions(std::string language)
{
    std::string request = "watch/providers/regions";
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::watchProviders_movie(std::string language)
{
    std::string request = "watch/providers/movie";
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::watchProviders_tv(std::string language)
{
    std::string request = "watch/providers/tv";
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    return _runGetRequest(request, params);
}