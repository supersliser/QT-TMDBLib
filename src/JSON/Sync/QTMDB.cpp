#include "QTMDB.h"
#include <QApplication>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonArray>

Qtmdb::Qtmdb(std::string i_accessToken, QObject* parent) : QObject(parent)
{
    _m_accessToken = i_accessToken;
}

std::string Qtmdb::accessToken()
{
    return _m_accessToken;
}

void Qtmdb::setAccessToken(std::string i_accessToken)
{
    _m_accessToken = i_accessToken;
}

QJsonObject Qtmdb::_runGetRequest(std::string i_request, std::map<std::string, std::string> i_params)
{
    QUrl url((fmt::format("{}{}", _m_baseUrl, i_request).data()));
        for (const auto& param : i_params)
        {
            url.setQuery(fmt::format("{}{}{}{}{}",url.query().toStdString(), "&", QUrl::toPercentEncoding(param.first.data()).toStdString(), "=", QUrl::toPercentEncoding(param.second.data()).toStdString()).c_str());
        }
    QNetworkAccessManager manager;
    QNetworkRequest request(url);
    request.setRawHeader("Authorization", fmt::format("{}{}", "Bearer ", _m_accessToken).data());
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

QJsonArray Qtmdb::_runGetRequestArray(std::string i_request, std::map<std::string, std::string> i_params)
{
    QUrl url((fmt::format("{}{}", _m_baseUrl, i_request).data()));
    for (const auto& param : i_params)
    {
        url.setQuery(fmt::format("{}{}{}{}",url.query().toStdString(), QUrl::toPercentEncoding(param.first.data()).toStdString(), "=", QUrl::toPercentEncoding(param.second.data()).toStdString()).c_str());
    }
    QNetworkAccessManager manager;
    QNetworkRequest request(url);
    request.setRawHeader("Authorization", fmt::format("{}{}", "Bearer ", _m_accessToken).data());
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
    QJsonArray jsonObj = jsonDoc.array();
    if (jsonObj.isEmpty())
    {
        qDebug() << "Error: Empty Response" ;
        return {};
    }
    return jsonObj;
}

std::string Qtmdb::getImageURL(std::string i_path, std::string i_size)
{
    return fmt::format("https://image.tmdb.org/t/p/{}{}", i_size, i_path);
}