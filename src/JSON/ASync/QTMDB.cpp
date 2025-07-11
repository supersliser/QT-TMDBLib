//
// Created by t on 07/06/25.
//

#include <QJsonObject>
#include <QJsonDocument>
#include "ASync/QTMDB.h"

aQtmdb::aQtmdb(std::string i_accessToken, QObject* parent) : QObject(parent)
{
    _m_accessToken = i_accessToken;
    _m_nam = new QNetworkAccessManager(this);
    connect(_m_nam, &QNetworkAccessManager::finished, this, &aQtmdb::_received);
}

std::string aQtmdb::accessToken()
{
    return _m_accessToken;
}

void aQtmdb::setAccessToken(std::string i_accessToken)
{
    _m_accessToken = i_accessToken;
}

void aQtmdb::_received(QNetworkReply* reply)
{
    if (reply->error() != QNetworkReply::NoError)
    {
        qDebug() << "Error: " << reply->errorString();
        return;
    }
    QByteArray response = reply->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
    if (jsonDoc.isNull())
    {
        qDebug() << "Error: Null Response";
        return;
    }
    if (!jsonDoc.isObject())
    {
        QJsonArray jsonArray = jsonDoc.array();
        if (jsonArray.isEmpty())
        {
            qDebug() << "Error: Empty Response";
            return;
        }
        emit finishedLoadingData(&jsonArray);
        reply->deleteLater();
    }
    else
    {
        QJsonObject jsonObj = jsonDoc.object();
        if (jsonObj.isEmpty())
        {
            qDebug() << "Error: Empty Response";
            return;
        }
        emit finishedLoadingData(&jsonObj);
        reply->deleteLater();
    }
}


void aQtmdb::_runGetRequest(std::string i_request, std::map<std::string, std::string> i_params)
{
    emit startedLoadingData();

    QUrl url((fmt::format("{}{}", _m_baseUrl, i_request).data()));
    for (const auto& param : i_params)
    {
        url.setQuery(fmt::format("{}{}{}{}{}", url.query().toStdString(), "&",
                                 QUrl::toPercentEncoding(param.first.data()).toStdString(), "=",
                                 QUrl::toPercentEncoding(param.second.data()).toStdString()).c_str());
    }
    QNetworkRequest request(url);
    request.setRawHeader("Authorization", fmt::format("{}{}", "Bearer ", _m_accessToken).data());
    request.setRawHeader("accept", "application/json");

    _m_nam->get(request);
}

std::string aQtmdb::getImageURL(std::string i_path, std::string i_size)
{
    return fmt::format("https://image.tmdb.org/t/p/{}{}", i_size, i_path);
}
