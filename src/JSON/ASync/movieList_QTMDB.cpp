//
// Created by t on 21/05/25.
//

#include "Async/QTMDB.h"
#include <QJsonObject>

void aQtmdb::movieList_nowPlaying(std::string region,std::string language, int32_t page)
{
    std::string request = "movie/now_playing";
    std::map<std::string, std::string> params = {
        {"language", language},
        {"page", std::to_string(page)},
        {"region", region}
    };
    _runGetRequest(request, params);
}

void aQtmdb::movieList_popular(std::string region,std::string language, int32_t page)
{
    std::string request = "movie/popular";
    std::map<std::string, std::string> params = {
        {"language", language},
        {"page", std::to_string(page)},
        {"region", region}
    };
    _runGetRequest(request, params);
}

void aQtmdb::movieList_topRated(std::string region,std::string language, int32_t page)
{
    std::string request = "movie/top_rated";
    std::map<std::string, std::string> params = {
        {"language", language},
        {"page", std::to_string(page)},
        {"region", region}
    };
    _runGetRequest(request, params);
}

void aQtmdb::movieList_upcoming(std::string region,std::string language, int32_t page)
{
    std::string request = "movie/upcoming";
    std::map<std::string, std::string> params = {
        {"language", language},
        {"page", std::to_string(page)},
        {"region", region}
    };
    _runGetRequest(request, params);
}