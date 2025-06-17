//
// Created by t on 26/05/25.
//

#include "ASync/Movie.h"

#include <QApplication>

#include "ASync/Account.h"
#include "ASync/Image.h"
#include "ASync/QTMDB.h"

tmdb::ASync::Movie::Movie() : m_q("")
{
    m_q.setParent(this);
}

tmdb::ASync::Movie::Movie(const QString& i_access_token) : m_q(i_access_token.toStdString())
{
    m_q.setParent(this);
}

tmdb::ASync::Movie::Movie(const QString& i_access_token, int32_t i_movieID) : Movie(i_access_token)
{
    loadMovie(i_movieID);
}

void tmdb::ASync::Movie::setAdult(bool i_adult) { m_adult = i_adult; }
bool tmdb::ASync::Movie::adult() const { return m_adult; }

void tmdb::ASync::Movie::setBackdropPath(const QString& i_backdropPath) { m_backdropPath = i_backdropPath; }
QString tmdb::ASync::Movie::backdropPath() const { return m_backdropPath; }

void tmdb::ASync::Movie::setBelongsToCollection(const QString& i_belongsToCollection)
{
    m_belongsToCollection = i_belongsToCollection;
}

QString tmdb::ASync::Movie::belongsToCollection() const { return m_belongsToCollection; }

void tmdb::ASync::Movie::setBudget(int i_budget) { m_budget = i_budget; }
int tmdb::ASync::Movie::budget() const { return m_budget; }

void tmdb::ASync::Movie::setGenres(const std::vector<Genre*>& i_genres) { m_genres = i_genres; }
std::vector<tmdb::ASync::Genre*> tmdb::ASync::Movie::genres() const { return m_genres; }

void tmdb::ASync::Movie::setHomepage(const QString& i_homepage) { m_homepage = i_homepage; }
QString tmdb::ASync::Movie::homepage() const { return m_homepage; }

void tmdb::ASync::Movie::setId(int i_id) { m_id = i_id; }
int tmdb::ASync::Movie::id() const { return m_id; }

void tmdb::ASync::Movie::setImdbID(const QString& i_imdbID) { m_imdbID = i_imdbID; }
QString tmdb::ASync::Movie::imdbID() const { return m_imdbID; }

void tmdb::ASync::Movie::setOriginalLanguage(Language* i_originalLanguage)
{
    m_originalLanguage = i_originalLanguage;
}

tmdb::ASync::Language* tmdb::ASync::Movie::originalLanguage() const { return m_originalLanguage; }

void tmdb::ASync::Movie::setOriginalTitle(const QString& i_originalTitle) { m_originalTitle = i_originalTitle; }
QString tmdb::ASync::Movie::originalTitle() const { return m_originalTitle; }

void tmdb::ASync::Movie::setOverview(const QString& i_overview) { m_overview = i_overview; }
QString tmdb::ASync::Movie::overview() const { return m_overview; }

void tmdb::ASync::Movie::setPopularity(float i_popularity) { m_popularity = i_popularity; }
float tmdb::ASync::Movie::popularity() const { return m_popularity; }

void tmdb::ASync::Movie::setPosterPath(const QString& i_posterPath) { m_posterPath = i_posterPath; }
QString tmdb::ASync::Movie::posterPath() const { return m_posterPath; }

void tmdb::ASync::Movie::setProductionCompanies(const std::vector<Company*>& i_productionCompanies)
{
    m_productionCompanies = i_productionCompanies;
}

std::vector<tmdb::ASync::Company*> tmdb::ASync::Movie::productionCompanies() const { return m_productionCompanies; }

void tmdb::ASync::Movie::setCountries(const std::vector<Country*>& i_countries) { m_countries = i_countries; }
std::vector<tmdb::ASync::Country*> tmdb::ASync::Movie::countries() const { return m_countries; }

void tmdb::ASync::Movie::setReleaseDate(const QDate& i_releaseDate) { m_releaseDate = i_releaseDate; }
QDate tmdb::ASync::Movie::releaseDate() const { return m_releaseDate; }

void tmdb::ASync::Movie::setRevenue(int i_revenue) { m_revenue = i_revenue; }
int tmdb::ASync::Movie::revenue() const { return m_revenue; }

void tmdb::ASync::Movie::setRuntime(int i_runtime) { m_runtime = i_runtime; }
int tmdb::ASync::Movie::runtime() const { return m_runtime; }

void tmdb::ASync::Movie::setLanguages(const std::vector<Language*>& i_languages) { m_languages = i_languages; }
std::vector<tmdb::ASync::Language*> tmdb::ASync::Movie::languages() const { return m_languages; }

