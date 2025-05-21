//
// Created by t on 21/05/25.
//

#include "QTMDB.h"
#include <QJsonObject>

QJsonObject Qtmdb::collection_details(int32_t collection_id, std::string_view language)
{
    std::string_view request = "collection/" + std::to_string(collection_id);
    std::map<std::string_view, std::string_view> params = {
        {"language", language}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::collection_images(int32_t collection_id, std::string_view language)
{
    std::string_view request = "collection/" + std::to_string(collection_id) + "/images";
    std::map<std::string_view, std::string_view> params = {
        {"language", language}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::collection_translations(int32_t collection_id)
{
    std::string_view request = "collection/" + std::to_string(collection_id) + "/translations";
    return _runGetRequest(request);
}