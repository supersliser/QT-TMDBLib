//
// Created by t on 25/05/25.
//

#include "Sync/Account.h"
#include <QJsonObject>
#include <gtest/gtest.h>

#include "Sync/QTMDB.h"

TEST(AccountSyncTests, DefaultConstructor)
{
    tmdb::Account account;
    EXPECT_EQ(account.id(), 0);
    EXPECT_STREQ(account.iso6391().toStdString().c_str(), QString().toStdString().c_str());
    EXPECT_STREQ(account.iso31661().toStdString().c_str(), QString().toStdString().c_str());
    EXPECT_STREQ(account.name().toStdString().c_str(), QString().toStdString().c_str());
    EXPECT_STREQ(account.username().toStdString().c_str(), QString().toStdString().c_str());
    EXPECT_TRUE(account.includeAdult());
}

TEST(AccountSyncTests, ParameterizedConstructor) {
    tmdb::Account account(1, "en", "US", "Test User", "testuser", false);
    EXPECT_EQ(account.id(), 1);
    EXPECT_STREQ(account.iso6391().toStdString().c_str(), "en");
    EXPECT_STREQ(account.iso31661().toStdString().c_str(), "US");
    EXPECT_STREQ(account.name().toStdString().c_str(), "Test User");
    EXPECT_STREQ(account.username().toStdString().c_str(), "testuser");
    EXPECT_FALSE(account.includeAdult());
}

TEST(AccountSyncTests, APIGetter)
{
    tmdb::Account a(std::getenv("API_KEY"), 22023427);
    EXPECT_EQ(a.id(), 22023427);
    EXPECT_STREQ(a.iso6391().toStdString().c_str(), "en");
    EXPECT_STREQ(a.iso31661().toStdString().c_str(), "GB");
    EXPECT_STREQ(a.name().toStdString().c_str(), "");
    EXPECT_STREQ(a.username().toStdString().c_str(), "supersliser");
    EXPECT_TRUE(a.includeAdult());
    EXPECT_STREQ(a.avatar()->gravatar().hash().toStdString().c_str(), "467183536659af2a02f4b2dbf0901aea");
}

TEST(AccountSyncTests, APIJSON)
{
    Qtmdb q(std::getenv("API_KEY"));
    QJsonObject response = q.account_details(22023427);
    EXPECT_FALSE(response.isEmpty());
    tmdb::Account a(response);
    EXPECT_EQ(a.id(), 22023427);
    EXPECT_STREQ(a.iso6391().toStdString().c_str(), "en");
    EXPECT_STREQ(a.iso31661().toStdString().c_str(), "GB");
    EXPECT_STREQ(a.name().toStdString().c_str(), "");
    EXPECT_STREQ(a.username().toStdString().c_str(), "supersliser");
    EXPECT_TRUE(a.includeAdult());
    EXPECT_STREQ(a.avatar()->gravatar().hash().toStdString().c_str(), "467183536659af2a02f4b2dbf0901aea");
}

TEST(AccountSyncTests, StaticConstructor)
{
    tmdb::Account account = tmdb::Account::getAccount(std::getenv("API_KEY"), 22023427);
    EXPECT_EQ(account.id(), 22023427);
    EXPECT_STREQ(account.iso6391().toStdString().c_str(), "en");
    EXPECT_STREQ(account.iso31661().toStdString().c_str(), "GB");
    EXPECT_STREQ(account.name().toStdString().c_str(), "");
    EXPECT_STREQ(account.username().toStdString().c_str(), "supersliser");
    EXPECT_TRUE(account.includeAdult());
    EXPECT_STREQ(account.avatar()->gravatar().hash().toStdString().c_str(), "467183536659af2a02f4b2dbf0901aea");
}

TEST(AccountSyncTests, setAvatar)
{
    tmdb::Account a;
    tmdb::Avatar* avatar = new tmdb::Avatar("testhash", "testpath");
    a.setAvatar(avatar);
    EXPECT_STREQ(a.avatar()->gravatar().hash().toStdString().c_str(), "testhash");
    EXPECT_STREQ(a.avatar()->tmdb().avatarPath().toStdString().c_str(), "testpath");
}

TEST(AccountSyncTests, setGetters)
{
    tmdb::Account a;
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