void tmdb::ASync::Movie::setStatus(const QString& i_status) { m_status = i_status; }
QString tmdb::ASync::Movie::status() const { return m_status; }

void tmdb::ASync::Movie::setTagline(const QString& i_tagline) { m_tagline = i_tagline; }
QString tmdb::ASync::Movie::tagline() const { return m_tagline; }

void tmdb::ASync::Movie::setTitle(const QString& i_title) { m_title = i_title; }
QString tmdb::ASync::Movie::title() const { return m_title; }

void tmdb::ASync::Movie::setVideo(bool i_video) { m_video = i_video; }
bool tmdb::ASync::Movie::video() const { return m_video; }

void tmdb::ASync::Movie::setVoteAverage(float i_voteAverage) { m_voteAverage = i_voteAverage; }
float tmdb::ASync::Movie::voteAverage() const { return m_voteAverage; }

void tmdb::ASync::Movie::setVoteCount(int i_voteCount) { m_voteCount = i_voteCount; }
int tmdb::ASync::Movie::voteCount() const { return m_voteCount; }

tmdb::ASync::Movie::Movie(const QJsonObject& i_json, const QString& i_access_token)
    : Movie(i_access_token)
{
    parseJson(i_json, i_access_token);
}

void tmdb::ASync::Movie::parseJson(const QJsonObject& i_json, const QString& i_access_token)
{
    setAdult(i_json["adult"].toBool());
    setBackdropPath(i_json["backdrop_path"].toString());
    setBelongsToCollection(i_json["belongs_to_collection"].toString());
    setBudget(i_json["budget"].toInt());
    auto genresArray = std::vector<Genre*>();
    for (const auto& genre : i_json["genres"].toArray())
    {
        genresArray.push_back(new Genre(genre.toObject(), i_access_token));
    }
    setGenres(genresArray);
    setHomepage(i_json["homepage"].toString());
    setId(i_json["id"].toInt());
    setImdbID(i_json["imdb_id"].toString());
    bool languageSet = false;
    setOriginalLanguage(new Language(i_access_token, i_json["original_language"].toString()));
    connect(originalLanguage(), &Language::finishedLoadingLanguage, [&languageSet](Language* language)
    {
        languageSet = true;
    });
    setOriginalTitle(i_json["original_title"].toString());
    setOverview(i_json["overview"].toString());
    setPopularity(i_json["popularity"].toDouble());
    setPosterPath(i_json["poster_path"].toString());
    auto productionCompaniesArray = std::vector<Company*>();
    for (const auto& company : i_json["production_companies"].toArray())
    {
        productionCompaniesArray.push_back(new Company(company.toObject(), i_access_token));
    }
    setProductionCompanies(productionCompaniesArray);
    auto countriesArray = std::vector<Country*>();
    int countriesLoaded = 0;
    for (const auto& country : i_json["production_countries"].toArray())
    {
        countriesArray.push_back(new Country(i_access_token, country.toObject()["iso_3166_1"].toString()));
        countriesArray.back()->connect(countriesArray.back(), &Country::finishedLoadingCountry,
                                       [&countriesLoaded](Country* country)
                                       {
                                           countriesLoaded++;
                                       });
    }
    setCountries(countriesArray);
    setReleaseDate(QDate::fromString(i_json["release_date"].toString(), Qt::ISODate));
    setRevenue(i_json["revenue"].toInt());
    setRuntime(i_json["runtime"].toInt());
    auto languagesArray = std::vector<Language*>();
    for (const auto& language : i_json["spoken_languages"].toArray())
    {
        languagesArray.push_back(new Language(language.toObject(), i_access_token));
    }
    setLanguages(languagesArray);
    setStatus(i_json["status"].toString());
    setTagline(i_json["tagline"].toString());
    setTitle(i_json["title"].toString());
    setVideo(i_json["video"].toBool());
    setVoteAverage(i_json["vote_average"].toDouble());
    setVoteCount(i_json["vote_count"].toInt());
    while (countriesLoaded < countriesArray.size() || !languageSet)
    {
        QApplication::processEvents();
    }
}

void tmdb::ASync::Movie::loadMovie(int32_t i_movieID)
{
    setId(i_movieID);
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingMovieReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingMovieReceived);
    m_q.movie_details(i_movieID);
}

void tmdb::ASync::Movie::startedLoadingMovieReceived()
{
    emit startedLoadingMovie();
}

void tmdb::ASync::Movie::finishedLoadingMovieReceived(void* i_data)
{
    parseJson(*static_cast<QJsonObject*>(i_data), m_q.accessToken().c_str());
    emit finishedLoadingMovie(this);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingMovieReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingMovieReceived);
}

