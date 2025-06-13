//
// Created by t on 26/05/25.
//

#include "Sync/Genre.h"
#include "Sync/QTMDB.h"
#include <gtest/gtest.h>

TEST(GenreSyncTests, DefaultConstructor)
{
    tmdb::Genre genre;
    EXPECT_EQ(genre.id(), 0);
    EXPECT_TRUE(genre.name().isEmpty());
}

TEST(GenreSyncTests, ParameterizedConstructor)
{
    tmdb::Genre genre(1, "Action");
    EXPECT_EQ(genre.id(), 1);
    EXPECT_STREQ(genre.name().toStdString().c_str(), "Action");
}

TEST(GenreSyncTests, APIConstructor)
{
    tmdb::Genre genre(std::getenv("API_KEY"), 28);
    EXPECT_EQ(genre.id(), 28);
    EXPECT_STREQ(genre.name().toStdString().c_str(), "Action");
}


TEST(GenreSyncTests, APIJSON)
{
    Qtmdb q(std::getenv("API_KEY"));
    QJsonObject response = q.genres_movie();
    EXPECT_FALSE(response.isEmpty());
    tmdb::Genre genre(response.value("genres").toArray()[0].toObject());
    EXPECT_EQ(genre.id(), 28);
    EXPECT_STREQ(genre.name().toStdString().c_str(), "Action");
}

TEST(GenreSyncTests, StaticConstructor)
{
    tmdb::Genre genre = tmdb::Genre::getGenre(std::getenv("API_KEY"), 28);
    EXPECT_EQ(genre.id(), 28);
    EXPECT_STREQ(genre.name().toStdString().c_str(), "Action");
}

TEST(GenreSyncTests, GetAllGenres)
{
    auto genres = tmdb::Genre::getAllGenres(std::getenv("API_KEY"));
    EXPECT_FALSE(genres.empty());
    EXPECT_EQ(genres[0].id(), 28); // Action
    EXPECT_STREQ(genres[0].name().toStdString().c_str(), "Action");
}

TEST(GenreSyncTests, GetMovieGenres)
{
    auto genres = tmdb::Genre::getMovieGenres(std::getenv("API_KEY"));
    EXPECT_FALSE(genres.empty());
    EXPECT_EQ(genres[0].id(), 28); // Action
    EXPECT_EQ(genres[0].name(), "Action");
}

TEST(GenreSyncTests, GetTvGenres)
{
    auto genres = tmdb::Genre::getTvGenres(std::getenv("API_KEY"));
    EXPECT_FALSE(genres.empty());
    EXPECT_EQ(genres[0].id(), 10759); // Action & Adventure
    EXPECT_STREQ(genres[0].name().toStdString().c_str(), "Action & Adventure");
}

TEST(GenreSyncTests, setGetters)
{
    tmdb::Genre genre;
    genre.setID(1);
    genre.setName("Comedy");
    EXPECT_EQ(genre.id(), 1);
    EXPECT_STREQ(genre.name().toStdString().c_str(), "Comedy");
    genre.setID(2);
    genre.setName("Drama");
    EXPECT_EQ(genre.id(), 2);
    EXPECT_STREQ(genre.name().toStdString().c_str(), "Drama");
}