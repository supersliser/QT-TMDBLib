//
// Created by t on 26/05/25.
//

#include "Sync/Config.h"

#include <QJsonArray>
#include <QJsonObject>

#include "Sync/QTMDB.h"
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


std::vector<tmdb::config::country> tmdb::config::getSupportedCountries(const QString& i_accessToken)
{
    Qtmdb q(i_accessToken.toStdString());
    QJsonArray response = q.config_countries();
    std::vector<country> countries;
    for (const auto& item : response) {
        QJsonObject countryObj = item.toObject();
        country country;
        country.native_name = countryObj.value("native_name").toString();
        country.english_name = countryObj.value("english_name").toString();
        country.iso_3166_1 = countryObj.value("iso_3166_1").toString();
        countries.push_back(country);
    }
    return countries;
}

tmdb::config::country tmdb::config::getCountry(const QString& country_code, const QString& i_accessToken)
{
    auto countries = getSupportedCountries(i_accessToken);
    for (const auto& country : countries) {
        if (country.iso_3166_1 == country_code) {
            return country;
        }
    }
    return tmdb::config::country(); // Return an empty country if not found
}

tmdb::config::country tmdb::config::getCountry(const QJsonObject& i_json)
{
    country country;
    country.native_name = i_json.value("native_name").toString();
    country.english_name = i_json.value("english_name").toString();
    country.iso_3166_1 = i_json.value("iso_3166_1").toString();
    return country;
}

std::vector<tmdb::config::jobDept> tmdb::config::getSupportedJobs(const QString& i_accessToken)
{
    Qtmdb q(i_accessToken.toStdString());
    QJsonArray response = q.config_jobs();
    std::vector<tmdb::config::jobDept> jobs;
    for (const auto& item : response) {
        QJsonObject jobObj = item.toObject();
        tmdb::config::jobDept jobDept;
        jobDept.dept_name = jobObj.value("department").toString();
        QJsonArray jobTitlesArray = jobObj.value("jobs").toArray();
        for (const auto& title : jobTitlesArray) {
            jobDept.job_titles.push_back(title.toString());
        }
        jobs.push_back(jobDept);
    }
    return jobs;
}

tmdb::config::jobDept tmdb::config::getDept(const QString& dept_title, const QString& i_accessToken)
{
    auto jobs = getSupportedJobs(i_accessToken);
    for (const auto& job : jobs) {
        if (job.dept_name == dept_title) {
            return job;
        }
    }
    return tmdb::config::jobDept(); // Return an empty jobDept if not found
}

std::vector<tmdb::config::language> tmdb::config::getSupportedLanguages(const QString& i_accessToken)
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

tmdb::config::language tmdb::config::getLanguage(const QString& i_iso_639_1, const QString& i_accessToken)
{
    auto languages = getSupportedLanguages(i_accessToken);
    for (const auto& lang : languages) {
        if (lang.iso_639_1 == i_iso_639_1.toLower()) {
            return lang;
        }
    }
    return tmdb::config::language(); // Return an empty language if not found
}
std::vector<QString> tmdb::config::getSupportedTranslations(const QString& i_accessToken)
{
    Qtmdb q(i_accessToken.toStdString());
    QJsonArray response = q.config_primaryTranslations();
    std::vector<QString> translations;
    for (const auto& item : response) {
        translations.push_back(item.toString());
    }
    return translations;
}

std::vector<QString> tmdb::config::getSupportedTimezones(const QString& i_accessToken)
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

QPixmap tmdb::config::getPixmapFromUrl(const QUrl& url) {
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

std::vector<tmdb::config::LinkInfo> tmdb::config::extractLinksFromUrl(const QUrl& url) {
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