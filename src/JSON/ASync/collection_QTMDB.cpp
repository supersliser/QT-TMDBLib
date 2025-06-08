//
// Created by t on 21/05/25.
//

#include "ASync/QTMDB.h"
#include <QJsonObject>

void aQtmdb::collection_details(int32_t collection_id, std::string language)
{
    std::string request = fmt::format("{}{}", "collection/", std::to_string(collection_id));
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    _runGetRequest(request, params);
}

void aQtmdb::collection_images(int32_t collection_id, std::string language)
{
    std::string request = fmt::format("{}{}{}", "collection/", std::to_string(collection_id), "/images");
    std::map<std::string, std::string> params = {
        {"language", language}
    };
    _runGetRequest(request, params);
}

void aQtmdb::collection_translations(int32_t collection_id)
{
    std::string request = fmt::format("{}{}{}", "collection/", std::to_string(collection_id), "/translations");
    _runGetRequest(request);
}
