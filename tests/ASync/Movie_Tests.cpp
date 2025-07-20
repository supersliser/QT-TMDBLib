//
// Created by t on 26/05/25.
//

#include "ASync/QTMDB.h"
#include <gtest/gtest.h>
#include <QApplication>

#include "ASync/Image.h"
#include "ASync/Movie.h"
#include "Sync/WatchProvider.h"

using namespace tmdb::ASync;

TEST(MovieASyncTests, DefaultConstructor)
{
    Movie movie;
    EXPECT_TRUE(movie.adult());
    EXPECT_STREQ(movie.backdropPath().toStdString().c_str(), "EMPTY_BACKDROP_PATH");
    EXPECT_STREQ(movie.belongsToCollection().toStdString().c_str(), "EMPTY_COLLECTION");
    EXPECT_EQ(movie.budget(), 0);
    EXPECT_TRUE(movie.genres().empty());
    EXPECT_STREQ(movie.homepage().toStdString().c_str(), "EMPTY_HOMEPAGE");
    EXPECT_EQ(movie.id(), 0);
    EXPECT_STREQ(movie.imdbID().toStdString().c_str(), "EMPTY_IMDB_ID");
    EXPECT_STREQ(movie.originalTitle().toStdString().c_str(), "EMPTY_TITLE");
    EXPECT_STREQ(movie.overview().toStdString().c_str(), "EMPTY_OVERVIEW");
    EXPECT_FLOAT_EQ(movie.popularity(), 0.0f);
    EXPECT_STREQ(movie.posterPath().toStdString().c_str(), "EMPTY_POSTER_PATH");
    EXPECT_TRUE(movie.productionCompanies().empty());
    EXPECT_TRUE(movie.countries().empty());
    EXPECT_EQ(movie.releaseDate(), QDate::currentDate());
    EXPECT_EQ(movie.revenue(), 0);
    EXPECT_EQ(movie.runtime(), 0);
    EXPECT_TRUE(movie.languages().empty());
    EXPECT_STREQ(movie.status().toStdString().c_str(), "EMPTY_STATUS");
    EXPECT_STREQ(movie.tagline().toStdString().c_str(), "EMPTY_TAGLINE");
    EXPECT_STREQ(movie.title().toStdString().c_str(), "EMPTY_TITLE");
    EXPECT_TRUE(movie.video());
    EXPECT_FLOAT_EQ(movie.voteAverage(), 0.0f);
    EXPECT_EQ(movie.voteCount(), 0);
}

TEST(MovieASyncTests, APIConstructor)
{
    bool f = false;
    Movie* movie = new Movie(std::getenv("API_KEY"));
    QObject::connect(movie, &Movie::finishedLoadingMovie, [&f](Movie* movie)
    {
        EXPECT_FALSE(movie->adult());
        EXPECT_FALSE(movie->backdropPath().isNull());
        EXPECT_STREQ(movie->belongsToCollection().toStdString().c_str(), "");
        EXPECT_EQ(movie->budget(), 63000000);
        EXPECT_EQ(movie->genres()[0]->id(), 18);
        EXPECT_STREQ(movie->genres()[0]->name().toStdString().c_str(), "Drama");
        EXPECT_STREQ(movie->homepage().toStdString().c_str(), "http://www.foxmovies.com/movies/fight-club");
        EXPECT_EQ(movie->id(), 550);
        EXPECT_STREQ(movie->imdbID().toStdString().c_str(), "tt0137523");
        EXPECT_STREQ(movie->originalTitle().toStdString().c_str(), "Fight Club");
        EXPECT_STREQ(movie->overview().toStdString().c_str(),
                     "A ticking-time-bomb insomniac and a slippery soap salesman channel primal male aggression into a shocking new form of therapy. Their concept catches on, with underground \"fight clubs\" forming in every town, until an eccentric gets in the way and ignites an out-of-control spiral toward oblivion.");
        EXPECT_GT(movie->popularity(), 0.0f);
        EXPECT_FALSE(movie->posterPath().isNull());
        EXPECT_EQ(movie->productionCompanies()[0]->id(), 711);
        EXPECT_STREQ(movie->productionCompanies()[0]->name().toStdString().c_str(), "Fox 2000 Pictures");
        EXPECT_STREQ(movie->countries()[0]->isoCountryCode().toStdString().c_str(), "DE");
        EXPECT_EQ(movie->releaseDate(), QDate(1999, 10, 15));
        EXPECT_EQ(movie->revenue(), 100853753);
        EXPECT_EQ(movie->runtime(), 139);
        EXPECT_STREQ(movie->languages()[0]->iso6391().toStdString().c_str(), "en");
        EXPECT_STREQ(movie->status().toStdString().c_str(), "Released");
        EXPECT_STREQ(movie->tagline().toStdString().c_str(), "Mischief. Mayhem. Soap.");
        EXPECT_STREQ(movie->title().toStdString().c_str(), "Fight Club");
        EXPECT_FALSE(movie->video());
        EXPECT_GT(movie->voteAverage(), 0);
        EXPECT_GT(movie->voteCount(), 30292);
        f = true;
    });
    movie->loadMovie(550);
    while (!f)
    {
        QApplication::processEvents();
    }
}


