//
// Created by t on 21/05/25.
//

#include "QTMDB.h"
#include <QJsonObject>

QJsonObject Qtmdb::company_details(int32_t company_id)
{
    std::string request = fmt::format("{}{}","company/" ,std::to_string(company_id));
    return _runGetRequest(request);
}

QJsonObject Qtmdb::company_alternativeNames(int32_t company_id)
{
    std::string request = fmt::format("{}{}{}","company/", std::to_string(company_id), "/alternative_names");
    return _runGetRequest(request);
}

QJsonObject Qtmdb::company_images(int32_t company_id)
{
    std::string request = fmt::format("{}{}{}","company/", std::to_string(company_id), "/images");
    return _runGetRequest(request);
}