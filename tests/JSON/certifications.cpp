//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "QTMDB.h"

TEST(Qtmdb_JSON_Certifications_Test, movie)
{
    Qtmdb qtmdb("eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJmZWZjMDcwYTExNTZlZDExM2JjN2RhZDA1ZWM5OWMyOCIsIm5iZiI6MTc0Nzc2ODM5Mi44MDgsInN1YiI6IjY4MmNkNDQ4ODA2OTJiYWI1NTY0OTRiYyIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.4wbjpPC366q5YFsHnuo9g4bIQ2xgMB5hIHx84SejLMg");
    QJsonObject response = qtmdb.certifications_movie();
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("certifications").toObject().value("GB").toArray()[0].toObject().value("certification").toString().toStdString().c_str(), "15");
}

TEST(Qtmdb_JSON_Certifications_Test, tv)
{
    Qtmdb qtmdb("eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJmZWZjMDcwYTExNTZlZDExM2JjN2RhZDA1ZWM5OWMyOCIsIm5iZiI6MTc0Nzc2ODM5Mi44MDgsInN1YiI6IjY4MmNkNDQ4ODA2OTJiYWI1NTY0OTRiYyIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.4wbjpPC366q5YFsHnuo9g4bIQ2xgMB5hIHx84SejLMg");
    QJsonObject response = qtmdb.certifications_tv();
    EXPECT_FALSE(response.isEmpty());
    EXPECT_STREQ(response.value("certifications").toObject().value("GB").toArray()[0].toObject().value("certification").toString().toStdString().c_str(), "U");
}