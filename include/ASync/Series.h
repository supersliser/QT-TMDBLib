//
// Created by t on 30/05/25.
//

#ifndef ASYNC_SERIES_H
#define ASYNC_SERIES_H

#include "Company.h"
#include "Genre.h"
#include "Movie.h"
#include "Network.h"
#include "Person.h"
#include "Season.h"
#include "WatchProvider.h"

namespace tmdb::ASync::TV
{
    class Series : public QObject
    {
        Q_OBJECT

    public:
        void setAdult(bool i_adult);
        [[nodiscard]] bool adult() const;
        void setBackdropPath(const QString& i_backdropPath);
        [[nodiscard]] QString backdropPath() const;
        void setCreatedBy(const std::vector<tmdb::ASync::Person*>& i_createdBy);
        [[nodiscard]] std::vector<tmdb::ASync::Person*> createdBy() const;
        void setEpisodeRunTime(const std::vector<int>& i_episodeRunTime);
        [[nodiscard]] std::vector<int> episodeRunTime() const;
        void setFirstAirDate(const QDate& i_firstAirDate);
        [[nodiscard]] QDate firstAirDate() const;
        void setGenres(const std::vector<tmdb::ASync::Genre*>& i_genres);
        [[nodiscard]] std::vector<tmdb::ASync::Genre*> genres() const;
        void setHomepage(const QString& i_homepage);
        [[nodiscard]] QString homepage() const;
        void setId(int i_id);
        [[nodiscard]] int id() const;
        void setInProduction(bool i_inProduction);
        [[nodiscard]] bool inProduction() const;
        void setLanguages(const std::vector<tmdb::ASync::Language*>& i_languages);
        [[nodiscard]] std::vector<tmdb::ASync::Language*> languages() const;
        void setLastAirDate(const QDate& i_lastAirDate);
        [[nodiscard]] QDate lastAirDate() const;
        void setName(const QString& i_name);
        [[nodiscard]] QString name() const;
        void setNetworks(const std::vector<tmdb::ASync::TV::Network*>& i_networks);
        [[nodiscard]] std::vector<tmdb::ASync::TV::Network*> networks() const;
        void setOriginCountries(const std::vector<tmdb::ASync::Country*>& i_originCountries);
        [[nodiscard]] std::vector<tmdb::ASync::Country*> originCountries() const;
        void setOriginalLanguage(const QString& i_originalLanguage);
        [[nodiscard]] QString originalLanguage() const;
        void setOverview(const QString& i_overview);
        [[nodiscard]] QString overview() const;
        void setPopularity(float i_popularity);
        [[nodiscard]] float popularity() const;
        void setPosterPath(const QString& i_posterPath);
        [[nodiscard]] QString posterPath() const;
        void setProductionCompanies(const std::vector<tmdb::ASync::Company*>& i_productionCompanies);
        [[nodiscard]] std::vector<tmdb::ASync::Company*> productionCompanies() const;
        void setProductionCountries(const std::vector<tmdb::ASync::Country*>& i_productionCountries);
        [[nodiscard]] std::vector<tmdb::ASync::Country*> productionCountries() const;
        void setSeasons(const std::vector<tmdb::ASync::TV::Season*>& i_seasons);
        [[nodiscard]] std::vector<tmdb::ASync::TV::Season*> seasons() const;
        void setSpokenLanguages(const std::vector<tmdb::ASync::Language*>& i_spokenLanguages);
        [[nodiscard]] std::vector<tmdb::ASync::Language*> spokenLanguages() const;
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

        Series();
        explicit Series(const QString& i_access_token);
        Series(const QString& i_access_token, int32_t i_seriesID);
        ~Series() override = default;

        Series(const QJsonObject& i_json, const QString& i_access_token);

    protected:
        void parseJson(const QJsonObject& i_json, const QString& i_access_token);

    public slots:
        void loadSeries(int32_t i_seriesID);
        void loadSearchResults(const QString& i_query, const Language& i_language, int32_t i_page = 1,
                               bool i_includeAdult = false, int i_year = 0, int i_firstAirYear = 0);

        void loadAiringToday(const Language& i_language, int32_t i_page = 1,
                             const QString& i_region = "America/New_York");
        void loadOnTheAir(const Language& i_language, int32_t i_page = 1,
                          const QString& i_region = "America/New_York");
        void loadPopular(const Language& i_language, int32_t i_page = 1);
        void loadTopRated(const Language& i_language, int32_t i_page = 1);
        void loadRecommendations(int32_t i_page = 1);
        void loadSimilar(int32_t i_page = 1);
        void loadWatchProviders(Country* i_country);
        void loadExternalIDs();
        void loadBackdrops(const QString& i_size = "original");
        void loadBackdrop(int i_index, const QString& i_size = "original");
        void loadPosters(const QString& i_size = "original");
        void loadPoster(int i_index, const QString& i_size = "original");
        void loadLogos(const QString& i_size = "original");
        void loadLogo(int i_index, const QString& i_size = "original");
        void loadSeasons();

