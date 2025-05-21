#include "QTMDB.h"
#include <QApplication>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

Qtmdb::Qtmdb(std::string_view i_accessToken, QObject* parent) : QObject(parent)
{
    _m_accessToken = i_accessToken;
}

std::string_view Qtmdb::accessToken()
{
    return _m_accessToken;
}

void Qtmdb::setAccessToken(std::string_view i_accessToken)
{
    _m_accessToken = i_accessToken;
}

QJsonObject Qtmdb::_runGetRequest(std::string_view i_request, std::map<std::string_view, std::string_view> i_params)
{
    QUrl url(_m_baseUrl + i_request.data());
        for (const auto& param : i_params)
        {
            url.setQuery(url.query() + QUrl::toPercentEncoding(param.first.data()) + "=" + QUrl::toPercentEncoding(param.second.data()));
        }
    QNetworkAccessManager manager;
    QNetworkRequest request(url);
    request.setRawHeader("Authorization", ("Bearer " + _m_accessToken).data());
    request.setRawHeader("accept", "application/json");
    QNetworkReply* reply = manager.get(request);
    while (!reply->isFinished())
    {
        QCoreApplication::processEvents();
    }
    if (reply->error() != QNetworkReply::NoError)
    {
        qDebug() << "Error: " << reply->errorString();
        return {};
    }
    QByteArray response = reply->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
    if (jsonDoc.isNull())
    {
        qDebug() << "Error: Null Response" ;
        return {};
    }
    QJsonObject jsonObj = jsonDoc.object();
    if (jsonObj.isEmpty())
    {
        qDebug() << "Error: Empty Response" ;
        return {};
    }
    return jsonObj;
}