//
// Created by t on 31/05/25.
//

#ifndef EPISODE_H
#define EPISODE_H
#include "Person.h"

namespace tmdb
{
    namespace TV
    {
        class Episode
        {
        public:
            void setAirDate(const QDate& i_airDate);
            [[nodiscard]] QDate airDate() const;
            void setCrew(const std::vector<Credit>& i_crew);
            [[nodiscard]] std::vector<Credit> crew() const;
            void setEpisodeNumber(int i_episodeNumber);
            [[nodiscard]] int episodeNumber() const;
            void setGuestStars(const std::vector<Credit>& i_guestStars);
            [[nodiscard]] std::vector<Credit> guestStars() const;
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

            Episode() = default;
            Episode(const QDate& i_airDate, const std::vector<Credit>& i_crew, int i_episodeNumber,
                    const std::vector<Credit>& i_guestStars, const QString& i_name, const QString& i_overview,
                    int i_id, const QString& i_productionCode, int i_runtime, int i_seasonNumber,
                    const QString& i_stillPath, float i_voteAverage, int i_voteCount);
            Episode(const QString& i_access_token, int32_t i_seriesID, int32_t i_seasonNumber, int32_t i_episodeNumber);
            explicit Episode(const QJsonObject& i_json);

            static Episode getEpisode(const QString& i_access_token, int32_t i_seriesID, int32_t i_seasonNumber,
                                      int32_t i_episodeNumber);

        protected:
            QDate m_airDate;
            std::vector<Credit> m_crew;
            int m_episodeNumber = 0;
            std::vector<Credit> m_guestStars;
            QString m_name;
            QString m_overview;
            int m_id = 0;
            QString m_productionCode;
            int m_runtime = 0;
            int m_seasonNumber = 0;
            QString m_stillPath;
            float m_voteAverage = 0.0f;
            int m_voteCount = 0;
        };
    }
}

#endif //EPISODE_H
