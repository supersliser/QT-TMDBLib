//
// Created by t on 21/05/25.
//

#include "QTMDB.h"
#include <QJsonObject>

QJsonObject Qtmdb::watchProviders_regions(std::string_view language)
{
    std::string_view request = "watch/providers/regions";
    std::map<std::string_view, std::string_view> params = {
        {"language", language}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::watchProviders_movie(std::string_view language)
{
    std::string_view request = "watch/providers/movie";
    std::map<std::string_view, std::string_view> params = {
        {"language", language}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::watchProviders_tv(std::string_view language)
{
    std::string_view request = "watch/providers/tv";
    std::map<std::string_view, std::string_view> params = {
        {"language", language}
    };
    return _runGetRequest(request, params);
}