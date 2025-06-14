//
// Created by t on 26/05/25.
//

#include <QApplication>

#include "ASync/Genre.h"
#include "ASync/QTMDB.h"
#include <gtest/gtest.h>

using namespace tmdb::ASync;

TEST(GenreASyncTests, DefaultConstructor)
{
    Genre genre;
    EXPECT_EQ(genre.id(), 0);
    EXPECT_TRUE(genre.name().isEmpty());
}

TEST(GenreASyncTests, APIConstructor)
{
    bool f = false;
    Genre* genre = new Genre(std::getenv("API_KEY"));
    QObject::connect(genre, &Genre::finishedLoadingGenre, [&f](Genre* g)
    {
        EXPECT_EQ(g->id(), 28);
        EXPECT_STREQ(g->name().toStdString().c_str(), "Action");
        f = true;
    });
    genre->loadGenre(28);
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(GenreASyncTests, APIJSON)
{
    bool f = false;
    aQtmdb q(std::getenv("API_KEY"));
    QObject::connect(&q, &aQtmdb::finishedLoadingData, [&f](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        Genre* genre = new Genre(data.value("genres").toArray()[0].toObject(), std::getenv("API_KEY"));
        EXPECT_EQ(genre->id(), 28);
        EXPECT_STREQ(genre->name().toStdString().c_str(), "Action");
        f = true;
    });
    q.genres_movie();
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(GenreASyncTests, GetAllGenres)
{
    bool f = false;
    auto temp = new Genre(std::getenv("API_KEY"));
    QObject::connect(temp, &Genre::finishedLoadingAllGenres, [&f](const std::vector<Genre*>& genres)
    {
        EXPECT_FALSE(genres.empty());
        EXPECT_EQ(genres[0]->id(), 28); // Action
        EXPECT_STREQ(genres[0]->name().toStdString().c_str(), "Action");
        f = true;
    });
    temp->loadAllGenres();
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(GenreASyncTests, GetMovieGenres)
{
    bool f = false;
    auto temp = new Genre(std::getenv("API_KEY"));
    QObject::connect(temp, &Genre::finishedLoadingMovieGenres, [&f](const std::vector<Genre*> genres)
    {
        EXPECT_FALSE(genres.empty());
        EXPECT_EQ(genres[0]->id(), 28); // Action
        EXPECT_STREQ(genres[0]->name().toStdString().c_str(), "Action");
        f = true;
    });
    temp->loadMovieGenres();
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(GenreASyncTests, GetTvGenres)
{
    bool f = false;
    auto temp = new Genre(std::getenv("API_KEY"));
    QObject::connect(temp, &Genre::finishedLoadingTvGenres, [&f](const std::vector<Genre*> genres)
    {
        EXPECT_FALSE(genres.empty());
        EXPECT_EQ(genres[0]->id(), 10759); // Action
        EXPECT_STREQ(genres[0]->name().toStdString().c_str(), "Action & Adventure");
        f = true;
    });
    temp->loadTvGenres();
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(GenreASyncTests, setGetters)
{
    Genre genre;
    genre.setID(1);
    genre.setName("Comedy");
    EXPECT_EQ(genre.id(), 1);
    EXPECT_STREQ(genre.name().toStdString().c_str(), "Comedy");
    genre.setID(2);
    genre.setName("Drama");
    EXPECT_EQ(genre.id(), 2);
    EXPECT_STREQ(genre.name().toStdString().c_str(), "Drama");
}
