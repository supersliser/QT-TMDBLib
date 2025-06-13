//
// Created by t on 31/05/25.
//

#include "ASync/Episode.h"

#include "ASync/QTMDB.h"

void tmdb::ASync::TV::Episode::setAirDate(const QDate &i_airDate) {
    m_airDate = i_airDate;
}
QDate tmdb::ASync::TV::Episode::airDate() const {
    return m_airDate;
}

void tmdb::ASync::TV::Episode::setCrew(const std::vector<Credit*> &i_crew) {
    m_crew = i_crew;
}
std::vector<tmdb::ASync::Credit*> tmdb::ASync::TV::Episode::crew() const {
    return m_crew;
}

void tmdb::ASync::TV::Episode::setEpisodeNumber(int i_episodeNumber) {
    m_episodeNumber = i_episodeNumber;
}
int tmdb::ASync::TV::Episode::episodeNumber() const {
    return m_episodeNumber;
}

void tmdb::ASync::TV::Episode::setGuestStars(const std::vector<Credit*> &i_guestStars) {
    m_guestStars = i_guestStars;
}
std::vector<tmdb::ASync::Credit*> tmdb::ASync::TV::Episode::guestStars() const {
    return m_guestStars;
}

void tmdb::ASync::TV::Episode::setName(const QString &i_name) {
    m_name = i_name;
}
QString tmdb::ASync::TV::Episode::name() const {
    return m_name;
}

void tmdb::ASync::TV::Episode::setOverview(const QString &i_overview) {
    m_overview = i_overview;
}
QString tmdb::ASync::TV::Episode::overview() const {
    return m_overview;
}

void tmdb::ASync::TV::Episode::setId(int i_id) {
    m_id = i_id;
}
int tmdb::ASync::TV::Episode::id() const {
    return m_id;
}

void tmdb::ASync::TV::Episode::setProductionCode(const QString &i_productionCode) {
    m_productionCode = i_productionCode;
}
QString tmdb::ASync::TV::Episode::productionCode() const {
    return m_productionCode;
}

void tmdb::ASync::TV::Episode::setRuntime(int i_runtime) {
    m_runtime = i_runtime;
}
int tmdb::ASync::TV::Episode::runtime() const {
    return m_runtime;
}

void tmdb::ASync::TV::Episode::setSeasonNumber(int i_seasonNumber) {
    m_seasonNumber = i_seasonNumber;
}
int tmdb::ASync::TV::Episode::seasonNumber() const {
    return m_seasonNumber;
}

void tmdb::ASync::TV::Episode::setStillPath(const QString &i_stillPath) {
    m_stillPath = i_stillPath;
}
QString tmdb::ASync::TV::Episode::stillPath() const {
    return m_stillPath;
}

void tmdb::ASync::TV::Episode::setVoteAverage(float i_voteAverage) {
    m_voteAverage = i_voteAverage;
}
float tmdb::ASync::TV::Episode::voteAverage() const {
    return m_voteAverage;
}

void tmdb::ASync::TV::Episode::setVoteCount(int i_voteCount) {
    m_voteCount = i_voteCount;
}
int tmdb::ASync::TV::Episode::voteCount() const {
    return m_voteCount;
}

tmdb::ASync::TV::Episode::Episode(const QString& i_access_token, int32_t i_seriesID, int32_t i_seasonNumber, int32_t i_episodeNumber) : m_q(i_access_token.toStdString())
{
    m_q.setParent(this);
    loadEpisode(i_seriesID, i_seasonNumber, i_episodeNumber);
}

tmdb::ASync::TV::Episode::Episode() : m_q("")
{
    m_q.setParent(this);
}

tmdb::ASync::TV::Episode* tmdb::ASync::TV::Episode::fromJSON(const QJsonObject& i_json) {
    auto* episode = new Episode();
    episode->m_q.setParent(episode);
    episode->setAirDate(QDate::fromString(i_json["air_date"].toString(), Qt::ISODate));
    std::vector<tmdb::ASync::Credit*> crew;
    for (const auto &crewMember : i_json["crew"].toArray()) {
        crew.push_back(tmdb::ASync::Credit::fromJSON(crewMember.toObject()));
    }
    episode->setCrew(crew);
    episode->setEpisodeNumber(i_json["episode_number"].toInt());
    std::vector<tmdb::ASync::Credit*> guestStars;
    for (const auto &guestStar : i_json["guest_stars"].toArray()) {
        guestStars.push_back(tmdb::ASync::Credit::fromJSON(guestStar.toObject()));
    }
    episode->setGuestStars(guestStars);
    episode->setName(i_json["name"].toString());
    episode->setOverview(i_json["overview"].toString());
    episode->setId(i_json["id"].toInt());
    episode->setProductionCode(i_json["production_code"].toString());
    episode->setRuntime(i_json["runtime"].toInt());
    episode->setSeasonNumber(i_json["season_number"].toInt());
    episode->setStillPath(i_json["still_path"].toString());
    episode->setVoteAverage(i_json["vote_average"].toDouble());
    episode->setVoteCount(i_json["vote_count"].toInt());
    return episode;
}

void tmdb::ASync::TV::Episode::loadEpisode(int32_t i_seriesID, int32_t i_seasonNumber, int32_t i_episodeNumber) {
    connect(&m_q, &aQtmdb::startedLoadingData, this, &tmdb::ASync::TV::Episode::startedLoadingEpisodeReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &tmdb::ASync::TV::Episode::finishedLoadingEpisodeReceived);
    m_q.tv_episodes_details(i_seriesID, i_seasonNumber, i_episodeNumber);
}

void tmdb::ASync::TV::Episode::startedLoadingEpisodeReceived() {
    emit startedLoadingEpisode();
}

void tmdb::ASync::TV::Episode::finishedLoadingEpisodeReceived(void* i_data) {
    auto episode = *static_cast<QJsonObject*>(i_data);
    emit finishedLoadingEpisode(fromJSON(episode));
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &tmdb::ASync::TV::Episode::startedLoadingEpisodeReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &tmdb::ASync::TV::Episode::finishedLoadingEpisodeReceived);
}

void tmdb::ASync::TV::Episode::loadEpisodesForSeason(int32_t i_seriesID, int32_t i_seasonNumber) {
    connect(&m_q, &aQtmdb::startedLoadingData, this, &tmdb::ASync::TV::Episode::startedLoadingSeasonEpisodesReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &tmdb::ASync::TV::Episode::finishedLoadingSeasonEpisodesReceived);
    m_q.tv_seasons_details(i_seriesID, i_seasonNumber);
}

void tmdb::ASync::TV::Episode::startedLoadingSeasonEpisodesReceived() {
    emit startedLoadingSeasonEpisodes();
}

void tmdb::ASync::TV::Episode::finishedLoadingSeasonEpisodesReceived(void* i_data) {
    auto episodes = *static_cast<QJsonObject*>(i_data);
    std::vector<tmdb::ASync::TV::Episode*> episodeList;
    for (const auto& episode : episodes["episodes"].toArray()) {
        episodeList.push_back(tmdb::ASync::TV::Episode::fromJSON(episode.toObject()));
    }
    emit finishedLoadingSeasonEpisodes(episodeList);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &tmdb::ASync::TV::Episode::startedLoadingSeasonEpisodesReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &tmdb::ASync::TV::Episode::finishedLoadingSeasonEpisodesReceived);
}