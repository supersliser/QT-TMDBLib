//
// Created by t on 30/05/25.
//

#include <QApplication>

#include "ASync/Network.h"
#include <gtest/gtest.h>

#include "ASync/QTMDB.h"
using namespace tmdb::ASync::TV;

TEST(NetworkASyncTests, DefaultConstructor)
{
    Network network;
    EXPECT_EQ(network.id(), 0);
    EXPECT_STREQ(network.name().toStdString().c_str(), "BLANK_NAME");
    EXPECT_STREQ(network.headquarters().toStdString().c_str(), "BLANK_HEADQUARTERS");
    EXPECT_STREQ(network.homepage().toStdString().c_str(), "BLANK_HOMEPAGE");
    EXPECT_STREQ(network.logoPath().toStdString().c_str(), "BLANK_LOGO_PATH");
    EXPECT_STREQ(network.originCountry()->englishName().toStdString().c_str(), "United States");
}

TEST(NetworkASyncTests, APIConstructor)
{
    Network network(std::getenv("API_KEY"));
    bool f = false;
    QObject::connect(&network, &Network::finishedLoadingNetwork, [&f](Network* n) {
        EXPECT_EQ(n->id(), 49);
        EXPECT_STREQ(n->name().toStdString().c_str(), "HBO");
        EXPECT_STREQ(n->headquarters().toStdString().c_str(), "New York City, New York");
        EXPECT_STREQ(n->homepage().toStdString().c_str(), "https://www.hbo.com");
        EXPECT_STREQ(n->logoPath().toStdString().c_str(), "/tuomPhY2UtuPTqqFnKMVHvSb724.png");
        EXPECT_STREQ(n->originCountry()->isoCountryCode().toStdString().c_str(), "US");
        f = true;
    });
    network.loadNetwork(49);
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(NetworkASyncTests, APIJSON) {
    bool f = false;
    aQtmdb q(std::getenv("API_KEY"));
    QObject::connect(&q, &aQtmdb::finishedLoadingData, [&f](void* response) {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        Network network(data, std::getenv("API_KEY"));
        EXPECT_EQ(network.id(), 49);
        EXPECT_STREQ(network.name().toStdString().c_str(), "HBO");
        EXPECT_STREQ(network.headquarters().toStdString().c_str(), "New York City, New York");
        EXPECT_STREQ(network.homepage().toStdString().c_str(), "https://www.hbo.com");
        EXPECT_STREQ(network.logoPath().toStdString().c_str(), "/tuomPhY2UtuPTqqFnKMVHvSb724.png");
        EXPECT_STREQ(network.originCountry()->isoCountryCode().toStdString().c_str(), "US");
        f = true;
    });
    q.network_details(49);
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(NetworkASyncTests, setGetters)
{
    Network n;
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
}