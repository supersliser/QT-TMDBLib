//
// Created by t on 30/05/25.
//

#include "ASync/Series.h"

#include <QApplication>
#include <QJsonObject>

#include "ASync/Image.h"
#include "Sync/QTMDB.h"

using namespace tmdb::ASync::TV;

void Series::setAdult(bool i_adult)
{
    m_adult = i_adult;
}

bool Series::adult() const
{
    return m_adult;
}

void Series::setBackdropPath(const QString& i_backdropPath)
{
    m_backdropPath = i_backdropPath;
}

QString Series::backdropPath() const
{
    return m_backdropPath;
}

void Series::setCreatedBy(const std::vector<Person*>& i_createdBy)
{
    m_createdBy = i_createdBy;
}

std::vector<tmdb::ASync::Person*> Series::createdBy() const
{
    return m_createdBy;
}

void Series::setEpisodeRunTime(const std::vector<int>& i_episodeRunTime)
{
    m_episodeRunTime = i_episodeRunTime;
}

std::vector<int> Series::episodeRunTime() const
{
    return m_episodeRunTime;
}

void Series::setFirstAirDate(const QDate& i_firstAirDate)
{
    m_firstAirDate = i_firstAirDate;
}

QDate Series::firstAirDate() const
{
    return m_firstAirDate;
}

void Series::setGenres(const std::vector<Genre*>& i_genres)
{
    m_genres = i_genres;
}

std::vector<tmdb::ASync::Genre*> Series::genres() const
{
    return m_genres;
}

void Series::setHomepage(const QString& i_homepage)
{
    m_homepage = i_homepage;
}

QString Series::homepage() const
{
    return m_homepage;
}

void Series::setId(int i_id)
{
    m_id = i_id;
}

int Series::id() const
{
    return m_id;
}

void Series::setInProduction(bool i_inProduction)
{
    in_production = i_inProduction;
}

bool Series::inProduction() const
{
    return in_production;
}

void Series::setLanguages(const std::vector<Language*>& i_languages)
{
    m_languages = i_languages;
}

std::vector<tmdb::ASync::Language*> Series::languages() const
{
    return m_languages;
}

void Series::setLastAirDate(const QDate& i_lastAirDate)
{
    m_lastAirDate = i_lastAirDate;
}

QDate Series::lastAirDate() const
{
    return m_lastAirDate;
}

void Series::setName(const QString& i_name)
{
    m_name = i_name;
}

QString Series::name() const
{
    return m_name;
}

void Series::setNetworks(const std::vector<Network*>& i_networks)
{
    m_networks = i_networks;
}

std::vector<Network*> Series::networks() const
{
    return m_networks;
}

void Series::setOriginCountries(const std::vector<Country*>& i_originCountries)
{
    m_originCountries = i_originCountries;
}

std::vector<tmdb::ASync::Country*> Series::originCountries() const
{
    return m_originCountries;
}

void Series::setOriginalLanguage(const QString& i_originalLanguage)
{
    m_originalLanguage = i_originalLanguage;
}

QString Series::originalLanguage() const
{
    return m_originalLanguage;
}

void Series::setOverview(const QString& i_overview)
{
    m_overview = i_overview;
}

QString Series::overview() const
{
    return m_overview;
}

void Series::setPopularity(float i_popularity)
{
    m_popularity = i_popularity;
}

float Series::popularity() const
{
    return m_popularity;
}

void Series::setPosterPath(const QString& i_posterPath)
{
    m_posterPath = i_posterPath;
}

QString Series::posterPath() const
{
    return m_posterPath;
}

void Series::setProductionCompanies(const std::vector<Company*>& i_productionCompanies)
{
    m_productionCompanies = i_productionCompanies;
}

std::vector<tmdb::ASync::Company*> Series::productionCompanies() const
{
    return m_productionCompanies;
}

void Series::setProductionCountries(const std::vector<Country*>& i_productionCountries)
{
    m_productionCountries = i_productionCountries;
}

std::vector<tmdb::ASync::Country*> Series::productionCountries() const
{
    return m_productionCountries;
}

void Series::setSeasons(const std::vector<Season*>& i_seasons)
{
    m_seasons = i_seasons;
}

std::vector<tmdb::ASync::TV::Season*> Series::seasons() const
{
    return m_seasons;
}

void Series::setStatus(const QString& i_status)
{
    m_status = i_status;
}

QString Series::status() const
{
    return m_status;
}

