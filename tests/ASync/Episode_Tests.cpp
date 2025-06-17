//
// Created by t on 31/05/25.
//

#include <QApplication>

#include "ASync/Episode.h"
#include <gtest/gtest.h>
#include "ASync/QTMDB.h"

using namespace tmdb::ASync::TV;

TEST(EpisodeASyncTests, DefaultConstructor)
{
    Episode episode;
    EXPECT_EQ(episode.id(), 0);
    EXPECT_STREQ(episode.name().toStdString().c_str(), "BLANK_NAME");
    EXPECT_STREQ(episode.overview().toStdString().c_str(), "BLANK_OVERVIEW");
    EXPECT_EQ(episode.episodeNumber(), 0);
    EXPECT_EQ(episode.seasonNumber(), 0);
    EXPECT_EQ(episode.voteAverage(), 0.0f);
    EXPECT_STREQ(episode.stillPath().toStdString().c_str(), "BLANK_STILL_PATH");
}

TEST(EpisodeASyncTests, APIGetter)
{
    bool f = false;
    Episode* episode = new Episode(std::getenv("API_KEY"));
    QObject::connect(episode, &Episode::finishedLoadingEpisode, [&f](Episode* episode)
    {
        EXPECT_EQ(episode->airDate(), QDate(2011, 4, 17));
        EXPECT_FALSE(episode->crew().empty());
        EXPECT_STREQ(episode->crew()[0]->name().toStdString().c_str(), "David Benioff");
        EXPECT_EQ(episode->episodeNumber(), 1);
        EXPECT_FALSE(episode->guestStars().empty());
        EXPECT_STREQ(episode->guestStars()[0]->name().toStdString().c_str(), "Joseph Mawle");
        EXPECT_STREQ(episode->name().toStdString().c_str(), "Winter Is Coming");
        EXPECT_STREQ(episode->overview().toStdString().c_str(),
                     "Jon Arryn, the Hand of the King, is dead. King Robert Baratheon plans to ask his oldest friend, Eddard Stark, to take Jon's place. Across the sea, Viserys Targaryen plans to wed his sister to a nomadic warlord in exchange for an army.");
        EXPECT_EQ(episode->id(), 63056);
        EXPECT_STREQ(episode->productionCode().toStdString().c_str(), "101");
        EXPECT_EQ(episode->runtime(), 62);
        EXPECT_EQ(episode->seasonNumber(), 1);
        EXPECT_STREQ(episode->stillPath().toStdString().c_str(), "/wrGWeW4WKxnaeA8sxJb2T9O6ryo.jpg");
        EXPECT_GT(episode->voteAverage(), 0.0f);
        EXPECT_GT(episode->voteCount(), 300);
        f = true;
    });
    episode->loadEpisode(1399, 1, 1);
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(EpisodeASyncTests, APIJSON)
{
    bool f = false;
    aQtmdb q(std::getenv("API_KEY"));
    QObject::connect(&q, &aQtmdb::finishedLoadingData, [&f](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        Episode* episode = new Episode(data, std::getenv("API_KEY"));
        EXPECT_EQ(episode->airDate(), QDate(2011, 4, 17));
        EXPECT_FALSE(episode->crew().empty());
        EXPECT_STREQ(episode->crew()[0]->name().toStdString().c_str(), "David Benioff");
        EXPECT_EQ(episode->episodeNumber(), 1);
        EXPECT_FALSE(episode->guestStars().empty());
        EXPECT_STREQ(episode->guestStars()[0]->name().toStdString().c_str(), "Joseph Mawle");
        EXPECT_STREQ(episode->name().toStdString().c_str(), "Winter Is Coming");
        EXPECT_STREQ(episode->overview().toStdString().c_str(),
                     "Jon Arryn, the Hand of the King, is dead. King Robert Baratheon plans to ask his oldest friend, Eddard Stark, to take Jon's place. Across the sea, Viserys Targaryen plans to wed his sister to a nomadic warlord in exchange for an army.");
        EXPECT_EQ(episode->id(), 63056);
        EXPECT_STREQ(episode->productionCode().toStdString().c_str(), "101");
        EXPECT_EQ(episode->runtime(), 62);
        EXPECT_EQ(episode->seasonNumber(), 1);
        EXPECT_STREQ(episode->stillPath().toStdString().c_str(), "/wrGWeW4WKxnaeA8sxJb2T9O6ryo.jpg");
        EXPECT_GT(episode->voteAverage(), 0.0f);
        EXPECT_GT(episode->voteCount(), 300);
        f = true;
    });
    q.tv_episodes_details(1399, 1, 1);
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(EpisodeASyncTests, APISeasonEpisodesGetter)
{
    bool f = false;
    Episode* episode = new Episode(std::getenv("API_KEY"));
    QObject::connect(episode, &Episode::finishedLoadingSeasonEpisodes, [&f](std::vector<Episode*> episodes)
    {
        EXPECT_EQ(episodes.size(), 10);
        EXPECT_EQ(episodes[0]->seasonNumber(), 1);
        EXPECT_STREQ(episodes[0]->name().toStdString().c_str(), "Winter Is Coming");
        f = true;
    });
    episode->loadEpisodesForSeason(1399, 1);
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(EpisodeASyncTests, setGetters)
{
    Episode e;
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
