//
// Created by t on 26/05/25.
//

#ifndef MOVIE_H
#define MOVIE_H

#include "Company.h"
#include "Config.h"
#include "Genre.h"
#include <QPixmap>

#include "Person.h"
#include "WatchProvider.h"

namespace tmdb
{
    struct AlternateTitle
    {
        config::country country;
        QString title;
        QString type;
    };

    class Movie
    {
    public:
        Movie() = default;
        ~Movie() = default;
        Movie(const QString& i_access_token, int32_t i_movieID);
        static Movie getMovie(const QString& i_access_token, int32_t i_movieID);
        static std::vector<Movie> searchForMovies(const QString& i_access_token, const QString& i_query,
                                                  int32_t i_page = 1, int32_t i_year = 0,
                                                  int32_t i_primaryReleaseYear = 0,
                                                  bool i_includeAdult = false,
                                                  const QString& i_country = QString(),
                                                  const QString& i_language = "en-US");
        Movie(const QJsonObject& i_json, const QString& i_access_token);

        static std::vector<Movie> getNowPlaying(const QString& i_access_token, const config::language& i_language = {"en-US", "United States", "United States"},
                                                int32_t i_page = 1, const config::country& i_region = config::country());
        static std::vector<Movie> getPopular(const QString& i_access_token, const config::language& i_language = {"en-US", "United States", "United States"},
                                                int32_t i_page = 1, const config::country& i_region = config::country());
        static std::vector<Movie> getTopRated(const QString& i_access_token, const config::language& i_language = {"en-US", "United States", "United States"},
                                                int32_t i_page = 1, const config::country& i_region = config::country());
        static std::vector<Movie> getUpcoming(const QString& i_access_token, const config::language& i_language = {"en-US", "United States", "United States"},
                                                int32_t i_page = 1, const config::country& i_region = config::country());

        [[nodiscard]] std::vector<Movie> recommendations(const QString& i_access_token, int32_t i_page = 1) const;
        [[nodiscard]] std::vector<Movie> similar(const QString& i_access_token, int32_t i_page = 1) const;

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
        void setOriginalLanguage(const tmdb::config::language& i_originalLanguage);
        [[nodiscard]] config::language originalLanguage() const;
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
        void setCountries(const std::vector<config::country>& i_countries);
        [[nodiscard]] std::vector<config::country> countries() const;
        void setReleaseDate(const QDate& i_releaseDate);
        [[nodiscard]] QDate releaseDate() const;
        void setRevenue(int i_revenue);
        [[nodiscard]] int revenue() const;
        void setRuntime(int i_runtime);
        [[nodiscard]] int runtime() const;
        void setLanguages(const std::vector<config::language>& i_languages);
        [[nodiscard]] std::vector<config::language> languages() const;
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

        [[nodiscard]] std::vector<AlternateTitle> alternateTitles(const QString& i_access_token) const;
        [[nodiscard]] std::array<QString, 5> externalIDs(const QString& i_access_token) const;
        [[nodiscard]] std::vector<QPixmap> backdrops(const QString& i_access_token, const QString& i_size = "original") const;
        [[nodiscard]] std::vector<QPixmap> posters(const QString& i_access_token, const QString& i_size = "original") const;
        [[nodiscard]] std::vector<QPixmap> logos(const QString& i_access_token, const QString& i_size = "original") const;
        [[nodiscard]] std::vector<WatchProvider> watchProviders(const QString& i_access_token, const config::country& i_region = config::country()) const;
        [[nodiscard]] std::map<int, QString> keywords(const QString& i_access_token) const;
        [[nodiscord]] std::vector<tmdb::Credit> credits(const QString& i_access_token) const;

    protected:
        bool m_adult = true;
        QString m_backdropPath = "EMPTY_BACKDROP_PATH";
        QString m_belongsToCollection = "EMPTY_COLLECTION";
        int m_budget = 0;
        std::vector<Genre> m_genres = {};
        QString m_homepage = "EMPTY_HOMEPAGE";
        int m_id = 0;
        QString m_imdbID = "EMPTY_IMDB_ID";
        config::language m_originalLanguage = config::language();
        QString m_originalTitle = "EMPTY_TITLE";
        QString m_overview = "EMPTY_OVERVIEW";
        float m_popularity = 0.0f;
        QString m_posterPath = "EMPTY_POSTER_PATH";
        std::vector<Company> m_productionCompanies = {};
        std::vector<config::country> m_countries = {};
        QDate m_releaseDate = QDate::currentDate();
        int m_revenue = 0;
        int m_runtime = 0;
        std::vector<config::language> m_languages = {};
        QString m_status = "EMPTY_STATUS";
        QString m_tagline = "EMPTY_TAGLINE";
        QString m_title = "EMPTY_TITLE";
        bool m_video = true;
        float m_voteAverage = 0.0f;
        int m_voteCount = 0;
    };
}
#endif //MOVIE_H
