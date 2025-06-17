//
// Created by t on 25/05/25.
//

#include "Sync/Company.h"
#include <gtest/gtest.h>

#include "Sync/QTMDB.h"

TEST(CompanySyncTests, DefaultConstructor)
{
    tmdb::Company company;
    EXPECT_TRUE(company.description().isEmpty());
    EXPECT_TRUE(company.headquarters().isEmpty());
    EXPECT_TRUE(company.homepage().isEmpty());
    EXPECT_TRUE(company.name().isEmpty());
    EXPECT_TRUE(company.originCountry().isEmpty());
    EXPECT_TRUE(company.parentCompany().isEmpty());
    EXPECT_TRUE(company.logoPath().isEmpty());
    EXPECT_EQ(company.id(), 0);
}

TEST(CompanySyncTests, ParameterizedConstructor)
{
    tmdb::Company company("Test Description", "Test Headquarters", "http://example.com",
                    "Test Company", "US", "Parent Company", "/logo.png", 12345);
    EXPECT_STREQ(company.description().toStdString().c_str(), "Test Description");
    EXPECT_STREQ(company.headquarters().toStdString().c_str(), "Test Headquarters");
    EXPECT_STREQ(company.homepage().toStdString().c_str(), "http://example.com");
    EXPECT_STREQ(company.name().toStdString().c_str(), "Test Company");
    EXPECT_STREQ(company.originCountry().toStdString().c_str(), "US");
    EXPECT_STREQ(company.parentCompany().toStdString().c_str(), "Parent Company");
    EXPECT_STREQ(company.logoPath().toStdString().c_str(), "/logo.png");
    EXPECT_EQ(company.id(), 12345);
}

TEST(CompanySyncTests, APIConstructor)
{
    tmdb::Company company(std::getenv("API_KEY"), 1);
    EXPECT_EQ(company.id(), 1);
    EXPECT_STREQ(company.description().toStdString().c_str(), "");
    EXPECT_STREQ(company.headquarters().toStdString().c_str(), "San Francisco, California");
    EXPECT_STREQ(company.homepage().toStdString().c_str(), "https://www.lucasfilm.com");
    EXPECT_STREQ(company.name().toStdString().c_str(), "Lucasfilm Ltd.");
    EXPECT_STREQ(company.originCountry().toStdString().c_str(), "US");
    EXPECT_STREQ(company.parentCompany().toStdString().c_str(), "");
    EXPECT_STREQ(company.logoPath().toStdString().c_str(), "/tlVSws0RvvtPBwViUyOFAO0vcQS.png");
}

TEST(CompanySyncTests, APIJSON)
{
    Qtmdb q(std::getenv("API_KEY"));
    QJsonObject response = q.company_details(1);
    EXPECT_FALSE(response.isEmpty());
    tmdb::Company company(response);
    EXPECT_EQ(company.id(), 1);
    EXPECT_STREQ(company.description().toStdString().c_str(), "");
    EXPECT_STREQ(company.headquarters().toStdString().c_str(), "San Francisco, California");
    EXPECT_STREQ(company.homepage().toStdString().c_str(), "https://www.lucasfilm.com");
    EXPECT_STREQ(company.name().toStdString().c_str(), "Lucasfilm Ltd.");
    EXPECT_STREQ(company.originCountry().toStdString().c_str(), "US");
    EXPECT_STREQ(company.parentCompany().toStdString().c_str(), "");
    EXPECT_STREQ(company.logoPath().toStdString().c_str(), "/tlVSws0RvvtPBwViUyOFAO0vcQS.png");
}

TEST(CompanySyncTests, StaticConstructor)
{
    tmdb::Company company = tmdb::Company::getCompany(std::getenv("API_KEY"), 1);
    EXPECT_EQ(company.id(), 1);
    EXPECT_STREQ(company.description().toStdString().c_str(), "");
    EXPECT_STREQ(company.headquarters().toStdString().c_str(), "San Francisco, California");
    EXPECT_STREQ(company.homepage().toStdString().c_str(), "https://www.lucasfilm.com");
    EXPECT_STREQ(company.name().toStdString().c_str(), "Lucasfilm Ltd.");
    EXPECT_STREQ(company.originCountry().toStdString().c_str(), "US");
    EXPECT_STREQ(company.parentCompany().toStdString().c_str(), "");
    EXPECT_STREQ(company.logoPath().toStdString().c_str(), "/tlVSws0RvvtPBwViUyOFAO0vcQS.png");
}

TEST(CompanySyncTests, setGetters)
{
    tmdb::Company c;
    c.setDescription("Test Description");
    c.setHeadquarters("Test Headquarters");
    c.setHomepage("http://example.com");
    c.setName("Test Company");
    c.setOriginCountry("US");
    c.setParentCompany("Parent Company");
    c.setLogoPath("/logo.png");
    c.setID(12345);
    EXPECT_STREQ(c.description().toStdString().c_str(), "Test Description");
    EXPECT_STREQ(c.headquarters().toStdString().c_str(), "Test Headquarters");
    EXPECT_STREQ(c.homepage().toStdString().c_str(), "http://example.com");
    EXPECT_STREQ(c.name().toStdString().c_str(), "Test Company");
    EXPECT_STREQ(c.originCountry().toStdString().c_str(), "US");
    EXPECT_STREQ(c.parentCompany().toStdString().c_str(), "Parent Company");
    EXPECT_STREQ(c.logoPath().toStdString().c_str(), "/logo.png");
    EXPECT_EQ(c.id(), 12345);
}