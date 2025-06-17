//
// Created by t on 30/05/25.
//

#ifndef SERIES_H
#define SERIES_H
#include <QString>

#include "Company.h"
#include "Genre.h"
#include "Movie.h"
#include "Network.h"
#include "Person.h"
#include "Season.h"
#include "WatchProvider.h"

namespace tmdb
{
    namespace TV
    {
        class Series
        {
        public:
            void setAdult(bool i_adult);
            [[nodiscard]] bool adult() const;
            void setBackdropPath(const QString& i_backdropPath);
            [[nodiscard]] QString backdropPath() const;
            void setCreatedBy(const std::vector<Person>& i_createdBy);
            [[nodiscard]] std::vector<Person> createdBy() const;
            void setEpisodeRunTime(const std::vector<int>& i_episodeRunTime);
            [[nodiscard]] std::vector<int> episodeRunTime() const;
            void setFirstAirDate(const QDate& i_firstAirDate);
            [[nodiscard]] QDate firstAirDate() const;
            void setGenres(const std::vector<Genre>& i_genres);
            [[nodiscard]] std::vector<Genre> genres() const;
            void setHomepage(const QString& i_homepage);
            [[nodiscard]] QString homepage() const;
            void setId(int i_id);
            [[nodiscard]] int id() const;
            void setInProduction(bool i_inProduction);
            [[nodiscard]] bool inProduction() const;
            void setLanguages(const std::vector<config::language>& i_languages);
            [[nodiscard]] std::vector<config::language> languages() const;
            void setLastAirDate(const QDate& i_lastAirDate);
            [[nodiscard]] QDate lastAirDate() const;
            void setName(const QString& i_name);
            [[nodiscard]] QString name() const;
            void setNetworks(const std::vector<Network>& i_networks);
            [[nodiscard]] std::vector<Network> networks() const;
            void setOriginCountries(const std::vector<config::country>& i_originCountries);
            [[nodiscard]] std::vector<config::country> originCountries() const;
            void setOriginalLanguage(const QString& i_originalLanguage);
            [[nodiscard]] QString originalLanguage() const;
            void setOverview(const QString& i_overview);
            [[nodiscard]] QString overview() const;
            void setPopularity(float i_popularity);
            [[nodiscard]] float popularity() const;
            void setPosterPath(const QString& i_posterPath);
            [[nodiscard]] QString posterPath() const;
            void setProductionCompanies(const std::vector<Company>& i_productionCompanies);
            [[nodiscard]] std::vector<Company> productionCompanies() const;
            void setProductionCountries(const std::vector<config::country>& i_productionCountries);
            [[nodiscard]] std::vector<config::country> productionCountries() const;
            void setSeasons(const std::vector<Season>& i_seasons);
            [[nodiscard]] std::vector<Season> seasons() const;
            void setSpokenLanguages(const std::vector<config::language>& i_spokenLanguages);
            [[nodiscard]] std::vector<config::language> spokenLanguages() const;
            void setStatus(const QString& i_status);
            [[nodiscard]] QString status() const;
            void setTagline(const QString& i_tagline);
            [[nodiscard]] QString tagline() const;
            void setType(const QString& i_type);
            [[nodiscard]] QString type() const;
            void setVoteAverage(float i_voteAverage);
            [[nodiscard]] float voteAverage() const;
            void setVoteCount(int i_voteCount);
            [[nodiscard]] int voteCount() const;

            Series() = default;
            Series(const QString& i_access_token, int32_t i_seriesID);
            explicit Series(const QJsonObject& i_json, const QString& i_access_token);
            ~Series() = default;

            static Series getSeries(const QString& i_access_token, int32_t i_seriesID);

            static std::vector<Series> getAiringToday(const QString& i_access_token,
                                                      const config::language& i_language = {
                                                          "en-US", "English", "English"
                                                      },
                                                      int32_t i_page = 1, const QString& i_region = "America/New_York");
            static std::vector<Series> getOnTheAir(const QString& i_access_token,
                                                   const config::language& i_language = {"en-US", "English", "English"},
                                                   int32_t i_page = 1, const QString& i_region = "America/New_York");
            static std::vector<Series> getPopular(const QString& i_access_token,
                                                  const config::language& i_language = {"en-US", "English", "English"},
                                                  int32_t i_page = 1);
            static std::vector<Series> getTopRated(const QString& i_access_token,
                                                   const config::language& i_language = {"en-US", "English", "English"},
                                                   int32_t i_page = 1);

            [[nodiscard]] std::vector<Series> recommendations(const QString& i_access_token, int32_t i_page = 1) const;
            [[nodiscard]] std::vector<Series> similar(const QString& i_access_token, int32_t i_page = 1) const;

            [[nodiscard]] std::vector<WatchProvider> watchProviders(const QString& i_access_token,
                                                                    const config::country& i_country =
                                                                        config::country()) const;
            [[nodiscard]] std::vector<Season> seasons(const QString& i_access_token, int32_t i_page = 1) const;
            [[nodiscard]] std::array<QString, 9> externalIDs(const QString& i_access_token) const;
            [[nodiscard]] std::vector<QPixmap> backdrops(const QString& i_access_token,
                                                         const QString& i_size = "original") const;
            [[nodiscard]] QPixmap backdrop(const QString& i_access_token, int i_index,
                                           const QString& i_size = "original") const;
            [[nodiscard]] std::vector<QPixmap> posters(const QString& i_access_token,
                                                       const QString& i_size = "original") const;
            [[nodiscard]] QPixmap poster(const QString& i_access_token, int i_index,
                                         const QString& i_size = "original") const;
            [[nodiscard]] std::vector<QPixmap> logos(const QString& i_access_token,
                                                     const QString& i_size = "original") const;
            [[nodiscard]] QPixmap logo(const QString& i_access_token, int i_index,
                                       const QString& i_size = "original") const;

        protected:
            bool m_adult = true;
            QString m_backdropPath;
            std::vector<Person> m_createdBy;
            std::vector<int> m_episodeRunTime;
            QDate m_firstAirDate;
            std::vector<Genre> m_genres;
            QString m_homepage;
            int m_id = 0;
            bool in_production = true;
            std::vector<config::language> m_languages;
            QDate m_lastAirDate;
            QString m_name;
            std::vector<Network> m_networks;
            int m_episodeCount = 0;
            int m_seasonCount = 0;
            std::vector<config::country> m_originCountries;
            QString m_originalLanguage;
            QString m_overview;
            float m_popularity = 0.0f;
            QString m_posterPath;
            std::vector<Company> m_productionCompanies;
            std::vector<config::country> m_productionCountries;
            std::vector<Season> m_seasons;
            std::vector<config::language> m_spokenLanguages;
            QString m_status;
            QString m_tagline;
            QString m_type;
            float m_voteAverage = 0.0f;
            int m_voteCount = 0;
        };
    }
}
#endif //SERIES_H
