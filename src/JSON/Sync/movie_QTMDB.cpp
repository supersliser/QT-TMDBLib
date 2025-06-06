//
// Created by t on 21/05/25.
//

#include "QTMDB.h"
#include <QJsonObject>

QJsonObject Qtmdb::movie_details(int32_t movie_id, std::string language)
{
    std::map<std::string, std::string> params = {
        {"language", language},
    };
    std::string request = fmt::format("{}{}", "movie/", std::to_string(movie_id));
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::movie_alternativeTitles(int32_t movie_id, std::string country)
{
    std::map<std::string, std::string> params;
    if (!country.empty())
    {
        params["country"] = country;
    }
    std::string request = fmt::format("{}{}{}","movie/", std::to_string(movie_id), "/alternative_titles");
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::movie_changes(int32_t movie_id, QDate start_date, QDate end_date, int32_t page)
{
    std::map<std::string, std::string> params = {
        {"start_date", start_date.toString("yyyy-MM-dd").toStdString()},
        {"end_date", end_date.toString("yyyy-MM-dd").toStdString()},
        {"page", std::to_string(page)},
    };
    std::string request = fmt::format("{}{}{}","movie/", std::to_string(movie_id), "/changes");
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::movie_credits(int32_t movie_id, std::string language)
{
    std::map<std::string, std::string> params = {
        {"language", language},
    };
    std::string request = fmt::format("{}{}{}","movie/", std::to_string(movie_id), "/credits");
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::movie_externalIDs(int32_t movie_id)
{
    std::string request = fmt::format("{}{}{}","movie/", std::to_string(movie_id), "/external_ids");
    return _runGetRequest(request);
}

QJsonObject Qtmdb::movie_images(int32_t movie_id, std::string language)
{
    std::map<std::string, std::string> params = {
        {"language", language},
    };
    std::string request = fmt::format("{}{}{}","movie/", std::to_string(movie_id) ,"/images");
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::movie_latest()
{
    std::string request = "movie/latest";
    return _runGetRequest(request);
}

QJsonObject Qtmdb::movie_keywords(int32_t movie_id)
{
    std::string request = fmt::format("{}{}{}","movie/", std::to_string(movie_id), "/keywords");
    return _runGetRequest(request);
}

QJsonObject Qtmdb::movie_lists(int32_t movie_id, int32_t page, std::string language)
{
    std::map<std::string, std::string> params = {
        {"page", std::to_string(page)},
        {"language", language},
    };
    std::string request = fmt::format("{}{}{}","movie/", std::to_string(movie_id), "/lists");
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::movie_recommendations(int32_t movie_id, std::string language, int32_t page)
{
    std::map<std::string, std::string> params = {
        {"language", language},
        {"page", std::to_string(page)},
    };
    std::string request = fmt::format("{}{}{}","movie/", std::to_string(movie_id), "/recommendations");
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::movie_releaseDates(int32_t movie_id)
{
    std::string request = fmt::format("{}{}{}","movie/", std::to_string(movie_id), "/release_dates");
    return _runGetRequest(request);
}

QJsonObject Qtmdb::movie_reviews(int32_t movie_id, std::string language, int32_t page)
{
    std::map<std::string, std::string> params = {
        {"language", language},
        {"page", std::to_string(page)},
    };
    std::string request = fmt::format("{}{}{}","movie/", std::to_string(movie_id), "/reviews");
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::movie_similar(int32_t movie_id, std::string language, int32_t page)
{
    std::map<std::string, std::string> params = {
        {"language", language},
        {"page", std::to_string(page)},
    };
    std::string request = fmt::format("{}{}{}","movie/", std::to_string(movie_id), "/similar");
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::movie_translations(int32_t movie_id)
{
    std::string request = fmt::format("{}{}{}","movie/", std::to_string(movie_id), "/translations");
    return _runGetRequest(request);
}

QJsonObject Qtmdb::movie_videos(int32_t movie_id, std::string language)
{
    std::map<std::string, std::string> params = {
        {"language", language},
    };
    std::string request = fmt::format("{}{}{}","movie/", std::to_string(movie_id), "/videos");
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::movie_watchProviders(int32_t movie_id)
{
    std::string request = fmt::format("{}{}{}","movie/", std::to_string(movie_id), "/watch/providers");
    return _runGetRequest(request);
}