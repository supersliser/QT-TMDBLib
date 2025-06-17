//
// Created by t on 21/05/25.
//

#include "ASync/QTMDB.h"
#include <QJsonObject>

void aQtmdb::credits_details(std::string credit_id)
{
    std::string request = fmt::format("{}{}", "credit/", credit_id);
    _runGetRequest(request);

}
