//
// Created by t on 20/05/25.
//

#include <QJsonObject>
#include <QApplication>
#include <gtest/gtest.h>
#include "QTMDB.h"

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

TEST(QtmdbTest, RunRequest)
{
    Qtmdb qtmdb("eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJmZWZjMDcwYTExNTZlZDExM2JjN2RhZDA1ZWM5OWMyOCIsIm5iZiI6MTc0Nzc2ODM5Mi44MDgsInN1YiI6IjY4MmNkNDQ4ODA2OTJiYWI1NTY0OTRiYyIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.4wbjpPC366q5YFsHnuo9g4bIQ2xgMB5hIHx84SejLMg");
    QJsonObject response = qtmdb.account_details(1);
    EXPECT_FALSE(response.isEmpty());
    EXPECT_TRUE(response.contains("id"));
}