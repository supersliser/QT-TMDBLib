//
// Created by t on 21/05/25.
//

#include "QTMDB.h"
#include <QJsonObject>

QJsonObject Qtmdb::tv_episodes_details(int32_t series_id, int32_t season_number, int32_t episode_number, std::string_view language)
{
    std::string_view request = "tv/" + std::to_string(series_id) + "/season/" + std::to_string(season_number) + "/episode/" + std::to_string(episode_number);
    std::map<std::string_view, std::string_view> params = {
        {"language", language}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::tv_episodes_changes(int32_t episode_id, QDate start_date, QDate end_date, int32_t page)
{
    std::string_view request = "tv/" + std::to_string(episode_id) + "/changes";
    std::map<std::string_view, std::string_view> params = {
        {"start_date", start_date.toString(Qt::ISODate).toStdString()},
        {"end_date", end_date.toString(Qt::ISODate).toStdString()},
        {"page", std::to_string(page)}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::tv_episodes_credits(int32_t series_id, int32_t season_number, int32_t episode_number, std::string_view language)
{
    std::string_view request = "tv/" + std::to_string(series_id) + "/season/" + std::to_string(season_number) + "/episode/" + std::to_string(episode_number) + "/credits";
    std::map<std::string_view, std::string_view> params = {
        {"language", language}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::tv_episodes_externalIDs(int32_t series_id, int32_t season_number, int32_t episode_number)
{
    std::string_view request = "tv/" + std::to_string(series_id) + "/season/" + std::to_string(season_number) + "/episode/" + std::to_string(episode_number) + "/external_ids";
    return _runGetRequest(request);
}

QJsonObject Qtmdb::tv_episodes_images(int32_t series_id, int32_t season_number, int32_t episode_number, std::string_view language)
{
    std::string_view request = "tv/" + std::to_string(series_id) + "/season/" + std::to_string(season_number) + "/episode/" + std::to_string(episode_number) + "/images";
    std::map<std::string_view, std::string_view> params = {
        {"language", language}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::tv_episodes_translations(int32_t series_id, int32_t season_number, int32_t episode_number)
{
    std::string_view request = "tv/" + std::to_string(series_id) + "/season/" + std::to_string(season_number) + "/episode/" + std::to_string(episode_number) + "/translations";
    return _runGetRequest(request);
}

QJsonObject Qtmdb::tv_episodes_videos(int32_t series_id, int32_t season_number, int32_t episode_number, std::string_view language)
{
    std::string_view request = "tv/" + std::to_string(series_id) + "/season/" + std::to_string(season_number) + "/episode/" + std::to_string(episode_number) + "/videos";
    std::map<std::string_view, std::string_view> params = {
        {"language", language}
    };
    return _runGetRequest(request, params);
}