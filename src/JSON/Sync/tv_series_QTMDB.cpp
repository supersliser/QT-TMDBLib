//
// Created by t on 21/05/25.
//

#include "Sync/QTMDB.h"
#include <QJsonObject>

QJsonObject Qtmdb::tv_series_airingToday(std::string language, int32_t page, std::string timezone)
{
    std::string request = "tv/airing_today";
    std::map<std::string, std::string> params = {
        {"language", language},
        {"page", std::to_string(page)},
        {"timezone", timezone}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::tv_series_onTheAir(std::string language, int32_t page, std::string timezone)
{
    std::string request = "tv/on_the_air";
    std::map<std::string, std::string> params = {
        {"language", language},
        {"page", std::to_string(page)},
        {"timezone", timezone}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::tv_series_popular(std::string language, int32_t page)
{
    std::string request = "tv/popular";
    std::map<std::string, std::string> params = {
        {"language", language},
        {"page", std::to_string(page)}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::tv_series_topRated(std::string language, int32_t page)
{
    std::string request = "tv/top_rated";
    std::map<std::string, std::string> params = {
        {"language", language},
        {"page", std::to_string(page)}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::tv_series_details(int32_t series_id, std::string language)
{
    std::string request = fmt::format("{}{}", "tv/", std::to_string(series_id));
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::tv_series_aggregateCredits(int32_t series_id, std::string language)
{
    std::string request = fmt::format("{}{}{}", "tv/", std::to_string(series_id), "/aggregate_credits");
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::tv_series_alternativeTitles(int32_t series_id)
{
    std::string request = fmt::format("{}{}{}", "tv/", std::to_string(series_id), "/alternative_titles");
    return _runGetRequest(request);
}

QJsonObject Qtmdb::tv_series_changes(int32_t series_id, QDate start_date, QDate end_date, int32_t page)
{
    std::string request = fmt::format("{}{}{}", "tv/", std::to_string(series_id), "/changes");
    std::map<std::string, std::string> params = {
        {"start_date", start_date.toString(Qt::ISODate).toStdString()},
        {"end_date", end_date.toString(Qt::ISODate).toStdString()},
        {"page", std::to_string(page)}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::tv_series_contentRatings(int32_t series_id)
{
    std::string request = fmt::format("{}{}{}", "tv/", std::to_string(series_id), "/content_ratings");
    return _runGetRequest(request);
}

QJsonObject Qtmdb::tv_series_credits(int32_t series_id, std::string language)
{
    std::string request = fmt::format("{}{}{}", "tv/", std::to_string(series_id), "/credits");
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::tv_series_episodeGroups(int32_t series_id)
{
    std::string request = fmt::format("{}{}{}", "tv/", std::to_string(series_id), "/episode_groups");
    return _runGetRequest(request);
}

QJsonObject Qtmdb::tv_series_externalIDs(int32_t series_id)
{
    std::string request = fmt::format("{}{}{}", "tv/", std::to_string(series_id), "/external_ids");
    return _runGetRequest(request);
}

QJsonObject Qtmdb::tv_series_images(int32_t series_id, std::string language)
{
    std::string request = fmt::format("{}{}{}", "tv/", std::to_string(series_id), "/images");
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::tv_series_keywords(int32_t series_id)
{
    std::string request = fmt::format("{}{}{}", "tv/", std::to_string(series_id), "/keywords");
    return _runGetRequest(request);
}

QJsonObject Qtmdb::tv_series_latest()
{
    std::string request = "tv/latest";
    return _runGetRequest(request);
}

QJsonObject Qtmdb::tv_series_lists(int32_t series_id, int32_t page, std::string language)
{
    std::string request = fmt::format("{}{}{}", "tv/", std::to_string(series_id), "/lists");
    std::map<std::string, std::string> params = {
        {"page", std::to_string(page)},
        {"language", language}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::tv_series_recommendations(int32_t series_id, std::string language, int32_t page)
{
    std::string request = fmt::format("{}{}{}", "tv/", std::to_string(series_id), "/recommendations");
    std::map<std::string, std::string> params = {
        {"language", language},
        {"page", std::to_string(page)}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::tv_series_reviews(int32_t series_id, std::string language, int32_t page)
{
    std::string request = fmt::format("{}{}{}", "tv/", std::to_string(series_id), "/reviews");
    std::map<std::string, std::string> params = {
        {"language", language},
        {"page", std::to_string(page)}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::tv_series_screenedTheatrically(int32_t series_id)
{
    std::string request = fmt::format("{}{}{}", "tv/", std::to_string(series_id), "/screened_theatrically");
    return _runGetRequest(request);
}

QJsonObject Qtmdb::tv_series_similar(int32_t series_id, std::string language, int32_t page)
{
    std::string request = fmt::format("{}{}{}", "tv/", std::to_string(series_id), "/similar");
    std::map<std::string, std::string> params = {
        {"language", language},
        {"page", std::to_string(page)}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::tv_series_translations(int32_t series_id)
{
    std::string request = fmt::format("{}{}{}", "tv/", std::to_string(series_id), "/translations");
    return _runGetRequest(request);
}

QJsonObject Qtmdb::tv_series_videos(int32_t series_id, std::string language)
{
    std::string request = fmt::format("{}{}{}", "tv/", std::to_string(series_id), "/videos");
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::tv_series_watchProviders(int32_t series_id)
{
    std::string request = fmt::format("{}{}{}", "tv/", std::to_string(series_id), "/watch/providers");
    return _runGetRequest(request);
}