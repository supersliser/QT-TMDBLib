//
// Created by t on 21/05/25.
//

#include "ASync/QTMDB.h"
#include <QJsonObject>

void aQtmdb::tv_seasons_details(int32_t series_id, int32_t season_number, std::string language)
{
    std::string request = fmt::format("{}{}{}{}", "tv/", std::to_string(series_id), "/season/", std::to_string(season_number));
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    _runGetRequest(request, params);
}

void aQtmdb::tv_seasons_aggregateCredits(int32_t series_id, int32_t season_number, std::string language)
{
    std::string request = fmt::format("{}{}{}{}{}", "tv/", std::to_string(series_id), "/season/", std::to_string(season_number), "/aggregate_credits");
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    _runGetRequest(request, params);
}

void aQtmdb::tv_seasons_changes(int32_t season_id, QDate start_date, QDate end_date, int32_t page)
{
    std::string request = fmt::format("{}{}{}", "tv/season/", std::to_string(season_id), "/changes");
    std::map<std::string, std::string> params = {
        {"start_date", start_date.toString(Qt::ISODate).toStdString()},
        {"end_date", end_date.toString(Qt::ISODate).toStdString()},
        {"page", std::to_string(page)}
    };
    _runGetRequest(request, params);
}

void aQtmdb::tv_seasons_credits(int32_t series_id, int32_t season_number, std::string language)
{
    std::string request = fmt::format("{}{}{}{}{}", "tv/", std::to_string(series_id), "/season/", std::to_string(season_number), "/credits");
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    _runGetRequest(request, params);
}

void aQtmdb::tv_seasons_externalIDs(int32_t series_id, int32_t season_number)
{
    std::string request = fmt::format("{}{}{}{}{}", "tv/", std::to_string(series_id), "/season/", std::to_string(season_number), "/external_ids");
    _runGetRequest(request);
}

void aQtmdb::tv_seasons_images(int32_t series_id, int32_t season_number, std::string language)
{
    std::string request = fmt::format("{}{}{}{}{}", "tv/", std::to_string(series_id), "/season/", std::to_string(season_number), "/images");
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    _runGetRequest(request, params);
}

void aQtmdb::tv_seasons_videos(int32_t series_id, int32_t season_number, std::string language)
{
    std::string request = fmt::format("{}{}{}{}{}", "tv/", std::to_string(series_id), "/season/", std::to_string(season_number), "/videos");
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    _runGetRequest(request, params);
}

void aQtmdb::tv_seasons_translations(int32_t series_id, int32_t season_number)
{
    std::string request = fmt::format("{}{}{}{}{}", "tv/", std::to_string(series_id), "/season/", std::to_string(season_number), "/translations");
    _runGetRequest(request);
}

void aQtmdb::tv_seasons_watchProviders(int32_t series_id, int32_t season_number)
{
    std::string request = fmt::format("{}{}{}{}{}", "tv/", std::to_string(series_id), "/season/", std::to_string(season_number), "/watch/providers");
    _runGetRequest(request);
}