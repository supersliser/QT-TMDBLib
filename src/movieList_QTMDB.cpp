//
// Created by t on 21/05/25.
//

#include "QTMDB.h"
#include <QJsonObject>

QJsonObject Qtmdb::movieList_nowPlaying(std::string_view region,std::string_view language, int32_t page)
{
    std::string_view request = "movie/now_playing";
    std::map<std::string_view, std::string_view> params = {
        {"language", language},
        {"page", std::to_string(page)},
        {"region", region}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::movieList_popular(std::string_view region,std::string_view language, int32_t page)
{
    std::string_view request = "movie/popular";
    std::map<std::string_view, std::string_view> params = {
        {"language", language},
        {"page", std::to_string(page)},
        {"region", region}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::movieList_topRated(std::string_view region,std::string_view language, int32_t page)
{
    std::string_view request = "movie/top_rated";
    std::map<std::string_view, std::string_view> params = {
        {"language", language},
        {"page", std::to_string(page)},
        {"region", region}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::movieList_upcoming(std::string_view region,std::string_view language, int32_t page)
{
    std::string_view request = "movie/upcoming";
    std::map<std::string_view, std::string_view> params = {
        {"language", language},
        {"page", std::to_string(page)},
        {"region", region}
    };
    return _runGetRequest(request, params);
}