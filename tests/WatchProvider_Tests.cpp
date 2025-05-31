//
// Created by t on 28/05/25.
//

#include "WatchProvider.h"
#include "QTMDB.h"
#include <gtest/gtest.h>

TEST(WatchProviderTests, DefaultConstructor)
{
    tmdb::WatchProvider provider;
    EXPECT_EQ(provider.type(), tmdb::unset);
    EXPECT_STREQ(provider.logoPath().toStdString().c_str(), "");
    EXPECT_EQ(provider.providerID(), 0);
    EXPECT_STREQ(provider.providerName().toStdString().c_str(), "");
    EXPECT_TRUE(provider.link().isEmpty());
}

TEST(WatchProviderTests, ParameterizedConstructor)
{
    tmdb::WatchProvider provider(tmdb::flatrate, "logo_path.png", 123, "Provider Name", QUrl("https://example.com"));
    EXPECT_EQ(provider.type(), tmdb::flatrate);
    EXPECT_STREQ(provider.logoPath().toStdString().c_str(), "logo_path.png");
    EXPECT_EQ(provider.providerID(), 123);
    EXPECT_STREQ(provider.providerName().toStdString().c_str(), "Provider Name");
    EXPECT_EQ(provider.link(), QUrl("https://example.com"));
}

TEST(WatchProviderTests, APIConstructor)
{
    tmdb::WatchProvider provider(
        std::getenv("API_KEY"),
        8);
    EXPECT_EQ(provider.type(), tmdb::unset);
    EXPECT_STREQ(provider.logoPath().toStdString().c_str(), "/pbpMk2JmcoNnQwx5JGpXngfoWtp.jpg");
    EXPECT_EQ(provider.providerID(), 8);
    EXPECT_STREQ(provider.providerName().toStdString().c_str(), "Netflix");
    EXPECT_TRUE(provider.link().isEmpty());
}

TEST(WatchProviderTests, StaticConstructor)
{
    tmdb::WatchProvider provider = tmdb::WatchProvider::getWatchProvider(
        std::getenv("API_KEY"),
        8);
    EXPECT_EQ(provider.type(), tmdb::unset);
    EXPECT_STREQ(provider.logoPath().toStdString().c_str(), "/pbpMk2JmcoNnQwx5JGpXngfoWtp.jpg");
    EXPECT_EQ(provider.providerID(), 8);
    EXPECT_STREQ(provider.providerName().toStdString().c_str(), "Netflix");
    EXPECT_TRUE(provider.link().isEmpty());
}

TEST(WatchProviderTests, GetAllWatchProviders)
{
    auto providers = tmdb::WatchProvider::getAllWatchProviders(
        std::getenv("API_KEY"),
        tmdb::flatrate, tmdb::config::getLanguage("GB"));
    EXPECT_FALSE(providers.empty());
    EXPECT_EQ(providers[0].type(), tmdb::unset);
    EXPECT_STREQ(providers[0].logoPath().toStdString().c_str(), "/9ghgSC0MA082EL6HLCW3GalykFD.jpg");
    EXPECT_EQ(providers[0].providerID(), 2);
    EXPECT_STREQ(providers[0].providerName().toStdString().c_str(), "Apple TV");
    EXPECT_TRUE(providers[0].link().isEmpty());
}

