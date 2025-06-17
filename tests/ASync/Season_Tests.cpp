//
// Created by t on 31/05/25.
//

#include <QApplication>
#include <QJsonObject>

#include "ASync/Season.h"
#include <gtest/gtest.h>

#include "ASync/QTMDB.h"

using namespace tmdb::ASync::TV;

TEST(SeasonASyncTests, DefaultConstructor)
{
    Season season;
    EXPECT_EQ(season.id(), 0);
    EXPECT_STREQ(season.name().toStdString().c_str(), "BLANK_NAME");
    EXPECT_STREQ(season.overview().toStdString().c_str(), "BLANK_OVERVIEW");
    EXPECT_EQ(season.seasonNumber(), 0);
    EXPECT_EQ(season.voteAverage(), 0.0f);
    EXPECT_STREQ(season.posterPath().toStdString().c_str(), "BLANK_POSTER_PATH");
}

TEST(SeasonASyncTests, APIConstructor)
{
    Season* season = new Season(std::getenv("API_KEY"));
    bool f = false;
    QObject::connect(season, &Season::finishedLoadingSeason, [&f](Season* s) {
        EXPECT_EQ(s->id(), 3624); // Assuming the season ID is 1 for the test series
        EXPECT_STREQ(s->name().toStdString().c_str(), "Season 1");
        EXPECT_STREQ(s->overview().toStdString().c_str(), "Trouble is brewing in the Seven Kingdoms of Westeros. For the driven inhabitants of this visionary world, control of Westeros' Iron Throne holds the lure of great power. But in a land where the seasons can last a lifetime, winter is coming...and beyond the Great Wall that protects them, an ancient evil has returned. In Season One, the story centers on three primary areas: the Stark and the Lannister families, whose designs on controlling the throne threaten a tenuous peace; the dragon princess Daenerys, heir to the former dynasty, who waits just over the Narrow Sea with her malevolent brother Viserys; and the Great Wall--a massive barrier of ice where a forgotten danger is stirring.");
        EXPECT_EQ(s->seasonNumber(), 1);
        EXPECT_GT(s->voteAverage(), 0.0f);
        EXPECT_STREQ(s->posterPath().toStdString().c_str(), "/wgfKiqzuMrFIkU1M68DDDY8kGC1.jpg");
        f = true;
    });
    season->loadSeason(1399, 1);
    while (!f)
    {
        QApplication::processEvents();
    }
}


TEST(SeasonASyncTests, APIJSON)
{
    bool f = false;
    aQtmdb q(std::getenv("API_KEY"));
    QObject::connect(&q, &aQtmdb::finishedLoadingData, [&f](void* response) {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        Season* season = new Season(data, std::getenv("API_KEY"));
        EXPECT_EQ(season->id(), 3624); // Assuming the season ID is 1 for the test series
        EXPECT_STREQ(season->name().toStdString().c_str(), "Season 1");
        EXPECT_STREQ(season->overview().toStdString().c_str(), "Trouble is brewing in the Seven Kingdoms of Westeros. For the driven inhabitants of this visionary world, control of Westeros' Iron Throne holds the lure of great power. But in a land where the seasons can last a lifetime, winter is coming...and beyond the Great Wall that protects them, an ancient evil has returned. In Season One, the story centers on three primary areas: the Stark and the Lannister families, whose designs on controlling the throne threaten a tenuous peace; the dragon princess Daenerys, heir to the former dynasty, who waits just over the Narrow Sea with her malevolent brother Viserys; and the Great Wall--a massive barrier of ice where a forgotten danger is stirring.");
        EXPECT_EQ(season->seasonNumber(), 1);
        EXPECT_GT(season->voteAverage(), 0.0f);
        EXPECT_STREQ(season->posterPath().toStdString().c_str(), "/wgfKiqzuMrFIkU1M68DDDY8kGC1.jpg");
        f = true;
    });
    q.tv_seasons_details(1399, 1);
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(SeasonASyncTests, setGetters)
{
    Season s;
    s.setAirDate(QDate(2023, 1, 1));
    EXPECT_EQ(s.airDate(), QDate(2023, 1, 1));
    s.setName("Test Season");
    EXPECT_STREQ(s.name().toStdString().c_str(), "Test Season");
    s.setOverview("This is a test season overview");
    EXPECT_STREQ(s.overview().toStdString().c_str(), "This is a test season overview");
    s.setId(1);
    EXPECT_EQ(s.id(), 1);
    s.setPosterPath("/path/to/poster.jpg");
    EXPECT_STREQ(s.posterPath().toStdString().c_str(), "/path/to/poster.jpg");
    s.setSeasonNumber(1);
    EXPECT_EQ(s.seasonNumber(), 1);
    s.setVoteAverage(8.5f);
    EXPECT_FLOAT_EQ(s.voteAverage(), 8.5f);
}

TEST(SeasonASyncTests, LoadEpisodesForSeason)
{
    Season* season = new Season(std::getenv("API_KEY"));
    bool f = false;
    QObject::connect(season, &Season::finishedLoadingSeasonEpisodes, [&f](std::vector<Episode*> episodes) {
        EXPECT_FALSE(episodes.empty());
        EXPECT_EQ(episodes.size(), 10);
        f = true;
    });
    season->loadEpisodesForSeason(1399, 1);
    while (!f)
    {
        QApplication::processEvents();
    }
}