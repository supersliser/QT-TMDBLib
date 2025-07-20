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
    _m_requestInProgress = false;
    connect(_m_nam, &QNetworkAccessManager::finished, this, &aQtmdb::_received);
}

aQtmdb::~aQtmdb()
{
    // Clear the request queue to prevent any pending requests
    _m_requestQueue.clear();
    _m_requestInProgress = false;
    
    // The QNetworkAccessManager will be deleted automatically since it's a child of this object
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
        reply->deleteLater();
        _m_requestInProgress = false;
        _processNextRequest();
        return;
    }
    QByteArray response = reply->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
    if (jsonDoc.isNull())
    {
        qDebug() << "Error: Null Response";
        reply->deleteLater();
        _m_requestInProgress = false;
        _processNextRequest();
        return;
    }
    if (!jsonDoc.isObject())
    {
        QJsonArray jsonArray = jsonDoc.array();
        if (jsonArray.isEmpty())
        {
            qDebug() << "Error: Empty Response";
            reply->deleteLater();
            _m_requestInProgress = false;
            _processNextRequest();
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
            reply->deleteLater();
            _m_requestInProgress = false;
            _processNextRequest();
            return;
        }
        emit finishedLoadingData(&jsonObj);
        reply->deleteLater();
    }
    
    // Mark request as finished and process next queued request
    _m_requestInProgress = false;
    _processNextRequest();
}


void aQtmdb::_runGetRequest(std::string i_request, std::map<std::string, std::string> i_params)
{
    // Add request to queue
    RequestInfo requestInfo;
    requestInfo.request = i_request;
    requestInfo.params = i_params;
    _m_requestQueue.enqueue(requestInfo);
    
    // Process the request if no request is currently in progress
    if (!_m_requestInProgress)
    {
        _processNextRequest();
    }
}

void aQtmdb::_processNextRequest()
{
    // If queue is empty or a request is already in progress, do nothing
    if (_m_requestQueue.isEmpty() || _m_requestInProgress)
    {
        return;
    }
    
    // Get the next request from the queue
    RequestInfo requestInfo = _m_requestQueue.dequeue();
    _m_requestInProgress = true;
    
    emit startedLoadingData();

    QUrl url((fmt::format("{}{}", _m_baseUrl, requestInfo.request).data()));
    for (const auto& param : requestInfo.params)
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
