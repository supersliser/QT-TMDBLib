//
// Created by t on 25/05/25.
//

#include "Company.h"
#include <gtest/gtest.h>

#include "QTMDB.h"

TEST(CompanyTests, DefaultConstructor)
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

TEST(CompanyTests, ParameterizedConstructor)
{
    tmdb::Company company("Test Description", "Test Headquarters", "http://example.com",
                    "Test Company", "US", "Parent Company", "/logo.png", 12345);
    EXPECT_EQ(company.description(), "Test Description");
    EXPECT_EQ(company.headquarters(), "Test Headquarters");
    EXPECT_EQ(company.homepage(), "http://example.com");
    EXPECT_EQ(company.name(), "Test Company");
    EXPECT_EQ(company.originCountry(), "US");
    EXPECT_EQ(company.parentCompany(), "Parent Company");
    EXPECT_EQ(company.logoPath(), "/logo.png");
    EXPECT_EQ(company.id(), 12345);
}

TEST(CompanyTests, APIConstructor)
{
    tmdb::Company company("eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJmZWZjMDcwYTExNTZlZDExM2JjN2RhZDA1ZWM5OWMyOCIsIm5iZiI6MTc0Nzc2ODM5Mi44MDgsInN1YiI6IjY4MmNkNDQ4ODA2OTJiYWI1NTY0OTRiYyIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.4wbjpPC366q5YFsHnuo9g4bIQ2xgMB5hIHx84SejLMg", 1);
    EXPECT_EQ(company.id(), 1);
    EXPECT_EQ(company.description(), "");
    EXPECT_EQ(company.headquarters(), "San Francisco, California");
    EXPECT_EQ(company.homepage(), "https://www.lucasfilm.com");
    EXPECT_EQ(company.name(), "Lucasfilm Ltd.");
    EXPECT_EQ(company.originCountry(), "US");
    EXPECT_EQ(company.parentCompany(), "");
    EXPECT_EQ(company.logoPath(), "/tlVSws0RvvtPBwViUyOFAO0vcQS.png");
}

TEST(CompanyTests, APIJSON)
{
    Qtmdb q("eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJmZWZjMDcwYTExNTZlZDExM2JjN2RhZDA1ZWM5OWMyOCIsIm5iZiI6MTc0Nzc2ODM5Mi44MDgsInN1YiI6IjY4MmNkNDQ4ODA2OTJiYWI1NTY0OTRiYyIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.4wbjpPC366q5YFsHnuo9g4bIQ2xgMB5hIHx84SejLMg");
    QJsonObject response = q.company_details(1);
    EXPECT_FALSE(response.isEmpty());
    tmdb::Company company(response);
    EXPECT_EQ(company.id(), 1);
    EXPECT_EQ(company.description(), "");
    EXPECT_EQ(company.headquarters(), "San Francisco, California");
    EXPECT_EQ(company.homepage(), "https://www.lucasfilm.com");
    EXPECT_EQ(company.name(), "Lucasfilm Ltd.");
    EXPECT_EQ(company.originCountry(), "US");
    EXPECT_EQ(company.parentCompany(), "");
    EXPECT_EQ(company.logoPath(), "/tlVSws0RvvtPBwViUyOFAO0vcQS.png");
}

TEST(CompanyTests, StaticConstructor)
{
    tmdb::Company company = tmdb::Company::getCompany("eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJmZWZjMDcwYTExNTZlZDExM2JjN2RhZDA1ZWM5OWMyOCIsIm5iZiI6MTc0Nzc2ODM5Mi44MDgsInN1YiI6IjY4MmNkNDQ4ODA2OTJiYWI1NTY0OTRiYyIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.4wbjpPC366q5YFsHnuo9g4bIQ2xgMB5hIHx84SejLMg", 1);
    EXPECT_EQ(company.id(), 1);
    EXPECT_EQ(company.description(), "");
    EXPECT_EQ(company.headquarters(), "San Francisco, California");
    EXPECT_EQ(company.homepage(), "https://www.lucasfilm.com");
    EXPECT_EQ(company.name(), "Lucasfilm Ltd.");
    EXPECT_EQ(company.originCountry(), "US");
    EXPECT_EQ(company.parentCompany(), "");
    EXPECT_EQ(company.logoPath(), "/tlVSws0RvvtPBwViUyOFAO0vcQS.png");
}

TEST(CompanyTests, setGetters)
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
    EXPECT_EQ(c.description(), "Test Description");
    EXPECT_EQ(c.headquarters(), "Test Headquarters");
    EXPECT_EQ(c.homepage(), "http://example.com");
    EXPECT_EQ(c.name(), "Test Company");
    EXPECT_EQ(c.originCountry(), "US");
    EXPECT_EQ(c.parentCompany(), "Parent Company");
    EXPECT_EQ(c.logoPath(), "/logo.png");
    EXPECT_EQ(c.id(), 12345);
}