void Series::setSpokenLanguages(const std::vector<Language*>& i_spokenLanguages)
{
    m_spokenLanguages = i_spokenLanguages;
}

std::vector<tmdb::ASync::Language*> Series::spokenLanguages() const
{
    return m_spokenLanguages;
}

void Series::setType(const QString& i_type)
{
    m_type = i_type;
}

QString Series::type() const
{
    return m_type;
}

void Series::setVoteAverage(float i_voteAverage)
{
    m_voteAverage = i_voteAverage;
}

float Series::voteAverage() const
{
    return m_voteAverage;
}

void Series::setVoteCount(int i_voteCount)
{
    m_voteCount = i_voteCount;
}

int Series::voteCount() const
{
    return m_voteCount;
}

void Series::setTagline(const QString& i_tagline)
{
    m_tagline = i_tagline;
}

QString Series::tagline() const
{
    return m_tagline;
}

Series::Series(const QString& i_access_token, int32_t i_seriesID) : Series(i_access_token)
{
    setId(i_seriesID);
    loadSeries(i_seriesID);
}

Series::Series(const QString& i_access_token) : m_q(i_access_token.toStdString())
{
    m_q.setParent(this);
}

Series::Series(const QJsonObject& i_json, const QString& i_access_token) : Series(i_access_token)
{
    parseJson(i_json, i_access_token);
}

void Series::parseJson(const QJsonObject& i_json, const QString& i_access_token)
{
    m_adult = i_json["adult"].toBool();
    m_backdropPath = i_json["backdrop_path"].toString();
    std::vector<tmdb::ASync::Person*> createdByArray;
    for (const auto& item : i_json["created_by"].toArray())
    {
        createdByArray.push_back(new Person(item.toObject(), m_q.accessToken().c_str()));
    }
    m_createdBy = createdByArray;
    std::vector<int> episodeRunTimeArray;
    for (const auto& item : i_json["episode_run_time"].toArray())
    {
        episodeRunTimeArray.push_back(item.toInt());
    }
    m_episodeRunTime = episodeRunTimeArray;
    m_firstAirDate = QDate::fromString(i_json["first_air_date"].toString(), Qt::ISODate);
    std::vector<tmdb::ASync::Genre*> genreArray;
    for (const auto& item : i_json["genres"].toArray())
    {
        genreArray.push_back(new Genre(item.toObject(), m_q.accessToken().c_str()));
    }
    m_genres = genreArray;
    m_homepage = i_json["homepage"].toString();
    m_id = i_json["id"].toInt();
    in_production = i_json["in_production"].toBool();
    std::vector<Language*> languageArray;
    int languagesGot = 0;
    for (const auto& item : i_json["languages"].toArray())
    {
        languageArray.push_back(new Language(m_q.accessToken().c_str(), item.toString()));
        connect(languageArray.back(), &Language::finishedLoadingLanguage,
                [this, &languagesGot](Language* language)
                {
                    languagesGot++;
                });
    }
    while (languagesGot < languageArray.size())
    {
        QCoreApplication::processEvents();
    }
    m_languages = languageArray;
    m_lastAirDate = QDate::fromString(i_json["last_air_date"].toString(), Qt::ISODate);
    m_name = i_json["name"].toString();
    std::vector<Network*> networkArray;
    int networksGot = 0;
    for (const auto& item : i_json["networks"].toArray())
    {
        networkArray.push_back(new Network(m_q.accessToken().c_str(), item.toObject()["id"].toInt()));
        connect(networkArray.back(), &Network::finishedLoadingNetwork,
                [this, &networksGot](Network* network)
                {
                    networksGot++;
                });
    }
    while (networksGot < networkArray.size())
    {
        QCoreApplication::processEvents();
    }
    m_networks = networkArray;
    m_episodeCount = i_json["number_of_episodes"].toInt();
    m_seasonCount = i_json["number_of_seasons"].toInt();
    std::vector<Country*> originCountryArray;
    int originCountriesGot = 0;
    for (const auto& item : i_json["origin_country"].toArray())
    {
        originCountryArray.push_back(new Country(m_q.accessToken().c_str(), item.toString()));
        connect(originCountryArray.back(), &Country::finishedLoadingCountry,
                [this, &originCountriesGot](Country* country)
                {
                    originCountriesGot++;
                });
    }
    while (originCountriesGot < originCountryArray.size())
    {
        QCoreApplication::processEvents();
    }
    m_originCountries = originCountryArray;
    m_originalLanguage = i_json["original_language"].toString();
    m_overview = i_json["overview"].toString();
    m_popularity = static_cast<float>(i_json["popularity"].toDouble());
    m_posterPath = i_json["poster_path"].toString();
    std::vector<Company*> companyArray;
    for (const auto& item : i_json["production_companies"].toArray())
    {
        companyArray.push_back(new Company(item.toObject(), m_q.accessToken().c_str()));
    }
    m_productionCompanies = companyArray;
    std::vector<Country*> productionCountryArray;
    int productionCountriesGot = 0;
    for (const auto& item : i_json["production_countries"].toArray())
    {
        productionCountryArray.push_back(new Country(m_q.accessToken().c_str(),
                                                     item.toObject()["iso_3166_1"].toString()));
        connect(productionCountryArray.back(), &Country::finishedLoadingCountry,
                [this, &productionCountriesGot](Country* country)
                {
                    productionCountriesGot++;
                });
    }
    while (productionCountriesGot < productionCountryArray.size())
    {
        QCoreApplication::processEvents();
    }
    m_productionCountries = productionCountryArray;
    std::vector<Season*> seasonArray;
    for (const auto& item : i_json["seasons"].toArray())
    {
        seasonArray.push_back(new Season(item.toObject(), m_q.accessToken().c_str()));
    }
    m_seasons = seasonArray;
    std::vector<Language*> spokenLanguageArray;
    int spokenLanguagesGot = 0;
    for (const auto& item : i_json["spoken_languages"].toArray())
    {
        spokenLanguageArray.push_back(new Language(m_q.accessToken().c_str(), item.toObject()["iso_639_1"].toString()));
        connect(spokenLanguageArray.back(), &Language::finishedLoadingLanguage,
                [this, &spokenLanguagesGot](Language* language)
                {
                    spokenLanguagesGot++;
                });
    }
    while (spokenLanguagesGot < spokenLanguageArray.size())
    {
        QCoreApplication::processEvents();
    }
    m_spokenLanguages = spokenLanguageArray;
    m_status = i_json["status"].toString();
    m_tagline = i_json["tagline"].toString();
    m_type = i_json["type"].toString();
    m_voteAverage = static_cast<float>(i_json["vote_average"].toDouble());
    m_voteCount = i_json["vote_count"].toInt();
}

