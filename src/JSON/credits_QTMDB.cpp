//
// Created by t on 21/05/25.
//

#include "QTMDB.h"
#include <QJsonObject>

QJsonObject Qtmdb::credits_details(std::string credit_id)
{
    std::string request = fmt::format("{}{}","credit/", credit_id);
    return _runGetRequest(request);
}