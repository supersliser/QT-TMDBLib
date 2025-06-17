//
// Created by t on 26/05/25.
//

#include "ASync/Config.h"

#include <QJsonArray>
#include <QJsonObject>

#include "ASync/QTMDB.h"
#include <QPixmap>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QRegularExpression>
#include <QEventLoop>
#include <QStringList>
#include <QUrl>
#include <QXmlStreamReader>
#include <QTextDocument>
#include <QTextBlock>
#include <QTextFragment>
#include <QTextCursor>

#include "Sync/QTMDB.h"


std::vector<QString> tmdb::ASync::config::getSupportedTranslations(const QString& i_accessToken)
{
    Qtmdb q(i_accessToken.toStdString());
    QJsonArray response = q.config_primaryTranslations();
    std::vector<QString> translations;
    for (const auto& item : response) {
        translations.push_back(item.toString());
    }
    return translations;
}

std::vector<QString> tmdb::ASync::config::getSupportedTimezones(const QString& i_accessToken)
{
    Qtmdb q(i_accessToken.toStdString());
    QJsonArray response = q.config_timezones();
    std::vector<QString> timezones;
    for (const auto& item : response) {
        QJsonArray timezoneObj = item.toObject().value("zones").toArray();
        for (const auto& zone : timezoneObj) {
            bool contains = false;
            for (const auto& existing : timezones) {
                if (existing == zone.toString()) {
                    contains = true;
                    break;
                }
            }
            if (!contains) {
                timezones.push_back(zone.toString());
            }
        }
    }
    return timezones;
}

std::vector<tmdb::ASync::config::LinkInfo> tmdb::ASync::config::extractLinksFromUrl(const QUrl& url) {
    QNetworkAccessManager manager;
    QEventLoop loop;
    QNetworkReply* reply = manager.get(QNetworkRequest(url));
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    std::vector<LinkInfo> links;
    if (reply->error() == QNetworkReply::NoError) {
        QString html = reply->readAll();
        QRegularExpression re(R"(<a\s+[^>]*href\s*=\s*['"]([^'"]+)['"][^>]*title\s*=\s*['"]([^'"]*)['"][^>]*>)", QRegularExpression::CaseInsensitiveOption);
        QRegularExpressionMatchIterator i = re.globalMatch(html);
        while (i.hasNext()) {
            QRegularExpressionMatch match = i.next();
            QString href = match.captured(1);
            QString title = match.captured(2);
            links.push_back({href, title});
        }
    }
    reply->deleteLater();
    return links;
}