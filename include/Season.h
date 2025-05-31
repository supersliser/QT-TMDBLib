//
// Created by t on 30/05/25.
//

#ifndef SEASON_H
#define SEASON_H
#include <QDate>

#include "Episode.h"

namespace tmdb
{
    namespace TV
    {
        class Season
        {
        public:
            void setAirDate(const QDate &i_airDate);
            QDate airDate() const;
            void setEpisodes(const std::vector<Episode> &i_episodes);
            const std::vector<Episode> &episodes() const;
            void setName(const QString &i_name);
            QString name() const;
            void setOverview(const QString &i_overview);
            QString overview() const;
            void setId(int i_id);
            int id() const;
            void setPosterPath(const QString &i_posterPath);
            QString posterPath() const;
            void setSeasonNumber(int i_seasonNumber);
            int seasonNumber() const;
            void setVoteAverage(float i_voteAverage);
            float voteAverage() const;

            Season() = default;
            Season(const QString& i_access_token, int32_t i_seriesID, int32_t i_seasonNumber);
            Season(const QJsonObject &i_json);
            Season(const QDate &i_airDate, const std::vector<Episode> &i_episodes, const QString &i_name,
                   const QString &i_overview, int i_id, const QString &i_posterPath, int i_seasonNumber,
                   float i_voteAverage);
            ~Season() = default;

            static Season getSeason(const QString& i_access_token, int32_t i_seriesID, int32_t i_seasonNumber);

        protected:
            QDate m_airDate;
            std::vector<Episode> m_episodes;
            QString m_name;
            QString m_overview;
            int m_id = 0;
            QString m_posterPath;
            int m_seasonNumber = 0;
            float m_voteAverage = 0.0f;
        };
    }
}

#endif //SEASON_H
