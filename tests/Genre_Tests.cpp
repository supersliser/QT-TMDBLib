//
// Created by t on 26/05/25.
//

#include "Genre.h"
#include "QTMDB.h"
#include <gtest/gtest.h>

TEST(GenreTests, DefaultConstructor)
{
    tmdb::Genre genre;
    EXPECT_EQ(genre.id(), 0);
    EXPECT_TRUE(genre.name().isEmpty());
}

TEST(GenreTests, ParameterizedConstructor)
{
    tmdb::Genre genre(1, "Action");
    EXPECT_EQ(genre.id(), 1);
    EXPECT_STREQ(genre.name().toStdString().c_str(), "Action");
}

TEST(GenreTests, APIConstructor)
{
    tmdb::Genre genre("eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJmZWZjMDcwYTExNTZlZDExM2JjN2RhZDA1ZWM5OWMyOCIsIm5iZiI6MTc0Nzc2ODM5Mi44MDgsInN1YiI6IjY4MmNkNDQ4ODA2OTJiYWI1NTY0OTRiYyIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.4wbjpPC366q5YFsHnuo9g4bIQ2xgMB5hIHx84SejLMg", 28);
    EXPECT_EQ(genre.id(), 28);
    EXPECT_STREQ(genre.name().toStdString().c_str(), "Action");
}


TEST(GenreTests, APIJSON)
{
    Qtmdb q("eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJmZWZjMDcwYTExNTZlZDExM2JjN2RhZDA1ZWM5OWMyOCIsIm5iZiI6MTc0Nzc2ODM5Mi44MDgsInN1YiI6IjY4MmNkNDQ4ODA2OTJiYWI1NTY0OTRiYyIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.4wbjpPC366q5YFsHnuo9g4bIQ2xgMB5hIHx84SejLMg");
    QJsonObject response = q.genres_movie();
    EXPECT_FALSE(response.isEmpty());
    tmdb::Genre genre(response.value("genres").toArray()[0].toObject());
    EXPECT_EQ(genre.id(), 28);
    EXPECT_STREQ(genre.name().toStdString().c_str(), "Action");
}

TEST(GenreTests, StaticConstructor)
{
    tmdb::Genre genre = tmdb::Genre::getGenre("eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJmZWZjMDcwYTExNTZlZDExM2JjN2RhZDA1ZWM5OWMyOCIsIm5iZiI6MTc0Nzc2ODM5Mi44MDgsInN1YiI6IjY4MmNkNDQ4ODA2OTJiYWI1NTY0OTRiYyIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.4wbjpPC366q5YFsHnuo9g4bIQ2xgMB5hIHx84SejLMg", 28);
    EXPECT_EQ(genre.id(), 28);
    EXPECT_STREQ(genre.name().toStdString().c_str(), "Action");
}

TEST(GenreTests, GetAllGenres)
{
    auto genres = tmdb::Genre::getAllGenres("eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJmZWZjMDcwYTExNTZlZDExM2JjN2RhZDA1ZWM5OWMyOCIsIm5iZiI6MTc0Nzc2ODM5Mi44MDgsInN1YiI6IjY4MmNkNDQ4ODA2OTJiYWI1NTY0OTRiYyIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.4wbjpPC366q5YFsHnuo9g4bIQ2xgMB5hIHx84SejLMg");
    EXPECT_FALSE(genres.empty());
    EXPECT_EQ(genres[0].id(), 28); // Action
    EXPECT_STREQ(genres[0].name().toStdString().c_str(), "Action");
}

TEST(GenreTests, GetMovieGenres)
{
    auto genres = tmdb::Genre::getMovieGenres("eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJmZWZjMDcwYTExNTZlZDExM2JjN2RhZDA1ZWM5OWMyOCIsIm5iZiI6MTc0Nzc2ODM5Mi44MDgsInN1YiI6IjY4MmNkNDQ4ODA2OTJiYWI1NTY0OTRiYyIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.4wbjpPC366q5YFsHnuo9g4bIQ2xgMB5hIHx84SejLMg");
    EXPECT_FALSE(genres.empty());
    EXPECT_EQ(genres[0].id(), 28); // Action
    EXPECT_EQ(genres[0].name(), "Action");
}

TEST(GenreTests, GetTvGenres)
{
    auto genres = tmdb::Genre::getTvGenres("eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJmZWZjMDcwYTExNTZlZDExM2JjN2RhZDA1ZWM5OWMyOCIsIm5iZiI6MTc0Nzc2ODM5Mi44MDgsInN1YiI6IjY4MmNkNDQ4ODA2OTJiYWI1NTY0OTRiYyIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.4wbjpPC366q5YFsHnuo9g4bIQ2xgMB5hIHx84SejLMg");
    EXPECT_FALSE(genres.empty());
    EXPECT_EQ(genres[0].id(), 10759); // Action & Adventure
    EXPECT_STREQ(genres[0].name().toStdString().c_str(), "Action & Adventure");
}

TEST(GenreTests, setGetters)
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