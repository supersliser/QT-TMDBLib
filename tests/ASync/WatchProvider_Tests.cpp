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
    EXPECT_STREQ(provider.logoPath().toStdString().c_str(), "BLANK_LOGO_PATH");
    EXPECT_EQ(provider.providerID(), 0);
    EXPECT_STREQ(provider.providerName().toStdString().c_str(), "BLANK_PROVIDER_NAME");
    EXPECT_STREQ(provider.link().toString().toStdString().c_str(), "https://www.themoviedb.org/");
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
        EXPECT_STREQ(p->link().toString().toStdString().c_str(), "https://www.themoviedb.org/");
        f = true;
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
    QObject::connect(&provider, &WatchProvider::finishedLoadingAllWatchProviders,
                     [&f](std::vector<WatchProvider*> providers)
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
    QObject::connect(&provider, &WatchProvider::finishedLoadingWatchProvidersForMovie,
                     [&f](std::vector<WatchProvider*> providers)
                     {
                         EXPECT_FALSE(providers.empty());
                         EXPECT_EQ(providers[0]->type(), rent);
                         EXPECT_EQ(providers[0]->providerID(), 192);
                         EXPECT_STREQ(providers[0]->providerName().toStdString().c_str(), "YouTube");
                         EXPECT_FALSE(providers[0]->link().toString().isEmpty());
                         EXPECT_FALSE(providers[0]->logoPath().isEmpty());
                         f = true;
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
    QObject::connect(&provider, &WatchProvider::finishedLoadingWatchProvidersForTV,
                     [&f](std::vector<WatchProvider*> providers)
                     {
                         EXPECT_FALSE(providers.empty());
                         EXPECT_EQ(providers[0]->type(), buy);
                         EXPECT_EQ(providers[0]->providerID(), 68);
                         EXPECT_STREQ(providers[0]->providerName().toStdString().c_str(), "Microsoft Store");
                         EXPECT_FALSE(providers[0]->link().isEmpty());
                         EXPECT_FALSE(providers[0]->logoPath().isEmpty());
                         f = true;
                     });
    provider.loadWatchProvidersForTV("GB", 1399);
    while (!f)
    {
        QApplication::processEvents();
    }
}
