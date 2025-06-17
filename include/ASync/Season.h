//
// Created by t on 30/05/25.
//

#ifndef ASYNC_SEASON_H
#define ASYNC_SEASON_H
#include <QDate>

#include "Episode.h"

namespace tmdb::ASync
{
    namespace TV
    {
        class Season : public QObject
        {
            Q_OBJECT
        public:
            void setAirDate(const QDate& i_airDate);
            [[nodiscard]] QDate airDate() const;
            void setEpisodes(const std::vector<Episode*>& i_episodes);
            [[nodiscard]] const std::vector<Episode*>& episodes() const;
            void setName(const QString& i_name);
            [[nodiscard]] QString name() const;
            void setOverview(const QString& i_overview);
            [[nodiscard]] QString overview() const;
            void setId(int i_id);
            [[nodiscard]] int id() const;
            void setPosterPath(const QString& i_posterPath);
            [[nodiscard]] QString posterPath() const;
            void setSeasonNumber(int i_seasonNumber);
            [[nodiscard]] int seasonNumber() const;
            void setVoteAverage(float i_voteAverage);
            [[nodiscard]] float voteAverage() const;

            Season();
            explicit Season(const QString& i_access_token);
            Season(const QString& i_access_token, int32_t i_seriesID, int32_t i_seasonNumber);
            ~Season() override = default;

            Season(const QJsonObject& i_json, const QString& i_access_token);
        protected:
            void parseJson(const QJsonObject& i_json, const QString& i_access_token);
        public slots:
            void loadSeason(int32_t i_seriesID, int32_t i_seasonNumber);
            void loadEpisodesForSeason(int32_t i_seriesID, int32_t i_seasonNumber);

        private slots:
            void startedLoadingSeasonReceived();
            void finishedLoadingSeasonReceived(void* i_data);
            void startedLoadingSeasonEpisodesReceived();
            void finishedLoadingSeasonEpisodesReceived(void* i_data);

        signals:
            void startedLoadingSeason();
            void finishedLoadingSeason(tmdb::ASync::TV::Season* i_season);
            void startedLoadingSeasonEpisodes();
            void finishedLoadingSeasonEpisodes(std::vector<tmdb::ASync::TV::Episode*> i_episodes);

        protected:
            aQtmdb m_q;
            QDate m_airDate = QDate();
            std::vector<Episode*> m_episodes = {};
            QString m_name = "BLANK_NAME";
            QString m_overview = "BLANK_OVERVIEW";
            int m_id = 0;
            QString m_posterPath = "BLANK_POSTER_PATH";
            int m_seasonNumber = 0;
            float m_voteAverage = 0.0f;
        };
    }
}

#endif //ASYNC_SEASON_H