TEST(WatchProviderTests, GetWatchProvidersForMovieTest)
{
    std::vector<tmdb::WatchProvider> providers = tmdb::WatchProvider::getWatchProvidersForMovie(
        std::getenv("API_KEY"),
        "GB", 550);

    EXPECT_FALSE(providers.empty());
    EXPECT_EQ(providers[0].type(), tmdb::flatrate);
    EXPECT_EQ(providers[0].providerID(), 337);
    EXPECT_STREQ(providers[0].providerName().toStdString().c_str(), "Disney Plus");
    EXPECT_STREQ(providers[0].link().toString().toStdString().c_str(),
                 "https://click.justwatch.com/a?cx=eyJzY2hlbWEiOiJpZ2x1OmNvbS5zbm93cGxvd2FuYWx5dGljcy5zbm93cGxvdy9jb250ZXh0cy9qc29uc2NoZW1hLzEtMC0wIiwiZGF0YSI6W3sic2NoZW1hIjoiaWdsdTpjb20uanVzdHdhdGNoL2NsaWNrb3V0X2NvbnRleHQvanNvbnNjaGVtYS8xLTMtMiIsImRhdGEiOnsicHJvdmlkZXIiOiJEaXNuZXkgUGx1cyIsIm1vbmV0aXphdGlvblR5cGUiOiJmbGF0cmF0ZSIsInByZXNlbnRhdGlvblR5cGUiOiJoZCIsImN1cnJlbmN5IjoiR0JQIiwicGFydG5lcklkIjo2LCJwcm92aWRlcklkIjozMzcsImNsaWNrb3V0VHlwZSI6Imp3LWNvbnRlbnQtcGFydG5lci1leHBvcnQtYXBpIn19LHsic2NoZW1hIjoiaWdsdTpjb20uanVzdHdhdGNoL3RpdGxlX2NvbnRleHQvanNvbnNjaGVtYS8xLTMtMCIsImRhdGEiOnsidGl0bGVJZCI6NDI0MDksIm9iamVjdFR5cGUiOiJtb3ZpZSIsImp3RW50aXR5SWQiOiJ0bTQyNDA5In19XX0&r=https%3A%2F%2Fdisneyplus.bn5x.net%2Fc%2F1206980%2F705874%2F9358%3Fu%3Dhttps%253A%252F%252Fwww.disneyplus.com%252Fmovies%252Ffight-club%252F38HCX4uW3BlA%26subId3%3Djustappsvod&uct_country=gb");
    EXPECT_STREQ(providers[0].logoPath().toStdString().c_str(), "/97yvRBw1GzX7fXprcF80er19ot.jpg");
}

TEST(WatchProviderTests, GetWatchProvidersForTVTest)
{
    std::vector<tmdb::WatchProvider> providers = tmdb::WatchProvider::getWatchProvidersForTV(
        std::getenv("API_KEY"),
        "GB", 1399);

    EXPECT_FALSE(providers.empty());
    EXPECT_EQ(providers[0].type(), tmdb::flatrate);
    EXPECT_EQ(providers[0].providerID(), 39);
    EXPECT_STREQ(providers[0].providerName().toStdString().c_str(), "Now TV");
    EXPECT_STREQ(providers[0].link().toString().toStdString().c_str(),
                 "https://click.justwatch.com/a?cx=eyJzY2hlbWEiOiJpZ2x1OmNvbS5zbm93cGxvd2FuYWx5dGljcy5zbm93cGxvdy9jb250ZXh0cy9qc29uc2NoZW1hLzEtMC0wIiwiZGF0YSI6W3sic2NoZW1hIjoiaWdsdTpjb20uanVzdHdhdGNoL2NsaWNrb3V0X2NvbnRleHQvanNvbnNjaGVtYS8xLTMtMiIsImRhdGEiOnsicHJvdmlkZXIiOiJOb3cgVFYiLCJtb25ldGl6YXRpb25UeXBlIjoiZmxhdHJhdGUiLCJwcmVzZW50YXRpb25UeXBlIjoiaGQiLCJjdXJyZW5jeSI6IkdCUCIsInBhcnRuZXJJZCI6NiwicHJvdmlkZXJJZCI6MzksImNsaWNrb3V0VHlwZSI6Imp3LWNvbnRlbnQtcGFydG5lci1leHBvcnQtYXBpIn19LHsic2NoZW1hIjoiaWdsdTpjb20uanVzdHdhdGNoL3RpdGxlX2NvbnRleHQvanNvbnNjaGVtYS8xLTMtMCIsImRhdGEiOnsidGl0bGVJZCI6Miwib2JqZWN0VHlwZSI6InNob3ciLCJqd0VudGl0eUlkIjoidHMyIn19XX0&r=https%3A%2F%2Fwww.nowtv.com%2Fwatch%2Fthe-game-of-thrones-reunion%2FiYEQZ2rcf32XR8pW3dPCJm%2Fseasons%2F1%2Fepisodes%2F1%2FA5EK65Bcwd6MFzPYd3yaE&uct_country=gb");
    EXPECT_STREQ(providers[0].logoPath().toStdString().c_str(), "/g0E9h3JAeIwmdvxlT73jiEuxdNj.jpg");
}
