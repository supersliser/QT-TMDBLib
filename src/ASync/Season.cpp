//
// Created by t on 31/05/25.
//

#include "ASync/Season.h"
#include "ASync/Episode.h"
#include <QJsonArray>
#include <QJsonObject>

#include "ASync/QTMDB.h"

using namespace tmdb::ASync::TV;

void Season::setAirDate(const QDate &i_airDate) {
    m_airDate = i_airDate;
}
QDate Season::airDate() const {
    return m_airDate;
}

void Season::setEpisodes(const std::vector<Episode*> &i_episodes) {
    m_episodes = i_episodes;
}
const std::vector<Episode*> &Season::episodes() const {
    return m_episodes;
}

void Season::setName(const QString &i_name) {
    m_name = i_name;
}
QString Season::name() const {
    return m_name;
}

void Season::setOverview(const QString &i_overview) {
    m_overview = i_overview;
}
QString Season::overview() const {
    return m_overview;
}

void Season::setId(int i_id) {
    m_id = i_id;
}
int Season::id() const {
    return m_id;
}

void Season::setPosterPath(const QString &i_posterPath) {
    m_posterPath = i_posterPath;
}
QString Season::posterPath() const {
    return m_posterPath;
}

void Season::setSeasonNumber(int i_seasonNumber) {
    m_seasonNumber = i_seasonNumber;
}
int Season::seasonNumber() const {
    return m_seasonNumber;
}

void Season::setVoteAverage(float i_voteAverage) {
    m_voteAverage = i_voteAverage;
}
float Season::voteAverage() const {
    return m_voteAverage;
}

Season::Season(const QString& i_access_token, int32_t i_seriesID, int32_t i_seasonNumber) : Season(i_access_token) {
    m_q.setParent(this);
    loadSeason(i_seriesID, i_seasonNumber);
}

Season::Season() : m_q("") {
    m_q.setParent(this);
}

Season::Season(const QString& i_access_token) : m_q(i_access_token.toStdString()) {
    m_q.setParent(this);
}

Season::Season(const QJsonObject& i_json, const QString& i_access_token) : Season(i_access_token)
{
    parseJson(i_json, i_access_token);
}

void Season::parseJson(const QJsonObject& i_json, const QString& i_access_token) {
    setId(i_json["id"].toInt());
    setName(i_json["name"].toString());
    setOverview(i_json["overview"].toString());
    setPosterPath(i_json["poster_path"].toString());
    setSeasonNumber(i_json["season_number"].toInt());
    setVoteAverage(i_json["vote_average"].toDouble());

    if (i_json.contains("air_date")) {
        setAirDate(QDate::fromString(i_json["air_date"].toString(), Qt::ISODate));
    }

    if (i_json.contains("episodes")) {
        QJsonArray episodesArray = i_json["episodes"].toArray();
        std::vector<Episode*> episodes;
        for (const auto& episodeValue : episodesArray) {
            episodes.push_back(new Episode(episodeValue.toObject(), i_access_token));
        }
        setEpisodes(episodes);
    }
}

void Season::loadSeason(int32_t i_seriesID, int32_t i_seasonNumber) {
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Season::startedLoadingSeasonReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Season::finishedLoadingSeasonReceived);
    m_q.tv_seasons_details(i_seriesID, i_seasonNumber);
}
void Season::startedLoadingSeasonReceived() {
    emit startedLoadingSeason();
}
void Season::finishedLoadingSeasonReceived(void* i_data) {
    parseJson(*static_cast<QJsonObject*>(i_data), m_q.accessToken().c_str());
    emit finishedLoadingSeason(this);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Season::startedLoadingSeasonReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Season::finishedLoadingSeasonReceived);
}

void Season::loadEpisodesForSeason(int32_t i_seriesID, int32_t i_seasonNumber) {
    connect(&m_q, &aQtmdb::startedLoadingData, this, &Season::startedLoadingSeasonEpisodesReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &Season::finishedLoadingSeasonEpisodesReceived);
    m_q.tv_seasons_details(i_seriesID, i_seasonNumber);
}
void Season::startedLoadingSeasonEpisodesReceived() {
    emit startedLoadingSeasonEpisodes();
}
void Season::finishedLoadingSeasonEpisodesReceived(void* i_data) {
    auto json = static_cast<QJsonObject*>(i_data);
    std::vector<Episode*> episodes;
    if (json->contains("episodes")) {
        QJsonArray episodesArray = (*json)["episodes"].toArray();
        for (const auto& episodeValue : episodesArray) {
            episodes.push_back(new Episode(episodeValue.toObject(), m_q.accessToken().c_str()));
        }
    }
    emit finishedLoadingSeasonEpisodes(episodes);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &Season::startedLoadingSeasonEpisodesReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &Season::finishedLoadingSeasonEpisodesReceived);
}