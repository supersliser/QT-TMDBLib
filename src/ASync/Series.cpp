//
// Created by t on 30/05/25.
//

#include "ASync/Series.h"
#include <QJsonObject>

#include "ASync/Image.h"
#include "Sync/QTMDB.h"

using namespace tmdb::ASync::TV;
void Series::setAdult(bool i_adult) {
    m_adult = i_adult;
}
bool Series::adult() const {
    return m_adult;
}

void Series::setBackdropPath(const QString &i_backdropPath) {
    m_backdropPath = i_backdropPath;
}
QString Series::backdropPath() const {
    return m_backdropPath;
}

void Series::setCreatedBy(const std::vector<Person> &i_createdBy) {
    m_createdBy = i_createdBy;
}

std::vector<tmdb::ASync::Person> Series::createdBy() const {
    return m_createdBy;
}

void Series::setEpisodeRunTime(const std::vector<int> &i_episodeRunTime) {
    m_episodeRunTime = i_episodeRunTime;
}
std::vector<int> Series::episodeRunTime() const {
    return m_episodeRunTime;
}

void Series::setFirstAirDate(const QDate &i_firstAirDate) {
    m_firstAirDate = i_firstAirDate;
}
QDate Series::firstAirDate() const {
    return m_firstAirDate;
}

void Series::setGenres(const std::vector<Genre> &i_genres) {
    m_genres = i_genres;
}
std::vector<tmdb::ASync::Genre> Series::genres() const {
    return m_genres;
}

void Series::setHomepage(const QString &i_homepage) {
    m_homepage = i_homepage;
}
QString Series::homepage() const {
    return m_homepage;
}

void Series::setId(int i_id) {
    m_id = i_id;
}
int Series::id() const {
    return m_id;
}

void Series::setInProduction(bool i_inProduction) {
    in_production = i_inProduction;
}
bool Series::inProduction() const {
    return in_production;
}

void Series::setLanguages(const std::vector<Language> &i_languages) {
    m_languages = i_languages;
}
std::vector<tmdb::ASync::Language> Series::languages() const {
    return m_languages;
}

void Series::setLastAirDate(const QDate &i_lastAirDate) {
    m_lastAirDate = i_lastAirDate;
}
QDate Series::lastAirDate() const {
    return m_lastAirDate;
}

void Series::setName(const QString &i_name) {
    m_name = i_name;
}
QString Series::name() const {
    return m_name;
}

void Series::setNetworks(const std::vector<Network> &i_networks) {
    m_networks = i_networks;
}
std::vector<Network> Series::networks() const {
    return m_networks;
}

void Series::setOriginCountries(const std::vector<Country> &i_originCountries) {
    m_originCountries = i_originCountries;
}
std::vector<tmdb::ASync::Country> Series::originCountries() const {
    return m_originCountries;
}

void Series::setOriginalLanguage(const QString &i_originalLanguage) {
    m_originalLanguage = i_originalLanguage;
}
QString Series::originalLanguage() const {
    return m_originalLanguage;
}

void Series::setOverview(const QString &i_overview) {
    m_overview = i_overview;
}
QString Series::overview() const {
    return m_overview;
}

void Series::setPopularity(float i_popularity) {
    m_popularity = i_popularity;
}
float Series::popularity() const {
    return m_popularity;
}

void Series::setPosterPath(const QString &i_posterPath) {
    m_posterPath = i_posterPath;
}
QString Series::posterPath() const {
    return m_posterPath;
}

void Series::setProductionCompanies(const std::vector<Company> &i_productionCompanies) {
    m_productionCompanies = i_productionCompanies;
}
std::vector<tmdb::ASync::Company> Series::productionCompanies() const {
    return m_productionCompanies;
}

void Series::setProductionCountries(const std::vector<Country> &i_productionCountries) {
    m_productionCountries = i_productionCountries;
}
std::vector<tmdb::ASync::Country> Series::productionCountries() const {
    return m_productionCountries;
}

void Series::setSeasons(const std::vector<Season> &i_seasons) {
    m_seasons = i_seasons;
}
std::vector<tmdb::ASync::TV::Season> Series::seasons() const {
    return m_seasons;
}

void Series::setStatus(const QString &i_status) {
    m_status = i_status;
}
QString Series::status() const {
    return m_status;
}

void Series::setSpokenLanguages(const std::vector<Language> &i_spokenLanguages) {
    m_spokenLanguages = i_spokenLanguages;
}
std::vector<tmdb::ASync::Language> Series::spokenLanguages() const {
    return m_spokenLanguages;
}

