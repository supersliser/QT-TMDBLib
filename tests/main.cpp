//
// Created by t on 20/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "../include/Sync/QTMDB.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(QtmdbTest, Constructor)
{
    Qtmdb qtmdb("test_token");
    EXPECT_EQ(qtmdb.accessToken(), "test_token");
}

TEST(QtmdbTest, SetAccessToken)
{
    Qtmdb qtmdb("test_token");
    qtmdb.setAccessToken("new_token");
    EXPECT_EQ(qtmdb.accessToken(), "new_token");
}