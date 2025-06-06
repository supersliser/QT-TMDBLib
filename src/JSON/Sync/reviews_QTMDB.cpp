//
// Created by t on 21/05/25.
//

#include "QTMDB.h"
#include <QJsonObject>

QJsonObject Qtmdb::reviews_details(std::string review_id)
{
    std::string request = fmt::format("{}{}", "review/", std::string(review_id));
    return _runGetRequest(request);
}