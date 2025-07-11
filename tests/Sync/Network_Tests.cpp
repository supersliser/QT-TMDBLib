//
// Created by t on 30/05/25.
//

#include "Sync/Network.h"
#include <gtest/gtest.h>

#include "Sync/QTMDB.h"

TEST(NetworkSyncTests, DefaultConstructor)
{
    tmdb::TV::Network network;
    EXPECT_EQ(network.id(), 0);
    EXPECT_TRUE(network.name().isEmpty());
    EXPECT_STREQ(network.headquarters().toStdString().c_str(), "");
    EXPECT_TRUE(network.homepage().isEmpty());
    EXPECT_TRUE(network.logoPath().isEmpty());
    EXPECT_STREQ(network.originCountry().english_name.toStdString().c_str(), "");
}

TEST(NetworkSyncTests, ParameterizedConstructor) {
    tmdb::TV::Network network("Los Angeles", "http://example.com", 1, "/logo.png", "Example Network",
                               tmdb::config::getCountry("US", std::getenv("API_KEY")));
    EXPECT_EQ(network.id(), 1);
    EXPECT_STREQ(network.name().toStdString().c_str(), "Example Network");
    EXPECT_STREQ(network.headquarters().toStdString().c_str(), "Los Angeles");
    EXPECT_STREQ(network.homepage().toStdString().c_str(), "http://example.com");
    EXPECT_STREQ(network.logoPath().toStdString().c_str(), "/logo.png");
    EXPECT_STREQ(network.originCountry().iso_3166_1.toStdString().c_str(),"US");
}

TEST(NetworkSyncTests, APIConstructor)
{
    tmdb::TV::Network network(std::getenv("API_KEY"), 49);
    EXPECT_EQ(network.id(), 49);
    EXPECT_STREQ(network.name().toStdString().c_str(), "HBO");
    EXPECT_STREQ(network.headquarters().toStdString().c_str(), "New York City, New York");
    EXPECT_STREQ(network.homepage().toStdString().c_str(), "https://www.hbo.com");
    EXPECT_STREQ(network.logoPath().toStdString().c_str(), "/tuomPhY2UtuPTqqFnKMVHvSb724.png");
    EXPECT_STREQ(network.originCountry().iso_3166_1.toStdString().c_str(),"US");
}

TEST(NetworkSyncTests, APIJSON) {
    Qtmdb q(std::getenv("API_KEY"));
    QJsonObject response = q.network_details(49);
    EXPECT_FALSE(response.isEmpty());
    tmdb::TV::Network network(response, std::getenv("API_KEY"));
    EXPECT_EQ(network.id(), 49);
    EXPECT_STREQ(network.name().toStdString().c_str(), "HBO");
    EXPECT_STREQ(network.headquarters().toStdString().c_str(), "New York City, New York");
    EXPECT_STREQ(network.homepage().toStdString().c_str(), "https://www.hbo.com");
    EXPECT_STREQ(network.logoPath().toStdString().c_str(), "/tuomPhY2UtuPTqqFnKMVHvSb724.png");
    EXPECT_STREQ(network.originCountry().iso_3166_1.toStdString().c_str(), "US");
}

TEST(NetworkSyncTests, StaticConstructor) {
    tmdb::TV::Network network = tmdb::TV::Network::getNetwork(std::getenv("API_KEY"), 49);
    EXPECT_EQ(network.id(), 49);
    EXPECT_STREQ(network.name().toStdString().c_str(), "HBO");
    EXPECT_STREQ(network.headquarters().toStdString().c_str(), "New York City, New York");
    EXPECT_STREQ(network.homepage().toStdString().c_str(), "https://www.hbo.com");
    EXPECT_STREQ(network.logoPath().toStdString().c_str(), "/tuomPhY2UtuPTqqFnKMVHvSb724.png");
    EXPECT_STREQ(network.originCountry().iso_3166_1.toStdString().c_str(), "US");
}

TEST(NetworkSyncTests, setGetters)
{
    tmdb::TV::Network n;
    n.setHeadquarters("Los Angeles");
    EXPECT_STREQ(n.headquarters().toStdString().c_str(), "Los Angeles");
    n.setHomepage("http://example.com");
    EXPECT_STREQ(n.homepage().toStdString().c_str(), "http://example.com");
    n.setId(1);
    EXPECT_EQ(n.id(), 1);
    n.setLogoPath("/logo.png");
    EXPECT_STREQ(n.logoPath().toStdString().c_str(), "/logo.png");
    n.setName("Example Network");
    EXPECT_STREQ(n.name().toStdString().c_str(), "Example Network");
    n.setOriginCountry(tmdb::config::getCountry("US", std::getenv("API_KEY")));
    EXPECT_STREQ(n.originCountry().iso_3166_1.toStdString().c_str(), "US");
}