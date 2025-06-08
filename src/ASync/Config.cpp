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

tmdb::ASync::config::jobDept tmdb::ASync::config::getDept(const QString& dept_title, const QString& i_accessToken)
{
    auto jobs = getSupportedJobs(i_accessToken);
    for (const auto& job : jobs) {
        if (job.dept_name == dept_title) {
            return job;
        }
    }
    return tmdb::ASync::config::jobDept(); // Return an empty jobDept if not found
}

std::vector<tmdb::ASync::config::language> tmdb::ASync::config::getSupportedLanguages(const QString& i_accessToken)
{
    Qtmdb q(i_accessToken.toStdString());
    QJsonArray response = q.config_languages();
    std::vector<language> languages;
    for (const auto& item : response) {
        QJsonObject languageObj = item.toObject();
        language lang;
        lang.iso_639_1 = languageObj.value("iso_639_1").toString();
        lang.english_name = languageObj.value("english_name").toString();
        lang.native_name = languageObj.value("name").toString();
        languages.push_back(lang);
    }
    return languages;
}

tmdb::ASync::config::language tmdb::ASync::config::getLanguage(const QString& i_iso_639_1, const QString& i_accessToken)
{
    auto languages = getSupportedLanguages(i_accessToken);
    for (const auto& lang : languages) {
        if (lang.iso_639_1 == i_iso_639_1.toLower()) {
            return lang;
        }
    }
    return tmdb::ASync::config::language(); // Return an empty language if not found
}
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

QPixmap tmdb::ASync::config::getPixmapFromUrl(const QUrl& url) {
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
    return pixmap;
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