Series::Series() : m_q("")
{
    m_q.setParent(this);
}

void Series::loadSeries(int32_t i_seriesID)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingSeriesReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingSeriesReceived);
    m_q.tv_series_details(i_seriesID);
}

void Series::startedLoadingSeriesReceived()
{
    emit startedLoadingSeries();
}

void Series::finishedLoadingSeriesReceived(void* i_data)
{
    parseJson(*static_cast<QJsonObject*>(i_data), m_q.accessToken().c_str());
    emit finishedLoadingSeries(this);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingSeriesReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingSeriesReceived);
}

void Series::loadSearchResults(const QString& i_query, const Language& i_language, int32_t i_page, bool i_includeAdult,
                               int i_year, int i_firstAirYear)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingSearchResultsReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingSearchResultsReceived);
    m_q.get_tv(i_query.toStdString(), i_firstAirYear, i_includeAdult, i_language.iso6391().toStdString(), i_page,
               i_year);
}

void Series::startedLoadingSearchResultsReceived()
{
    emit startedLoadingSearchResults();
}

void Series::finishedLoadingSearchResultsReceived(void* i_data)
{
    QJsonObject json = *static_cast<QJsonObject*>(i_data);
    std::vector<Series*> seriesList;
    int gotSeries = 0;
    for (const auto& item : json["results"].toArray())
    {
        seriesList.push_back(new Series(m_q.accessToken().c_str(), item.toObject()["id"].toInt()));
        connect(seriesList.back(), &Series::finishedLoadingSeries, [&gotSeries](Series* series)
        {
            gotSeries++;
        });
    }
    while (gotSeries < seriesList.size())
    {
        QApplication::processEvents();
    }
    emit finishedLoadingSearchResults(seriesList);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingSearchResultsReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingSearchResultsReceived);
}

void Series::loadAiringToday(const Language& i_language, int32_t i_page, const QString& i_region)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingAiringTodayReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingAiringTodayReceived);
    m_q.tv_series_airingToday(i_language.iso6391().toStdString(), i_page, i_region.toStdString());
}

