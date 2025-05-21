//
// Created by t on 21/05/25.
//

#include "QTMDB.h"
#include <QJsonObject>

QJsonObject Qtmdb::reviews_details(std::string_view review_id)
{
    std::string_view request = "review/" + std::string(review_id);
    return _runGetRequest(request);
}