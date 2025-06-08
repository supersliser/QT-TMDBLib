//
// Created by t on 26/05/25.
//

#ifndef ASYNC_CONFIG_H
#define ASYNC_CONFIG_H

#include <QJsonObject>
#include <QString>
#include <vector>

#include "QTMDB.h"

namespace tmdb::ASync::config
{




    struct LinkInfo {
        QString href;
        QString title;
    };
    std::vector<LinkInfo> extractLinksFromUrl(const QUrl& url);

    struct jobDept
    {
        QString dept_name;
        std::vector<QString> job_titles;
    };
    std::vector<jobDept> getSupportedJobs(const QString& i_accessToken);
    jobDept getDept(const QString& dept_title, const QString& i_accessToken);
    struct language
    {
        QString iso_639_1;
        QString english_name;
        QString native_name;
        language() = default;
    };
    std::vector<language> getSupportedLanguages(const QString& i_accessToken);
    language getLanguage(const QString& i_iso_639_1, const QString& i_accessToken);
    std::vector<QString> getSupportedTranslations(const QString& i_accessToken);
    std::vector<QString> getSupportedTimezones(const QString& i_accessToken);

    QPixmap getPixmapFromUrl(const QUrl& url);
}


#endif //CONFIG_H
