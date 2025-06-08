//
// Created by t on 21/05/25.
//

#include "Async/QTMDB.h"
#include <QJsonObject>

void aQtmdb::account_details(int32_t account_id)
{
    auto accountId = std::to_string(account_id);
    std::string request = fmt::format("account/{}", accountId);
    _runGetRequest(request);
}

void aQtmdb::account_favoriteMovies(int32_t account_id, std::string language, int32_t page)
{
    std::string request = fmt::format("{}{}{}", "account/", std::to_string(account_id), "/favorite/movies");
    std::map<std::string, std::string> params = {
        {"language", language},
        {"page", std::to_string(page)}
    };
    _runGetRequest(request, params);
}

void aQtmdb::account_favoriteTV(int32_t account_id, std::string language, int32_t page)
{
    std::string request = fmt::format("{}{}{}", "account/", std::to_string(account_id), "/favorite/tv");
    std::map<std::string, std::string> params = {
        {"language", language},
        {"page", std::to_string(page)}
    };
    _runGetRequest(request, params);
}

void aQtmdb::account_lists(int32_t account_id, int32_t page)
{
    std::string request = fmt::format("{}{}{}", "account/", std::to_string(account_id), "/lists");
    std::map<std::string, std::string> params = {
        {"page", std::to_string(page)}
    };
    _runGetRequest(request, params);
}

void aQtmdb::account_ratedMovies(int32_t account_id, std::string language, int32_t page)
{
    std::string request = fmt::format("{}{}{}", "account/", std::to_string(account_id), "/rated/movies");
    std::map<std::string, std::string> params = {
        {"language", language},
        {"page", std::to_string(page)}
    };
    _runGetRequest(request, params);
}

void aQtmdb::account_ratedTV(int32_t account_id, std::string language, int32_t page)
{
    std::string request = fmt::format("{}{}{}", "account/", std::to_string(account_id), "/rated/tv");
    std::map<std::string, std::string> params = {
        {"language", language},
        {"page", std::to_string(page)}
    };
    _runGetRequest(request, params);
}

void aQtmdb::account_ratedTVEpisodes(int32_t account_id, std::string language, int32_t page)
{
    std::string request = fmt::format("{}{}{}", "account/", std::to_string(account_id), "/rated/tv/episodes");
    std::map<std::string, std::string> params = {
        {"language", language},
        {"page", std::to_string(page)}
    };
    _runGetRequest(request, params);
}

void aQtmdb::account_watchlistMovies(int32_t account_id, std::string language, int32_t page)
{
    std::string request = fmt::format("{}{}{}", "account/", std::to_string(account_id), "/watchlist/movies");
    std::map<std::string, std::string> params = {
        {"language", language},
        {"page", std::to_string(page)}
    };
    _runGetRequest(request, params);
}

void aQtmdb::account_watchlistTV(int32_t account_id, std::string language, int32_t page)
{
    std::string request = fmt::format("{}{}{}", "account/", std::to_string(account_id), "/watchlist/tv");
    std::map<std::string, std::string> params = {
        {"language", language},
        {"page", std::to_string(page)}
    };
    _runGetRequest(request, params);
}
