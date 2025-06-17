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

    std::vector<QString> getSupportedTranslations(const QString& i_accessToken);
    std::vector<QString> getSupportedTimezones(const QString& i_accessToken);

}


#endif //CONFIG_H