void Series::setType(const QString &i_type) {
    m_type = i_type;
}
QString Series::type() const {
    return m_type;
}

void Series::setVoteAverage(float i_voteAverage) {
    m_voteAverage = i_voteAverage;
}
float Series::voteAverage() const {
    return m_voteAverage;
}

void Series::setVoteCount(int i_voteCount) {
    m_voteCount = i_voteCount;
}
int Series::voteCount() const {
    return m_voteCount;
}

void Series::setTagline(const QString &i_tagline)
{
    m_tagline = i_tagline;
}
QString Series::tagline() const
{
    return m_tagline;
}

Series::Series(const QString& i_access_token, int32_t i_seriesID) : m_q(i_access_token.toStdString()) {
    loadSeries(i_seriesID);
}

Series* Series::fromJSON(const QJsonObject &i_json) {
    auto *s = new Series();
    s->m_adult = i_json["adult"].toBool();
    s->m_backdropPath = i_json["backdrop_path"].toString();
    std::vector<tmdb::ASync::Person> createdByArray;
    for (const auto &item : i_json["created_by"].toArray()) {
        createdByArray.push_back(*Person::fromJSON(item.toObject()));
    }
    s->m_createdBy = createdByArray;
    std::vector<int> episodeRunTimeArray;
    for (const auto &item : i_json["episode_run_time"].toArray()) {
        episodeRunTimeArray.push_back(item.toInt());
    }
    s->m_episodeRunTime = episodeRunTimeArray;
    s->m_firstAirDate = QDate::fromString(i_json["first_air_date"].toString(), Qt::ISODate);
    std::vector<tmdb::ASync::Genre> genreArray;
    for (const auto &item : i_json["genres"].toArray()) {
        genreArray.push_back(*Genre::fromJSON(item.toObject()));
    }
    s->m_genres = genreArray;
    s->m_homepage = i_json["homepage"].toString();
    s->m_id = i_json["id"].toInt();
    s->in_production = i_json["in_production"].toBool();
    std::vector<Language> languageArray;
    for (const auto &item : i_json["languages"].toArray()) {
        languageArray.emplace_back(m_q.accessToken().c_str(), item.toString());
    }
    s->m_languages = languageArray;
    s->m_lastAirDate = QDate::fromString(i_json["last_air_date"].toString(), Qt::ISODate);
    s->m_name = i_json["name"].toString();
    std::vector<Network> networkArray;
    for (const auto &item : i_json["networks"].toArray()) {
        networkArray.emplace_back(m_q.accessToken().c_str(), item.toObject()["id"].toInt());
    }
    s->m_networks = networkArray;
    s->m_episodeCount = i_json["number_of_episodes"].toInt();
    s->m_seasonCount = i_json["number_of_seasons"].toInt();
    std::vector<Country> originCountryArray;
    for (const auto &item : i_json["origin_country"].toArray()) {
        originCountryArray.emplace_back(m_q.accessToken().c_str(), item.toString());
    }
    s->m_originCountries = originCountryArray;
    s->m_originalLanguage = i_json["original_language"].toString();
    s->m_overview = i_json["overview"].toString();
    s->m_popularity = static_cast<float>(i_json["popularity"].toDouble());
    s->m_posterPath = i_json["poster_path"].toString();
    std::vector<Company> companyArray;
    for (const auto &item : i_json["production_companies"].toArray()) {
        companyArray.push_back(*Company::fromJSON(item.toObject(), m_q.accessToken().c_str()));
    }
    s->m_productionCompanies = companyArray;
    std::vector<Country> productionCountryArray;
    for (const auto &item : i_json["production_countries"].toArray()) {
        productionCountryArray.emplace_back(m_q.accessToken().c_str(), item.toObject()["iso_3166_1"].toString());
    }
    s->m_productionCountries = productionCountryArray;
    std::vector<Season> seasonArray;
    for (const auto &item : i_json["seasons"].toArray()) {
        seasonArray.push_back(*Season::fromJSON(item.toObject()));
    }
    s->m_seasons = seasonArray;
    std::vector<Language> spokenLanguageArray;
    for (const auto &item : i_json["spoken_languages"].toArray()) {
        spokenLanguageArray.emplace_back(m_q.accessToken().c_str(), item.toObject()["iso_639_1"].toString());
    }
    s->m_spokenLanguages = spokenLanguageArray;
    s->m_status = i_json["status"].toString();
    s->m_tagline = i_json["tagline"].toString();
    s->m_type = i_json["type"].toString();
    s->m_voteAverage = static_cast<float>(i_json["vote_average"].toDouble());
    s->m_voteCount = i_json["vote_count"].toInt();
    return s;
}

