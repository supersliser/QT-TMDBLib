//
// Created by t on 31/05/25.
//

#ifndef ASYNC_EPISODE_H
#define ASYNC_EPISODE_H
#include "Person.h"

namespace tmdb::ASync
{
    namespace TV
    {
        class Episode : public QObject
        {
            Q_OBJECT

        public:
            void setAirDate(const QDate& i_airDate);
            [[nodiscard]] QDate airDate() const;
            void setCrew(const std::vector<Credit*>& i_crew);
            [[nodiscard]] std::vector<Credit*> crew() const;
            void setEpisodeNumber(int i_episodeNumber);
            [[nodiscard]] int episodeNumber() const;
            void setGuestStars(const std::vector<Credit*>& i_guestStars);
            [[nodiscard]] std::vector<Credit*> guestStars() const;
            void setName(const QString& i_name);
            [[nodiscard]] QString name() const;
            void setOverview(const QString& i_overview);
            [[nodiscard]] QString overview() const;
            void setId(int i_id);
            [[nodiscard]] int id() const;
            void setProductionCode(const QString& i_productionCode);
            [[nodiscard]] QString productionCode() const;
            void setRuntime(int i_runtime);
            [[nodiscard]] int runtime() const;
            void setSeasonNumber(int i_seasonNumber);
            [[nodiscard]] int seasonNumber() const;
            void setStillPath(const QString& i_stillPath);
            [[nodiscard]] QString stillPath() const;
            void setVoteAverage(float i_voteAverage);
            [[nodiscard]] float voteAverage() const;
            void setVoteCount(int i_voteCount);
            [[nodiscard]] int voteCount() const;

            Episode();
            explicit Episode(const QString& i_access_token, int32_t i_seriesID, int32_t i_seasonNumber,
                             int32_t i_episodeNumber);

            static Episode* fromJSON(const QJsonObject& i_json);
            ~Episode() override = default;

        public slots:
            void loadEpisode(int32_t i_seriesID, int32_t i_seasonNumber, int32_t i_episodeNumber);
            void loadEpisodesForSeason(int32_t i_seriesID, int32_t i_seasonNumber);

        private slots:
            void startedLoadingEpisodeReceived();
            void finishedLoadingEpisodeReceived(void* i_data);

            void startedLoadingSeasonEpisodesReceived();
            void finishedLoadingSeasonEpisodesReceived(void* i_data);

        signals:
            void startedLoadingEpisode();
            void finishedLoadingEpisode(tmdb::ASync::TV::Episode* i_episode);
            void startedLoadingSeasonEpisodes();
            void finishedLoadingSeasonEpisodes(std::vector<tmdb::ASync::TV::Episode*> i_episodes);

        protected:
            QDate m_airDate;
            std::vector<Credit*> m_crew;
            int m_episodeNumber = 0;
            std::vector<Credit*> m_guestStars;
            QString m_name;
            QString m_overview;
            int m_id = 0;
            QString m_productionCode;
            int m_runtime = 0;
            int m_seasonNumber = 0;
            QString m_stillPath;
            float m_voteAverage = 0.0f;
            int m_voteCount = 0;
            aQtmdb m_q;
        };
    }
}

#endif //ASYNC_EPISODE_H