TEST(MovieASyncTests, searchForMovies)
{
    auto m = new Movie(std::getenv("API_KEY"));
    bool f = false;
    QObject::connect(m, &Movie::finishedLoadingSearchResults, [&f](std::vector<Movie*> movies)
    {
        QObject::connect(movies[0]->genres()[0], &Genre::finishedLoadingGenre, [&f](Genre* genre)
        {
            EXPECT_STREQ(genre->name().toStdString().c_str(), "Drama");
            f = true;
        });
        EXPECT_FALSE(movies.empty());
        EXPECT_FALSE(movies[0]->adult());
        EXPECT_FALSE(movies[0]->backdropPath().isNull());
        EXPECT_STREQ(movies[0]->belongsToCollection().toStdString().c_str(), "");
        EXPECT_EQ(movies[0]->budget(), 63000000);
        EXPECT_STREQ(movies[0]->homepage().toStdString().c_str(), "http://www.foxmovies.com/movies/fight-club");
        EXPECT_EQ(movies[0]->id(), 550);
        EXPECT_STREQ(movies[0]->imdbID().toStdString().c_str(), "tt0137523");
        EXPECT_STREQ(movies[0]->originalLanguage()->iso6391().toStdString().c_str(), "en");
        EXPECT_STREQ(movies[0]->originalTitle().toStdString().c_str(), "Fight Club");
        EXPECT_STREQ(movies[0]->overview().toStdString().c_str(),
                     "A ticking-time-bomb insomniac and a slippery soap salesman channel primal male aggression into a shocking new form of therapy. Their concept catches on, with underground \"fight clubs\" forming in every town, until an eccentric gets in the way and ignites an out-of-control spiral toward oblivion.");
        EXPECT_GT(movies[0]->popularity(), 0);
        EXPECT_FALSE(movies[0]->posterPath().isNull());
        EXPECT_EQ(movies[0]->productionCompanies()[0]->id(), 711);
        EXPECT_STREQ(movies[0]->productionCompanies()[0]->name().toStdString().c_str(), "Fox 2000 Pictures");
        EXPECT_STREQ(movies[0]->countries()[0]->isoCountryCode().toStdString().c_str(), "DE");
        EXPECT_EQ(movies[0]->releaseDate(), QDate(1999, 10, 15));
        EXPECT_EQ(movies[0]->revenue(), 100853753);
        EXPECT_EQ(movies[0]->runtime(), 139);
        EXPECT_STREQ(movies[0]->languages()[0]->iso6391().toStdString().c_str(), "en");
        EXPECT_STREQ(movies[0]->status().toStdString().c_str(), "Released");
        EXPECT_STREQ(movies[0]->tagline().toStdString().c_str(), "Mischief. Mayhem. Soap.");
        EXPECT_STREQ(movies[0]->title().toStdString().c_str(), "Fight Club");
        EXPECT_FALSE(movies[0]->video());
        EXPECT_GT(movies[0]->voteAverage(), 0);
        EXPECT_GT(movies[0]->voteCount(), 30292);
        f = true;
    });
    m->loadSearchResults("Fight Club");
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(MovieASyncTests, setGetters)
{
    Movie movie;
    movie.setAdult(false);
    movie.setBackdropPath("./1.png");
    movie.setBelongsToCollection("collection1");
    movie.setBudget(20000);
    movie.setHomepage("https://www.thomaslower.com");
    movie.setId(22);
    movie.setImdbID("ttthelloworld");
    movie.setOriginalTitle("Title");
    movie.setOverview("Overview");
    movie.setPopularity(43.3764);
    movie.setPosterPath("Path.png");
    movie.setReleaseDate(QDate(2004, 10, 22));
    movie.setRevenue(6);
    movie.setRuntime(179);
    movie.setStatus("EXISTS I PROMISE");
    movie.setTagline("Tagline");
    movie.setTitle("Title");
    movie.setVideo(false);
    movie.setVoteAverage(50);
    movie.setVoteCount(10);

    EXPECT_FALSE(movie.adult());
    EXPECT_STREQ(movie.backdropPath().toStdString().c_str(), "./1.png");
    EXPECT_STREQ(movie.belongsToCollection().toStdString().c_str(), "collection1");
    EXPECT_EQ(movie.budget(), 20000);
    EXPECT_STREQ(movie.homepage().toStdString().c_str(), "https://www.thomaslower.com");
    EXPECT_EQ(movie.id(), 22);
    EXPECT_STREQ(movie.originalTitle().toStdString().c_str(), "Title");
    EXPECT_STREQ(movie.overview().toStdString().c_str(), "Overview");
    EXPECT_FLOAT_EQ(movie.popularity(), 43.3764);
    EXPECT_STREQ(movie.posterPath().toStdString().c_str(), "Path.png");
    EXPECT_EQ(movie.releaseDate(), QDate(2004, 10, 22));
    EXPECT_EQ(movie.revenue(), 6);
    EXPECT_EQ(movie.runtime(), 179);
    EXPECT_STREQ(movie.status().toStdString().c_str(), "EXISTS I PROMISE");
    EXPECT_STREQ(movie.tagline().toStdString().c_str(), "Tagline");
    EXPECT_STREQ(movie.title().toStdString().c_str(), "Title");
    EXPECT_FALSE(movie.video());
    EXPECT_FLOAT_EQ(movie.voteAverage(), 50);
    EXPECT_EQ(movie.voteCount(), 10);
}

TEST(MovieASyncTests, getNowPlaying)
{
    auto m = new Movie(std::getenv("API_KEY"));
    bool f = false;
    QObject::connect(m, &Movie::finishedLoadingNowPlaying, [&f](std::vector<Movie*> movies)
    {
        EXPECT_FALSE(movies.empty());

        for (const auto& movie : movies)
        {
            EXPECT_FALSE(movie->adult());
            EXPECT_STRNE(movie->backdropPath().toStdString().c_str(), "EMPTY_BACKDROP_PATH");
            EXPECT_STRNE(movie->belongsToCollection().toStdString().c_str(), "EMPTY_COLLECTION");
            EXPECT_FALSE(movie->genres().empty());
            EXPECT_STRNE(movie->homepage().toStdString().c_str(), "EMPTY_HOMEPAGE");
            EXPECT_NE(movie->id(), 0);
            EXPECT_STRNE(movie->imdbID().toStdString().c_str(), "EMPTY_IMDB_ID");
            EXPECT_STRNE(movie->originalLanguage()->englishName().toStdString().c_str(), "");
            EXPECT_STRNE(movie->originalTitle().toStdString().c_str(), "EMPTY_TITLE");
            EXPECT_STRNE(movie->overview().toStdString().c_str(), "EMPTY_OVERVIEW");
            EXPECT_STRNE(movie->posterPath().toStdString().c_str(), "EMPTY_POSTER_PATH");
            EXPECT_FALSE(movie->productionCompanies().empty());
            EXPECT_FALSE(movie->countries().empty());
            EXPECT_NE(movie->releaseDate(), QDate::currentDate());
            EXPECT_FALSE(movie->languages().empty());
            EXPECT_STRNE(movie->status().toStdString().c_str(), "EMPTY_STATUS");
            EXPECT_STRNE(movie->tagline().toStdString().c_str(), "EMPTY_TAGLINE");
            EXPECT_STRNE(movie->title().toStdString().c_str(), "EMPTY_TITLE");
        }
        f = true;
    });
    m->loadNowPlaying();
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(MovieASyncTests, getPopular)
{
    auto m = new Movie(std::getenv("API_KEY"));
    bool f = false;
    QObject::connect(m, &Movie::finishedLoadingPopular, [&f](std::vector<Movie*> movies)
    {
        EXPECT_FALSE(movies.empty());

        for (const auto& movie : movies)
        {
            EXPECT_STRNE(movie->backdropPath().toStdString().c_str(), "EMPTY_BACKDROP_PATH");
            EXPECT_STRNE(movie->belongsToCollection().toStdString().c_str(), "EMPTY_COLLECTION");
            EXPECT_FALSE(movie->genres().empty());
            EXPECT_STRNE(movie->homepage().toStdString().c_str(), "EMPTY_HOMEPAGE");
            EXPECT_NE(movie->id(), 0);
            EXPECT_STRNE(movie->imdbID().toStdString().c_str(), "EMPTY_IMDB_ID");
            EXPECT_STRNE(movie->originalLanguage()->englishName().toStdString().c_str(), "");
            EXPECT_STRNE(movie->originalTitle().toStdString().c_str(), "EMPTY_TITLE");
            EXPECT_STRNE(movie->overview().toStdString().c_str(), "EMPTY_OVERVIEW");
            EXPECT_STRNE(movie->posterPath().toStdString().c_str(), "EMPTY_POSTER_PATH");
            EXPECT_FALSE(movie->productionCompanies().empty());
            EXPECT_FALSE(movie->countries().empty());
            EXPECT_NE(movie->releaseDate(), QDate::currentDate());
            EXPECT_FALSE(movie->languages().empty());
            EXPECT_STRNE(movie->status().toStdString().c_str(), "EMPTY_STATUS");
            EXPECT_STRNE(movie->tagline().toStdString().c_str(), "EMPTY_TAGLINE");
            EXPECT_STRNE(movie->title().toStdString().c_str(), "EMPTY_TITLE");
        }
        f = true;
    });
    m->loadPopular();
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(MovieASyncTests, getTopRated)
{
    auto m = new Movie(std::getenv("API_KEY"));
    bool f = false;
    QObject::connect(m, &Movie::finishedLoadingTopRated, [&f](std::vector<Movie*> movies)
    {
        EXPECT_FALSE(movies.empty());

        for (const auto& movie : movies)
        {
            EXPECT_STRNE(movie->backdropPath().toStdString().c_str(), "EMPTY_BACKDROP_PATH");
            EXPECT_STRNE(movie->belongsToCollection().toStdString().c_str(), "EMPTY_COLLECTION");
            EXPECT_FALSE(movie->genres().empty());
            EXPECT_STRNE(movie->homepage().toStdString().c_str(), "EMPTY_HOMEPAGE");
            EXPECT_NE(movie->id(), 0);
            EXPECT_STRNE(movie->imdbID().toStdString().c_str(), "EMPTY_IMDB_ID");
            EXPECT_STRNE(movie->originalLanguage()->englishName().toStdString().c_str(), "");
            EXPECT_STRNE(movie->originalTitle().toStdString().c_str(), "EMPTY_TITLE");
            EXPECT_STRNE(movie->overview().toStdString().c_str(), "EMPTY_OVERVIEW");
            EXPECT_STRNE(movie->posterPath().toStdString().c_str(), "EMPTY_POSTER_PATH");
            EXPECT_FALSE(movie->productionCompanies().empty());
            EXPECT_NE(movie->releaseDate(), QDate::currentDate());
            EXPECT_FALSE(movie->languages().empty());
            EXPECT_STRNE(movie->status().toStdString().c_str(), "EMPTY_STATUS");
            EXPECT_STRNE(movie->tagline().toStdString().c_str(), "EMPTY_TAGLINE");
            EXPECT_STRNE(movie->title().toStdString().c_str(), "EMPTY_TITLE");
        }
        f = true;
    });
    m->loadTopRated();
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(MovieASyncTests, getUpcoming)
{
    auto m = new Movie(std::getenv("API_KEY"));
    bool f = false;
    QObject::connect(m, &Movie::finishedLoadingUpcoming, [&f](std::vector<Movie*> movies)
    {
        EXPECT_FALSE(movies.empty());

        for (const auto& movie : movies)
        {
            EXPECT_STRNE(movie->backdropPath().toStdString().c_str(), "EMPTY_BACKDROP_PATH");
            EXPECT_STRNE(movie->belongsToCollection().toStdString().c_str(), "EMPTY_COLLECTION");
            EXPECT_STRNE(movie->homepage().toStdString().c_str(), "EMPTY_HOMEPAGE");
            EXPECT_NE(movie->id(), 0);
            EXPECT_STRNE(movie->imdbID().toStdString().c_str(), "EMPTY_IMDB_ID");
            EXPECT_STRNE(movie->originalLanguage()->englishName().toStdString().c_str(), "");
            EXPECT_STRNE(movie->originalTitle().toStdString().c_str(), "EMPTY_TITLE");
            EXPECT_STRNE(movie->overview().toStdString().c_str(), "EMPTY_OVERVIEW");
            EXPECT_STRNE(movie->posterPath().toStdString().c_str(), "EMPTY_POSTER_PATH");
            EXPECT_GT(movie->releaseDate(), QDate(1990, 1, 1));
            EXPECT_STRNE(movie->status().toStdString().c_str(), "EMPTY_STATUS");
            EXPECT_STRNE(movie->tagline().toStdString().c_str(), "EMPTY_TAGLINE");
            EXPECT_STRNE(movie->title().toStdString().c_str(), "EMPTY_TITLE");
        }
        f = true;
    });
    m->loadUpcoming();
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(MovieASyncTests, getBackdrop)
{
    auto m = new Movie(std::getenv("API_KEY"), 550);
    bool f = false;
    while (m->title() == "EMPTY_TITLE")
    {
        QApplication::processEvents();
    }
    QObject::connect(m, &Movie::finishedLoadingBackdrop, [&f](QPixmap backdrop)
    {
        EXPECT_EQ(backdrop.height(), 1080);
        EXPECT_EQ(backdrop.width(), 1920);
        f = true;
    });
    m->loadBackdrop(0, "original");
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(MovieASyncTests, getLogo)
{
    auto movie = new Movie(std::getenv("API_KEY"), 550);
    bool f = false;
    while (movie->title() == "EMPTY_TITLE")
    {
        QApplication::processEvents();
    }
    QObject::connect(movie, &Movie::finishedLoadingLogo, [&f](QPixmap logo)
    {
        EXPECT_EQ(logo.height(), 389);
        EXPECT_EQ(logo.width(), 1804);
        f = true;
    });
    movie->loadLogo(0, "original");
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(MovieASyncTests, getPoster)
{
    auto movie = new Movie(std::getenv("API_KEY"), 550);
    bool f = false;
    while (movie->title() == "EMPTY_TITLE")
    {
        QApplication::processEvents();
    }
    QObject::connect(movie, &Movie::finishedLoadingPoster, [&f](QPixmap poster)
    {
        EXPECT_EQ(poster.height(), 3000);
        EXPECT_EQ(poster.width(), 2000);
        f = true;
    });
    movie->loadPoster(0, "original");
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(MovieASyncTests, getRecommended)
{
    auto m = new Movie(std::getenv("API_KEY"), 550);
    while (m->title() == "EMPTY_TITLE")
    {
        QApplication::processEvents();
    }
    bool f = false;
    QObject::connect(m, &Movie::finishedLoadingRecommendations, [&f](std::vector<Movie*> movies)
    {
        EXPECT_FALSE(movies.empty());

        for (const auto& movie : movies)
        {
            EXPECT_STRNE(movie->backdropPath().toStdString().c_str(), "EMPTY_BACKDROP_PATH");
            EXPECT_STRNE(movie->belongsToCollection().toStdString().c_str(), "EMPTY_COLLECTION");
            EXPECT_STRNE(movie->homepage().toStdString().c_str(), "EMPTY_HOMEPAGE");
            EXPECT_NE(movie->id(), 0);
            EXPECT_STRNE(movie->imdbID().toStdString().c_str(), "EMPTY_IMDB_ID");
            EXPECT_STRNE(movie->originalLanguage()->englishName().toStdString().c_str(), "");
            EXPECT_STRNE(movie->originalTitle().toStdString().c_str(), "EMPTY_TITLE");
            EXPECT_STRNE(movie->overview().toStdString().c_str(), "EMPTY_OVERVIEW");
            EXPECT_STRNE(movie->posterPath().toStdString().c_str(), "EMPTY_POSTER_PATH");
            EXPECT_GT(movie->releaseDate(), QDate(1900, 1, 1));
            EXPECT_STRNE(movie->status().toStdString().c_str(), "EMPTY_STATUS");
            EXPECT_STRNE(movie->tagline().toStdString().c_str(), "EMPTY_TAGLINE");
            EXPECT_STRNE(movie->title().toStdString().c_str(), "EMPTY_TITLE");
        }
        f = true;
    });
    m->loadRecommendations();
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(MovieASyncTests, getSimilar)
{
    auto m = new Movie(std::getenv("API_KEY"), 550);
    while (m->title() == "EMPTY_TITLE")
    {
        QApplication::processEvents();
    }
    bool f = false;
    QObject::connect(m, &Movie::finishedLoadingSimilar, [&f](std::vector<Movie*> movies)
    {
        EXPECT_FALSE(movies.empty());

        for (const auto& movie : movies)
        {
            EXPECT_STRNE(movie->backdropPath().toStdString().c_str(), "EMPTY_BACKDROP_PATH");
            EXPECT_STRNE(movie->belongsToCollection().toStdString().c_str(), "EMPTY_COLLECTION");
            EXPECT_STRNE(movie->homepage().toStdString().c_str(), "EMPTY_HOMEPAGE");
            EXPECT_NE(movie->id(), 0);
            EXPECT_STRNE(movie->imdbID().toStdString().c_str(), "EMPTY_IMDB_ID");
            EXPECT_STRNE(movie->originalLanguage()->englishName().toStdString().c_str(), "");
            EXPECT_STRNE(movie->originalTitle().toStdString().c_str(), "EMPTY_TITLE");
            EXPECT_STRNE(movie->overview().toStdString().c_str(), "EMPTY_OVERVIEW");
            EXPECT_STRNE(movie->posterPath().toStdString().c_str(), "EMPTY_POSTER_PATH");
            EXPECT_GT(movie->releaseDate(), QDate(1900, 1, 1));
            EXPECT_STRNE(movie->status().toStdString().c_str(), "EMPTY_STATUS");
            EXPECT_STRNE(movie->tagline().toStdString().c_str(), "EMPTY_TAGLINE");
            EXPECT_STRNE(movie->title().toStdString().c_str(), "EMPTY_TITLE");
        }
        f = true;
    });
    m->loadSimilar();
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(MovieASyncTests, getWatchProviders)
{
    auto m = new Movie(std::getenv("API_KEY"), 550);
    while (m->title() == "EMPTY_TITLE")
    {
        QApplication::processEvents();
    }
    bool f = false;
    QObject::connect(m, &Movie::finishedLoadingWatchProviders, [&f](std::vector<WatchProvider*> providers)
    {
        EXPECT_FALSE(providers.empty());
        EXPECT_EQ(providers[0]->type(), tmdb::flatrate);
        EXPECT_EQ(providers[0]->providerID(), 337);
        EXPECT_STREQ(providers[0]->providerName().toStdString().c_str(), "Disney Plus");
        EXPECT_FALSE(providers[0]->link().toString().isNull());
<<<<<<< HEAD
        EXPECT_FALSE(providers[0]->logoPath().isNull());
=======
        EXPECT_STREQ(providers[0]->logoPath().toStdString().c_str(), "/97yvRBw1GzX7fXprcF80er19ot.jpg");
>>>>>>> 9d81f359eabe1110fb5ea77c9433c2092198b48c
        f = true;
    });
    auto c = new Country( std::getenv("API_KEY"));
    c->setISOCountryCode("GB");
    m->loadWatchProviders(c);
    while (!f)
    {
        QApplication::processEvents();
    }
}
