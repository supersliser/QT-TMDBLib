//
// Created by t on 07/06/25.
//

#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "aQTMDB.h"

aQtmdb::aQtmdb(std::string i_accessToken, QObject* parent) : QObject(parent)
{
    _m_accessToken = i_accessToken;
}

std::string aQtmdb::accessToken()
{
    return _m_accessToken;
}

void aQtmdb::setAccessToken(std::string i_accessToken)
{
    _m_accessToken = i_accessToken;
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

    QNetworkAccessManager manager;
    QNetworkRequest request(url);
    request.setRawHeader("Authorization", fmt::format("{}{}", "Bearer ", _m_accessToken).data());
    request.setRawHeader("accept", "application/json");

    QNetworkReply* reply = manager.get(request);
    auto lambda = [this, reply]()
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
        QJsonObject jsonObj = jsonDoc.object();
        if (jsonObj.isEmpty())
        {
            qDebug() << "Error: Empty Response";
            return;
        }
        emit finishedLoadingData(&jsonObj);
        QJsonObject data = jsonObj;

        reply->deleteLater();
        emit finishedLoadingData(&data);
    };
    connect(reply, &QNetworkReply::finished, lambda);
}
std::string aQtmdb::getImageURL(std::string i_path, std::string i_size)
{
    return fmt::format("https://image.tmdb.org/t/p/{}{}", i_size, i_path);
}