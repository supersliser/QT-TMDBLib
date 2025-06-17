//
// Created by t on 21/05/25.
//

#include "Sync/QTMDB.h"
#include <QJsonObject>

QJsonObject Qtmdb::collection_details(int32_t collection_id, std::string language)
{
    std::string request = fmt::format("{}{}","collection/", std::to_string(collection_id));
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::collection_images(int32_t collection_id, std::string language)
{
    std::string request = fmt::format("{}{}{}","collection/", std::to_string(collection_id), "/images");
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::collection_translations(int32_t collection_id)
{
    std::string request = fmt::format("{}{}{}","collection/", std::to_string(collection_id), "/translations");
    return _runGetRequest(request);
}