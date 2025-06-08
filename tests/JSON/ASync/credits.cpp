//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "Async/QTMDB.h"

TEST(aQtmdb_JSON_Credits_Test, details)
{
    aQtmdb qtmdb(std::getenv("API_KEY"));
    qtmdb.credits_details("6024a814c0ae36003d59cc3c");
    QObject::connect(&qtmdb, &aQtmdb::finishedLoadingData, [&qtmdb](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("job").toString().toStdString().c_str(), "Actor");
    });
}
