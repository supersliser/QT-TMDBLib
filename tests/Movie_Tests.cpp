//
// Created by t on 26/05/25.
//

#include "Sync/Movie.h"
#include "Sync/QTMDB.h"
#include <gtest/gtest.h>

TEST(MovieTests, DefaultConstructor)
{
    tmdb::Movie movie;
    EXPECT_TRUE(movie.adult());
    EXPECT_STREQ(movie.backdropPath().toStdString().c_str(), "EMPTY_BACKDROP_PATH");
    EXPECT_STREQ(movie.belongsToCollection().toStdString().c_str(), "EMPTY_COLLECTION");
    EXPECT_EQ(movie.budget(), 0);
    EXPECT_TRUE(movie.genres().empty());
    EXPECT_STREQ(movie.homepage().toStdString().c_str(), "EMPTY_HOMEPAGE");
    EXPECT_EQ(movie.id(), 0);
    EXPECT_STREQ(movie.imdbID().toStdString().c_str(), "EMPTY_IMDB_ID");
    EXPECT_STREQ(movie.originalLanguage().english_name.toStdString().c_str(), "");
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

TEST(MovieTests, APIConstructor)
{
    tmdb::Movie movie(std::getenv("API_KEY"), 550);
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
    EXPECT_GT(movie.popularity(), 0.0f);
    EXPECT_STREQ(movie.posterPath().toStdString().c_str(), "/pB8BM7pdSp6B6Ih7QZ4DrQ3PmJK.jpg");
    EXPECT_EQ(movie.productionCompanies()[0].id(), 711);
    EXPECT_STREQ(movie.productionCompanies()[0].name().toStdString().c_str(), "Fox 2000 Pictures");
    EXPECT_STREQ(movie.countries()[0].iso_3166_1.toStdString().c_str(), "DE");
    EXPECT_EQ(movie.releaseDate(), QDate(1999, 10, 15));
    EXPECT_EQ(movie.revenue(), 100853753);
    EXPECT_EQ(movie.runtime(), 139);
    EXPECT_STREQ(movie.languages()[0].iso_639_1.toStdString().c_str(), "en");
    EXPECT_STREQ(movie.status().toStdString().c_str(), "Released");
    EXPECT_STREQ(movie.tagline().toStdString().c_str(), "Mischief. Mayhem. Soap.");
    EXPECT_STREQ(movie.title().toStdString().c_str(), "Fight Club");
    EXPECT_FALSE(movie.video());
    EXPECT_GT(movie.voteAverage(), 0);
    EXPECT_GT(movie.voteCount(), 30292);

}

TEST(MovieTests, StaticConstructor)
{
    tmdb::Movie movie = tmdb::Movie::getMovie(std::getenv("API_KEY"), 550);
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
    EXPECT_GT(movie.popularity(), 0);
    EXPECT_STREQ(movie.posterPath().toStdString().c_str(), "/pB8BM7pdSp6B6Ih7QZ4DrQ3PmJK.jpg");
    EXPECT_EQ(movie.productionCompanies()[0].id(), 711);
    EXPECT_STREQ(movie.productionCompanies()[0].name().toStdString().c_str(), "Fox 2000 Pictures");
    EXPECT_STREQ(movie.countries()[0].iso_3166_1.toStdString().c_str(), "DE");
    EXPECT_EQ(movie.releaseDate(), QDate(1999, 10, 15));
    EXPECT_EQ(movie.revenue(), 100853753);
    EXPECT_EQ(movie.runtime(), 139);
    EXPECT_STREQ(movie.languages()[0].iso_639_1.toStdString().c_str(), "en");
    EXPECT_STREQ(movie.status().toStdString().c_str(), "Released");
    EXPECT_STREQ(movie.tagline().toStdString().c_str(), "Mischief. Mayhem. Soap.");
    EXPECT_STREQ(movie.title().toStdString().c_str(), "Fight Club");
    EXPECT_FALSE(movie.video());
    EXPECT_GT(movie.voteAverage(), 0);
    EXPECT_GT(movie.voteCount(), 30292);
}

TEST(MovieTests, searchForMovies)
{
    std::vector<tmdb::Movie> movies = tmdb::Movie::searchForMovies(
        std::getenv("API_KEY"),
        "Fight Club");

    EXPECT_FALSE(movies[0].adult());
    EXPECT_STREQ(movies[0].backdropPath().toStdString().c_str(), "/xRyINp9KfMLVjRiO5nCsoRDdvvF.jpg");
    EXPECT_STREQ(movies[0].belongsToCollection().toStdString().c_str(), "");
    EXPECT_EQ(movies[0].budget(), 63000000);
    EXPECT_EQ(movies[0].genres()[0].id(), 18);
    EXPECT_STREQ(movies[0].genres()[0].name().toStdString().c_str(), "Drama");
    EXPECT_STREQ(movies[0].homepage().toStdString().c_str(), "http://www.foxmovies.com/movies/fight-club");
    EXPECT_EQ(movies[0].id(), 550);
    EXPECT_STREQ(movies[0].imdbID().toStdString().c_str(), "tt0137523");
    EXPECT_STREQ(movies[0].originalLanguage().iso_639_1.toStdString().c_str(), "en");
    EXPECT_STREQ(movies[0].originalTitle().toStdString().c_str(), "Fight Club");
    EXPECT_STREQ(movies[0].overview().toStdString().c_str(), "A ticking-time-bomb insomniac and a slippery soap salesman channel primal male aggression into a shocking new form of therapy. Their concept catches on, with underground \"fight clubs\" forming in every town, until an eccentric gets in the way and ignites an out-of-control spiral toward oblivion.");
    EXPECT_GT(movies[0].popularity(), 0);
    EXPECT_STREQ(movies[0].posterPath().toStdString().c_str(), "/pB8BM7pdSp6B6Ih7QZ4DrQ3PmJK.jpg");
    EXPECT_EQ(movies[0].productionCompanies()[0].id(), 711);
    EXPECT_STREQ(movies[0].productionCompanies()[0].name().toStdString().c_str(), "Fox 2000 Pictures");
    EXPECT_STREQ(movies[0].countries()[0].iso_3166_1.toStdString().c_str(), "DE");
    EXPECT_EQ(movies[0].releaseDate(), QDate(1999, 10, 15));
    EXPECT_EQ(movies[0].revenue(), 100853753);
    EXPECT_EQ(movies[0].runtime(), 139);
    EXPECT_STREQ(movies[0].languages()[0].iso_639_1.toStdString().c_str(), "en");
    EXPECT_STREQ(movies[0].status().toStdString().c_str(), "Released");
    EXPECT_STREQ(movies[0].tagline().toStdString().c_str(), "Mischief. Mayhem. Soap.");
    EXPECT_STREQ(movies[0].title().toStdString().c_str(), "Fight Club");
    EXPECT_FALSE(movies[0].video());
    EXPECT_GT(movies[0].voteAverage(), 0);
    EXPECT_GT(movies[0].voteCount(), 30292);
}

TEST(MovieTests, setGetters)
{
    tmdb::Movie movie;
    movie.setAdult(false);
    movie.setBackdropPath("./1.png");
    movie.setBelongsToCollection("collection1");
    movie.setBudget(20000);
    movie.setGenres({tmdb::Genre(5, "Drama")});
    movie.setHomepage("https://www.thomaslower.com");
    movie.setId(22);
    movie.setImdbID("ttthelloworld");
    movie.setOriginalLanguage({"en-GB", "English", "English"});
    movie.setOriginalTitle("Title");
    movie.setOverview("Overview");
    movie.setPopularity(43.3764);
    movie.setPosterPath("Path.png");
    movie.setProductionCompanies({tmdb::Company("Desc", "Bournemouth", "https://www.thomaslower.com", "Supersliser Industries", "UK", "None", "logo.png", 26)});
    movie.setCountries({{"en-GB", "Britain", "Britain"}});
    movie.setReleaseDate(QDate(2004, 10, 22));
    movie.setRevenue(6);
    movie.setRuntime(179);
    movie.setLanguages({{"en", "English", "English"}});
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
    EXPECT_EQ(movie.genres().size(), 1);
    EXPECT_EQ(movie.genres()[0].id(), 5);
    EXPECT_STREQ(movie.genres()[0].name().toStdString().c_str(), "Drama");
    EXPECT_STREQ(movie.homepage().toStdString().c_str(), "https://www.thomaslower.com");
    EXPECT_EQ(movie.id(), 22);
    EXPECT_STREQ(movie.imdbID().toStdString().c_str(), "ttthelloworld");
    EXPECT_STREQ(movie.originalLanguage().iso_639_1.toStdString().c_str(), "en-GB");
    EXPECT_STREQ(movie.originalLanguage().english_name.toStdString().c_str(), "English");
    EXPECT_STREQ(movie.originalLanguage().native_name.toStdString().c_str(), "English");
    EXPECT_STREQ(movie.originalTitle().toStdString().c_str(), "Title");
    EXPECT_STREQ(movie.overview().toStdString().c_str(), "Overview");
    EXPECT_FLOAT_EQ(movie.popularity(), 43.3764);
    EXPECT_STREQ(movie.posterPath().toStdString().c_str(), "Path.png");
    EXPECT_EQ(movie.productionCompanies().size(), 1);
    EXPECT_EQ(movie.productionCompanies()[0].id(), 26);
    EXPECT_STREQ(movie.productionCompanies()[0].description().toStdString().c_str(), "Desc");
    EXPECT_STREQ(movie.productionCompanies()[0].headquarters().toStdString().c_str(), "Bournemouth");
    EXPECT_STREQ(movie.productionCompanies()[0].homepage().toStdString().c_str(), "https://www.thomaslower.com");
    EXPECT_STREQ(movie.productionCompanies()[0].name().toStdString().c_str(), "Supersliser Industries");
    EXPECT_STREQ(movie.productionCompanies()[0].originCountry().toStdString().c_str(), "UK");
    EXPECT_STREQ(movie.productionCompanies()[0].logoPath().toStdString().c_str(), "logo.png");
    EXPECT_EQ(movie.countries().size(), 1);
    EXPECT_STREQ(movie.countries()[0].english_name.toStdString().c_str(), "Britain");
    EXPECT_STREQ(movie.countries()[0].native_name.toStdString().c_str(), "Britain");
    EXPECT_STREQ(movie.countries()[0].iso_3166_1.toStdString().c_str(), "en-GB");
    EXPECT_EQ(movie.releaseDate(), QDate(2004, 10, 22));
    EXPECT_EQ(movie.revenue(), 6);
    EXPECT_EQ(movie.runtime(), 179);
    EXPECT_EQ(movie.languages().size(), 1);
    EXPECT_STREQ(movie.languages()[0].iso_639_1.toStdString().c_str(), "en");
    EXPECT_STREQ(movie.languages()[0].english_name.toStdString().c_str(), "English");
    EXPECT_STREQ(movie.languages()[0].native_name.toStdString().c_str(), "English");
    EXPECT_STREQ(movie.status().toStdString().c_str(), "EXISTS I PROMISE");
    EXPECT_STREQ(movie.tagline().toStdString().c_str(), "Tagline");
    EXPECT_STREQ(movie.title().toStdString().c_str(), "Title");
    EXPECT_FALSE(movie.video());
    EXPECT_FLOAT_EQ(movie.voteAverage(), 50);
    EXPECT_EQ(movie.voteCount(), 10);
}

TEST(MovieTests, getNowPlaying)
{
    std::vector<tmdb::Movie> movies = tmdb::Movie::getNowPlaying(std::getenv("API_KEY"));

    for (auto& movie: movies)
    {
        EXPECT_STRNE(movie.backdropPath().toStdString().c_str(), "EMPTY_BACKDROP_PATH");
        EXPECT_STRNE(movie.belongsToCollection().toStdString().c_str(), "EMPTY_COLLECTION");
        EXPECT_FALSE(movie.genres().empty());
        EXPECT_STRNE(movie.homepage().toStdString().c_str(), "EMPTY_HOMEPAGE");
        EXPECT_NE(movie.id(), 0);
        EXPECT_STRNE(movie.imdbID().toStdString().c_str(), "EMPTY_IMDB_ID");
        EXPECT_STRNE(movie.originalLanguage().english_name.toStdString().c_str(), "");
        EXPECT_STRNE(movie.originalTitle().toStdString().c_str(), "EMPTY_TITLE");
        EXPECT_STRNE(movie.overview().toStdString().c_str(), "EMPTY_OVERVIEW");
        EXPECT_STRNE(movie.posterPath().toStdString().c_str(), "EMPTY_POSTER_PATH");
        EXPECT_FALSE(movie.productionCompanies().empty());
        EXPECT_FALSE(movie.countries().empty());
        EXPECT_NE(movie.releaseDate(), QDate::currentDate());
        EXPECT_FALSE(movie.languages().empty());
        EXPECT_STRNE(movie.status().toStdString().c_str(), "EMPTY_STATUS");
        EXPECT_STRNE(movie.tagline().toStdString().c_str(), "EMPTY_TAGLINE");
        EXPECT_STRNE(movie.title().toStdString().c_str(), "EMPTY_TITLE");
        EXPECT_NE(movie.voteCount(), 0);
    }
}

TEST(MovieTests, getPopular)
{
    std::vector<tmdb::Movie> movies = tmdb::Movie::getPopular(std::getenv("API_KEY"));

    for (auto& movie: movies)
    {
        EXPECT_STRNE(movie.backdropPath().toStdString().c_str(), "EMPTY_BACKDROP_PATH");
        EXPECT_STRNE(movie.belongsToCollection().toStdString().c_str(), "EMPTY_COLLECTION");
        EXPECT_FALSE(movie.genres().empty());
        EXPECT_STRNE(movie.homepage().toStdString().c_str(), "EMPTY_HOMEPAGE");
        EXPECT_NE(movie.id(), 0);
        EXPECT_STRNE(movie.imdbID().toStdString().c_str(), "EMPTY_IMDB_ID");
        EXPECT_STRNE(movie.originalLanguage().english_name.toStdString().c_str(), "");
        EXPECT_STRNE(movie.originalTitle().toStdString().c_str(), "EMPTY_TITLE");
        EXPECT_STRNE(movie.overview().toStdString().c_str(), "EMPTY_OVERVIEW");
        EXPECT_STRNE(movie.posterPath().toStdString().c_str(), "EMPTY_POSTER_PATH");
        EXPECT_NE(movie.releaseDate(), QDate::currentDate());
        EXPECT_STRNE(movie.status().toStdString().c_str(), "EMPTY_STATUS");
        EXPECT_STRNE(movie.tagline().toStdString().c_str(), "EMPTY_TAGLINE");
        EXPECT_STRNE(movie.title().toStdString().c_str(), "EMPTY_TITLE");
        EXPECT_NE(movie.voteCount(), 0);
    }
}

TEST(MovieTests, getTopRated)
{
    std::vector<tmdb::Movie> movies = tmdb::Movie::getTopRated(std::getenv("API_KEY"));

    for (auto& movie: movies)
    {
        EXPECT_STRNE(movie.backdropPath().toStdString().c_str(), "EMPTY_BACKDROP_PATH");
        EXPECT_STRNE(movie.belongsToCollection().toStdString().c_str(), "EMPTY_COLLECTION");
        EXPECT_FALSE(movie.genres().empty());
        EXPECT_STRNE(movie.homepage().toStdString().c_str(), "EMPTY_HOMEPAGE");
        EXPECT_NE(movie.id(), 0);
        EXPECT_STRNE(movie.imdbID().toStdString().c_str(), "EMPTY_IMDB_ID");
        EXPECT_STRNE(movie.originalLanguage().english_name.toStdString().c_str(), "");
        EXPECT_STRNE(movie.originalTitle().toStdString().c_str(), "EMPTY_TITLE");
        EXPECT_STRNE(movie.overview().toStdString().c_str(), "EMPTY_OVERVIEW");
        EXPECT_STRNE(movie.posterPath().toStdString().c_str(), "EMPTY_POSTER_PATH");
        EXPECT_FALSE(movie.productionCompanies().empty());
        EXPECT_NE(movie.releaseDate(), QDate::currentDate());
        EXPECT_FALSE(movie.languages().empty());
        EXPECT_STRNE(movie.status().toStdString().c_str(), "EMPTY_STATUS");
        EXPECT_STRNE(movie.tagline().toStdString().c_str(), "EMPTY_TAGLINE");
        EXPECT_STRNE(movie.title().toStdString().c_str(), "EMPTY_TITLE");
        EXPECT_NE(movie.voteCount(), 0);
    }
}

TEST(MovieTests, getUpcoming)
{
    std::vector<tmdb::Movie> movies = tmdb::Movie::getUpcoming(std::getenv("API_KEY"));

    for (auto& movie: movies)
    {
        EXPECT_STRNE(movie.backdropPath().toStdString().c_str(), "EMPTY_BACKDROP_PATH");
        EXPECT_STRNE(movie.belongsToCollection().toStdString().c_str(), "EMPTY_COLLECTION");
        EXPECT_FALSE(movie.genres().empty());
        EXPECT_STRNE(movie.homepage().toStdString().c_str(), "EMPTY_HOMEPAGE");
        EXPECT_NE(movie.id(), 0);
        EXPECT_STRNE(movie.imdbID().toStdString().c_str(), "EMPTY_IMDB_ID");
        EXPECT_STRNE(movie.originalLanguage().english_name.toStdString().c_str(), "");
        EXPECT_STRNE(movie.originalTitle().toStdString().c_str(), "EMPTY_TITLE");
        EXPECT_STRNE(movie.overview().toStdString().c_str(), "EMPTY_OVERVIEW");
        EXPECT_STRNE(movie.posterPath().toStdString().c_str(), "EMPTY_POSTER_PATH");
        EXPECT_FALSE(movie.productionCompanies().empty());
        EXPECT_FALSE(movie.countries().empty());
        EXPECT_GT(movie.releaseDate(), QDate(1990, 1, 1));
        EXPECT_FALSE(movie.languages().empty());
        EXPECT_STRNE(movie.status().toStdString().c_str(), "EMPTY_STATUS");
        EXPECT_STRNE(movie.tagline().toStdString().c_str(), "EMPTY_TAGLINE");
        EXPECT_STRNE(movie.title().toStdString().c_str(), "EMPTY_TITLE");
    }
}

TEST(MovieTests, getAlternateTitles)
{
    auto movie = tmdb::Movie::getMovie(std::getenv("API_KEY"), 550);
    auto alternateTitles = movie.alternateTitles(std::getenv("API_KEY"));
    EXPECT_STREQ(alternateTitles[0].country.iso_3166_1.toStdString().c_str(), "IL");
    EXPECT_STREQ(alternateTitles[0].title.toStdString().c_str(), "Mo'adon Krav");
    EXPECT_STREQ(alternateTitles[0].type.toStdString().c_str(), "romanization");
}

TEST(MovieTests, getExternalIDs)
{
    auto movie = tmdb::Movie::getMovie(std::getenv("API_KEY"), 550);
    auto externalIDs = movie.externalIDs(std::getenv("API_KEY"));
    EXPECT_STREQ(externalIDs[0].toStdString().c_str(), "tt0137523");
    EXPECT_STREQ(externalIDs[1].toStdString().c_str(), "Q190050");
    EXPECT_STREQ(externalIDs[2].toStdString().c_str(), "FightClub");
    EXPECT_STREQ(externalIDs[3].toStdString().c_str(), "");
    EXPECT_STREQ(externalIDs[4].toStdString().c_str(), "");
}

TEST(MovieTests, getBackdrops)
{
    auto movie = tmdb::Movie::getMovie(std::getenv("API_KEY"), 550);
    auto backdrops = movie.backdrops(std::getenv("API_KEY"), "original");
    EXPECT_EQ(backdrops[0].height(), 1080);
    EXPECT_EQ(backdrops[0].width(), 1920);
}

TEST(MovieTests, getBackdrop)
{
    auto movie = tmdb::Movie::getMovie(std::getenv("API_KEY"), 550);
    auto backdrop = movie.backdrop(std::getenv("API_KEY"), 0, "original");
    EXPECT_EQ(backdrop.height(), 1080);
    EXPECT_EQ(backdrop.width(), 1920);
}

TEST(MovieTests, getLogos)
{
    auto movie = tmdb::Movie::getMovie(std::getenv("API_KEY"), 550);
    auto logos = movie.logos(std::getenv("API_KEY"), "original");
    EXPECT_EQ(logos[0].height(), 389);
    EXPECT_EQ(logos[0].width(), 1804);
}

TEST(MovieTests, getLogo)
{
    auto movie = tmdb::Movie::getMovie(std::getenv("API_KEY"), 550);
    auto backdrop = movie.logo(std::getenv("API_KEY"), 0, "original");
    EXPECT_EQ(backdrop.height(), 389);
    EXPECT_EQ(backdrop.width(), 1804);
}

TEST(MovieTests, getPosters)
{
    auto movie = tmdb::Movie::getMovie(std::getenv("API_KEY"), 550);
    auto posters = movie.posters(std::getenv("API_KEY"), "original");
    EXPECT_EQ(posters[0].height(), 3000);
    EXPECT_EQ(posters[0].width(), 2000);
}

TEST(MovieTests, getPoster)
{
    auto movie = tmdb::Movie::getMovie(std::getenv("API_KEY"), 550);
    auto poster = movie.poster(std::getenv("API_KEY"), 0, "original");
    EXPECT_EQ(poster.height(), 3000);
    EXPECT_EQ(poster.width(), 2000);
}

TEST(MovieTests, getKeywords)
{
    auto movie = tmdb::Movie::getMovie(std::getenv("API_KEY"), 550);
    auto keywords = movie.keywords(std::getenv("API_KEY"));
    EXPECT_FALSE(keywords.empty());
    EXPECT_FALSE(keywords[851].isEmpty());
    EXPECT_STREQ(keywords[851].toStdString().c_str(), "dual identity");
}

TEST(MovieTests, getRecommended)
{
    auto movie = tmdb::Movie::getMovie(std::getenv("API_KEY"), 550);
    auto recs = movie.recommendations(std::getenv("API_KEY"));
    EXPECT_FALSE(recs.empty());
    EXPECT_EQ(recs[0].id(), 680);
}

TEST(MovieTests, getSimilar)
{
    auto movie = tmdb::Movie::getMovie(std::getenv("API_KEY"), 550);
    auto similar = movie.similar(std::getenv("API_KEY"));
    EXPECT_FALSE(similar.empty());
    EXPECT_TRUE(similar[0].id());
}

TEST(MovieTests, getWatchProviders)
{
    auto movie = tmdb::Movie::getMovie(std::getenv("API_KEY"), 550);
    auto providers = movie.watchProviders(std::getenv("API_KEY"), tmdb::config::getCountry("GB", std::getenv("API_KEY")));
    EXPECT_FALSE(providers.empty());
    EXPECT_EQ(providers[0].type(), tmdb::flatrate);
    EXPECT_EQ(providers[0].providerID(), 337);
    EXPECT_STREQ(providers[0].providerName().toStdString().c_str(), "Disney Plus");
    EXPECT_STREQ(providers[0].link().toString().toStdString().c_str(),
                 "https://click.justwatch.com/a?cx=eyJzY2hlbWEiOiJpZ2x1OmNvbS5zbm93cGxvd2FuYWx5dGljcy5zbm93cGxvdy9jb250ZXh0cy9qc29uc2NoZW1hLzEtMC0wIiwiZGF0YSI6W3sic2NoZW1hIjoiaWdsdTpjb20uanVzdHdhdGNoL2NsaWNrb3V0X2NvbnRleHQvanNvbnNjaGVtYS8xLTMtMiIsImRhdGEiOnsicHJvdmlkZXIiOiJEaXNuZXkgUGx1cyIsIm1vbmV0aXphdGlvblR5cGUiOiJmbGF0cmF0ZSIsInByZXNlbnRhdGlvblR5cGUiOiJoZCIsImN1cnJlbmN5IjoiR0JQIiwicGFydG5lcklkIjo2LCJwcm92aWRlcklkIjozMzcsImNsaWNrb3V0VHlwZSI6Imp3LWNvbnRlbnQtcGFydG5lci1leHBvcnQtYXBpIn19LHsic2NoZW1hIjoiaWdsdTpjb20uanVzdHdhdGNoL3RpdGxlX2NvbnRleHQvanNvbnNjaGVtYS8xLTMtMCIsImRhdGEiOnsidGl0bGVJZCI6NDI0MDksIm9iamVjdFR5cGUiOiJtb3ZpZSIsImp3RW50aXR5SWQiOiJ0bTQyNDA5In19XX0&r=https%3A%2F%2Fdisneyplus.bn5x.net%2Fc%2F1206980%2F705874%2F9358%3Fu%3Dhttps%253A%252F%252Fwww.disneyplus.com%252Fmovies%252Ffight-club%252F38HCX4uW3BlA%26subId3%3Djustappsvod&uct_country=gb");
    EXPECT_STREQ(providers[0].logoPath().toStdString().c_str(), "/97yvRBw1GzX7fXprcF80er19ot.jpg");
}

TEST(MovieTests, getCredits)
{
    auto movie = tmdb::Movie::getMovie(std::getenv("API_KEY"), 550);
    auto credits = movie.credits(std::getenv("API_KEY"));
    EXPECT_EQ(credits[0].id(), 819);
    EXPECT_STREQ(credits[0].name().toStdString().c_str(), "Edward Norton");
    EXPECT_EQ(credits[0].alsoKnownAs().size(), 0);
    EXPECT_STREQ(credits[0].biography().toStdString().c_str(), "");
    EXPECT_EQ(credits[0].birthday(), QDate());
    EXPECT_EQ(credits[0].deathday(), QDate());
    EXPECT_EQ(credits[0].gender(), 2);
    EXPECT_STREQ(credits[0].homepage().toStdString().c_str(), "");
    EXPECT_STREQ(credits[0].imdbId().toStdString().c_str(), "");
    EXPECT_STREQ(credits[0].knownFor().toStdString().c_str(), "Acting");
    EXPECT_STREQ(credits[0].placeOfBirth().toStdString().c_str(), "");
    EXPECT_GT(credits[0].popularity(), 0.0f);
    EXPECT_STREQ(credits[0].profilePath().toStdString().c_str(), "/8nytsqL59SFJTVYVrN72k6qkGgJ.jpg");
    EXPECT_STREQ(credits[0].character().toStdString().c_str(), "Narrator");
    EXPECT_STREQ(credits[0].creditID().toStdString().c_str(), "52fe4250c3a36847f80149f3");
}