//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "ASync/QTMDB.h"

TEST(aQtmdb_JSON_Movie_Test, details)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("title").toString().toStdString().c_str(), "Fight Club");
        finished = true;
    });
    aQtmdb.movie_details(550);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Movie_Test, alternativeTitles)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("titles").toArray()[0].toObject()["iso_3166_1"].toString().toStdString().c_str(), "IL");
        finished = true;
    });
    aQtmdb.movie_alternativeTitles(550);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Movie_Test, changes)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("changes").isArray());
        finished = true;
    });
    aQtmdb.movie_changes(550, QDate(2025, 05, 19), QDate(2025, 05, 20));
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Movie_Test, credits)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("cast").toArray()[0].toObject().value("name").toString().toStdString().c_str(),
                     "Edward Norton");
        finished = true;
    });
    aQtmdb.movie_credits(550);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Movie_Test, externalIDs)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("imdb_id").toString().toStdString().c_str(), "tt0137523");
        finished = true;
    });
    aQtmdb.movie_externalIDs(550);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Movie_Test, images)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("backdrops").toArray()[0].toObject().value("width").toInt(), 1920);
        finished = true;
    });
    aQtmdb.movie_images(550, "en");
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Movie_Test, keywords)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("keywords").toArray()[0].toObject().value("name").toString().toStdString().c_str(),
                     "dual identity");
        finished = true;
    });
    aQtmdb.movie_keywords(550);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Movie_Test, latest)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("adult").isBool());
        finished = true;
    });
    aQtmdb.movie_latest();
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Movie_Test, lists)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("results").isArray());
        finished = true;
    });
    aQtmdb.movie_lists(550);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Movie_Test, recommendations)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("results").toArray()[0].toObject().value("title").toString().toStdString().c_str(),
                     "Pulp Fiction");
        finished = true;
    });
    aQtmdb.movie_recommendations(550);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Movie_Test, releaseDates)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(
            data.value("results").toArray()[0].toObject().value("release_dates").toArray()[0].toObject().value("note").
            toString().toStdString().c_str(), "Blu-ray");
        finished = true;
    });
    aQtmdb.movie_releaseDates(550);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Movie_Test, reviews)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("results").toArray()[0].toObject().value("author").toString().toStdString().c_str(),
                     "Goddard");
        finished = true;
    });
    aQtmdb.movie_reviews(550, "en-GB");
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Movie_Test, similar)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("results").toArray()[0].isObject());
        finished = true;
    });
    aQtmdb.movie_similar(550, "en-GB");
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Movie_Test, translations)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(
            data.value("translations").toArray()[0].toObject().value("iso_639_1").toString().toStdString().c_str(),
            "en");
        finished = true;
    });
    aQtmdb.movie_translations(550);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Movie_Test, videos)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("results").toArray()[0].toObject()["iso_639_1"].toString().toStdString().c_str(), "en");
        finished = true;
    });
    aQtmdb.movie_videos(550, "en-GB");
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_Movie_Test, watchProviders)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(
            data.value("results").toObject().value("GB").toObject().value("flatrate").toArray()[0].toObject().value(
                "provider_name").toString().toStdString().c_str(), "Disney Plus");
        finished = true;
    });
    aQtmdb.movie_watchProviders(550);
    while (!finished)
    {
        QApplication::processEvents();
    }
}
