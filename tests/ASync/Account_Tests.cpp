//
// Created by t on 25/05/25.
//

#include <QApplication>

#include "ASync/Account.h"
#include <QJsonObject>
#include <gtest/gtest.h>

#include "ASync/QTMDB.h"
using namespace tmdb::ASync;

TEST(AccountASyncTests, DefaultConstructor)
{
    Account account;
    EXPECT_EQ(account.id(), 0);
    EXPECT_STREQ(account.iso6391().toStdString().c_str(), QString().toStdString().c_str());
    EXPECT_STREQ(account.iso31661().toStdString().c_str(), QString().toStdString().c_str());
    EXPECT_STREQ(account.name().toStdString().c_str(), QString().toStdString().c_str());
    EXPECT_STREQ(account.username().toStdString().c_str(), QString().toStdString().c_str());
    EXPECT_TRUE(account.includeAdult());
}

TEST(AccountASyncTests, APIGetter)
{
    bool f = false;
    Account* a = new Account(std::getenv("API_KEY"));
    QObject::connect(a, &Account::finishedLoadingAccount, [&f](Account* account) {
        EXPECT_EQ(account->id(), 22023427);
        EXPECT_STREQ(account->iso6391().toStdString().c_str(), "en");
        EXPECT_STREQ(account->iso31661().toStdString().c_str(), "GB");
        EXPECT_STREQ(account->name().toStdString().c_str(), "");
        EXPECT_STREQ(account->username().toStdString().c_str(), "supersliser");
        EXPECT_TRUE(account->includeAdult());
        EXPECT_STREQ(account->avatar()->gravatar().hash().toStdString().c_str(), "467183536659af2a02f4b2dbf0901aea");
        f = true;
    });
    a->loadAccount(22023427);
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(AccountASyncTests, APIJSON)
{
    bool f = false;
    aQtmdb q(std::getenv("API_KEY"));
    QObject::connect(&q, &aQtmdb::finishedLoadingData, [&f](void* response) {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        Account* a = new Account(data, std::getenv("API_KEY"));
        EXPECT_EQ(a->id(), 22023427);
        EXPECT_STREQ(a->iso6391().toStdString().c_str(), "en");
        EXPECT_STREQ(a->iso31661().toStdString().c_str(), "GB");
        EXPECT_STREQ(a->name().toStdString().c_str(), "");
        EXPECT_STREQ(a->username().toStdString().c_str(), "supersliser");
        EXPECT_TRUE(a->includeAdult());
        EXPECT_STREQ(a->avatar()->gravatar().hash().toStdString().c_str(), "467183536659af2a02f4b2dbf0901aea");
        f = true;
    });
    q.account_details(22023427);
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(AccountASyncTests, setGetters)
{
    Account a;
    a.setID(12345);
    a.setISO6391("fr");
    a.setISO31661("FR");
    a.setName("Test Name");
    a.setUsername("testuser");
    a.setIncludeAdult(true);

    EXPECT_EQ(a.id(), 12345);
    EXPECT_STREQ(a.iso6391().toStdString().c_str(), "fr");
    EXPECT_STREQ(a.iso31661().toStdString().c_str(), "FR");
    EXPECT_STREQ(a.name().toStdString().c_str(), "Test Name");
    EXPECT_STREQ(a.username().toStdString().c_str(), "testuser");
    EXPECT_TRUE(a.includeAdult());
}

