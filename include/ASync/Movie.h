//
// Created by t on 26/05/25.
//

#ifndef ASYNC_MOVIE_H
#define ASYNC_MOVIE_H

#include "Company.h"
#include "Config.h"
#include "Genre.h"
#include <QPixmap>

#include "Country.h"
#include "Language.h"
#include "Person.h"
#include "WatchProvider.h"

namespace tmdb::ASync
{
    struct AlternateTitle
    {
        Country country;
        QString title;
        QString type;
    };

    class Movie : public QObject
    {
        Q_OBJECT

    public:
        void setAdult(bool i_adult);
        [[nodiscard]] bool adult() const;
        void setBackdropPath(const QString& i_backdropPath);
        [[nodiscard]] QString backdropPath() const;
        void setBelongsToCollection(const QString& i_belongsToCollection);
        [[nodiscard]] QString belongsToCollection() const;
        void setBudget(int i_budget);
        [[nodiscard]] int budget() const;
        void setGenres(const std::vector<Genre>& i_genres);
        [[nodiscard]] std::vector<Genre> genres() const;
        void setHomepage(const QString& i_homepage);
        [[nodiscard]] QString homepage() const;
        void setId(int i_id);
        [[nodiscard]] int id() const;
        void setImdbID(const QString& i_imdbID);
        [[nodiscard]] QString imdbID() const;
        void setOriginalLanguage(Language* i_originalLanguage);
        [[nodiscard]] Language* originalLanguage() const;
        void setOriginalTitle(const QString& i_originalTitle);
        [[nodiscard]] QString originalTitle() const;
        void setOverview(const QString& i_overview);
        [[nodiscard]] QString overview() const;
        void setPopularity(float i_popularity);
        [[nodiscard]] float popularity() const;
        void setPosterPath(const QString& i_posterPath);
        [[nodiscard]] QString posterPath() const;
        void setProductionCompanies(const std::vector<Company>& i_productionCompanies);
        [[nodiscard]] std::vector<Company> productionCompanies() const;
        void setCountries(const std::vector<Country>& i_countries);
        [[nodiscard]] std::vector<Country> countries() const;
        void setReleaseDate(const QDate& i_releaseDate);
        [[nodiscard]] QDate releaseDate() const;
        void setRevenue(int i_revenue);
        [[nodiscard]] int revenue() const;
        void setRuntime(int i_runtime);
        [[nodiscard]] int runtime() const;
        void setLanguages(const std::vector<Language>& i_languages);
        [[nodiscard]] std::vector<Language> languages() const;
        void setStatus(const QString& i_status);
        [[nodiscard]] QString status() const;
        void setTagline(const QString& i_tagline);
        [[nodiscard]] QString tagline() const;
        void setTitle(const QString& i_title);
        [[nodiscard]] QString title() const;
        void setVideo(bool i_video);
        [[nodiscard]] bool video() const;
        void setVoteAverage(float i_voteAverage);
        [[nodiscard]] float voteAverage() const;
        void setVoteCount(int i_voteCount);
        [[nodiscard]] int voteCount() const;

        Movie();
        ~Movie() override = default;
        explicit Movie(const QString& i_access_token, int32_t i_movieID);

        Movie* fromJSON(const QJsonObject& i_json);

    public slots:
        void loadMovie(int32_t i_movieID);
        void loadSearchResults(const QString& i_query,
                               int32_t i_page = 1, int32_t i_year = 0,
                               int32_t i_primaryReleaseYear = 0,
                               bool i_includeAdult = false,
                               const QString& i_country = QString(),
                               const QString& i_language = "en-US");
        void loadNowPlaying();
        void loadPopular();
        void loadTopRated();
        void loadUpcoming();
        void loadRecommendations(int32_t i_page = 1);
        void loadSimilar(int32_t i_page = 1);
        void loadExternalIDs(int32_t i_movieID);
        void loadBackdrops(const QString& i_size = "original");
        void loadBackdrop(int i_index, const QString& i_size = "original");
        void loadPosters(const QString& i_size = "original");
        void loadPoster(int i_index, const QString& i_size = "original");
        void loadLogos(const QString& i_size = "original");
        void loadLogo(int i_index, const QString& i_size = "original");
        void loadWatchProviders(Country* i_region);
        void loadKeywords();
        void loadCredits();