Series::Series() : m_q("") {
    m_q.setParent(this);
}

void Series::loadSeries(int32_t i_seriesID) {
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingSeriesReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingSeriesReceived);
    m_q.tv_series_details(i_seriesID);
}
void Series::startedLoadingSeriesReceived() {
    emit startedLoadingSeries();
}
void Series::finishedLoadingSeriesReceived(void* i_data) {
    QJsonObject json = *static_cast<QJsonObject*>(i_data);
    auto series = fromJSON(json);
    emit finishedLoadingSeries(series);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingSeriesReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingSeriesReceived);
}

void Series::loadSearchResults(const QString& i_query, int32_t i_page, const Language& i_language, bool i_includeAdult, int i_year, int i_firstAirYear){
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingSearchResultsReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingSearchResultsReceived);
    m_q.get_tv(i_query.toStdString(), i_firstAirYear, i_includeAdult, i_language.iso6391().toStdString(), i_page, i_year);
}
void Series::startedLoadingSearchResultsReceived() {
    emit startedLoadingSearchResults();
}
void Series::finishedLoadingSearchResultsReceived(void* i_data) {
    QJsonObject json = *static_cast<QJsonObject*>(i_data);
    std::vector<Series> seriesList;
    for (const auto &item : json["results"].toArray()) {
        seriesList.emplace_back(m_q.accessToken().c_str(), item.toObject()["id"].toInt());
    }
    emit finishedLoadingSearchResults(seriesList);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingSearchResultsReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingSearchResultsReceived);
}

void Series::loadAiringToday(const Language& i_language, int32_t i_page, const QString& i_region) {
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingAiringTodayReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingAiringTodayReceived);
    m_q.tv_series_airingToday(i_language.iso6391().toStdString(), i_page, i_region.toStdString());
}
void Series::startedLoadingAiringTodayReceived() {
    emit startedLoadingAiringToday();
}
void Series::finishedLoadingAiringTodayReceived(void* i_data) {
    QJsonObject json = *static_cast<QJsonObject*>(i_data);
    std::vector<Series> seriesList;
    for (const auto &item : json["results"].toArray()) {
        seriesList.emplace_back(m_q.accessToken().c_str(), item.toObject()["id"].toInt());
    }
    emit finishedLoadingAiringToday(seriesList);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingAiringTodayReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingAiringTodayReceived);
}

void Series::loadOnTheAir(const Language& i_language, int32_t i_page, const QString& i_region) {
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingOnTheAirReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingOnTheAirReceived);
    m_q.tv_series_onTheAir(i_language.iso6391().toStdString(), i_page, i_region.toStdString());
}
void Series::startedLoadingOnTheAirReceived() {
    emit startedLoadingOnTheAir();
}
void Series::finishedLoadingOnTheAirReceived(void* i_data) {
    QJsonObject json = *static_cast<QJsonObject*>(i_data);
    std::vector<Series> seriesList;
    for (const auto &item : json["results"].toArray()) {
        seriesList.emplace_back(m_q.accessToken().c_str(), item.toObject()["id"].toInt());
    }
    emit finishedLoadingOnTheAir(seriesList);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingOnTheAirReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingOnTheAirReceived);
}

void Series::loadPopular(const Language& i_language, int32_t i_page) {
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingPopularReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingPopularReceived);
    m_q.tv_series_popular(i_language.iso6391().toStdString(), i_page);
}
void Series::startedLoadingPopularReceived() {
    emit startedLoadingPopular();
}
void Series::finishedLoadingPopularReceived(void* i_data) {
    QJsonObject json = *static_cast<QJsonObject*>(i_data);
    std::vector<Series> seriesList;
    for (const auto &item : json["results"].toArray()) {
        seriesList.emplace_back(m_q.accessToken().c_str(), item.toObject()["id"].toInt());
    }
    emit finishedLoadingPopular(seriesList);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingPopularReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingPopularReceived);
}

void Series::loadTopRated(const Language& i_language, int32_t i_page) {
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingTopRatedReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingTopRatedReceived);
    m_q.tv_series_topRated(i_language.iso6391().toStdString(), i_page);
}
void Series::startedLoadingTopRatedReceived() {
    emit startedLoadingTopRated();
}
void Series::finishedLoadingTopRatedReceived(void* i_data) {
    QJsonObject json = *static_cast<QJsonObject*>(i_data);
    std::vector<Series> seriesList;
    for (const auto &item : json["results"].toArray()) {
        seriesList.emplace_back(m_q.accessToken().c_str(), item.toObject()["id"].toInt());
    }
    emit finishedLoadingTopRated(seriesList);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingTopRatedReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingTopRatedReceived);
}

