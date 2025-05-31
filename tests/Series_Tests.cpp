//
// Created by t on 30/05/25.
//

#include "Series.h"
#include <gtest/gtest.h>

#include "QTMDB.h"

TEST(SeriesTests, DefaultConstructor)
{
    tmdb::TV::Series series;
    EXPECT_TRUE(series.adult());
    EXPECT_TRUE(series.backdropPath().isEmpty());
    EXPECT_TRUE(series.createdBy().empty());
    EXPECT_TRUE(series.episodeRunTime().empty());
    EXPECT_EQ(series.firstAirDate(), QDate());
    EXPECT_TRUE(series.genres().empty());
    EXPECT_TRUE(series.homepage().isEmpty());
    EXPECT_EQ(series.id(), 0);
    EXPECT_TRUE(series.inProduction());
    EXPECT_TRUE(series.languages().empty());
    EXPECT_EQ(series.lastAirDate(), QDate());
    EXPECT_TRUE(series.name().isEmpty());
    EXPECT_TRUE(series.networks().empty());
    EXPECT_TRUE(series.originCountries().empty());
    EXPECT_TRUE(series.originalLanguage().isEmpty());
    EXPECT_TRUE(series.overview().isEmpty());
    EXPECT_FLOAT_EQ(series.popularity(), 0.0f);
    EXPECT_TRUE(series.posterPath().isEmpty());
    EXPECT_TRUE(series.productionCompanies().empty());
    EXPECT_TRUE(series.productionCountries().empty());
    EXPECT_TRUE(series.seasons().empty());
    EXPECT_TRUE(series.spokenLanguages().empty());
    EXPECT_TRUE(series.status().isEmpty());
    EXPECT_TRUE(series.tagline().isEmpty());
    EXPECT_TRUE(series.type().isEmpty());
    EXPECT_FLOAT_EQ(series.voteAverage(), 0.0f);
    EXPECT_EQ(series.voteCount(), 0);
}

TEST(SeriesTests, ParameterizedConstructor)
{
    tmdb::TV::Series series(std::getenv("API_KEY"), 1399); // Game of Thrones
    EXPECT_FALSE(series.adult());
    EXPECT_STREQ(series.backdropPath().toStdString().c_str(), "/zZqpAXxVSBtxV9qPBcscfXBcL2w.jpg");
    EXPECT_EQ(series.createdBy().size(), 2);
    EXPECT_EQ(series.episodeRunTime().size(), 0);
    EXPECT_EQ(series.firstAirDate(), QDate(2011, 4, 17));
    EXPECT_EQ(series.genres().size(), 3);
    EXPECT_STREQ(series.genres()[0].name().toStdString().c_str(), "Sci-Fi & Fantasy");
    EXPECT_STREQ(series.homepage().toStdString().c_str(), "https://www.hbo.com/game-of-thrones");
    EXPECT_EQ(series.id(), 1399);
    EXPECT_FALSE(series.inProduction());
    EXPECT_EQ(series.languages().size(), 1);
    EXPECT_STREQ(series.languages()[0].english_name.toStdString().c_str(), "English");
    EXPECT_EQ(series.lastAirDate(), QDate(2019, 5, 19));
    EXPECT_STREQ(series.name().toStdString().c_str(), "Game of Thrones");
    EXPECT_EQ(series.networks().size(), 1);
    EXPECT_STREQ(series.networks()[0].name().toStdString().c_str(), "HBO");
    EXPECT_EQ(series.originCountries().size(), 1);
    EXPECT_STREQ(series.originCountries()[0].native_name.toStdString().c_str(), "United States");
    EXPECT_STREQ(series.originalLanguage().toStdString().c_str(), "en");
    EXPECT_GT(series.popularity(), 0.0f);
    EXPECT_STREQ(series.posterPath().toStdString().c_str(), "/1XS1oqL89opfnbLl8WnZY1O1uJx.jpg");
    EXPECT_EQ(series.productionCompanies().size(), 4);
    EXPECT_STREQ(series.productionCompanies()[0].name().toStdString().c_str(), "Revolution Sun Studios");
    EXPECT_EQ(series.productionCountries().size(), 2);
    EXPECT_STREQ(series.productionCountries()[0].native_name.toStdString().c_str(), "United Kingdom");
    EXPECT_EQ(series.seasons().size(), 9);
    EXPECT_STREQ(series.seasons()[0].name().toStdString().c_str(), "Specials");
    EXPECT_EQ(series.spokenLanguages().size(), 1);
    EXPECT_STREQ(series.spokenLanguages()[0].english_name.toStdString().c_str(), "English");
    EXPECT_STREQ(series.status().toStdString().c_str(), "Ended");
    EXPECT_STREQ(series.tagline().toStdString().c_str(), "Winter is coming.");
    EXPECT_STREQ(series.type().toStdString().c_str(), "Scripted");
    EXPECT_GT(series.voteAverage(), 0);
    EXPECT_GT(series.voteCount(), 0);
}

