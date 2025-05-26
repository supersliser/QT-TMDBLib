//
// Created by t on 25/05/25.
//

#include "Account.h"
#include <QJsonObject>
#include <gtest/gtest.h>

#include "QTMDB.h"

TEST(AccountTests, DefaultConstructor)
{
    tmdb::Account account;
    EXPECT_EQ(account.id(), 0);
    EXPECT_EQ(account.iso6391(), QString());
    EXPECT_EQ(account.iso31661(), QString());
    EXPECT_EQ(account.name(), QString());
    EXPECT_EQ(account.username(), QString());
    EXPECT_TRUE(account.includeAdult());
}

TEST(AccountTests, ParameterizedConstructor) {
    tmdb::Account account(1, "en", "US", "Test User", "testuser", false);
    EXPECT_EQ(account.id(), 1);
    EXPECT_EQ(account.iso6391(), "en");
    EXPECT_EQ(account.iso31661(), "US");
    EXPECT_EQ(account.name(), "Test User");
    EXPECT_EQ(account.username(), "testuser");
    EXPECT_FALSE(account.includeAdult());
}

TEST(AccountTests, APIGetter)
{
    tmdb::Account a("eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJmZWZjMDcwYTExNTZlZDExM2JjN2RhZDA1ZWM5OWMyOCIsIm5iZiI6MTc0Nzc2ODM5Mi44MDgsInN1YiI6IjY4MmNkNDQ4ODA2OTJiYWI1NTY0OTRiYyIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.4wbjpPC366q5YFsHnuo9g4bIQ2xgMB5hIHx84SejLMg", 22023427);
    EXPECT_EQ(a.id(), 22023427);
    EXPECT_EQ(a.iso6391(), "en");
    EXPECT_EQ(a.iso31661(), "GB");
    EXPECT_EQ(a.name(), "");
    EXPECT_EQ(a.username(), "supersliser");
    EXPECT_TRUE(a.includeAdult());
    EXPECT_EQ(a.avatar()->gravatar().hash(), "467183536659af2a02f4b2dbf0901aea");
}

TEST(AccountTests, APIJSON)
{
    Qtmdb q("eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJmZWZjMDcwYTExNTZlZDExM2JjN2RhZDA1ZWM5OWMyOCIsIm5iZiI6MTc0Nzc2ODM5Mi44MDgsInN1YiI6IjY4MmNkNDQ4ODA2OTJiYWI1NTY0OTRiYyIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.4wbjpPC366q5YFsHnuo9g4bIQ2xgMB5hIHx84SejLMg");
    QJsonObject response = q.account_details(22023427);
    EXPECT_FALSE(response.isEmpty());
    tmdb::Account a(response);
    EXPECT_EQ(a.id(), 22023427);
    EXPECT_EQ(a.iso6391(), "en");
    EXPECT_EQ(a.iso31661(), "GB");
    EXPECT_EQ(a.name(), "");
    EXPECT_EQ(a.username(), "supersliser");
    EXPECT_TRUE(a.includeAdult());
    EXPECT_EQ(a.avatar()->gravatar().hash(), "467183536659af2a02f4b2dbf0901aea");
}

TEST(AccountTests, StaticConstructor)
{
    tmdb::Account account = tmdb::Account::getAccount("eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJmZWZjMDcwYTExNTZlZDExM2JjN2RhZDA1ZWM5OWMyOCIsIm5iZiI6MTc0Nzc2ODM5Mi44MDgsInN1YiI6IjY4MmNkNDQ4ODA2OTJiYWI1NTY0OTRiYyIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.4wbjpPC366q5YFsHnuo9g4bIQ2xgMB5hIHx84SejLMg", 22023427);
    EXPECT_EQ(account.id(), 22023427);
    EXPECT_EQ(account.iso6391(), "en");
    EXPECT_EQ(account.iso31661(), "GB");
    EXPECT_EQ(account.name(), "");
    EXPECT_EQ(account.username(), "supersliser");
    EXPECT_TRUE(account.includeAdult());
    EXPECT_EQ(account.avatar()->gravatar().hash(), "467183536659af2a02f4b2dbf0901aea");
}

TEST(AccountTests, setAvatar)
{
    tmdb::Account a;
    tmdb::Avatar* avatar = new tmdb::Avatar("testhash", "testpath");
    a.setAvatar(avatar);
    EXPECT_EQ(a.avatar()->gravatar().hash(), "testhash");
    EXPECT_EQ(a.avatar()->tmdb().avatarPath(), "testpath");
}

TEST(AccountTests, setGetters)
{
    tmdb::Account a;
    a.setID(12345);
    a.setISO6391("fr");
    a.setISO31661("FR");
    a.setName("Test Name");
    a.setUsername("testuser");
    a.setIncludeAdult(true);

    EXPECT_EQ(a.id(), 12345);
    EXPECT_EQ(a.iso6391(), "fr");
    EXPECT_EQ(a.iso31661(), "FR");
    EXPECT_EQ(a.name(), "Test Name");
    EXPECT_EQ(a.username(), "testuser");
    EXPECT_TRUE(a.includeAdult());
}

