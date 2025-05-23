//
// Created by t on 21/05/25.
//

#include "QTMDB.h"
#include <QJsonObject>

QJsonObject Qtmdb::people_popular(std::string language, int32_t page)
{
    std::string request = "person/popular";
    std::map<std::string, std::string> params = {
        {"language", language},
        {"page", std::to_string(page)}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::people_details(int32_t person_id, std::string language)
{
    std::string request = fmt::format("{}{}","person/", std::to_string(person_id));
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::people_changes(int32_t person_id, QDate start_date, QDate end_date, int32_t page)
{
    std::string request = fmt::format("{}{}{}","person/", std::to_string(person_id), "/changes");
    std::map<std::string, std::string> params = {
        {"start_date", start_date.toString(Qt::ISODate).toStdString()},
        {"end_date", end_date.toString(Qt::ISODate).toStdString()},
        {"page", std::to_string(page)}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::people_combinedCredits(int32_t person_id, std::string language)
{
    std::string request = fmt::format("{}{}{}","person/", std::to_string(person_id), "/combined_credits");
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::people_externalIDs(int32_t person_id)
{
    std::string request = fmt::format("{}{}{}","person/", std::to_string(person_id), "/external_ids");
    return _runGetRequest(request);
}

QJsonObject Qtmdb::people_images(int32_t person_id)
{
    std::string request = fmt::format("{}{}{}","person/", std::to_string(person_id), "/images");
    return _runGetRequest(request);
}

QJsonObject Qtmdb::people_latest()
{
    std::string request = "person/latest";
    return _runGetRequest(request);
}

QJsonObject Qtmdb::people_movieCredits(int32_t person_id, std::string language)
{
    std::string request = fmt::format("{}{}{}","person/", std::to_string(person_id), "/movie_credits");
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::people_tvCredits(int32_t person_id, std::string language)
{
    std::string request = fmt::format("{}{}{}","person/", std::to_string(person_id), "/tv_credits");
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::people_taggedImages(int32_t person_id, int32_t page)
{
    std::string request = fmt::format("{}{}{}","person/", std::to_string(person_id), "/tagged_images");
    std::map<std::string, std::string> params = {
        {"page", std::to_string(page)}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::people_translations(int32_t person_id)
{
    std::string request = fmt::format("{}{}{}","person/", std::to_string(person_id), "/translations");
    return _runGetRequest(request);
}