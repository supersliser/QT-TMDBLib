//
// Created by t on 09/06/25.
//

#include "ASync/Image.h"

#include <QEventLoop>
#include <QNetworkReply>

void tmdb::ASync::Image::setPixmap(const QPixmap& i_pixmap)
{
    m_pixmap = i_pixmap;
}

void tmdb::ASync::Image::setPixmap(const QUrl& i_url)
{
    m_pixmap = getPixmapFromUrl(i_url);
}

QPixmap tmdb::ASync::Image::pixmap() const
{
    return m_pixmap;
}

QPixmap tmdb::ASync::Image::getPixmapFromUrl(const QUrl& url) {
    emit startedLoadingImage();
    QNetworkAccessManager manager;
    QNetworkReply* reply = manager.get(QNetworkRequest(url));
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QPixmap pixmap;
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
        pixmap.loadFromData(data);
    }
    reply->deleteLater();
    m_pixmap = pixmap;
    emit finishedLoadingImage(pixmap);
    return pixmap;
}

void tmdb::ASync::Image::loadImage(const QUrl& i_url)
{
    setPixmap(i_url);
}