void tmdb::ASync::Movie::loadSearchResults(const QString& i_query, int32_t i_page, int32_t i_year,
                                           int32_t i_primaryReleaseYear, bool i_includeAdult,
                                           const QString& i_country, const QString& i_language)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingSearchResultsReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingSearchResultsReceived);
    m_q.get_movie(i_query.toStdString(), i_includeAdult, i_language.toStdString(), std::to_string(i_primaryReleaseYear),
                  i_page, i_country.toStdString(), std::to_string(i_year));
}

void tmdb::ASync::Movie::startedLoadingSearchResultsReceived()
{
    emit startedLoadingSearchResults();
}

void tmdb::ASync::Movie::finishedLoadingSearchResultsReceived(void* i_data)
{
    auto temp = static_cast<QJsonObject*>(i_data);
    auto results = std::vector<Movie*>();
    int got = 0;
    for (const auto& result : temp->value("results").toArray())
    {
        results.push_back(new Movie(m_q.accessToken().c_str(), result.toObject()["id"].toInt()));
        tmdb::ASync::Movie::connect(results.back(), &Movie::finishedLoadingMovie, [this, &got](Movie* movie)
        {
            got++;
        });
    }
    while (got < results.size())
    {
        QApplication::processEvents();
    }
    emit finishedLoadingSearchResults(results);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingSearchResultsReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingSearchResultsReceived);
}

void tmdb::ASync::Movie::loadNowPlaying()
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingNowPlayingReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingNowPlayingReceived);
    m_q.movieList_nowPlaying("GB");
}

void tmdb::ASync::Movie::startedLoadingNowPlayingReceived()
{
    emit startedLoadingNowPlaying();
}

void tmdb::ASync::Movie::finishedLoadingNowPlayingReceived(void* i_data)
{
    auto temp = static_cast<QJsonObject*>(i_data);
    auto results = std::vector<Movie*>();
    int got = 0;
    for (const auto& result : temp->value("results").toArray())
    {
        results.push_back(new Movie(m_q.accessToken().c_str(), result.toObject()["id"].toInt()));
        results.back()->connect(results.back(), &Movie::finishedLoadingMovie, [this, &got](Movie* movie)
        {
            got++;
        });
    }
    while (got < results.size())
    {
        QApplication::processEvents();
    }
    emit finishedLoadingNowPlaying(results);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingNowPlayingReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingNowPlayingReceived);
}

void tmdb::ASync::Movie::loadPopular()
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingPopularReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingPopularReceived);
    m_q.movieList_popular("GB");
}

void tmdb::ASync::Movie::startedLoadingPopularReceived()
{
    emit startedLoadingPopular();
}

void tmdb::ASync::Movie::finishedLoadingPopularReceived(void* i_data)
{
    auto temp = static_cast<QJsonObject*>(i_data);
    auto results = std::vector<Movie*>();
    int got = 0;
    for (const auto& result : temp->value("results").toArray())
    {
        results.push_back(new Movie(m_q.accessToken().c_str(), result.toObject()["id"].toInt()));
        results.back()->connect(results.back(), &Movie::finishedLoadingMovie, [this, &got](Movie* movie)
        {
            got++;
        });
    }
    while (got < results.size())
    {
        QApplication::processEvents();
    }
    emit finishedLoadingPopular(results);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingPopularReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingPopularReceived);
}

void tmdb::ASync::Movie::loadTopRated()
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingTopRatedReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingTopRatedReceived);
    m_q.movieList_topRated("GB");
}

void tmdb::ASync::Movie::startedLoadingTopRatedReceived()
{
    emit startedLoadingTopRated();
}

void tmdb::ASync::Movie::finishedLoadingTopRatedReceived(void* i_data)
{
    auto temp = static_cast<QJsonObject*>(i_data);
    auto results = std::vector<Movie*>();
    int got = 0;
    for (const auto& result : temp->value("results").toArray())
    {
        results.push_back(new Movie(m_q.accessToken().c_str(), result.toObject()["id"].toInt()));
        results.back()->connect(results.back(), &Movie::finishedLoadingMovie, [this, &got](Movie* movie)
        {
            got++;
        });
    }
    while (got < results.size())
    {
        QApplication::processEvents();
    }
    emit finishedLoadingTopRated(results);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingTopRatedReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingTopRatedReceived);
}

void tmdb::ASync::Movie::loadUpcoming()
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingUpcomingReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingUpcomingReceived);
    m_q.movieList_upcoming("GB");
}

