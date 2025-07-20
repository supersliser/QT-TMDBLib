//
// Created by t on 30/05/25.
//

#include <QApplication>

#include "ASync/Series.h"
#include <gtest/gtest.h>

#include "ASync/QTMDB.h"

using namespace tmdb::ASync::TV;

TEST(SeriesASyncTests, DefaultConstructor)
{
    Series series;
    EXPECT_TRUE(series.adult());
    EXPECT_STREQ(series.backdropPath().toStdString().c_str(), "BLANK_BACKDROP_PATH");
    EXPECT_TRUE(series.createdBy().empty());
    EXPECT_TRUE(series.episodeRunTime().empty());
    EXPECT_EQ(series.firstAirDate(), QDate());
    EXPECT_TRUE(series.genres().empty());
    EXPECT_STREQ(series.homepage().toStdString().c_str(), "BLANK_HOMEPAGE");
    EXPECT_EQ(series.id(), 0);
    EXPECT_TRUE(series.inProduction());
    EXPECT_TRUE(series.languages().empty());
    EXPECT_EQ(series.lastAirDate(), QDate());
    EXPECT_STREQ(series.name().toStdString().c_str(), "BLANK_NAME");
    EXPECT_TRUE(series.networks().empty());
    EXPECT_TRUE(series.originCountries().empty());
    EXPECT_STREQ(series.originalLanguage().toStdString().c_str(), "BLANK_ORIGINAL_LANGUAGE");
    EXPECT_STREQ(series.overview().toStdString().c_str(), "BLANK_OVERVIEW");
    EXPECT_FLOAT_EQ(series.popularity(), 0.0f);
    EXPECT_STREQ(series.posterPath().toStdString().c_str(), "BLANK_POSTER_PATH");
    EXPECT_TRUE(series.productionCompanies().empty());
    EXPECT_TRUE(series.productionCountries().empty());
    EXPECT_TRUE(series.seasons().empty());
    EXPECT_TRUE(series.spokenLanguages().empty());
    EXPECT_STREQ(series.status().toStdString().c_str(), "BLANK_STATUS");
    EXPECT_STREQ(series.tagline().toStdString().c_str(), "BLANK_TAGLINE");
    EXPECT_STREQ(series.type().toStdString().c_str(), "BLANK_TYPE");
    EXPECT_FLOAT_EQ(series.voteAverage(), 0.0f);
    EXPECT_EQ(series.voteCount(), 0);
}

