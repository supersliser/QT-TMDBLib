//
// Created by t on 31/05/25.
//

#include "Season.h"
#include "Episode.h"
#include <QJsonArray>
#include <QJsonObject>

#include "QTMDB.h"

using namespace tmdb::TV;

void Season::setAirDate(const QDate &i_airDate) {
    m_airDate = i_airDate;
}
QDate Season::airDate() const {
    return m_airDate;
}

void Season::setEpisodes(const std::vector<Episode> &i_episodes) {
    m_episodes = i_episodes;
}
const std::vector<Episode> &Season::episodes() const {
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

Season::Season(const QString& i_access_token, int32_t i_seriesID, int32_t i_seasonNumber) {
    *this = getSeason(i_access_token, i_seriesID, i_seasonNumber);
}

Season::Season(const QJsonObject &i_json) {
    setAirDate(QDate::fromString(i_json["air_date"].toString(), Qt::ISODate));
    setName(i_json["name"].toString());
    setOverview(i_json["overview"].toString());
    setId(i_json["id"].toInt());
    setPosterPath(i_json["poster_path"].toString());
    setSeasonNumber(i_json["season_number"].toInt());
    setVoteAverage(static_cast<float>(i_json["vote_average"].toDouble()));

    QJsonArray episodesArray = i_json["episodes"].toArray();
    std::vector<Episode> episodes;
    for (const auto &episodeValue : episodesArray) {
        episodes.emplace_back(episodeValue.toObject());
    }
    setEpisodes(episodes);
}

Season::Season(const QDate &i_airDate, const std::vector<Episode> &i_episodes, const QString &i_name,
               const QString &i_overview, int i_id, const QString &i_posterPath, int i_seasonNumber,
               float i_voteAverage)
    : m_airDate(i_airDate), m_episodes(i_episodes), m_name(i_name), m_overview(i_overview), m_id(i_id),
      m_posterPath(i_posterPath), m_seasonNumber(i_seasonNumber), m_voteAverage(i_voteAverage) {}

Season Season::getSeason(const QString& i_access_token, int32_t i_seriesID, int32_t i_seasonNumber)
{
    Qtmdb q(i_access_token.toStdString());
    QJsonObject json = q.tv_seasons_details(i_seriesID, i_seasonNumber);
    return Season(json);
}