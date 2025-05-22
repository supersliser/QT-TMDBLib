//
// Created by t on 21/05/25.
//

#include "QTMDB.h"
#include <QJsonObject>

QJsonObject Qtmdb::network_details(int32_t network_id)
{
    std::string request = fmt::format("{}{}","network/", std::to_string(network_id));
    return _runGetRequest(request);
}

QJsonObject Qtmdb::network_alternativeNames(int32_t network_id)
{
    std::string request = fmt::format("{}{}{}","network/", std::to_string(network_id), "/alternative_names");
    return _runGetRequest(request);
}

QJsonObject Qtmdb::network_images(int32_t network_id)
{
    std::string request = fmt::format("{}{}{}","network/", std::to_string(network_id), "/images");
    return _runGetRequest(request);
}