//
// Created by t on 22/05/25.
//

#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include <gtest/gtest.h>
#include "ASync/QTMDB.h"

TEST(aQtmdb_JSON_TV_Series_Test, airingToday)
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
    aQtmdb.tv_series_airingToday();
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_TV_Series_Test, onTheAir)
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
    aQtmdb.tv_series_onTheAir();
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_TV_Series_Test, popular)
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
    aQtmdb.tv_series_popular();
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_TV_Series_Test, topRated)
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
    aQtmdb.tv_series_topRated();
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_TV_Series_Test, details)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("name").toString().toStdString().c_str(), "Game of Thrones");
        finished = true;
    });
    aQtmdb.tv_series_details(1399);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_TV_Series_Test, aggregateCredits)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("cast").isArray());
        finished = true;
    });
    aQtmdb.tv_series_aggregateCredits(1399);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_TV_Series_Test, alternativeTitles)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("results").toArray()[0].toObject().value("iso_3166_1").toString().toStdString().c_str(),
                     "AL");
        finished = true;
    });
    aQtmdb.tv_series_alternativeTitles(1399);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_TV_Series_Test, changes)
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
    aQtmdb.tv_series_changes(1399);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_TV_Series_Test, contentRatings)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("results").toArray()[0].toObject().value("iso_3166_1").toString().toStdString().c_str(),
                     "FR");
        finished = true;
    });
    aQtmdb.tv_series_contentRatings(1399);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_TV_Series_Test, credits)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("cast").isArray());
        finished = true;
    });
    aQtmdb.tv_series_credits(1399);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_TV_Series_Test, episodeGroups)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("results").toArray()[0].toObject().value("name").toString().toStdString().c_str(),
                     "Aired Order");
        finished = true;
    });
    aQtmdb.tv_series_episodeGroups(1399);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_TV_Series_Test, externalIDs)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("facebook_id").toString().toStdString().c_str(), "GameOfThrones");
        finished = true;
    });
    aQtmdb.tv_series_externalIDs(1399);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_TV_Series_Test, images)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("backdrops").toArray()[0].toObject().value("width"), 3840);
        finished = true;
    });
    aQtmdb.tv_series_images(1399, "en");
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_TV_Series_Test, keywords)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(data.value("results").toArray()[0].toObject().value("id"), 818);
        finished = true;
    });
    aQtmdb.tv_series_keywords(1399);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_TV_Series_Test, latest)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("name").isString());
        finished = true;
    });
    aQtmdb.tv_series_latest();
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_TV_Series_Test, lists)
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
    aQtmdb.tv_series_lists(1399);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_TV_Series_Test, recommendations)
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
    aQtmdb.tv_series_recommendations(1399);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_TV_Series_Test, reviews)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("results").toArray()[0].toObject().value("author").toString().toStdString().c_str(),
                     "lmao7");
        finished = true;
    });
    aQtmdb.tv_series_reviews(1399);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_TV_Series_Test, screenedTheatrically)
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
    aQtmdb.tv_series_screenedTheatrically(1399);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_TV_Series_Test, similar)
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
    aQtmdb.tv_series_similar(1399);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_TV_Series_Test, translations)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_TRUE(data.value("translations").isArray());
        finished = true;
    });
    aQtmdb.tv_series_translations(1399);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_TV_Series_Test, videos)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_STREQ(data.value("results").toArray()[0].toObject().value("type").toString().toStdString().c_str(),
                     "Trailer");
        finished = true;
    });
    aQtmdb.tv_series_videos(1399);
    while (!finished)
    {
        QApplication::processEvents();
    }
}

TEST(aQtmdb_JSON_TV_Series_Test, watchProviders)
{
    bool finished = false;
    aQtmdb aQtmdb(std::getenv("API_KEY"));
    QObject::connect(&aQtmdb, &aQtmdb::finishedLoadingData, [&finished](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        EXPECT_EQ(
            data.value("results").toObject().value("GB").toObject().value("flatrate").toArray()[0].toObject().value(
                "provider_id").toInt(), 39);
        finished = true;
    });
    aQtmdb.tv_series_watchProviders(1399);
    while (!finished)
    {
        QApplication::processEvents();
    }
}