TEST(SeriesTests, APIConstructor)
{
    tmdb::TV::Series series(std::getenv("API_KEY"), 1399); // Game of Thrones
    EXPECT_FALSE(series.adult());
    EXPECT_STREQ(series.backdropPath().toStdString().c_str(), "/zZqpAXxVSBtxV9qPBcscfXBcL2w.jpg");
    EXPECT_EQ(series.createdBy().size(), 2);
    EXPECT_EQ(series.episodeRunTime().size(), 0);
    EXPECT_EQ(series.firstAirDate(), QDate(2011, 4, 17));
    EXPECT_EQ(series.genres().size(), 3);
    EXPECT_STREQ(series.genres()[0].name().toStdString().c_str(), "Sci-Fi & Fantasy");
    EXPECT_STREQ(series.homepage().toStdString().c_str(), "https://www.hbo.com/game-of-thrones");
    EXPECT_EQ(series.id(), 1399);
    EXPECT_FALSE(series.inProduction());
    EXPECT_EQ(series.languages().size(), 1);
    EXPECT_STREQ(series.languages()[0].english_name.toStdString().c_str(), "English");
    EXPECT_EQ(series.lastAirDate(), QDate(2019, 5, 19));
    EXPECT_STREQ(series.name().toStdString().c_str(), "Game of Thrones");
    EXPECT_EQ(series.networks().size(), 1);
    EXPECT_STREQ(series.networks()[0].name().toStdString().c_str(), "HBO");
    EXPECT_EQ(series.originCountries().size(), 1);
    EXPECT_STREQ(series.originCountries()[0].native_name.toStdString().c_str(), "United States");
    EXPECT_STREQ(series.originalLanguage().toStdString().c_str(), "en");
    EXPECT_GT(series.popularity(), 0.0f);
    EXPECT_STREQ(series.posterPath().toStdString().c_str(), "/1XS1oqL89opfnbLl8WnZY1O1uJx.jpg");
    EXPECT_EQ(series.productionCompanies().size(), 4);
    EXPECT_STREQ(series.productionCompanies()[0].name().toStdString().c_str(), "Revolution Sun Studios");
    EXPECT_EQ(series.productionCountries().size(), 2);
    EXPECT_STREQ(series.productionCountries()[0].native_name.toStdString().c_str(), "United Kingdom");
    EXPECT_EQ(series.seasons().size(), 9);
    EXPECT_STREQ(series.seasons()[0].name().toStdString().c_str(), "Specials");
    EXPECT_EQ(series.spokenLanguages().size(), 1);
    EXPECT_STREQ(series.spokenLanguages()[0].english_name.toStdString().c_str(), "English");
    EXPECT_STREQ(series.status().toStdString().c_str(), "Ended");
    EXPECT_STREQ(series.tagline().toStdString().c_str(), "Winter is coming.");
    EXPECT_STREQ(series.type().toStdString().c_str(), "Scripted");
    EXPECT_GT(series.voteAverage(), 0);
    EXPECT_GT(series.voteCount(), 0);
}