void Series::loadRecommendations(int32_t i_page) {
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingRecommendationsReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingRecommendationsReceived);
    m_q.tv_series_recommendations(m_id, "en-US", i_page);
}
void Series::startedLoadingRecommendationsReceived() {
    emit startedLoadingRecommendations();
}
void Series::finishedLoadingRecommendationsReceived(void* i_data) {
    QJsonObject json = *static_cast<QJsonObject*>(i_data);
    std::vector<Series> seriesList;
    for (const auto &item : json["results"].toArray()) {
        seriesList.emplace_back(m_q.accessToken().c_str(), item.toObject()["id"].toInt());
    }
    emit finishedLoadingRecommendations(seriesList);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingRecommendationsReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingRecommendationsReceived);
}

void Series::loadSimilar(int32_t i_page) {
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingSimilarReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingSimilarReceived);
    m_q.tv_series_similar(m_id, "en-US", i_page);
}
void Series::startedLoadingSimilarReceived() {
    emit startedLoadingSimilar();
}
void Series::finishedLoadingSimilarReceived(void* i_data) {
    QJsonObject json = *static_cast<QJsonObject*>(i_data);
    std::vector<Series> seriesList;
    for (const auto &item : json["results"].toArray()) {
        seriesList.emplace_back(m_q.accessToken().c_str(), item.toObject()["id"].toInt());
    }
    emit finishedLoadingSimilar(seriesList);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingSimilarReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingSimilarReceived);
}

void Series::loadWatchProviders( Country* i_country) {
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingWatchProvidersReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingWatchProvidersReceived);
    m_tempCountry = i_country;
    m_q.tv_series_watchProviders(m_id);
}
void Series::startedLoadingWatchProvidersReceived() {
    emit startedLoadingWatchProviders();
}
void Series::finishedLoadingWatchProvidersReceived(void* i_data) {
    QJsonObject json = *static_cast<QJsonObject*>(i_data);
    std::vector<tmdb::ASync::WatchProvider> watchProviders;
    for (const auto &item : json["results"].toObject()) {
        watchProviders.push_back(*tmdb::ASync::WatchProvider::fromJSON(item.toObject()));
    }
    emit finishedLoadingWatchProviders(watchProviders);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingWatchProvidersReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingWatchProvidersReceived);
}

void Series::loadExternalIDs() {
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingExternalIDsReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingExternalIDsReceived);
    m_q.tv_series_externalIDs(m_id);
}
void Series::startedLoadingExternalIDsReceived() {
    emit startedLoadingExternalIDs();
}
void Series::finishedLoadingExternalIDsReceived(void* i_data) {
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

void Series::loadBackdrops(const QString& i_size) {
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingBackdropsReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingBackdropsReceived);
    m_q.tv_series_images(m_id);
}
void Series::startedLoadingBackdropsReceived() {
    emit startedLoadingBackdrops();
}
void Series::finishedLoadingBackdropsReceived(void* i_data) {
    auto temp = static_cast<QJsonObject*>(i_data);
    auto results = std::vector<Image>();
    for (const auto& result : temp->value("backdrops").toArray())
    {
        Image* b = new Image();
        connect(b, &Image::finishedLoadingImage, this, [this, b](void* i_data) {
            b->setPixmap(*static_cast<QPixmap*>(i_data));
            emit finishedLoadingBackdrop(b->pixmap());
        });
        b->loadImage(result.toObject()["file_path"].toString());
        results.push_back(*b);
    }
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingBackdropsReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingBackdropsReceived);
}

void Series::loadBackdrop(int i_index, const QString& i_size) {
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingBackdropReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingBackdropReceived);
    m_q.tv_series_images(m_id);
}
void Series::startedLoadingBackdropReceived() {
    emit startedLoadingBackdrop();
}
void Series::finishedLoadingBackdropReceived(void* i_data) {
    auto temp = static_cast<QJsonObject*>(i_data);
    auto results = std::vector<Image>();
    for (const auto& result : temp->value("backdrops").toArray())
    {
        Image* b = new Image();
        connect(b, &Image::finishedLoadingImage, this, [this, b](void* i_data) {
            b->setPixmap(*static_cast<QPixmap*>(i_data));
            emit finishedLoadingBackdrop(b->pixmap());
        });
        b->loadImage(result.toObject()["file_path"].toString());
        results.push_back(*b);
    }
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingBackdropsReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingBackdropsReceived);
}

