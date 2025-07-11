//
// Created by t on 21/05/25.
//
#include "Sync/QTMDB.h"
#include <QJsonObject>

QJsonObject Qtmdb::changes_movie(QDate end_date, QDate start_date, int32_t page)
{
    std::string request = "movie/changes";
    std::map<std::string, std::string> params = {
        {"start_date", start_date.toString(Qt::ISODate).toStdString()},
        {"end_date", end_date.toString(Qt::ISODate).toStdString()},
        {"page", std::to_string(page)}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::changes_people(QDate end_date, QDate start_date, int32_t page)
{
    std::string request = "person/changes";
    std::map<std::string, std::string> params = {
        {"start_date", start_date.toString(Qt::ISODate).toStdString()},
        {"end_date", end_date.toString(Qt::ISODate).toStdString()},
        {"page", std::to_string(page)}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::changes_tv(QDate end_date, QDate start_date, int32_t page)
{
    std::string request = "tv/changes";
    std::map<std::string, std::string> params = {
        {"start_date", start_date.toString(Qt::ISODate).toStdString()},
        {"end_date", end_date.toString(Qt::ISODate).toStdString()},
        {"page", std::to_string(page)}
    };
    return _runGetRequest(request, params);
}