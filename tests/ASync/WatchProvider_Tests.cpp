//
// Created by t on 28/05/25.
//

#include "ASync/WatchProvider.h"
#include "ASync/QTMDB.h"
#include <gtest/gtest.h>

#include <QApplication>

using namespace tmdb::ASync;

TEST(WatchProviderASyncTests, DefaultConstructor)
{
    WatchProvider provider;
    EXPECT_EQ(provider.type(), unset);
    EXPECT_STREQ(provider.logoPath().toStdString().c_str(), "");
    EXPECT_EQ(provider.providerID(), 0);
    EXPECT_STREQ(provider.providerName().toStdString().c_str(), "");
    EXPECT_TRUE(provider.link().isEmpty());
}

TEST(WatchProviderASyncTests, APIConstructor)
{
    bool f = false;
    WatchProvider provider(
        std::getenv("API_KEY"));
    QObject::connect(&provider, &WatchProvider::finishedLoadingWatchProvider, [&f](WatchProvider* p)
    {
        EXPECT_EQ(p->type(), unset);
        EXPECT_STREQ(p->logoPath().toStdString().c_str(), "/pbpMk2JmcoNnQwx5JGpXngfoWtp.jpg");
        EXPECT_EQ(p->providerID(), 8);
        EXPECT_STREQ(p->providerName().toStdString().c_str(), "Netflix");
        EXPECT_TRUE(p->link().isEmpty());
    });
    provider.loadWatchProvider(8);
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(WatchProviderASyncTests, GetAllWatchProviders)
{
    bool f = false;
    WatchProvider provider(
        std::getenv("API_KEY"));
    QObject::connect(&provider, &WatchProvider::finishedLoadingAllWatchProviders, [&f](std::vector<WatchProvider*> providers)
    {
        for (const auto& p : providers)
        {
            EXPECT_FALSE(p->logoPath().isEmpty());
            EXPECT_FALSE(p->providerName().isEmpty());
            EXPECT_TRUE(p->link().isEmpty());
        }
        f = true;
    }
    );
}

TEST(WatchProviderASyncTests, GetWatchProvidersForMovieTest)
{
    bool f = false;
    WatchProvider provider(
        std::getenv("API_KEY"));
    QObject::connect(&provider, &WatchProvider::finishedLoadingWatchProvidersForMovie, [&f](std::vector<WatchProvider*> providers)
    {
        EXPECT_FALSE(providers.empty());
        EXPECT_EQ(providers[0]->type(), flatrate);
        EXPECT_EQ(providers[0]->providerID(), 337);
        EXPECT_STREQ(providers[0]->providerName().toStdString().c_str(), "Disney Plus");
        EXPECT_STREQ(providers[0]->link().toString().toStdString().c_str(),
                 "https://click.justwatch.com/a?cx=eyJzY2hlbWEiOiJpZ2x1OmNvbS5zbm93cGxvd2FuYWx5dGljcy5zbm93cGxvdy9jb250ZXh0cy9qc29uc2NoZW1hLzEtMC0wIiwiZGF0YSI6W3sic2NoZW1hIjoiaWdsdTpjb20uanVzdHdhdGNoL2NsaWNrb3V0X2NvbnRleHQvanNvbnNjaGVtYS8xLTMtMiIsImRhdGEiOnsicHJvdmlkZXIiOiJEaXNuZXkgUGx1cyIsIm1vbmV0aXphdGlvblR5cGUiOiJmbGF0cmF0ZSIsInByZXNlbnRhdGlvblR5cGUiOiJoZCIsImN1cnJlbmN5IjoiR0JQIiwicGFydG5lcklkIjo2LCJwcm92aWRlcklkIjozMzcsImNsaWNrb3V0VHlwZSI6Imp3LWNvbnRlbnQtcGFydG5lci1leHBvcnQtYXBpIn19LHsic2NoZW1hIjoiaWdsdTpjb20uanVzdHdhdGNoL3RpdGxlX2NvbnRleHQvanNvbnNjaGVtYS8xLTMtMCIsImRhdGEiOnsidGl0bGVJZCI6NDI0MDksIm9iamVjdFR5cGUiOiJtb3ZpZSIsImp3RW50aXR5SWQiOiJ0bTQyNDA5In19XX0&r=https%3A%2F%2Fdisneyplus.bn5x.net%2Fc%2F1206980%2F705874%2F9358%3Fu%3Dhttps%253A%252F%252Fwww.disneyplus.com%252Fmovies%252Ffight-club%252F38HCX4uW3BlA%26subId3%3Djustappsvod&uct_country=gb");
        EXPECT_STREQ(providers[0]->logoPath().toStdString().c_str(), "/97yvRBw1GzX7fXprcF80er19ot.jpg");
    });
    provider.loadWatchProvidersForMovie("GB", 550);
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(WatchProviderASyncTests, GetWatchProvidersForTVTest)
{
    bool f = false;
    WatchProvider provider(
        std::getenv("API_KEY"));
    QObject::connect(&provider, &WatchProvider::finishedLoadingWatchProvidersForTV, [&f](std::vector<WatchProvider*> providers)
    {
        EXPECT_FALSE(providers.empty());
        EXPECT_EQ(providers[0]->type(), flatrate);
        EXPECT_EQ(providers[0]->providerID(), 39);
        EXPECT_STREQ(providers[0]->providerName().toStdString().c_str(), "Now TV");
        EXPECT_FALSE(providers[0]->link().toString().isEmpty());
        EXPECT_STREQ(providers[0]->logoPath().toStdString().c_str(), "/g0E9h3JAeIwmdvxlT73jiEuxdNj.jpg");
    });
    provider.loadWatchProvidersForTV("GB", 1399);
    while (!f)
    {
        QApplication::processEvents();
    }
}
