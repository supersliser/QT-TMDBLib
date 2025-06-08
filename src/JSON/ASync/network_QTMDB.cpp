//
// Created by t on 21/05/25.
//

#include "Async/QTMDB.h"
#include <QJsonObject>

void aQtmdb::network_details(int32_t network_id)
{
    std::string request = fmt::format("{}{}", "network/", std::to_string(network_id));
    _runGetRequest(request);
}

void aQtmdb::network_alternativeNames(int32_t network_id)
{
    std::string request = fmt::format("{}{}{}", "network/", std::to_string(network_id), "/alternative_names");
    _runGetRequest(request);
}

void aQtmdb::network_images(int32_t network_id)
{
    std::string request = fmt::format("{}{}{}", "network/", std::to_string(network_id), "/images");
    _runGetRequest(request);
}
