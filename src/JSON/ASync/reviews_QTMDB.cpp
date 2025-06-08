//
// Created by t on 21/05/25.
//

#include "ASync/QTMDB.h"
#include <QJsonObject>

void aQtmdb::reviews_details(std::string review_id)
{
    std::string request = fmt::format("{}{}", "review/", std::string(review_id));
    _runGetRequest(request);
}
