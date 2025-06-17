//
// Created by t on 31/05/25.
//

#include <QJsonObject>

#include "Sync/Season.h"
#include <gtest/gtest.h>

#include "Sync/QTMDB.h"

TEST(SeasonSyncTests, DefaultConstructor)
{
    tmdb::TV::Season season;
    EXPECT_EQ(season.id(), 0);
    EXPECT_TRUE(season.name().isEmpty());
    EXPECT_TRUE(season.overview().isEmpty());
    EXPECT_EQ(season.seasonNumber(), 0);
    EXPECT_EQ(season.voteAverage(), 0.0f);
    EXPECT_TRUE(season.posterPath().isEmpty());
}

TEST(SeasonSyncTests, ParameterizedConstructor)
{
    tmdb::TV::Season season(QDate(2023, 1, 1), {}, "Test Season", "This is a test season overview", 1, "/path/to/poster.jpg", 1, 8.5f);
    EXPECT_EQ(season.id(), 1);
    EXPECT_STREQ(season.name().toStdString().c_str(), "Test Season");
    EXPECT_STREQ(season.overview().toStdString().c_str(), "This is a test season overview");
    EXPECT_EQ(season.seasonNumber(), 1);
    EXPECT_FLOAT_EQ(season.voteAverage(), 8.5f);
    EXPECT_STREQ(season.posterPath().toStdString().c_str(), "/path/to/poster.jpg");
}

TEST(SeasonSyncTests, APIConstructor)
{
    tmdb::TV::Season season(std::getenv("API_KEY"), 1399, 1);
    EXPECT_EQ(season.id(), 3624); // Assuming the season ID is 1 for the test series
    EXPECT_STREQ(season.name().toStdString().c_str(), "Season 1");
    EXPECT_STREQ(season.overview().toStdString().c_str(), "Trouble is brewing in the Seven Kingdoms of Westeros. For the driven inhabitants of this visionary world, control of Westeros' Iron Throne holds the lure of great power. But in a land where the seasons can last a lifetime, winter is coming...and beyond the Great Wall that protects them, an ancient evil has returned. In Season One, the story centers on three primary areas: the Stark and the Lannister families, whose designs on controlling the throne threaten a tenuous peace; the dragon princess Daenerys, heir to the former dynasty, who waits just over the Narrow Sea with her malevolent brother Viserys; and the Great Wall--a massive barrier of ice where a forgotten danger is stirring.");
    EXPECT_EQ(season.seasonNumber(), 1);
    EXPECT_GT(season.voteAverage(), 0.0f);
    EXPECT_STREQ(season.posterPath().toStdString().c_str(), "/wgfKiqzuMrFIkU1M68DDDY8kGC1.jpg");
}

TEST(SeasonSyncTests, APIJSON)
{
    Qtmdb q(std::getenv("API_KEY"));
    auto response = q.tv_seasons_details(1399, 1);
    tmdb::TV::Season s(response);
    EXPECT_EQ(s.id(), 3624); // Assuming the season ID is 1 for the test series
    EXPECT_STREQ(s.name().toStdString().c_str(), "Season 1");
    EXPECT_STREQ(s.overview().toStdString().c_str(), "Trouble is brewing in the Seven Kingdoms of Westeros. For the driven inhabitants of this visionary world, control of Westeros' Iron Throne holds the lure of great power. But in a land where the seasons can last a lifetime, winter is coming...and beyond the Great Wall that protects them, an ancient evil has returned. In Season One, the story centers on three primary areas: the Stark and the Lannister families, whose designs on controlling the throne threaten a tenuous peace; the dragon princess Daenerys, heir to the former dynasty, who waits just over the Narrow Sea with her malevolent brother Viserys; and the Great Wall--a massive barrier of ice where a forgotten danger is stirring.");
    EXPECT_EQ(s.seasonNumber(), 1);
    EXPECT_GT(s.voteAverage(), 0.0f);
    EXPECT_STREQ(s.posterPath().toStdString().c_str(), "/wgfKiqzuMrFIkU1M68DDDY8kGC1.jpg");
}

TEST(SeasonSyncTests, StaticConstructor)
{
    tmdb::TV::Season season = tmdb::TV::Season::getSeason(std::getenv("API_KEY"), 1399, 1);
    EXPECT_EQ(season.id(), 3624); // Assuming the season ID is 1 for the test series
    EXPECT_STREQ(season.name().toStdString().c_str(), "Season 1");
    EXPECT_STREQ(season.overview().toStdString().c_str(), "Trouble is brewing in the Seven Kingdoms of Westeros. For the driven inhabitants of this visionary world, control of Westeros' Iron Throne holds the lure of great power. But in a land where the seasons can last a lifetime, winter is coming...and beyond the Great Wall that protects them, an ancient evil has returned. In Season One, the story centers on three primary areas: the Stark and the Lannister families, whose designs on controlling the throne threaten a tenuous peace; the dragon princess Daenerys, heir to the former dynasty, who waits just over the Narrow Sea with her malevolent brother Viserys; and the Great Wall--a massive barrier of ice where a forgotten danger is stirring.");
    EXPECT_EQ(season.seasonNumber(), 1);
    EXPECT_GT(season.voteAverage(), 0.0f);
    EXPECT_STREQ(season.posterPath().toStdString().c_str(), "/wgfKiqzuMrFIkU1M68DDDY8kGC1.jpg");
}

TEST(SeasonSyncTests, setGetters)
{
    tmdb::TV::Season s;
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