TEST(SeriesTests, APIJSON)
{
    Qtmdb q(std::getenv("API_KEY"));
    QJsonObject response = q.tv_series_details(1399); // Game of Thrones
    EXPECT_FALSE(response.isEmpty());
    tmdb::TV::Series series(response);
    EXPECT_FALSE(series.adult());
    EXPECT_STREQ(series.backdropPath().toStdString().c_str(), "/zZqpAXxVSBtxV9qPBcscfXBcL2w.jpg");
    EXPECT_EQ(series.createdBy().size(), 2);
    EXPECT_EQ(series.episodeRunTime().size(), 0);
    EXPECT_EQ(series.firstAirDate(), QDate(2011, 4, 17));
    EXPECT_EQ(series.genres().size(), 3);
    EXPECT_STREQ(series.genres()[0].name().toStdString().c_str(), "Sci-Fi & Fantasy");
    EXPECT_STREQ(series.homepage().toStdString().c_str(), "https://www.hbo.com/game-of-thrones");
    EXPECT_EQ(series.id(), 1399);
    EXPECT_FALSE(series.inProduction());
    EXPECT_EQ(series.languages().size(), 1);
    EXPECT_STREQ(series.languages()[0].english_name.toStdString().c_str(), "English");
    EXPECT_EQ(series.lastAirDate(), QDate(2019, 5, 19));
    EXPECT_STREQ(series.name().toStdString().c_str(), "Game of Thrones");
    EXPECT_EQ(series.networks().size(), 1);
    EXPECT_STREQ(series.networks()[0].name().toStdString().c_str(), "HBO");
    EXPECT_EQ(series.originCountries().size(), 1);
    EXPECT_STREQ(series.originCountries()[0].native_name.toStdString().c_str(), "United States");
    EXPECT_STREQ(series.originalLanguage().toStdString().c_str(), "en");
    EXPECT_GT(series.popularity(), 0.0f);
    EXPECT_STREQ(series.posterPath().toStdString().c_str(), "/1XS1oqL89opfnbLl8WnZY1O1uJx.jpg");
    EXPECT_EQ(series.productionCompanies().size(), 4);
    EXPECT_STREQ(series.productionCompanies()[0].name().toStdString().c_str(), "Revolution Sun Studios");
    EXPECT_EQ(series.productionCompanies().size(), 4);
    EXPECT_STREQ(series.productionCompanies()[0].name().toStdString().c_str(), "Revolution Sun Studios");
    EXPECT_EQ(series.productionCountries().size(), 2);
    EXPECT_STREQ(series.productionCountries()[0].native_name.toStdString().c_str(), "United Kingdom");
    EXPECT_EQ(series.seasons().size(), 9);
    EXPECT_STREQ(series.seasons()[0].name().toStdString().c_str(), "Specials");
    EXPECT_EQ(series.spokenLanguages().size(), 1);
    EXPECT_STREQ(series.spokenLanguages()[0].english_name.toStdString().c_str(), "English");
    EXPECT_STREQ(series.status().toStdString().c_str(), "Ended");
    EXPECT_STREQ(series.tagline().toStdString().c_str(), "Winter is coming.");
    EXPECT_STREQ(series.type().toStdString().c_str(), "Scripted");
    EXPECT_GT(series.voteAverage(), 0);
    EXPECT_GT(series.voteCount(), 0);
}

TEST(SeriesTests, StaticConstructor)
{
    tmdb::TV::Series series = tmdb::TV::Series::getSeries(std::getenv("API_KEY"), 1399); // Game of Thrones
    EXPECT_FALSE(series.adult());
    EXPECT_STREQ(series.backdropPath().toStdString().c_str(), "/zZqpAXxVSBtxV9qPBcscfXBcL2w.jpg");
    EXPECT_EQ(series.createdBy().size(), 2);
    EXPECT_EQ(series.episodeRunTime().size(), 0);
    EXPECT_EQ(series.firstAirDate(), QDate(2011, 4, 17));
    EXPECT_EQ(series.genres().size(), 3);
    EXPECT_STREQ(series.genres()[0].name().toStdString().c_str(), "Sci-Fi & Fantasy");
    EXPECT_STREQ(series.homepage().toStdString().c_str(), "https://www.hbo.com/game-of-thrones");
    EXPECT_EQ(series.id(), 1399);
    EXPECT_FALSE(series.inProduction());
    EXPECT_EQ(series.languages().size(), 1);
    EXPECT_STREQ(series.languages()[0].english_name.toStdString().c_str(), "English");
    EXPECT_EQ(series.lastAirDate(), QDate(2019, 5, 19));
    EXPECT_STREQ(series.name().toStdString().c_str(), "Game of Thrones");
    EXPECT_EQ(series.networks().size(), 1);
    EXPECT_STREQ(series.networks()[0].name().toStdString().c_str(), "HBO");
    EXPECT_EQ(series.originCountries().size(), 1);
    EXPECT_STREQ(series.originCountries()[0].native_name.toStdString().c_str(), "United States");
    EXPECT_STREQ(series.originalLanguage().toStdString().c_str(), "en");
    EXPECT_GT(series.popularity(), 0.0f);
    EXPECT_STREQ(series.posterPath().toStdString().c_str(), "/1XS1oqL89opfnbLl8WnZY1O1uJx.jpg");
    EXPECT_EQ(series.productionCompanies().size(), 4);
    EXPECT_STREQ(series.productionCompanies()[0].name().toStdString().c_str(), "Revolution Sun Studios");
    EXPECT_EQ(series.productionCompanies().size(), 4);
    EXPECT_STREQ(series.productionCompanies()[0].name().toStdString().c_str(), "Revolution Sun Studios");
    EXPECT_EQ(series.productionCountries().size(), 2);
    EXPECT_STREQ(series.productionCountries()[0].native_name.toStdString().c_str(), "United Kingdom");
    EXPECT_EQ(series.seasons().size(), 9);
    EXPECT_STREQ(series.seasons()[0].name().toStdString().c_str(), "Specials");
    EXPECT_EQ(series.spokenLanguages().size(), 1);
    EXPECT_STREQ(series.spokenLanguages()[0].english_name.toStdString().c_str(), "English");
    EXPECT_STREQ(series.status().toStdString().c_str(), "Ended");
    EXPECT_STREQ(series.tagline().toStdString().c_str(), "Winter is coming.");
    EXPECT_STREQ(series.type().toStdString().c_str(), "Scripted");
    EXPECT_GT(series.voteAverage(), 0);
    EXPECT_GT(series.voteCount(), 0);
}

