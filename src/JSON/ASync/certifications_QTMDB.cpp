//
// Created by t on 21/05/25.
//

#include "aQTMDB.h"
#include <QJsonObject>

void aQtmdb::certifications_movie()
{
    std::string request = "certification/movie/list";
    _runGetRequest(request);
}

void aQtmdb::certifications_tv()
{
    std::string request = "certification/tv/list";
    _runGetRequest(request);
}