    private slots:
        void startedLoadingSeriesReceived();
        void finishedLoadingSeriesReceived(void* i_data);
        void startedLoadingSearchResultsReceived();
        void finishedLoadingSearchResultsReceived(void* i_data);
        void startedLoadingAiringTodayReceived();
        void finishedLoadingAiringTodayReceived(void* i_data);
        void startedLoadingOnTheAirReceived();
        void finishedLoadingOnTheAirReceived(void* i_data);
        void startedLoadingPopularReceived();
        void finishedLoadingPopularReceived(void* i_data);
        void startedLoadingTopRatedReceived();
        void finishedLoadingTopRatedReceived(void* i_data);
        void startedLoadingRecommendationsReceived();
        void finishedLoadingRecommendationsReceived(void* i_data);
        void startedLoadingSimilarReceived();
        void finishedLoadingSimilarReceived(void* i_data);
        void startedLoadingWatchProvidersReceived();
        void finishedLoadingWatchProvidersReceived(void* i_data);
        void startedLoadingExternalIDsReceived();
        void finishedLoadingExternalIDsReceived(void* i_data);
        void startedLoadingBackdropsReceived();
        void finishedLoadingBackdropsReceived(void* i_data);
        void startedLoadingBackdropReceived();
        void finishedLoadingBackdropReceived(void* i_data);
        void startedLoadingPostersReceived();
        void finishedLoadingPostersReceived(void* i_data);
        void startedLoadingPosterReceived();
        void finishedLoadingPosterReceived(void* i_data);
        void startedLoadingLogosReceived();
        void finishedLoadingLogosReceived(void* i_data);
        void startedLoadingLogoReceived();
        void finishedLoadingLogoReceived(void* i_data);
        void startedLoadingSeasonsReceived();
        void finishedLoadingSeasonsReceived(void* i_data);

    signals:
        void startedLoadingSeries();
        void finishedLoadingSeries(tmdb::ASync::TV::Series* i_series);
        void startedLoadingSearchResults();
        void finishedLoadingSearchResults(std::vector<tmdb::ASync::TV::Series*> i_series);
        void startedLoadingAiringToday();
        void finishedLoadingAiringToday(std::vector<tmdb::ASync::TV::Series*> i_series);
        void startedLoadingOnTheAir();
        void finishedLoadingOnTheAir(std::vector<tmdb::ASync::TV::Series*> i_series);
        void startedLoadingPopular();
        void finishedLoadingPopular(std::vector<tmdb::ASync::TV::Series*> i_series);
        void startedLoadingTopRated();
        void finishedLoadingTopRated(std::vector<tmdb::ASync::TV::Series*> i_series);
        void startedLoadingRecommendations();
        void finishedLoadingRecommendations(std::vector<tmdb::ASync::TV::Series*> i_series);
        void startedLoadingSimilar();
        void finishedLoadingSimilar(std::vector<tmdb::ASync::TV::Series*> i_series);
        void startedLoadingWatchProviders();
        void finishedLoadingWatchProviders(std::vector<tmdb::ASync::WatchProvider*> i_watchProviders);
        void startedLoadingExternalIDs();
        void finishedLoadingExternalIDs(std::array<QString, 9> i_externalIDs);
        void startedLoadingBackdrops();
        void startedLoadingBackdrop();
        void finishedLoadingBackdrop(QPixmap i_backdrop);
        void startedLoadingPosters();
        void startedLoadingPoster();
        void finishedLoadingPoster(QPixmap i_poster);
        void startedLoadingLogos();
        void startedLoadingLogo();
        void finishedLoadingLogo(QPixmap i_logo);
        void startedLoadingSeasons();
        void finishedLoadingSeasons(std::vector<tmdb::ASync::TV::Season*> i_seasons);

    protected:
        aQtmdb m_q;
        bool m_adult = true;
        QString m_backdropPath;
        std::vector<tmdb::ASync::Person*> m_createdBy;
        std::vector<int> m_episodeRunTime;
        QDate m_firstAirDate;
        std::vector<tmdb::ASync::Genre*> m_genres;
        QString m_homepage;
        int m_id = 0;
        bool in_production = true;
        std::vector<Language*> m_languages;
        QDate m_lastAirDate;
        QString m_name;
        std::vector<tmdb::ASync::TV::Network*> m_networks;
        int m_episodeCount = 0;
        int m_seasonCount = 0;
        std::vector<Country*> m_originCountries;
        QString m_originalLanguage;
        QString m_overview;
        float m_popularity = 0.0f;
        QString m_posterPath;
        std::vector<tmdb::ASync::Company*> m_productionCompanies;
        std::vector<Country*> m_productionCountries;
        std::vector<tmdb::ASync::TV::Season*> m_seasons;
        std::vector<Language*> m_spokenLanguages;
        QString m_status;
        QString m_tagline;
        QString m_type;
        float m_voteAverage = 0.0f;
        int m_voteCount = 0;

        Country* m_tempCountry;
        QString m_tempSize;
    };
}
#endif //ASYNC_SERIES_H
