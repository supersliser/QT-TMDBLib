//
// Created by t on 21/05/25.
//

#include "QTMDB.h"
#include <QJsonObject>

QJsonObject Qtmdb::certifications_movie()
{
    std::string request = "certification/movie/list";
    return _runGetRequest(request);
}

QJsonObject Qtmdb::certifications_tv()
{
    std::string request = "certification/tv/list";
    return _runGetRequest(request);
}