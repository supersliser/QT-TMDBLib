//
// Created by t on 31/05/25.
//

#include "Sync/Episode.h"

#include "Sync/QTMDB.h"

void tmdb::TV::Episode::setAirDate(const QDate &i_airDate) {
    m_airDate = i_airDate;
}
QDate tmdb::TV::Episode::airDate() const {
    return m_airDate;
}

void tmdb::TV::Episode::setCrew(const std::vector<Credit> &i_crew) {
    m_crew = i_crew;
}
std::vector<tmdb::Credit> tmdb::TV::Episode::crew() const {
    return m_crew;
}

void tmdb::TV::Episode::setEpisodeNumber(int i_episodeNumber) {
    m_episodeNumber = i_episodeNumber;
}
int tmdb::TV::Episode::episodeNumber() const {
    return m_episodeNumber;
}

void tmdb::TV::Episode::setGuestStars(const std::vector<Credit> &i_guestStars) {
    m_guestStars = i_guestStars;
}
std::vector<tmdb::Credit> tmdb::TV::Episode::guestStars() const {
    return m_guestStars;
}

void tmdb::TV::Episode::setName(const QString &i_name) {
    m_name = i_name;
}
QString tmdb::TV::Episode::name() const {
    return m_name;
}

void tmdb::TV::Episode::setOverview(const QString &i_overview) {
    m_overview = i_overview;
}
QString tmdb::TV::Episode::overview() const {
    return m_overview;
}

void tmdb::TV::Episode::setId(int i_id) {
    m_id = i_id;
}
int tmdb::TV::Episode::id() const {
    return m_id;
}

void tmdb::TV::Episode::setProductionCode(const QString &i_productionCode) {
    m_productionCode = i_productionCode;
}
QString tmdb::TV::Episode::productionCode() const {
    return m_productionCode;
}

void tmdb::TV::Episode::setRuntime(int i_runtime) {
    m_runtime = i_runtime;
}
int tmdb::TV::Episode::runtime() const {
    return m_runtime;
}

void tmdb::TV::Episode::setSeasonNumber(int i_seasonNumber) {
    m_seasonNumber = i_seasonNumber;
}
int tmdb::TV::Episode::seasonNumber() const {
    return m_seasonNumber;
}

void tmdb::TV::Episode::setStillPath(const QString &i_stillPath) {
    m_stillPath = i_stillPath;
}
QString tmdb::TV::Episode::stillPath() const {
    return m_stillPath;
}

void tmdb::TV::Episode::setVoteAverage(float i_voteAverage) {
    m_voteAverage = i_voteAverage;
}
float tmdb::TV::Episode::voteAverage() const {
    return m_voteAverage;
}

void tmdb::TV::Episode::setVoteCount(int i_voteCount) {
    m_voteCount = i_voteCount;
}
int tmdb::TV::Episode::voteCount() const {
    return m_voteCount;
}

tmdb::TV::Episode::Episode(const QDate &i_airDate, const std::vector<Credit> &i_crew, int i_episodeNumber,
                            const std::vector<Credit> &i_guestStars, const QString &i_name, const QString &i_overview,
                            int i_id, const QString &i_productionCode, int i_runtime, int i_seasonNumber,
                            const QString &i_stillPath, float i_voteAverage, int i_voteCount)
    : m_airDate(i_airDate), m_crew(i_crew), m_episodeNumber(i_episodeNumber), m_guestStars(i_guestStars),
      m_name(i_name), m_overview(i_overview), m_id(i_id), m_productionCode(i_productionCode),
      m_runtime(i_runtime), m_seasonNumber(i_seasonNumber), m_stillPath(i_stillPath),
      m_voteAverage(i_voteAverage), m_voteCount(i_voteCount) {}

tmdb::TV::Episode::Episode(const QString& i_access_token, int32_t i_seriesID, int32_t i_seasonNumber, int32_t i_episodeNumber)
{
    *this = getEpisode(i_access_token, i_seriesID, i_seasonNumber, i_episodeNumber);
}

tmdb::TV::Episode::Episode(const QJsonObject &i_json)
{
    m_airDate = QDate::fromString(i_json["air_date"].toString(), Qt::ISODate);
    std::vector<Credit> credits;
    for (const auto &credit : i_json["crew"].toArray()) {
        credits.emplace_back(credit.toObject());
    }
    m_crew = credits;
    m_episodeNumber = i_json["episode_number"].toInt();
    std::vector<Credit> guestStars;
    for (const auto &guestStar : i_json["guest_stars"].toArray()) {
        guestStars.emplace_back(guestStar.toObject());
    }
    m_guestStars = guestStars;
    m_name = i_json["name"].toString();
    m_overview = i_json["overview"].toString();
    m_id = i_json["id"].toInt();
    m_productionCode = i_json["production_code"].toString();
    m_runtime = i_json["runtime"].toInt();
    m_seasonNumber = i_json["season_number"].toInt();
    m_stillPath = i_json["still_path"].toString();
    m_voteAverage = static_cast<float>(i_json["vote_average"].toDouble());
    m_voteCount = i_json["vote_count"].toInt();
}

tmdb::TV::Episode tmdb::TV::Episode::getEpisode(const QString& i_access_token, int32_t i_seriesID, int32_t i_seasonNumber, int32_t i_episodeNumber)
{
    Qtmdb q(i_access_token.toStdString());
    auto json = q.tv_episodes_details(i_seriesID, i_seasonNumber, i_episodeNumber);
    return Episode(json);
}