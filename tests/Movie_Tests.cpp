//
// Created by t on 26/05/25.
//

#include "Movie.h"
#include "QTMDB.h"
#include <gtest/gtest.h>

TEST(MovieTests, DefaultConstructor)
{
    tmdb::Movie movie;
    EXPECT_EQ(movie.id(), 0);
    EXPECT_TRUE(movie.title().isEmpty());
}

TEST(MovieTests, APIConstructor)
{
    tmdb::Movie movie("eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJmZWZjMDcwYTExNTZlZDExM2JjN2RhZDA1ZWM5OWMyOCIsIm5iZiI6MTc0Nzc2ODM5Mi44MDgsInN1YiI6IjY4MmNkNDQ4ODA2OTJiYWI1NTY0OTRiYyIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.4wbjpPC366q5YFsHnuo9g4bIQ2xgMB5hIHx84SejLMg", 550);
    EXPECT_FALSE(movie.adult());
    EXPECT_STREQ(movie.backdropPath().toStdString().c_str(), "/xRyINp9KfMLVjRiO5nCsoRDdvvF.jpg");
    EXPECT_STREQ(movie.belongsToCollection().toStdString().c_str(), "");
    EXPECT_EQ(movie.budget(), 63000000);
    EXPECT_EQ(movie.genres()[0].id(), 18);
    EXPECT_STREQ(movie.genres()[0].name().toStdString().c_str(), "Drama");
    EXPECT_STREQ(movie.homepage().toStdString().c_str(), "http://www.foxmovies.com/movies/fight-club");
    EXPECT_EQ(movie.id(), 550);
    EXPECT_STREQ(movie.imdbID().toStdString().c_str(), "tt0137523");
    EXPECT_STREQ(movie.originalLanguage().iso_639_1.toStdString().c_str(), "en");
    EXPECT_STREQ(movie.originalTitle().toStdString().c_str(), "Fight Club");
    EXPECT_STREQ(movie.overview().toStdString().c_str(), "A ticking-time-bomb insomniac and a slippery soap salesman channel primal male aggression into a shocking new form of therapy. Their concept catches on, with underground \"fight clubs\" forming in every town, until an eccentric gets in the way and ignites an out-of-control spiral toward oblivion.");
    EXPECT_FLOAT_EQ(movie.popularity(), 30.8279);
    EXPECT_STREQ(movie.posterPath().toStdString().c_str(), "/pB8BM7pdSp6B6Ih7QZ4DrQ3PmJK.jpg");
    EXPECT_EQ(movie.productionCompanies()[0].id(), 711);
    EXPECT_STREQ(movie.productionCompanies()[0].name().toStdString().c_str(), "Fox 2000 Pictures");
    EXPECT_STREQ(movie.countries()[0].country_code.toStdString().c_str(), "DE");
    EXPECT_EQ(movie.releaseDate(), QDate(1999, 10, 15));
    EXPECT_EQ(movie.revenue(), 100853753);
    EXPECT_EQ(movie.runtime(), 139);
    EXPECT_STREQ(movie.languages()[0].iso_639_1.toStdString().c_str(), "en");
    EXPECT_STREQ(movie.status().toStdString().c_str(), "Released");
    EXPECT_STREQ(movie.tagline().toStdString().c_str(), "Mischief. Mayhem. Soap.");
    EXPECT_STREQ(movie.title().toStdString().c_str(), "Fight Club");
    EXPECT_FALSE(movie.video());
    EXPECT_FLOAT_EQ(movie.voteAverage(), 8.438);
    EXPECT_EQ(movie.voteCount(), 30292);

}

TEST(MovieTests, StaticConstructor)
{
    tmdb::Movie movie = tmdb::Movie::getMovie("eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJmZWZjMDcwYTExNTZlZDExM2JjN2RhZDA1ZWM5OWMyOCIsIm5iZiI6MTc0Nzc2ODM5Mi44MDgsInN1YiI6IjY4MmNkNDQ4ODA2OTJiYWI1NTY0OTRiYyIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.4wbjpPC366q5YFsHnuo9g4bIQ2xgMB5hIHx84SejLMg", 550);
    EXPECT_EQ(movie.id(), 550);
    EXPECT_STREQ(movie.title().toStdString().c_str(), "Fight Club");
}

TEST(MovieTests, searchForMovies)
{
    std::vector<tmdb::Movie> movies = tmdb::Movie::searchForMovies(
        "eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJmZWZjMDcwYTExNTZlZDExM2JjN2RhZDA1ZWM5OWMyOCIsIm5iZiI6MTc0Nzc2ODM5Mi44MDgsInN1YiI6IjY4MmNkNDQ4ODA2OTJiYWI1NTY0OTRiYyIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.4wbjpPC366q5YFsHnuo9g4bIQ2xgMB5hIHx84SejLMg",
        "Fight Club");

    EXPECT_EQ(movies[0].id(), 550);
    EXPECT_STREQ(movies[0].title().toStdString().c_str(), "Fight Club");
}

TEST(MovieTests, setGetters)
{
    tmdb::Movie movie;
    movie.setId(550);
    movie.setTitle("Fight Club");
    movie.setOriginalTitle("Fight Club");
    movie.setOverview("A ticking-time-bomb insomniac and a slippery soap salesman channel primal aggression into a shocking new form of therapy. Their concept catches on, with underground fight clubs forming in every town, until an eccentric gets in the way and ignites an out-of-control spiral toward oblivion.");
    movie.setReleaseDate(QDate(1999, 10, 15));
    movie.setVoteAverage(8.4);
    movie.setVoteCount(21800);
    movie.setPopularity(61.416);
    movie.setRuntime(139);

    EXPECT_EQ(movie.id(), 550);
    EXPECT_STREQ(movie.title().toStdString().c_str(), "Fight Club");
    EXPECT_STREQ(movie.originalTitle().toStdString().c_str(), "Fight Club");
    EXPECT_STREQ(movie.overview().toStdString().c_str(), "A ticking-time-bomb insomniac and a slippery soap salesman channel primal aggression into a shocking new form of therapy. Their concept catches on, with underground fight clubs forming in every town, until an eccentric gets in the way and ignites an out-of-control spiral toward oblivion.");
    EXPECT_EQ(movie.releaseDate(), QDate(1999, 10, 15));
    EXPECT_FLOAT_EQ(movie.voteAverage(), 8.4);
    EXPECT_EQ(movie.voteCount(), 21800);
    EXPECT_FLOAT_EQ(movie.popularity(), 61.416);
    EXPECT_EQ(movie.runtime(), 139);
}