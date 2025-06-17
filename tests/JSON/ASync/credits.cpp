//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "ASync/QTMDB.h"

TEST(aQtmdb_JSON_Credits_Test, details)
{
    bool finished = false;
    aQtmdb qtmdb(std::getenv("API_KEY"));
    QObject::connect(&qtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("job").toString().toStdString().c_str(), "Actor");
        finished = true;
    });
    qtmdb.credits_details("6024a814c0ae36003d59cc3c");
    while (!finished)
    {
        QApplication::processEvents();
    }
}