void tmdb::ASync::Movie::startedLoadingUpcomingReceived()
{
    emit startedLoadingUpcoming();
}

void tmdb::ASync::Movie::finishedLoadingUpcomingReceived(void* i_data)
{
    auto temp = static_cast<QJsonObject*>(i_data);
    auto results = std::vector<Movie*>();
    int got = 0;
    for (const auto& result : temp->value("results").toArray())
    {
        results.push_back(new Movie(m_q.accessToken().c_str(), result.toObject()["id"].toInt()));
        results.back()->connect(results.back(), &Movie::finishedLoadingMovie, [this, &got](Movie* movie)
        {
            got++;
        });
    }
    while (got < results.size())
    {
        QApplication::processEvents();
    }
    emit finishedLoadingUpcoming(results);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingUpcomingReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingUpcomingReceived);
}

void tmdb::ASync::Movie::loadRecommendations(int32_t i_page)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingRecommendationsReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingRecommendationsReceived);
    m_q.movie_recommendations(m_id, "en-US", i_page);
}

void tmdb::ASync::Movie::startedLoadingRecommendationsReceived()
{
    emit startedLoadingRecommendations();
}

void tmdb::ASync::Movie::finishedLoadingRecommendationsReceived(void* i_data)
{
    auto temp = static_cast<QJsonObject*>(i_data);
    auto results = std::vector<Movie*>();
    int got = 0;
    for (const auto& result : temp->value("results").toArray())
    {
        results.push_back(new Movie(m_q.accessToken().c_str(), result.toObject()["id"].toInt()));
        results.back()->connect(results.back(), &Movie::finishedLoadingMovie, [this, &got](Movie* movie)
        {
            got++;
        });
    }
    while (got < results.size())
    {
        QApplication::processEvents();
    }
    emit finishedLoadingRecommendations(results);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingRecommendationsReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingRecommendationsReceived);
}

void tmdb::ASync::Movie::loadSimilar(int32_t i_page)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingSimilarReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingSimilarReceived);
    m_q.movie_similar(m_id, "en-US", i_page);
}

void tmdb::ASync::Movie::startedLoadingSimilarReceived()
{
    emit startedLoadingSimilar();
}

void tmdb::ASync::Movie::finishedLoadingSimilarReceived(void* i_data)
{
    auto temp = static_cast<QJsonObject*>(i_data);
    auto results = std::vector<Movie*>();
    int got = 0;
    for (const auto& result : temp->value("results").toArray())
    {
        results.push_back(new Movie(m_q.accessToken().c_str(), result.toObject()["id"].toInt()));
        results.back()->connect(results.back(), &Movie::finishedLoadingMovie, [this, &got](Movie* movie)
        {
            got++;
        });
    }
    while (got < results.size())
    {
        QApplication::processEvents();
    }
    emit finishedLoadingSimilar(results);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingSimilarReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingSimilarReceived);
}

void tmdb::ASync::Movie::loadExternalIDs(int32_t i_movieID)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingExternalIDsReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingExternalIDsReceived);
    m_q.movie_externalIDs(i_movieID);
}

void tmdb::ASync::Movie::startedLoadingExternalIDsReceived()
{
    emit startedLoadingExternalIDs();
}

void tmdb::ASync::Movie::finishedLoadingExternalIDsReceived(void* i_data)
{
    auto temp = static_cast<QJsonObject*>(i_data);
    std::array<QString, 5> externalIDs;
    externalIDs[0] = temp->value("imdb_id").toString();
    externalIDs[1] = temp->value("facebook_id").toString();
    externalIDs[2] = temp->value("instagram_id").toString();
    externalIDs[3] = temp->value("twitter_id").toString();
    externalIDs[4] = temp->value("tiktok_id").toString();
    emit finishedLoadingExternalIDs(externalIDs);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingExternalIDsReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingExternalIDsReceived);
}

void tmdb::ASync::Movie::loadBackdrop(int i_index, const QString& i_size)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingBackdropReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingBackdropReceived);
    m_tempIndex = i_index;
    m_tempSize = i_size;
    m_q.movie_images(m_id, "en");
}

void tmdb::ASync::Movie::startedLoadingBackdropReceived()
{
    emit startedLoadingBackdrop();
}

void tmdb::ASync::Movie::finishedLoadingBackdropReceived(void* i_data)
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
        disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingBackdropReceived);
        disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingBackdropReceived);
    });
    b->loadImage(QUrl(m_q.getImageURL(result["file_path"].toString().toStdString(), m_tempSize.toStdString()).c_str()));
}