    private slots:
        void startedLoadingMovieReceived();
        void finishedLoadingMovieReceived(void* i_data);
        void startedLoadingSearchResultsReceived();
        void finishedLoadingSearchResultsReceived(void* i_data);
        void startedLoadingNowPlayingReceived();
        void finishedLoadingNowPlayingReceived(void* i_data);
        void startedLoadingPopularReceived();
        void finishedLoadingPopularReceived(void* i_data);
        void startedLoadingTopRatedReceived();
        void finishedLoadingTopRatedReceived(void* i_data);
        void startedLoadingUpcomingReceived();
        void finishedLoadingUpcomingReceived(void* i_data);
        void startedLoadingRecommendationsReceived();
        void finishedLoadingRecommendationsReceived(void* i_data);
        void startedLoadingSimilarReceived();
        void finishedLoadingSimilarReceived(void* i_data);
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
        void startedLoadingWatchProvidersReceived();
        void finishedLoadingWatchProvidersReceived(void* i_data);
        void startedLoadingKeywordsReceived();
        void finishedLoadingKeywordsReceived(void* i_data);
        void startedLoadingCreditsReceived();
        void finishedLoadingCreditsReceived(void* i_data);

    signals:
        void startedLoadingMovie();
        void finishedLoadingMovie(tmdb::ASync::Movie* i_movie);
        void startedLoadingSearchResults();
        void finishedLoadingSearchResults(std::vector<tmdb::ASync::Movie> i_movies);
        void startedLoadingNowPlaying();
        void finishedLoadingNowPlaying(std::vector<tmdb::ASync::Movie> i_movies);
        void startedLoadingPopular();
        void finishedLoadingPopular(std::vector<tmdb::ASync::Movie> i_movies);
        void startedLoadingTopRated();
        void finishedLoadingTopRated(std::vector<tmdb::ASync::Movie> i_movies);
        void startedLoadingUpcoming();
        void finishedLoadingUpcoming(std::vector<tmdb::ASync::Movie> i_movies);
        void startedLoadingRecommendations();
        void finishedLoadingRecommendations(std::vector<tmdb::ASync::Movie> i_movies);
        void startedLoadingSimilar();
        void finishedLoadingSimilar(std::vector<tmdb::ASync::Movie> i_movies);
        void startedLoadingExternalIDs();
        void finishedLoadingExternalIDs(std::array<QString, 5> i_externalIDs);
        void startedLoadingBackdrops();
        void startedLoadingBackdrop();
        void finishedLoadingBackdrop(QPixmap i_backdrop);
        void startedLoadingPosters();
        void finishedLoadingPosters(std::vector<QPixmap> i_posters);
        void startedLoadingPoster();
        void finishedLoadingPoster(QPixmap i_poster);
        void startedLoadingLogos();
        void finishedLoadingLogos(std::vector<QPixmap> i_logos);
        void startedLoadingLogo();
        void finishedLoadingLogo(QPixmap i_logo);
        void startedLoadingWatchProviders();
        void finishedLoadingWatchProviders(std::vector<WatchProvider> i_watchProviders);
        void startedLoadingKeywords();
        void finishedLoadingKeywords(std::map<int, QString> i_keywords);
        void startedLoadingCredits();
        void finishedLoadingCredits(std::vector<Credit> i_credits);

    protected:
        aQtmdb m_q;
        bool m_adult = true;
        QString m_backdropPath = "EMPTY_BACKDROP_PATH";
        QString m_belongsToCollection = "EMPTY_COLLECTION";
        int m_budget = 0;
        std::vector<Genre> m_genres = {};
        QString m_homepage = "EMPTY_HOMEPAGE";
        int m_id = 0;
        QString m_imdbID = "EMPTY_IMDB_ID";
        Language* m_originalLanguage = new Language();
        QString m_originalTitle = "EMPTY_TITLE";
        QString m_overview = "EMPTY_OVERVIEW";
        float m_popularity = 0.0f;
        QString m_posterPath = "EMPTY_POSTER_PATH";
        std::vector<Company> m_productionCompanies = {};
        std::vector<Country> m_countries = {};
        QDate m_releaseDate = QDate::currentDate();
        int m_revenue = 0;
        int m_runtime = 0;
        std::vector<Language> m_languages = {};
        QString m_status = "EMPTY_STATUS";
        QString m_tagline = "EMPTY_TAGLINE";
        QString m_title = "EMPTY_TITLE";
        bool m_video = true;
        float m_voteAverage = 0.0f;
        int m_voteCount = 0;

        int m_tempIndex = 0; // Used for loading backdrops, posters, and logos
        Country* m_region = nullptr; // Used for loading watch providers
    };
}
#endif //ASYNC_MOVIE_H
