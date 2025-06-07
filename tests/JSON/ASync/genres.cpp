//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "aQTMDB.h"

TEST(aaQtmdb_JSON_Genres_Test, movie)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.genres_movie();
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("genres").toArray()[0].toObject().value("name").toString().toStdString().c_str(),
                     "Action");
    });
}

TEST(aQtmdb_JSON_Genres_Test, tv)
{
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    aQtmdb.genres_tv();
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&aQtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("genres").toArray()[0].toObject().value("name").toString().toStdString().c_str(),
                     "Action & Adventure");
    });
}