void Series::startedLoadingAiringTodayReceived()
{
    emit startedLoadingAiringToday();
}

void Series::finishedLoadingAiringTodayReceived(void* i_data)
{
    QJsonObject json = *static_cast<QJsonObject*>(i_data);
    std::vector<Series*> seriesList;
    int gotSeries = 0;
    for (const auto& item : json["results"].toArray())
    {
        seriesList.push_back(new Series(m_q.accessToken().c_str(), item.toObject()["id"].toInt()));
        connect(seriesList.back(), &Series::finishedLoadingSeries, [&gotSeries](tmdb::ASync::TV::Series* i_series)
        {
            gotSeries++;
        });
    }
    while (gotSeries < seriesList.size())
    {
        QApplication::processEvents();
    }
    emit finishedLoadingAiringToday(seriesList);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingAiringTodayReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingAiringTodayReceived);
}

void Series::loadOnTheAir(const Language& i_language, int32_t i_page, const QString& i_region)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingOnTheAirReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingOnTheAirReceived);
    m_q.tv_series_onTheAir(i_language.iso6391().toStdString(), i_page, i_region.toStdString());
}

void Series::startedLoadingOnTheAirReceived()
{
    emit startedLoadingOnTheAir();
}

void Series::finishedLoadingOnTheAirReceived(void* i_data)
{
    QJsonObject json = *static_cast<QJsonObject*>(i_data);
    std::vector<Series*> seriesList;
    int gotSeries = 0;
    for (const auto& item : json["results"].toArray())
    {
        seriesList.push_back(new Series(m_q.accessToken().c_str(), item.toObject()["id"].toInt()));
        connect(seriesList.back(), &Series::finishedLoadingSeries, [&gotSeries](tmdb::ASync::TV::Series* i_series)
        {
            gotSeries++;
        });
    }
    while (gotSeries < seriesList.size())
    {
        QApplication::processEvents();
    }
    emit finishedLoadingOnTheAir(seriesList);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingOnTheAirReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingOnTheAirReceived);
}

void Series::loadPopular(const Language& i_language, int32_t i_page)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingPopularReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingPopularReceived);
    m_q.tv_series_popular(i_language.iso6391().toStdString(), i_page);
}

void Series::startedLoadingPopularReceived()
{
    emit startedLoadingPopular();
}

void Series::finishedLoadingPopularReceived(void* i_data)
{
    QJsonObject json = *static_cast<QJsonObject*>(i_data);
    std::vector<Series*> seriesList;
    int gotSeries = 0;
    for (const auto& item : json["results"].toArray())
    {
        seriesList.push_back(new Series(m_q.accessToken().c_str(), item.toObject()["id"].toInt()));
        connect(seriesList.back(), &Series::finishedLoadingSeries, [this, &gotSeries](Series* series)
        {
            gotSeries++;
        });
    }
    while (gotSeries < seriesList.size())
    {
        QCoreApplication::processEvents();
    }
    emit finishedLoadingPopular(seriesList);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingPopularReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingPopularReceived);
}

void Series::loadTopRated(const Language& i_language, int32_t i_page)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingTopRatedReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingTopRatedReceived);
    m_q.tv_series_topRated(i_language.iso6391().toStdString(), i_page);
}

void Series::startedLoadingTopRatedReceived()
{
    emit startedLoadingTopRated();
}

void Series::finishedLoadingTopRatedReceived(void* i_data)
{
    QJsonObject json = *static_cast<QJsonObject*>(i_data);
    std::vector<Series*> seriesList;
    int gotSeries = 0;
    for (const auto& item : json["results"].toArray())
    {
        seriesList.push_back(new Series(m_q.accessToken().c_str(), item.toObject()["id"].toInt()));
        connect(seriesList.back(), &Series::finishedLoadingSeries, [this, &gotSeries](Series* series)
        {
            gotSeries++;
        });
    }
    while (gotSeries < seriesList.size())
    {
        QCoreApplication::processEvents();
    }
    emit finishedLoadingTopRated(seriesList);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingTopRatedReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingTopRatedReceived);
}

void Series::loadRecommendations(int32_t i_page)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingRecommendationsReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingRecommendationsReceived);
    m_q.tv_series_recommendations(m_id, "en-US", i_page);
}

void Series::startedLoadingRecommendationsReceived()
{
    emit startedLoadingRecommendations();
}