void tmdb::ASync::Movie::loadPoster(int i_index, const QString& i_size)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingPosterReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingPosterReceived);
    m_tempIndex = i_index;
    m_tempSize = i_size;
    m_q.movie_images(m_id, "en");
}

void tmdb::ASync::Movie::startedLoadingPosterReceived()
{
    emit startedLoadingPoster();
}

void tmdb::ASync::Movie::finishedLoadingPosterReceived(void* i_data)
{
    auto temp = static_cast<QJsonObject*>(i_data);
    if (temp->value("posters").toArray().isEmpty())
    {
        emit finishedLoadingPoster(QPixmap());
        return;
    }
    auto result = temp->value("posters").toArray().at(m_tempIndex).toObject();
    Image* p = new Image();
    connect(p, &Image::finishedLoadingImage, this, [this, p](QPixmap i_data)
    {
        emit finishedLoadingPoster(i_data);
        disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingPosterReceived);
        disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingPosterReceived);
    });
    p->loadImage(QUrl(m_q.getImageURL(result["file_path"].toString().toStdString(), m_tempSize.toStdString()).c_str()));
}

void tmdb::ASync::Movie::loadLogo(int i_index, const QString& i_size)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingLogoReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingLogoReceived);
    m_tempIndex = i_index;
    m_tempSize = i_size;
    m_q.movie_images(m_id, "en");
}

void tmdb::ASync::Movie::startedLoadingLogoReceived()
{
    emit startedLoadingLogo();
}

void tmdb::ASync::Movie::finishedLoadingLogoReceived(void* i_data)
{
    auto temp = static_cast<QJsonObject*>(i_data);
    if (temp->value("logos").toArray().isEmpty())
    {
        emit finishedLoadingLogo(QPixmap());
        return;
    }
    auto result = temp->value("logos").toArray().at(m_tempIndex).toObject();
    Image* l = new Image();
    connect(l, &Image::finishedLoadingImage, this, [this, l](QPixmap i_data)
    {
        emit finishedLoadingLogo(i_data);
        disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingLogoReceived);
        disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingLogoReceived);
    });
    l->loadImage(QUrl(m_q.getImageURL(result["file_path"].toString().toStdString(), m_tempSize.toStdString()).c_str()));
}

void tmdb::ASync::Movie::loadWatchProviders(Country* i_region)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingWatchProvidersReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingWatchProvidersReceived);
    m_region = i_region;
    m_q.movie_watchProviders(m_id);
}

void tmdb::ASync::Movie::startedLoadingWatchProvidersReceived()
{
    emit startedLoadingWatchProviders();
}

void tmdb::ASync::Movie::finishedLoadingWatchProvidersReceived(void* i_data)
{
    auto temp = static_cast<QJsonObject*>(i_data)->value("results").toObject().value(m_region->isoCountryCode()).
                                                   toObject();
    auto results = std::vector<WatchProvider*>();
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
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingWatchProvidersReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingWatchProvidersReceived);
}

void tmdb::ASync::Movie::loadKeywords()
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingKeywordsReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingKeywordsReceived);
    m_q.movie_keywords(m_id);
}

void tmdb::ASync::Movie::startedLoadingKeywordsReceived()
{
    emit startedLoadingKeywords();
}

void tmdb::ASync::Movie::finishedLoadingKeywordsReceived(void* i_data)
{
    auto temp = static_cast<QJsonObject*>(i_data);
    auto results = std::map<int, QString>();
    for (const auto& result : temp->value("keywords").toArray())
    {
        auto keyword = result.toObject();
        results[keyword["id"].toInt()] = keyword["name"].toString();
    }
    emit finishedLoadingKeywords(results);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingKeywordsReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingKeywordsReceived);
}

void tmdb::ASync::Movie::loadCredits()
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingCreditsReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingCreditsReceived);
    m_q.movie_credits(m_id);
}

void tmdb::ASync::Movie::startedLoadingCreditsReceived()
{
    emit startedLoadingCredits();
}

void tmdb::ASync::Movie::finishedLoadingCreditsReceived(void* i_data)
{
    auto temp = static_cast<QJsonObject*>(i_data);
    auto results = std::vector<Credit*>();
    for (const auto& result : temp->value("cast").toArray())
    {
        results.push_back(new Credit(result.toObject(), m_q.accessToken().c_str()));
    }
    emit finishedLoadingCredits(results);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Movie::startedLoadingCreditsReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Movie::finishedLoadingCreditsReceived);
}
