//
// Created by t on 21/05/25.
//

#include "QTMDB.h"
#include <QJsonObject>

QJsonObject Qtmdb::account_details(int32_t account_id)
{
    std::string_view request = "account/" + std::to_string(account_id);
    return _runGetRequest(request);
}

QJsonObject Qtmdb::account_favoriteMovies(int32_t account_id, std::string_view language, int32_t page)
{
    std::string_view request = "account/" + std::to_string(account_id) + "/favorite/movies";
    std::map<std::string_view, std::string_view> params = {
        {"language", language},
        {"page", std::to_string(page)}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::account_favoriteTV(int32_t account_id, std::string_view language, int32_t page)
{
    std::string_view request = "account/" + std::to_string(account_id) + "/favorite/tv";
    std::map<std::string_view, std::string_view> params = {
        {"language", language},
        {"page", std::to_string(page)}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::account_lists(int32_t account_id, int32_t page)
{
    std::string_view request = "account/" + std::to_string(account_id) + "/lists";
    std::map<std::string_view, std::string_view> params = {
        {"page", std::to_string(page)}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::account_ratedMovies(int32_t account_id, std::string_view language, int32_t page)
{
    std::string_view request = "account/" + std::to_string(account_id) + "/rated/movies";
    std::map<std::string_view, std::string_view> params = {
        {"language", language},
        {"page", std::to_string(page)}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::account_ratedTV(int32_t account_id, std::string_view language, int32_t page)
{
    std::string_view request = "account/" + std::to_string(account_id) + "/rated/tv";
    std::map<std::string_view, std::string_view> params = {
        {"language", language},
        {"page", std::to_string(page)}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::account_ratedTVEpisodes(int32_t account_id, std::string_view language, int32_t page)
{
    std::string_view request = "account/" + std::to_string(account_id) + "/rated/tv/episodes";
    std::map<std::string_view, std::string_view> params = {
        {"language", language},
        {"page", std::to_string(page)}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::account_watchlistMovies(int32_t account_id, std::string_view language, int32_t page)
{
    std::string_view request = "account/" + std::to_string(account_id) + "/watchlist/movies";
    std::map<std::string_view, std::string_view> params = {
        {"language", language},
        {"page", std::to_string(page)}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::account_watchlistTV(int32_t account_id, std::string_view language, int32_t page)
{
    std::string_view request = "account/" + std::to_string(account_id) + "/watchlist/tv";
    std::map<std::string_view, std::string_view> params = {
        {"language", language},
        {"page", std::to_string(page)}
    };
    return _runGetRequest(request, params);
}
