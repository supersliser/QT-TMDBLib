//
// Created by t on 21/05/25.
//

#include "QTMDB.h"
#include <QJsonObject>

QJsonObject Qtmdb::genres_movie(std::string language)
{
    std::string request = "genre/movie/list";
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::genres_tv(std::string language)
{
    std::string request = "genre/tv/list";
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    return _runGetRequest(request, params);
}