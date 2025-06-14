//
// Created by t on 21/05/25.
//

#include "ASync/QTMDB.h"
#include <QJsonObject>

void aQtmdb::company_details(int32_t company_id)
{
    std::string request = fmt::format("{}{}", "company/", std::to_string(company_id));
    _runGetRequest(request);

}

void aQtmdb::company_alternativeNames(int32_t company_id)
{
    std::string request = fmt::format("{}{}{}", "company/", std::to_string(company_id), "/alternative_names");
    _runGetRequest(request);

}

void aQtmdb::company_images(int32_t company_id)
{
    std::string request = fmt::format("{}{}{}", "company/", std::to_string(company_id), "/images");
    _runGetRequest(request);

}