TEST(SeriesASyncTests, APIConstructor)
{
    bool f = false;
    Series series(std::getenv("API_KEY"), 1399); // Game of Thrones
    QObject::connect(&series, &Series::finishedLoadingSeries, [&f](Series* s) {
        EXPECT_FALSE(s->adult());
        EXPECT_FALSE(s->backdropPath().isNull());
        EXPECT_EQ(s->createdBy().size(), 2);
        EXPECT_EQ(s->episodeRunTime().size(), 0);
        EXPECT_EQ(s->firstAirDate(), QDate(2011, 4, 17));
        EXPECT_EQ(s->genres().size(), 3);
        EXPECT_STREQ(s->genres()[0]->name().toStdString().c_str(), "Sci-Fi & Fantasy");
        EXPECT_STREQ(s->homepage().toStdString().c_str(), "https://www.hbo.com/game-of-thrones");
        EXPECT_EQ(s->id(), 1399);
        EXPECT_FALSE(s->inProduction());
        EXPECT_EQ(s->languages().size(), 1);
        EXPECT_STREQ(s->languages()[0]->englishName().toStdString().c_str(), "English");
        EXPECT_EQ(s->lastAirDate(), QDate(2019, 5, 19));
        EXPECT_STREQ(s->name().toStdString().c_str(), "Game of Thrones");
        EXPECT_EQ(s->networks().size(), 1);
        EXPECT_STREQ(s->networks()[0]->name().toStdString().c_str(), "HBO");
        EXPECT_EQ(s->originCountries().size(), 1);
        EXPECT_STREQ(s->originCountries()[0]->nativeName().toStdString().c_str(), "United States");
        EXPECT_STREQ(s->originalLanguage().toStdString().c_str(), "en");
        EXPECT_GT(s->popularity(), 0.0f);
        EXPECT_FALSE(s->posterPath().isNull());
        EXPECT_EQ(s->productionCompanies().size(), 4);
        EXPECT_STREQ(s->productionCompanies()[0]->name().toStdString().c_str(), "Revolution Sun Studios");
        EXPECT_EQ(s->productionCountries().size(), 2);
        EXPECT_STREQ(s->productionCountries()[0]->nativeName().toStdString().c_str(), "United Kingdom");
        EXPECT_EQ(s->seasons().size(), 9);
        EXPECT_STREQ(s->seasons()[0]->name().toStdString().c_str(), "Specials");
        EXPECT_EQ(s->spokenLanguages().size(), 1);
        EXPECT_STREQ(s->spokenLanguages()[0]->englishName().toStdString().c_str(), "English");
        EXPECT_STREQ(s->status().toStdString().c_str(), "Ended");
        EXPECT_STREQ(s->tagline().toStdString().c_str(), "Winter is coming.");
        EXPECT_STREQ(s->type().toStdString().c_str(), "Scripted");
        EXPECT_GT(s->voteAverage(), 0);
        EXPECT_GT(s->voteCount(), 0);
        f = true;
    });
    series.loadSeries(1399);
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(SeriesASyncTests, APIJSON)
{
    bool f = false;
    aQtmdb q(std::getenv("API_KEY"));
    QObject::connect(&q, &aQtmdb::finishedLoadingData, [&f](void* response) {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        Series series(data, std::getenv("API_KEY"));
        EXPECT_FALSE(series.adult());
        EXPECT_FALSE(series.backdropPath().isNull());
        EXPECT_EQ(series.createdBy().size(), 2);
        EXPECT_EQ(series.episodeRunTime().size(), 0);
        EXPECT_EQ(series.firstAirDate(), QDate(2011, 4, 17));
        EXPECT_EQ(series.genres().size(), 3);
        EXPECT_STREQ(series.genres()[0]->name().toStdString().c_str(), "Sci-Fi & Fantasy");
        EXPECT_STREQ(series.homepage().toStdString().c_str(), "https://www.hbo.com/game-of-thrones");
        EXPECT_EQ(series.id(), 1399);
        EXPECT_FALSE(series.inProduction());
        EXPECT_EQ(series.languages().size(), 1);
        EXPECT_STREQ(series.languages()[0]->englishName().toStdString().c_str(), "English");
        EXPECT_EQ(series.lastAirDate(), QDate(2019, 5, 19));
        EXPECT_STREQ(series.name().toStdString().c_str(), "Game of Thrones");
        EXPECT_EQ(series.networks().size(), 1);
        EXPECT_STREQ(series.networks()[0]->name().toStdString().c_str(), "HBO");
        EXPECT_EQ(series.originCountries().size(), 1);
        EXPECT_STREQ(series.originCountries()[0]->nativeName().toStdString().c_str(), "United States");
        EXPECT_STREQ(series.originalLanguage().toStdString().c_str(), "en");
        EXPECT_GT(series.popularity(), 0.0f);
        EXPECT_FALSE(series.posterPath().isNull());
        EXPECT_EQ(series.productionCompanies().size(), 4);
        EXPECT_STREQ(series.productionCompanies()[0]->name().toStdString().c_str(), "Revolution Sun Studios");
        EXPECT_EQ(series.productionCountries().size(), 2);
        EXPECT_STREQ(series.productionCountries()[0]->nativeName().toStdString().c_str(), "United Kingdom");
        EXPECT_EQ(series.seasons().size(), 9);
        EXPECT_STREQ(series.seasons()[0]->name().toStdString().c_str(), "Specials");
        EXPECT_EQ(series.spokenLanguages().size(), 1);
        EXPECT_STREQ(series.spokenLanguages()[0]->englishName().toStdString().c_str(), "English");
        EXPECT_STREQ(series.status().toStdString().c_str(), "Ended");
        EXPECT_STREQ(series.tagline().toStdString().c_str(), "Winter is coming.");
        EXPECT_STREQ(series.type().toStdString().c_str(), "Scripted");
        EXPECT_GT(series.voteAverage(), 0);
        EXPECT_GT(series.voteCount(), 0);
        f = true;
    });
    q.tv_series_details(1399); // Game of Thrones
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(SeriesASyncTests, setGetters)
{
    Series s;
    s.setAdult(false);
    s.setBackdropPath("/path/to/backdrop.jpg");
    s.setEpisodeRunTime({60});
    s.setFirstAirDate(QDate(2020, 1, 1));
    s.setHomepage("http://example.com");
    s.setId(12345);
    s.setInProduction(true);
    s.setLastAirDate(QDate(2021, 1, 1));
    s.setName("Test Series");
    s.setOriginalLanguage("en");
    s.setOverview("This is a test series.");
    s.setPopularity(7.5f);
    s.setPosterPath("/path/to/poster.jpg");
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
    EXPECT_STREQ(s.homepage().toStdString().c_str(), "http://example.com");
    EXPECT_EQ(s.id(), 12345);
    EXPECT_TRUE(s.inProduction());
    EXPECT_EQ(s.lastAirDate(), QDate(2021, 1, 1));
    EXPECT_STREQ(s.name().toStdString().c_str(), "Test Series");
    EXPECT_STREQ(s.overview().toStdString().c_str(), "This is a test series.");
    EXPECT_FLOAT_EQ(s.popularity(), 7.5f);
    EXPECT_STREQ(s.posterPath().toStdString().c_str(), "/path/to/poster.jpg");
    EXPECT_STREQ(s.status().toStdString().c_str(), "Returning Series");
    EXPECT_STREQ(s.tagline().toStdString().c_str(), "This is a test tagline.");
    EXPECT_STREQ(s.type().toStdString().c_str(), "Scripted");
    EXPECT_FLOAT_EQ(s.voteAverage(), 8.5f);
    EXPECT_EQ(s.voteCount(), 1000);
}

TEST(SeriesASyncTests, GetAiringToday)
{
    bool f = false;
    Series* series = new Series(std::getenv("API_KEY"));
    QObject::connect(series, &Series::finishedLoadingAiringToday, [&f](std::vector<tmdb::ASync::TV::Series*> seriesList) {
        EXPECT_FALSE(seriesList.empty());
        EXPECT_GT(seriesList.size(), 0);
        for (const auto &s : seriesList) {
            EXPECT_FALSE(s->name().isEmpty());
            EXPECT_FALSE(s->posterPath().isEmpty());
        }
        f = true;
    });
    tmdb::ASync::Language l;
    l.setIso6391("en-GB");
    series->loadAiringToday(l, 1, "GB");
    while (!f)
    {
        QApplication::processEvents();
    }
}
TEST(SeriesASyncTests, GetOnTheAir)
{
    bool f = false;
    auto* series = new Series(std::getenv("API_KEY"));
    QObject::connect(series, &Series::finishedLoadingOnTheAir, [&f](std::vector<Series*> seriesList) {
        EXPECT_FALSE(seriesList.empty());
        EXPECT_GT(seriesList.size(), 0);
        for (const auto &s : seriesList) {
            EXPECT_FALSE(s->name().isEmpty());
            EXPECT_FALSE(s->posterPath().isEmpty());
        }
        f = true;
    });
    tmdb::ASync::Language l;
    l.setIso6391("en-GB");
    series->loadOnTheAir(l, 1, "en-GB");
    while (!f)
    {
        QApplication::processEvents();
    }
}
TEST(SeriesASyncTests, GetPopular)
{
    bool f = false;
    Series* series = new Series(std::getenv("API_KEY"));
    QObject::connect(series, &Series::finishedLoadingPopular, [&f](std::vector<tmdb::ASync::TV::Series*> seriesList) {
        EXPECT_FALSE(seriesList.empty());
        EXPECT_GT(seriesList.size(), 0);
        for (const auto &s : seriesList) {
            EXPECT_FALSE(s->name().isEmpty());
            EXPECT_FALSE(s->posterPath().isEmpty());
        }
        f = true;
    });
    tmdb::ASync::Language l;
    l.setIso6391("en-GB");
    series->loadPopular(l, 1);
    while (!f)
    {
        QApplication::processEvents();
    }
}
TEST(SeriesASyncTests, GetTopRated)
{
    bool f = false;
    Series* series = new Series(std::getenv("API_KEY"));
    QObject::connect(series, &Series::finishedLoadingTopRated, [&f](std::vector<tmdb::ASync::TV::Series*> seriesList) {
        EXPECT_FALSE(seriesList.empty());
        EXPECT_GT(seriesList.size(), 0);
        for (const auto &s : seriesList) {
            EXPECT_FALSE(s->name().isEmpty());
            EXPECT_FALSE(s->posterPath().isEmpty());
        }
        f = true;
    });
    tmdb::ASync::Language l;
    l.setIso6391("en-GB");
    series->loadTopRated(l, 1);
    while (!f)
    {
        QApplication::processEvents();
    }
}
TEST(SeriesASyncTests, Recommendations)
{
    bool f = false;
    Series* series = new Series(std::getenv("API_KEY"), 1399); // Game of Thrones
    while (series->voteCount() == 0)
    {
        QApplication::processEvents();
    }
    QObject::connect(series, &Series::finishedLoadingRecommendations, [&f](std::vector<tmdb::ASync::TV::Series*> seriesList) {
        EXPECT_FALSE(seriesList.empty());
        for (const auto &s : seriesList) {
            EXPECT_FALSE(s->name().isEmpty());
        }
        f = true;
    });
    series->loadRecommendations();
    while (!f)
    {
        QApplication::processEvents();
    }
}
TEST(SeriesASyncTests, Similar)
{
    bool f = false;
    Series* series = new Series(std::getenv("API_KEY"), 1399);
    while (series->voteCount() == 0)
    {
        QApplication::processEvents();
    }
    QObject::connect(series, &Series::finishedLoadingSimilar, [&f](std::vector<tmdb::ASync::TV::Series*> seriesList) {
        EXPECT_FALSE(seriesList.empty());
        EXPECT_GT(seriesList.size(), 0);
        for (const auto &s : seriesList) {
            EXPECT_FALSE(s->name().isEmpty());
        }
        f = true;
    });
    series->loadSimilar();
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(SeriesASyncTests, WatchProviders)
{
    Series series(std::getenv("API_KEY"), 1399);
    while (series.voteCount() == 0)
    {
        QApplication::processEvents();
    }
    bool f = false;
    QObject::connect(&series, &Series::finishedLoadingWatchProviders, [&f](std::vector<tmdb::ASync::WatchProvider*> watchProviders) {
        EXPECT_FALSE(watchProviders.empty());
        EXPECT_GT(watchProviders.size(), 0);
        for (const auto &provider : watchProviders) {
            EXPECT_FALSE(provider->providerName().isEmpty());
        }
        f = true;
    });
    tmdb::ASync::Country country;
    country.setISOCountryCode("US");
    series.loadWatchProviders(&country);
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(SeriesASyncTests, Seasons)
{
    Series series(std::getenv("API_KEY"), 1399);
    while (series.voteCount() == 0)
    {
        QApplication::processEvents();
    }
    bool f = false;
    QObject::connect(&series, &Series::finishedLoadingSeasons, [&f](std::vector<tmdb::ASync::TV::Season*> watchProviders) {
        EXPECT_FALSE(watchProviders.empty());
        EXPECT_GT(watchProviders.size(), 0);
        for (const auto &season : watchProviders) {
            EXPECT_FALSE(season->name().isEmpty());
            EXPECT_FALSE(season->posterPath().isEmpty());
        }
        f = true;
    });
    series.loadSeasons();
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(SeriesASyncTests, ExternalIDs)
{
    Series series(std::getenv("API_KEY"), 1399); // Game of Thrones
    while (series.voteCount() == 0)
    {
        QApplication::processEvents();
    }
    bool f = false;
    QObject::connect(&series, &Series::finishedLoadingExternalIDs, [&f](std::array<QString, 9> externalIDs) {
        EXPECT_FALSE(externalIDs.empty());
        EXPECT_FALSE(externalIDs[0].isEmpty()); // IMDb ID
        f = true;
    });
    series.loadExternalIDs();
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(SeriesASyncTests, Backdrop)
{
    Series series(std::getenv("API_KEY"), 1399); // Game of Thrones
    bool f = false;
    while (series.voteCount() == 0)
    {
        QApplication::processEvents();
    }
    QObject::connect(&series, &Series::finishedLoadingBackdrop, [&f](QPixmap backdrop) {
        EXPECT_FALSE(backdrop.isNull());
        f = true;
    });
    series.loadBackdrop(0, "original");
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(SeriesASyncTests, Poster)
{
    Series series(std::getenv("API_KEY"), 1399); // Game of Thrones
    bool f = false;
    while (series.voteCount() == 0)
    {
        QApplication::processEvents();
    }
    QObject::connect(&series, &Series::finishedLoadingPoster, [&f](QPixmap poster) {
        EXPECT_FALSE(poster.isNull());
        f = true;
    });
    series.loadPoster(0, "original");
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(SeriesASyncTests, Logo)
{
    Series series(std::getenv("API_KEY"), 1399); // Game of Thrones
    bool f = false;
    while (series.voteCount() == 0)
    {
        QApplication::processEvents();
    }
    QObject::connect(&series, &Series::finishedLoadingLogo, [&f](QPixmap logo) {
        EXPECT_FALSE(logo.isNull());
        f = true;
    });
    series.loadLogo(0, "original");
    while (!f)
    {
        QApplication::processEvents();
    }
}