TEST(SeriesTests, setGetters)
{
    tmdb::TV::Series s;
    s.setAdult(false);
    s.setBackdropPath("/path/to/backdrop.jpg");
    s.setEpisodeRunTime({60});
    s.setFirstAirDate(QDate(2020, 1, 1));
    s.setGenres({tmdb::Genre(1, "Drama")});
    s.setHomepage("http://example.com");
    s.setId(12345);
    s.setInProduction(true);
    s.setLanguages({{"en", "English"}});
    s.setLastAirDate(QDate(2021, 1, 1));
    s.setName("Test Series");
    s.setOriginCountries({{"US", "United States"}});
    s.setOriginalLanguage("en");
    s.setOverview("This is a test series.");
    s.setPopularity(7.5f);
    s.setPosterPath("/path/to/poster.jpg");
    s.setProductionCompanies({tmdb::Company("Tests", "Tests", "Tests", "Test", "Tests", "", "Test", 5)});
    s.setProductionCountries({{"US", "United States"}});
    s.setSpokenLanguages({{"en", "English"}});
    s.setStatus("Returning Series");
    s.setTagline("This is a test tagline.");
    s.setType("Scripted");
    s.setVoteAverage(8.5f);
    s.setVoteCount(1000);
    EXPECT_FALSE(s.adult());
    EXPECT_STREQ(s.backdropPath().toStdString().c_str(), "/path/to/backdrop.jpg");
    EXPECT_EQ(s.episodeRunTime().size(), 1);
    EXPECT_EQ(s.episodeRunTime()[0], 60);
    EXPECT_EQ(s.firstAirDate(), QDate(2020, 1, 1));
    EXPECT_EQ(s.genres().size(), 1);
    EXPECT_EQ(s.genres()[0].id(), 1);
    EXPECT_STREQ(s.genres()[0].name().toStdString().c_str(), "Drama");
    EXPECT_STREQ(s.homepage().toStdString().c_str(), "http://example.com");
    EXPECT_EQ(s.id(), 12345);
    EXPECT_TRUE(s.inProduction());
    EXPECT_EQ(s.languages().size(), 1);
    EXPECT_STREQ(s.languages()[0].english_name.toStdString().c_str(), "English");
    EXPECT_EQ(s.lastAirDate(), QDate(2021, 1, 1));
    EXPECT_STREQ(s.name().toStdString().c_str(), "Test Series");
    EXPECT_EQ(s.originCountries().size(), 1);
    EXPECT_STREQ(s.originCountries()[0].native_name.toStdString().c_str(), "United States");
    EXPECT_STREQ(s.originalLanguage().toStdString().c_str(), "en");
    EXPECT_STREQ(s.overview().toStdString().c_str(), "This is a test series.");
    EXPECT_FLOAT_EQ(s.popularity(), 7.5f);
    EXPECT_STREQ(s.posterPath().toStdString().c_str(), "/path/to/poster.jpg");
    EXPECT_EQ(s.productionCompanies().size(), 1);
    EXPECT_STREQ(s.productionCompanies()[0].name().toStdString().c_str(), "Test");
    EXPECT_EQ(s.productionCountries().size(), 1);
    EXPECT_STREQ(s.productionCountries()[0].native_name.toStdString().c_str(), "United States");
    EXPECT_EQ(s.spokenLanguages().size(), 1);
    EXPECT_STREQ(s.spokenLanguages()[0].english_name.toStdString().c_str(), "English");
    EXPECT_STREQ(s.status().toStdString().c_str(), "Returning Series");
    EXPECT_STREQ(s.tagline().toStdString().c_str(), "This is a test tagline.");
    EXPECT_STREQ(s.type().toStdString().c_str(), "Scripted");
    EXPECT_FLOAT_EQ(s.voteAverage(), 8.5f);
    EXPECT_EQ(s.voteCount(), 1000);
}