void Series::loadPoster(int i_index, const QString& i_size) {
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingPosterReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingPosterReceived);
    m_q.tv_series_images(m_id);
}
void Series::startedLoadingPosterReceived() {
    emit startedLoadingPoster();
}
void Series::finishedLoadingPosterReceived(void* i_data) {
    auto temp = static_cast<QJsonObject*>(i_data);
    auto results = std::vector<Image>();
    for (const auto& result : temp->value("posters").toArray())
    {
        Image* p = new Image();
        connect(p, &Image::finishedLoadingImage, this, [this, p](void* i_data) {
            p->setPixmap(*static_cast<QPixmap*>(i_data));
            emit finishedLoadingPoster(p->pixmap());
        });
        p->loadImage(result.toObject()["file_path"].toString());
        results.push_back(*p);
    }
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingPosterReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingPosterReceived);
}

void Series::loadPosters(const QString& i_size) {
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingPostersReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingPostersReceived);
    m_q.tv_series_images(m_id);
}
void Series::startedLoadingPostersReceived() {
    emit startedLoadingPosters();
}
void Series::finishedLoadingPostersReceived(void* i_data) {
    auto temp = static_cast<QJsonObject*>(i_data);
    auto results = std::vector<Image>();
    for (const auto& result : temp->value("posters").toArray())
    {
        Image* p = new Image();
        connect(p, &Image::finishedLoadingImage, this, [this, p](void* i_data) {
            p->setPixmap(*static_cast<QPixmap*>(i_data));
            emit finishedLoadingPoster(p->pixmap());
        });
        p->loadImage(result.toObject()["file_path"].toString());
        results.push_back(*p);
    }
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingPostersReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingPostersReceived);
}

void Series::loadLogos(const QString& i_size) {
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingLogosReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingLogosReceived);
    m_q.tv_series_images(m_id);
}
void Series::startedLoadingLogosReceived() {
    emit startedLoadingLogos();
}
void Series::finishedLoadingLogosReceived(void* i_data) {
    auto temp = static_cast<QJsonObject*>(i_data);
    auto results = std::vector<Image>();
    for (const auto& result : temp->value("logos").toArray())
    {
        Image* l = new Image();
        connect(l, &Image::finishedLoadingImage, this, [this, l](void* i_data) {
            l->setPixmap(*static_cast<QPixmap*>(i_data));
            emit finishedLoadingLogo(l->pixmap());
        });
        l->loadImage(result.toObject()["file_path"].toString());
        results.push_back(*l);
    }
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingLogosReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingLogosReceived);
}

void Series::loadLogo(int i_index, const QString& i_size) {
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingLogoReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingLogoReceived);
    m_q.tv_series_images(m_id);
}
void Series::startedLoadingLogoReceived() {
    emit startedLoadingLogo();
}
void Series::finishedLoadingLogoReceived(void* i_data) {
    auto temp = static_cast<QJsonObject*>(i_data);
    auto results = std::vector<Image>();
    for (const auto& result : temp->value("logos").toArray())
    {
        Image* l = new Image();
        connect(l, &Image::finishedLoadingImage, this, [this, l](void* i_data) {
            l->setPixmap(*static_cast<QPixmap*>(i_data));
            emit finishedLoadingLogo(l->pixmap());
        });
        l->loadImage(result.toObject()["file_path"].toString());
        results.push_back(*l);
    }
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingLogoReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingLogoReceived);
}

void Series::loadSeasons() {
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingSeasonsReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingSeasonsReceived);
    m_q.tv_series_details(m_id);
}
void Series::startedLoadingSeasonsReceived() {
    emit startedLoadingSeasons();
}
void Series::finishedLoadingSeasonsReceived(void* i_data) {
    QJsonObject json = *static_cast<QJsonObject*>(i_data);
    std::vector<tmdb::ASync::TV::Season> seasons;
    for (const auto &item : json["seasons"].toArray()) {
        seasons.push_back(*tmdb::ASync::TV::Season::fromJSON(item.toObject()));
    }
    emit finishedLoadingSeasons(seasons);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Series::startedLoadingSeasonsReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Series::finishedLoadingSeasonsReceived);
}