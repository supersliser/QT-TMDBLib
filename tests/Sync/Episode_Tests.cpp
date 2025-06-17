//
// Created by t on 31/05/25.
//

#include "Sync/Episode.h"
#include <gtest/gtest.h>
#include "Sync/QTMDB.h"

TEST(EpisodeSyncTests, DefaultConstructor)
{
    tmdb::TV::Episode episode;
    EXPECT_EQ(episode.id(), 0);
    EXPECT_TRUE(episode.name().isEmpty());
    EXPECT_TRUE(episode.overview().isEmpty());
    EXPECT_EQ(episode.episodeNumber(), 0);
    EXPECT_EQ(episode.seasonNumber(), 0);
    EXPECT_EQ(episode.voteAverage(), 0.0f);
    EXPECT_TRUE(episode.stillPath().isEmpty());
}

TEST(EpisodeSyncTests, ParameterizedConstructor)
{
    tmdb::TV::Episode episode(QDate(2023, 1, 1), {}, 1, {}, "Test Episode", "This is a test episode overview", 1, "code", 1, 1, "/path/to/still.jpg", 8.5f, 1 );
    EXPECT_EQ(episode.airDate(), QDate(2023, 1, 1));
    EXPECT_TRUE(episode.crew().empty());
    EXPECT_EQ(episode.episodeNumber(), 1);
    EXPECT_TRUE(episode.guestStars().empty());
    EXPECT_STREQ(episode.name().toStdString().c_str(), "Test Episode");
    EXPECT_STREQ(episode.overview().toStdString().c_str(), "This is a test episode overview");
    EXPECT_EQ(episode.id(), 1);
    EXPECT_STREQ(episode.productionCode().toStdString().c_str(), "code");
    EXPECT_EQ(episode.runtime(), 1);
    EXPECT_EQ(episode.seasonNumber(), 1);
    EXPECT_STREQ(episode.stillPath().toStdString().c_str(), "/path/to/still.jpg");
    EXPECT_FLOAT_EQ(episode.voteAverage(), 8.5f);
    EXPECT_EQ(episode.voteCount(), 1);
}

TEST(EpisodeSyncTests, APIConstructor)
{
    tmdb::TV::Episode episode(std::getenv("API_KEY"), 1399, 1, 1);
    EXPECT_EQ(episode.airDate(), QDate(2011, 4, 17));
    EXPECT_FALSE(episode.crew().empty());
    EXPECT_STREQ(episode.crew()[0].name().toStdString().c_str(), "David Benioff");
    EXPECT_EQ(episode.episodeNumber(), 1);
    EXPECT_FALSE(episode.guestStars().empty());
    EXPECT_STREQ(episode.guestStars()[0].name().toStdString().c_str(), "Joseph Mawle");
    EXPECT_STREQ(episode.name().toStdString().c_str(), "Winter Is Coming");
    EXPECT_STREQ(episode.overview().toStdString().c_str(), "Jon Arryn, the Hand of the King, is dead. King Robert Baratheon plans to ask his oldest friend, Eddard Stark, to take Jon's place. Across the sea, Viserys Targaryen plans to wed his sister to a nomadic warlord in exchange for an army.");
    EXPECT_EQ(episode.id(), 63056);
    EXPECT_STREQ(episode.productionCode().toStdString().c_str(), "101");
    EXPECT_EQ(episode.runtime(), 62);
    EXPECT_EQ(episode.seasonNumber(), 1);
    EXPECT_STREQ(episode.stillPath().toStdString().c_str(), "/wrGWeW4WKxnaeA8sxJb2T9O6ryo.jpg");
    EXPECT_GT(episode.voteAverage(), 0.0f);
    EXPECT_GT(episode.voteCount(), 300);
}

