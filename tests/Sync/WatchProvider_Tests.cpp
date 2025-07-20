//
// Created by t on 28/05/25.
//

#include "Sync/WatchProvider.h"
#include "Sync/QTMDB.h"
#include <gtest/gtest.h>

TEST(WatchProviderSyncTests, DefaultConstructor)
{
    tmdb::WatchProvider provider;
    EXPECT_EQ(provider.type(), tmdb::unset);
    EXPECT_STREQ(provider.logoPath().toStdString().c_str(), "");
    EXPECT_EQ(provider.providerID(), 0);
    EXPECT_STREQ(provider.providerName().toStdString().c_str(), "");
    EXPECT_TRUE(provider.link().isEmpty());
}

TEST(WatchProviderSyncTests, ParameterizedConstructor)
{
    tmdb::WatchProvider provider(tmdb::flatrate, "logo_path.png", 123, "Provider Name", QUrl("https://example.com"));
    EXPECT_EQ(provider.type(), tmdb::flatrate);
    EXPECT_STREQ(provider.logoPath().toStdString().c_str(), "logo_path.png");
    EXPECT_EQ(provider.providerID(), 123);
    EXPECT_STREQ(provider.providerName().toStdString().c_str(), "Provider Name");
    EXPECT_EQ(provider.link(), QUrl("https://example.com"));
}

TEST(WatchProviderSyncTests, APIConstructor)
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

TEST(WatchProviderSyncTests, StaticConstructor)
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

TEST(WatchProviderSyncTests, GetAllWatchProviders)
{
    auto providers = tmdb::WatchProvider::getAllWatchProviders(
        std::getenv("API_KEY"),
        tmdb::flatrate, tmdb::config::getLanguage("GB", std::getenv("API_KEY")));
    EXPECT_FALSE(providers.empty());
    EXPECT_EQ(providers[0].type(), tmdb::unset);
    EXPECT_STREQ(providers[0].logoPath().toStdString().c_str(), "/9ghgSC0MA082EL6HLCW3GalykFD.jpg");
    EXPECT_EQ(providers[0].providerID(), 2);
    EXPECT_STREQ(providers[0].providerName().toStdString().c_str(), "Apple TV");
    EXPECT_TRUE(providers[0].link().isEmpty());
}

TEST(WatchProviderSyncTests, GetWatchProvidersForMovieTest)
{
    std::vector<tmdb::WatchProvider> providers = tmdb::WatchProvider::getWatchProvidersForMovie(
        std::getenv("API_KEY"),
        "GB", 550);

    EXPECT_FALSE(providers.empty());
    EXPECT_EQ(providers[0].type(), tmdb::flatrate);
    EXPECT_EQ(providers[0].providerID(), 337);
    EXPECT_STREQ(providers[0].providerName().toStdString().c_str(), "Disney Plus");
    EXPECT_FALSE(providers[0].link().toString().isNull());
    EXPECT_FALSE(providers[0].logoPath().isNull());
}

TEST(WatchProviderSyncTests, GetWatchProvidersForTVTest)
{
    std::vector<tmdb::WatchProvider> providers = tmdb::WatchProvider::getWatchProvidersForTV(
        std::getenv("API_KEY"),
        "GB", 1399);

    EXPECT_FALSE(providers.empty());
    EXPECT_EQ(providers[0].type(), tmdb::flatrate);
    EXPECT_EQ(providers[0].providerID(), 39);
    EXPECT_STREQ(providers[0].providerName().toStdString().c_str(), "Now TV");
    EXPECT_FALSE(providers[0].link().isEmpty());
    EXPECT_FALSE(providers[0].logoPath().isNull());
}
