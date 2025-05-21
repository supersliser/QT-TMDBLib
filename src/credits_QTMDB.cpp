//
// Created by t on 21/05/25.
//

#include "QTMDB.h"
#include <QJsonObject>

QJsonObject Qtmdb::credits_details(int32_t credit_id)
{
    std::string_view request = "credit/" + std::to_string(credit_id);
    return _runGetRequest(request);
}