void Series::finishedLoadingRecommendationsReceived(void* i_data)
{
    QJsonObject json = *static_cast<QJsonObject*>(i_data);
    std::vector<Series*> seriesList;
    int gotSeries = 0;
    for (const auto& item : json["results"].toArray())
    {
        seriesList.push_back(new Series(m_q.accessToken().c_str(), item.toObject()["id"].toInt()));
        connect(seriesList.back(), &Series::finishedLoadingSeries, [this, &gotSeries](Series* series)
        {
            gotSeries++;
        });
    }
    while (gotSeries < seriesList.size())
    {
        QApplication::processEvents();
    }
    emit finishedLoadingRecommendations(seriesList);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingRecommendationsReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingRecommendationsReceived);
}

void Series::loadSimilar(int32_t i_page)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingSimilarReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingSimilarReceived);
    m_q.tv_series_similar(m_id, "en-US", i_page);
}

void Series::startedLoadingSimilarReceived()
{
    emit startedLoadingSimilar();
}

void Series::finishedLoadingSimilarReceived(void* i_data)
{
    QJsonObject json = *static_cast<QJsonObject*>(i_data);
    std::vector<Series*> seriesList;
    int gotSeries = 0;
    for (const auto& item : json["results"].toArray())
    {
        seriesList.push_back(new Series(m_q.accessToken().c_str(), item.toObject()["id"].toInt()));
        connect(seriesList.back(), &Series::finishedLoadingSeries, [this, &gotSeries](Series* series)
        {
            gotSeries++;
        });
    }
    while (gotSeries < seriesList.size())
    {
        QCoreApplication::processEvents();
    }
    emit finishedLoadingSimilar(seriesList);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingSimilarReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingSimilarReceived);
}

void Series::loadWatchProviders(Country* i_country)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingWatchProvidersReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingWatchProvidersReceived);
    m_tempCountry = i_country;
    m_q.tv_series_watchProviders(m_id);
}

void Series::startedLoadingWatchProvidersReceived()
{
    emit startedLoadingWatchProviders();
}

void Series::finishedLoadingWatchProvidersReceived(void* i_data)
{
    QJsonObject json = *static_cast<QJsonObject*>(i_data);
    auto temp = static_cast<QJsonObject*>(i_data)->value("results").toObject().value(m_tempCountry->isoCountryCode()).
                                                   toObject();
    std::vector<tmdb::ASync::WatchProvider*> results;
    for (const auto& result : temp["flatrate"].toArray())
    {
        results.push_back(new WatchProvider(result.toObject(), m_q.accessToken().c_str()));
        results.back()->setType(flatrate);
        auto links = config::extractLinksFromUrl(QUrl(temp["link"].toString()));
        for (const auto& link : links)
        {
            if (link.title.contains(results.back()->providerName()) && link.title.contains("Watch "))
            {
                results.back()->setLink(QUrl(link.href));
            }
        }
    }
    for (const auto& result : temp["rent"].toArray())
    {
        results.push_back(new WatchProvider(result.toObject(), m_q.accessToken().c_str()));
        results.back()->setType(rent);
        auto links = config::extractLinksFromUrl(QUrl(temp["link"].toString()));
        for (const auto& link : links)
        {
            if (link.title.contains(results.back()->providerName()) && link.title.contains("Rent "))
            {
                results.back()->setLink(QUrl(link.href));
            }
        }
    }
    for (const auto& result : temp["buy"].toArray())
    {
        results.push_back(new WatchProvider(result.toObject(), m_q.accessToken().c_str()));
        results.back()->setType(buy);
        auto links = config::extractLinksFromUrl(QUrl(temp["link"].toString()));
        for (const auto& link : links)
        {
            if (link.title.contains(results.back()->providerName()) && link.title.contains("Buy "))
            {
                results.back()->setLink(QUrl(link.href));
            }
        }
    }
    emit finishedLoadingWatchProviders(results);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingWatchProvidersReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingWatchProvidersReceived);
}

void Series::loadExternalIDs()
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingExternalIDsReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingExternalIDsReceived);
    m_q.tv_series_externalIDs(m_id);
}

void Series::startedLoadingExternalIDsReceived()
{
    emit startedLoadingExternalIDs();
}