TEST(SeriesTests, GetAiringToday)
{
    auto seriesList = tmdb::TV::Series::getAiringToday(std::getenv("API_KEY"), tmdb::config::language{"en", "English"}, 1, "US");
    EXPECT_FALSE(seriesList.empty());
    EXPECT_GT(seriesList.size(), 0);
    for (const auto &series : seriesList) {
        EXPECT_FALSE(series.name().isEmpty());
        EXPECT_FALSE(series.posterPath().isEmpty());
    }
}
TEST(SeriesTests, GetOnTheAir)
{
    auto seriesList = tmdb::TV::Series::getOnTheAir(std::getenv("API_KEY"), tmdb::config::language{"en", "English"}, 1, "US");
    EXPECT_FALSE(seriesList.empty());
    EXPECT_GT(seriesList.size(), 0);
    for (const auto &series : seriesList) {
        EXPECT_FALSE(series.name().isEmpty());
        EXPECT_FALSE(series.posterPath().isEmpty());
    }
}
TEST(SeriesTests, GetPopular)
{
    auto seriesList = tmdb::TV::Series::getPopular(std::getenv("API_KEY"), tmdb::config::language{"en", "English"}, 1);
    EXPECT_FALSE(seriesList.empty());
    EXPECT_GT(seriesList.size(), 0);
    for (const auto &series : seriesList) {
        EXPECT_FALSE(series.name().isEmpty());
        EXPECT_FALSE(series.posterPath().isEmpty());
    }
}
TEST(SeriesTests, GetTopRated)
{
    auto seriesList = tmdb::TV::Series::getTopRated(std::getenv("API_KEY"), tmdb::config::language{"en", "English"}, 1);
    EXPECT_FALSE(seriesList.empty());
    EXPECT_GT(seriesList.size(), 0);
    for (const auto &series : seriesList) {
        EXPECT_FALSE(series.name().isEmpty());
        EXPECT_FALSE(series.posterPath().isEmpty());
    }
}
TEST(SeriesTests, Recommendations)
{
    tmdb::TV::Series series(std::getenv("API_KEY"), 1399); // Game of Thrones
    auto recommendations = series.recommendations(std::getenv("API_KEY"), 1);
    EXPECT_FALSE(recommendations.empty());
    EXPECT_GT(recommendations.size(), 0);
    for (const auto &rec : recommendations) {
        EXPECT_FALSE(rec.name().isEmpty());
        EXPECT_FALSE(rec.posterPath().isEmpty());
    }
}
TEST(SeriesTests, Similar)
{
    tmdb::TV::Series series(std::getenv("API_KEY"), 1399); // Game of Thrones
    auto similar = series.similar(std::getenv("API_KEY"), 1);
    EXPECT_FALSE(similar.empty());
    EXPECT_GT(similar.size(), 0);
    for (const auto &sim : similar) {
        EXPECT_FALSE(sim.name().isEmpty());
    }
}

TEST(SeriesTests, WatchProviders)
{
    tmdb::TV::Series series(std::getenv("API_KEY"), 1399); // Game of Thrones
    auto watchProviders = series.watchProviders(std::getenv("API_KEY"), tmdb::config::getCountry("GB"));
    EXPECT_FALSE(watchProviders.empty());
    EXPECT_GT(watchProviders.size(), 0);
    for (const auto &provider : watchProviders) {
        EXPECT_FALSE(provider.providerName().isEmpty());
        EXPECT_FALSE(provider.logoPath().isEmpty());
    }
}