TEST(EpisodeSyncTests, APIJSON)
{
    Qtmdb q(std::getenv("API_KEY"));
    auto response = q.tv_episodes_details(1399, 1, 1);
    tmdb::TV::Episode episode(response);
    EXPECT_EQ(episode.airDate(), QDate(2011, 4, 17));
    EXPECT_FALSE(episode.crew().empty());
    EXPECT_STREQ(episode.crew()[0].name().toStdString().c_str(), "David Benioff");
    EXPECT_EQ(episode.episodeNumber(), 1);
    EXPECT_FALSE(episode.guestStars().empty());
    EXPECT_STREQ(episode.guestStars()[0].name().toStdString().c_str(), "Joseph Mawle");
    EXPECT_STREQ(episode.name().toStdString().c_str(), "Winter Is Coming");
    EXPECT_STREQ(episode.overview().toStdString().c_str(), "Jon Arryn, the Hand of the King, is dead. King Robert Baratheon plans to ask his oldest friend, Eddard Stark, to take Jon's place. Across the sea, Viserys Targaryen plans to wed his sister to a nomadic warlord in exchange for an army.");
    EXPECT_EQ(episode.id(), 63056);
    EXPECT_STREQ(episode.productionCode().toStdString().c_str(), "101");
    EXPECT_EQ(episode.runtime(), 62);
    EXPECT_EQ(episode.seasonNumber(), 1);
    EXPECT_STREQ(episode.stillPath().toStdString().c_str(), "/wrGWeW4WKxnaeA8sxJb2T9O6ryo.jpg");
    EXPECT_GT(episode.voteAverage(), 0.0f);
    EXPECT_GT(episode.voteCount(), 300);
}

TEST(EpisodeSyncTests, StaticConstructor)
{
    tmdb::TV::Episode episode = tmdb::TV::Episode::getEpisode(std::getenv("API_KEY"), 1399, 1, 1);
    EXPECT_EQ(episode.airDate(), QDate(2011, 4, 17));
    EXPECT_FALSE(episode.crew().empty());
    EXPECT_STREQ(episode.crew()[0].name().toStdString().c_str(), "David Benioff");
    EXPECT_EQ(episode.episodeNumber(), 1);
    EXPECT_FALSE(episode.guestStars().empty());
    EXPECT_STREQ(episode.guestStars()[0].name().toStdString().c_str(), "Joseph Mawle");
    EXPECT_STREQ(episode.name().toStdString().c_str(), "Winter Is Coming");
    EXPECT_STREQ(episode.overview().toStdString().c_str(), "Jon Arryn, the Hand of the King, is dead. King Robert Baratheon plans to ask his oldest friend, Eddard Stark, to take Jon's place. Across the sea, Viserys Targaryen plans to wed his sister to a nomadic warlord in exchange for an army.");
    EXPECT_EQ(episode.id(), 63056);
    EXPECT_STREQ(episode.productionCode().toStdString().c_str(), "101");
    EXPECT_EQ(episode.runtime(), 62);
    EXPECT_EQ(episode.seasonNumber(), 1);
    EXPECT_STREQ(episode.stillPath().toStdString().c_str(), "/wrGWeW4WKxnaeA8sxJb2T9O6ryo.jpg");
    EXPECT_GT(episode.voteAverage(), 0.0f);
    EXPECT_GT(episode.voteCount(), 300);
}

TEST(EpisodeSyncTests, setGetters)
{
    tmdb::TV::Episode e;
    e.setAirDate(QDate(2023, 1, 1));
    EXPECT_EQ(e.airDate(), QDate(2023, 1, 1));
    e.setCrew({});
    EXPECT_TRUE(e.crew().empty());
    e.setEpisodeNumber(2);
    EXPECT_EQ(e.episodeNumber(), 2);
    e.setGuestStars({});
    EXPECT_TRUE(e.guestStars().empty());
    e.setName("Test Episode");
    EXPECT_STREQ(e.name().toStdString().c_str(), "Test Episode");
    e.setOverview("This is a test episode overview");
    EXPECT_STREQ(e.overview().toStdString().c_str(), "This is a test episode overview");
    e.setId(3);
    EXPECT_EQ(e.id(), 3);
    e.setProductionCode("PC123");
    EXPECT_STREQ(e.productionCode().toStdString().c_str(), "PC123");
    e.setRuntime(45);
    EXPECT_EQ(e.runtime(), 45);
    e.setSeasonNumber(1);
    EXPECT_EQ(e.seasonNumber(), 1);
    e.setStillPath("/path/to/still.jpg");
    EXPECT_STREQ(e.stillPath().toStdString().c_str(), "/path/to/still.jpg");
    e.setVoteAverage(9.0f);
    EXPECT_FLOAT_EQ(e.voteAverage(), 9.0f);
    e.setVoteCount(100);
    EXPECT_EQ(e.voteCount(), 100);
}