void Series::finishedLoadingExternalIDsReceived(void* i_data)
{
    QJsonObject json = *static_cast<QJsonObject*>(i_data);
    std::array<QString, 9> externalIDs = {
        json["imdb_id"].toString(),
        json["freebase_mid"].toString(),
        json["freebase_id"].toString(),
        json["tvdb_id"].toString(),
        json["tvrage_id"].toString(),
        json["wikidata_id"].toString(),
        json["facebook_id"].toString(),
        json["instagram_id"].toString(),
        json["twitter_id"].toString()
    };
    emit finishedLoadingExternalIDs(externalIDs);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingExternalIDsReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingExternalIDsReceived);
}

void Series::loadBackdrop(int i_index, const QString& i_size)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingBackdropReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingBackdropReceived);
    m_tempIndex = i_index;
    m_tempSize = i_size;
    m_q.tv_series_images(m_id);
}

void Series::startedLoadingBackdropReceived()
{
    emit startedLoadingBackdrop();
}

void Series::finishedLoadingBackdropReceived(void* i_data)
{
    auto temp = static_cast<QJsonObject*>(i_data);
    if (temp->value("backdrops").toArray().isEmpty())
    {
        emit finishedLoadingBackdrop(QPixmap());
        return;
    }
    auto result = temp->value("backdrops").toArray().at(m_tempIndex).toObject();
    Image* b = new Image();
    connect(b, &Image::finishedLoadingImage, this, [this, b](QPixmap i_data)
    {
        emit finishedLoadingBackdrop(i_data);
        disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingBackdropReceived);
        disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingBackdropReceived);
    });
    b->loadImage(QUrl(m_q.getImageURL(result["file_path"].toString().toStdString(), m_tempSize.toStdString()).c_str()));
}

void Series::loadPoster(int i_index, const QString& i_size)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingPosterReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingPosterReceived);
    m_tempIndex = i_index;
    m_tempSize = i_size;
    m_q.tv_series_images(m_id);
}

void Series::startedLoadingPosterReceived()
{
    emit startedLoadingPoster();
}

void Series::finishedLoadingPosterReceived(void* i_data)
{
    auto temp = static_cast<QJsonObject*>(i_data);
    if (temp->value("posters").toArray().isEmpty())
    {
        emit finishedLoadingPoster(QPixmap());
        return;
    }
    auto result = temp->value("posters").toArray().at(m_tempIndex).toObject();
    Image* b = new Image();
    connect(b, &Image::finishedLoadingImage, this, [this, b](QPixmap i_data)
    {
        emit finishedLoadingPoster(i_data);
        disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingPosterReceived);
        disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingPosterReceived);
    });
    b->loadImage(QUrl(m_q.getImageURL(result["file_path"].toString().toStdString(), m_tempSize.toStdString()).c_str()));
}

void Series::loadLogo(int i_index, const QString& i_size)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingLogoReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingLogoReceived);
    m_tempIndex = i_index;
    m_tempSize = i_size;
    m_q.tv_series_images(m_id);
}

void Series::startedLoadingLogoReceived()
{
    emit startedLoadingLogo();
}

void Series::finishedLoadingLogoReceived(void* i_data)
{
    auto temp = static_cast<QJsonObject*>(i_data);
    if (temp->value("logos").toArray().isEmpty())
    {
        emit finishedLoadingLogo(QPixmap());
        return;
    }
    auto result = temp->value("logos").toArray().at(m_tempIndex).toObject();
    Image* b = new Image();
    connect(b, &Image::finishedLoadingImage, this, [this, b](QPixmap i_data)
    {
        emit finishedLoadingLogo(i_data);
        disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingLogoReceived);
        disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingLogoReceived);
    });
    b->loadImage(QUrl(m_q.getImageURL(result["file_path"].toString().toStdString(), m_tempSize.toStdString()).c_str()));
}

void Series::loadSeasons()
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingSeasonsReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingSeasonsReceived);
    m_q.tv_series_details(m_id);
}

void Series::startedLoadingSeasonsReceived()
{
    emit startedLoadingSeasons();
}

void Series::finishedLoadingSeasonsReceived(void* i_data)
{
    QJsonObject json = *static_cast<QJsonObject*>(i_data);
    std::vector<tmdb::ASync::TV::Season*> seasons;
    for (const auto& item : json["seasons"].toArray())
    {
        seasons.push_back(new Season(item.toObject(), m_q.accessToken().c_str()));
    }
    emit finishedLoadingSeasons(seasons);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingSeasonsReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingSeasonsReceived);
}
