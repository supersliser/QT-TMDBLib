//
// Created by t on 30/05/25.
//

#include "Sync/Network.h"
#include "Sync/Series.h"
#include "Sync/Season.h"
#include "Sync/Config.h"
#include "Sync/Company.h"
#include "Sync/Genre.h"
#include <QJsonObject>

#include "Sync/QTMDB.h"

using namespace tmdb::TV;
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

std::vector<tmdb::Person> Series::createdBy() const {
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
std::vector<tmdb::Genre> Series::genres() const {
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

void Series::setLanguages(const std::vector<config::language> &i_languages) {
    m_languages = i_languages;
}
std::vector<tmdb::config::language> Series::languages() const {
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

void Series::setOriginCountries(const std::vector<config::country> &i_originCountries) {
    m_originCountries = i_originCountries;
}
std::vector<tmdb::config::country> Series::originCountries() const {
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
std::vector<tmdb::Company> Series::productionCompanies() const {
    return m_productionCompanies;
}

void Series::setProductionCountries(const std::vector<config::country> &i_productionCountries) {
    m_productionCountries = i_productionCountries;
}
std::vector<tmdb::config::country> Series::productionCountries() const {
    return m_productionCountries;
}

void Series::setSeasons(const std::vector<Season> &i_seasons) {
    m_seasons = i_seasons;
}
std::vector<tmdb::TV::Season> Series::seasons() const {
    return m_seasons;
}

void Series::setStatus(const QString &i_status) {
    m_status = i_status;
}
QString Series::status() const {
    return m_status;
}

void Series::setSpokenLanguages(const std::vector<config::language> &i_spokenLanguages) {
    m_spokenLanguages = i_spokenLanguages;
}
std::vector<tmdb::config::language> Series::spokenLanguages() const {
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

Series::Series(const QString& i_access_token, int32_t i_seriesID) {
    auto json = getSeries(i_access_token, i_seriesID);
    *this = Series(json);
}

Series::Series(const QJsonObject &i_json, const QString &i_access_token) {
    m_adult = i_json["adult"].toBool();
    m_backdropPath = i_json["backdrop_path"].toString();
    std::vector<tmdb::Person> createdByArray;
    for (const auto &item : i_json["created_by"].toArray()) {
        createdByArray.emplace_back(item.toObject());
    }
    m_createdBy = createdByArray;
    std::vector<int> episodeRunTimeArray;
    for (const auto &item : i_json["episode_run_time"].toArray()) {
        episodeRunTimeArray.push_back(item.toInt());
    }
    m_episodeRunTime = episodeRunTimeArray;
    m_firstAirDate = QDate::fromString(i_json["first_air_date"].toString(), Qt::ISODate);
    std::vector<tmdb::Genre> genreArray;
    for (const auto &item : i_json["genres"].toArray()) {
        genreArray.emplace_back(item.toObject());
    }
    m_genres = genreArray;
    m_homepage = i_json["homepage"].toString();
    m_id = i_json["id"].toInt();
    in_production = i_json["in_production"].toBool();
    std::vector<tmdb::config::language> languageArray;
    for (const auto &item : i_json["languages"].toArray()) {
        languageArray.emplace_back(config::getLanguage(item.toString(), i_access_token));
    }
    m_languages = languageArray;
    m_lastAirDate = QDate::fromString(i_json["last_air_date"].toString(), Qt::ISODate);
    m_name = i_json["name"].toString();
    std::vector<Network> networkArray;
    for (const auto &item : i_json["networks"].toArray()) {
        networkArray.emplace_back(item.toObject(), i_access_token);
    }
    m_networks = networkArray;
    m_episodeCount = i_json["number_of_episodes"].toInt();
    m_seasonCount = i_json["number_of_seasons"].toInt();
    std::vector<tmdb::config::country> originCountryArray;
    for (const auto &item : i_json["origin_country"].toArray()) {
        originCountryArray.emplace_back(config::getCountry(item.toString(), i_access_token));
    }
    m_originCountries = originCountryArray;
    m_originalLanguage = i_json["original_language"].toString();
    m_overview = i_json["overview"].toString();
    m_popularity = static_cast<float>(i_json["popularity"].toDouble());
    m_posterPath = i_json["poster_path"].toString();
    std::vector<Company> companyArray;
    for (const auto &item : i_json["production_companies"].toArray()) {
        companyArray.emplace_back(item.toObject());
    }
    m_productionCompanies = companyArray;
    std::vector<tmdb::config::country> productionCountryArray;
    for (const auto &item : i_json["production_countries"].toArray()) {
        productionCountryArray.emplace_back(config::getCountry(item.toObject()["iso_3166_1"].toString(), i_access_token));
    }
    m_productionCountries = productionCountryArray;
    std::vector<Season> seasonArray;
    for (const auto &item : i_json["seasons"].toArray()) {
        seasonArray.emplace_back(item.toObject());
    }
    m_seasons = seasonArray;
    std::vector<tmdb::config::language> spokenLanguageArray;
    for (const auto &item : i_json["spoken_languages"].toArray()) {
        spokenLanguageArray.emplace_back(tmdb::config::language({item.toObject()["iso_639_1"].toString(),
                                                              item.toObject()["english_name"].toString(),
                                                              item.toObject()["name"].toString()}));
    }
    m_spokenLanguages = spokenLanguageArray;
    m_status = i_json["status"].toString();
    m_tagline = i_json["tagline"].toString();
    m_type = i_json["type"].toString();
    m_voteAverage = static_cast<float>(i_json["vote_average"].toDouble());
    m_voteCount = i_json["vote_count"].toInt();
}

Series Series::getSeries(const QString& i_access_token, int32_t i_seriesID) {
    Qtmdb q(i_access_token.toStdString());
    auto json = q.tv_series_details(i_seriesID);
    return Series(json, i_access_token);
}

std::vector<Series> Series::getAiringToday(const QString& i_access_token, const config::language& i_language, int32_t i_page, const QString& i_region) {
    Qtmdb q(i_access_token.toStdString());
    auto json = q.tv_series_airingToday(i_language.iso_639_1.toStdString(), i_page, i_region.toStdString());
    std::vector<Series> seriesList;
    for (const auto &item : json["results"].toArray()) {
        seriesList.emplace_back(item.toObject(), i_access_token);
    }
    return seriesList;
}

std::vector<Series> Series::getOnTheAir(const QString& i_access_token, const config::language& i_language, int32_t i_page, const QString& i_region) {
    Qtmdb q(i_access_token.toStdString());
    auto json = q.tv_series_onTheAir(i_language.iso_639_1.toStdString(), i_page, i_region.toStdString());
    std::vector<Series> seriesList;
    for (const auto &item : json["results"].toArray()) {
        seriesList.emplace_back(item.toObject(), i_access_token);
    }
    return seriesList;
}

std::vector<Series> Series::getPopular(const QString& i_access_token, const config::language& i_language, int32_t i_page) {
    Qtmdb q(i_access_token.toStdString());
    auto json = q.tv_series_popular(i_language.iso_639_1.toStdString(), i_page);
    std::vector<Series> seriesList;
    for (const auto &item : json["results"].toArray()) {
        seriesList.emplace_back(item.toObject(), i_access_token);
    }
    return seriesList;
}

std::vector<Series> Series::getTopRated(const QString& i_access_token, const config::language& i_language, int32_t i_page) {
    Qtmdb q(i_access_token.toStdString());
    auto json = q.tv_series_topRated(i_language.iso_639_1.toStdString(), i_page);
    std::vector<Series> seriesList;
    for (const auto &item : json["results"].toArray()) {
        seriesList.emplace_back(item.toObject(), i_access_token);
    }
    return seriesList;
}

std::vector<Series> Series::recommendations(const QString& i_access_token, int32_t i_page) const {
    Qtmdb q(i_access_token.toStdString());
    auto json = q.tv_series_recommendations(m_id, "en-US", i_page);
    std::vector<Series> seriesList;
    for (const auto &item : json["results"].toArray()) {
        seriesList.emplace_back(item.toObject(), i_access_token);
    }
    return seriesList;
}

std::vector<Series> Series::similar(const QString& i_access_token, int32_t i_page) const {
    Qtmdb q(i_access_token.toStdString());
    auto json = q.tv_series_similar(m_id, "en-US", i_page);
    std::vector<Series> seriesList;
    for (const auto &item : json["results"].toArray()) {
        seriesList.emplace_back(item.toObject(), i_access_token);
    }
    return seriesList;
}

std::vector<tmdb::WatchProvider> Series::watchProviders(const QString& i_access_token, const config::country& i_country) const {
    return WatchProvider::getWatchProvidersForTV(i_access_token, i_country.iso_3166_1, m_id);
}

std::vector<Season> Series::seasons(const QString& i_access_token, int32_t i_page) const
{
    Qtmdb q(i_access_token.toStdString());
    auto json = q.tv_series_details(m_id);
    std::vector<Season> seasonsList;
    for (const auto &item : json["seasons"].toArray()) {
        seasonsList.emplace_back(i_access_token, m_id, item.toObject()["season_number"].toInt());
    }
    return seasonsList;
}

std::array<QString, 9> Series::externalIDs(const QString& i_access_token) const
{
    Qtmdb q(i_access_token.toStdString());
    auto json = q.tv_series_externalIDs(m_id);
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
    return externalIDs;
}

std::vector<QPixmap> Series::backdrops(const QString& i_access_token, const QString& i_size) const
{
    Qtmdb q(i_access_token.toStdString());
    auto response = q.tv_series_images(m_id, "en");
    std::vector<QPixmap> backdrops;
    for (const auto& item : response["backdrops"].toArray())
    {
        QJsonObject backdropObj = item.toObject();
        QString filePath = backdropObj["file_path"].toString();
        backdrops.emplace_back(config::getPixmapFromUrl(QUrl(q.getImageURL(filePath.toStdString(), i_size.toStdString()).c_str())));
    }
    return backdrops;
}

QPixmap Series::backdrop(const QString& i_access_token, int i_index, const QString& i_size) const
{
    Qtmdb q(i_access_token.toStdString());
    auto response = q.tv_series_images(m_id, "en");
    if (i_index < 0 || i_index >= response["backdrops"].toArray().size())
    {
        return QPixmap();
    }
    QJsonObject backdropObj = response["backdrops"].toArray()[i_index].toObject();
    QString filePath = backdropObj["file_path"].toString();
    return config::getPixmapFromUrl(QUrl(q.getImageURL(filePath.toStdString(), i_size.toStdString()).c_str()));
}

std::vector<QPixmap> Series::posters(const QString& i_access_token, const QString& i_size) const
{
    Qtmdb q(i_access_token.toStdString());
    auto response = q.tv_series_images(m_id, "en");
    std::vector<QPixmap> posters;
    for (const auto& item : response["posters"].toArray())
    {
        QJsonObject backdropObj = item.toObject();
        QString filePath = backdropObj["file_path"].toString();
        posters.emplace_back(config::getPixmapFromUrl(QUrl(q.getImageURL(filePath.toStdString(), i_size.toStdString()).c_str())));
    }
    return posters;
}

QPixmap Series::poster(const QString& i_access_token, int i_index, const QString& i_size) const
{
    Qtmdb q(i_access_token.toStdString());
    auto response = q.tv_series_images(m_id, "en");
    if (i_index < 0 || i_index >= response["posters"].toArray().size())
    {
        return QPixmap();
    }
    QJsonObject backdropObj = response["posters"].toArray()[i_index].toObject();
    QString filePath = backdropObj["file_path"].toString();
    return config::getPixmapFromUrl(QUrl(q.getImageURL(filePath.toStdString(), i_size.toStdString()).c_str()));
}

std::vector<QPixmap> Series::logos(const QString& i_access_token, const QString& i_size) const
{
    Qtmdb q(i_access_token.toStdString());
    auto response = q.tv_series_images(m_id, "en");
    std::vector<QPixmap> logos;
    for (const auto& item : response["logos"].toArray())
    {
        QJsonObject backdropObj = item.toObject();
        QString filePath = backdropObj["file_path"].toString();
        logos.emplace_back(config::getPixmapFromUrl(QUrl(q.getImageURL(filePath.toStdString(), i_size.toStdString()).c_str())));
    }
    return logos;
}

QPixmap Series::logo(const QString& i_access_token, int i_index, const QString& i_size) const
{
    Qtmdb q(i_access_token.toStdString());
    auto response = q.tv_series_images(m_id, "en");
    if (i_index < 0 || i_index >= response["logos"].toArray().size())
    {
        return QPixmap();
    }
    QJsonObject backdropObj = response["logos"].toArray()[i_index].toObject();
    QString filePath = backdropObj["file_path"].toString();
    return config::getPixmapFromUrl(QUrl(q.getImageURL(filePath.toStdString(), i_size.toStdString()).c_str()));
}