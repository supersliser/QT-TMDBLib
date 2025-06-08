//
// Created by t on 21/05/25.
//

#include "Async/QTMDB.h"
#include <QJsonObject>

void aQtmdb::movie_details(int32_t movie_id, std::string language)
{
    std::map<std::string, std::string> params = {
        {"language", language},
    };
    std::string request = fmt::format("{}{}", "movie/", std::to_string(movie_id));
    _runGetRequest(request, params);
}

void aQtmdb::movie_alternativeTitles(int32_t movie_id, std::string country)
{
    std::map<std::string, std::string> params;
    if (!country.empty())
    {
        params["country"] = country;
    }
    std::string request = fmt::format("{}{}{}", "movie/", std::to_string(movie_id), "/alternative_titles");
    _runGetRequest(request, params);
}

void aQtmdb::movie_changes(int32_t movie_id, QDate start_date, QDate end_date, int32_t page)
{
    std::map<std::string, std::string> params = {
        {"start_date", start_date.toString("yyyy-MM-dd").toStdString()},
        {"end_date", end_date.toString("yyyy-MM-dd").toStdString()},
        {"page", std::to_string(page)},
    };
    std::string request = fmt::format("{}{}{}", "movie/", std::to_string(movie_id), "/changes");
    _runGetRequest(request, params);
}

void aQtmdb::movie_credits(int32_t movie_id, std::string language)
{
    std::map<std::string, std::string> params = {
        {"language", language},
    };
    std::string request = fmt::format("{}{}{}", "movie/", std::to_string(movie_id), "/credits");
    _runGetRequest(request, params);
}

void aQtmdb::movie_externalIDs(int32_t movie_id)
{
    std::string request = fmt::format("{}{}{}", "movie/", std::to_string(movie_id), "/external_ids");
    _runGetRequest(request);
}

void aQtmdb::movie_images(int32_t movie_id, std::string language)
{
    std::map<std::string, std::string> params = {
        {"language", language},
    };
    std::string request = fmt::format("{}{}{}", "movie/", std::to_string(movie_id), "/images");
    _runGetRequest(request, params);
}

void aQtmdb::movie_latest()
{
    std::string request = "movie/latest";
    _runGetRequest(request);
}

void aQtmdb::movie_keywords(int32_t movie_id)
{
    std::string request = fmt::format("{}{}{}", "movie/", std::to_string(movie_id), "/keywords");
    _runGetRequest(request);
}

void aQtmdb::movie_lists(int32_t movie_id, int32_t page, std::string language)
{
    std::map<std::string, std::string> params = {
        {"page", std::to_string(page)},
        {"language", language},
    };
    std::string request = fmt::format("{}{}{}", "movie/", std::to_string(movie_id), "/lists");
    _runGetRequest(request, params);
}

void aQtmdb::movie_recommendations(int32_t movie_id, std::string language, int32_t page)
{
    std::map<std::string, std::string> params = {
        {"language", language},
        {"page", std::to_string(page)},
    };
    std::string request = fmt::format("{}{}{}", "movie/", std::to_string(movie_id), "/recommendations");
    _runGetRequest(request, params);
}

void aQtmdb::movie_releaseDates(int32_t movie_id)
{
    std::string request = fmt::format("{}{}{}", "movie/", std::to_string(movie_id), "/release_dates");
    _runGetRequest(request);
}

void aQtmdb::movie_reviews(int32_t movie_id, std::string language, int32_t page)
{
    std::map<std::string, std::string> params = {
        {"language", language},
        {"page", std::to_string(page)},
    };
    std::string request = fmt::format("{}{}{}", "movie/", std::to_string(movie_id), "/reviews");
    _runGetRequest(request, params);
}

void aQtmdb::movie_similar(int32_t movie_id, std::string language, int32_t page)
{
    std::map<std::string, std::string> params = {
        {"language", language},
        {"page", std::to_string(page)},
    };
    std::string request = fmt::format("{}{}{}", "movie/", std::to_string(movie_id), "/similar");
    _runGetRequest(request, params);
}

void aQtmdb::movie_translations(int32_t movie_id)
{
    std::string request = fmt::format("{}{}{}", "movie/", std::to_string(movie_id), "/translations");
    _runGetRequest(request);
}

void aQtmdb::movie_videos(int32_t movie_id, std::string language)
{
    std::map<std::string, std::string> params = {
        {"language", language},
    };
    std::string request = fmt::format("{}{}{}", "movie/", std::to_string(movie_id), "/videos");
    _runGetRequest(request, params);
}

void aQtmdb::movie_watchProviders(int32_t movie_id)
{
    std::string request = fmt::format("{}{}{}", "movie/", std::to_string(movie_id), "/watch/providers");
    _runGetRequest(request);
}
