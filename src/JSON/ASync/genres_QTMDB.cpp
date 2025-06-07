//
// Created by t on 21/05/25.
//

#include "aQTMDB.h"
#include <QJsonObject>

void aQtmdb::genres_movie(std::string language)
{
    std::string request = "genre/movie/list";
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    _runGetRequest(request, params);
}

void aQtmdb::genres_tv(std::string language)
{
    std::string request = "genre/tv/list";
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    _runGetRequest(request, params);
}
