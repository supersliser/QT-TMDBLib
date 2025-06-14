//
// Created by t on 25/05/25.
//

#include <QApplication>

#include "ASync/Company.h"
#include <gtest/gtest.h>

#include "ASync/QTMDB.h"

using namespace tmdb::ASync;

TEST(CompanyASyncTests, DefaultConstructor)
{
    Company company;
    EXPECT_TRUE(company.description().isEmpty());
    EXPECT_TRUE(company.headquarters().isEmpty());
    EXPECT_TRUE(company.homepage().isEmpty());
    EXPECT_TRUE(company.name().isEmpty());
    EXPECT_TRUE(company.originCountry()->englishName().isEmpty());
    EXPECT_TRUE(company.parentCompany().isEmpty());
    EXPECT_TRUE(company.logoPath().isEmpty());
    EXPECT_EQ(company.id(), 0);
}

TEST(CompanyASyncTests, APIConstructor)
{
    bool f = false;
    auto company = new Company(std::getenv("API_KEY"));
    QObject::connect(company, &Company::finishedLoadingCompany, [&f](Company* company)
    {
        EXPECT_EQ(company->id(), 1);
        EXPECT_STREQ(company->description().toStdString().c_str(), "");
        EXPECT_STREQ(company->headquarters().toStdString().c_str(), "San Francisco, California");
        EXPECT_STREQ(company->homepage().toStdString().c_str(), "https://www.lucasfilm.com");
        EXPECT_STREQ(company->name().toStdString().c_str(), "Lucasfilm Ltd.");
        EXPECT_STREQ(company->originCountry()->englishName().toStdString().c_str(), "United States");
        EXPECT_STREQ(company->parentCompany().toStdString().c_str(), "");
        EXPECT_STREQ(company->logoPath().toStdString().c_str(), "/tlVSws0RvvtPBwViUyOFAO0vcQS.png");
        f = true;
    });
    company->loadCompany(1);
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(CompanyASyncTests, APIJSON)
{
    bool f = false;
    aQtmdb q(std::getenv("API_KEY"));
    QObject::connect(&q, &aQtmdb::finishedLoadingData, [&f](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        Company* company = new Company(data, std::getenv("API_KEY"));
        EXPECT_EQ(company->id(), 1);
        EXPECT_STREQ(company->description().toStdString().c_str(), "");
        EXPECT_STREQ(company->headquarters().toStdString().c_str(), "San Francisco, California");
        EXPECT_STREQ(company->homepage().toStdString().c_str(), "https://www.lucasfilm.com");
        EXPECT_STREQ(company->name().toStdString().c_str(), "Lucasfilm Ltd.");
        EXPECT_STREQ(company->originCountry()->englishName().toStdString().c_str(), "US");
        EXPECT_STREQ(company->parentCompany().toStdString().c_str(), "");
        EXPECT_STREQ(company->logoPath().toStdString().c_str(), "/tlVSws0RvvtPBwViUyOFAO0vcQS.png");
        f = true;
    });
    q.company_details(1);
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(CompanyASyncTests, setGetters)
{
    Company c;
    c.setDescription("Test Description");
    c.setHeadquarters("Test Headquarters");
    c.setHomepage("http://example.com");
    c.setName("Test Company");
    c.setOriginCountry(new Country(std::getenv("API_KEY"), "GB"));
    c.setParentCompany("Parent Company");
    c.setLogoPath("/logo.png");
    c.setID(12345);
    EXPECT_STREQ(c.description().toStdString().c_str(), "Test Description");
    EXPECT_STREQ(c.headquarters().toStdString().c_str(), "Test Headquarters");
    EXPECT_STREQ(c.homepage().toStdString().c_str(), "http://example.com");
    EXPECT_STREQ(c.name().toStdString().c_str(), "Test Company");
    EXPECT_STREQ(c.originCountry()->englishName().toStdString().c_str(), "Great Britain");
    EXPECT_STREQ(c.parentCompany().toStdString().c_str(), "Parent Company");
    EXPECT_STREQ(c.logoPath().toStdString().c_str(), "/logo.png");
    EXPECT_EQ(c.id(), 12345);
}
