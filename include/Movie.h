//
// Created by t on 26/05/25.
//

#ifndef MOVIE_H
#define MOVIE_H

#include "Company.h"
#include "Config.h"
#include "Genre.h"
namespace tmdb
{
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

        void setAdult(bool i_adult);
        bool adult() const;
        void setBackdropPath(const QString& i_backdropPath);
        QString backdropPath() const;
        void setBelongsToCollection(const QString& i_belongsToCollection);
        QString belongsToCollection() const;
        void setBudget(int i_budget);
        int budget() const;
        void setGenres(const std::vector<Genre>& i_genres);
        std::vector<Genre> genres() const;
        void setHomepage(const QString& i_homepage);
        QString homepage() const;
        void setId(int i_id);
        int id() const;
        void setImdbID(const QString& i_imdbID);
        QString imdbID() const;
        void setOriginalLanguage(const tmdb::config::language& i_originalLanguage);
        tmdb::config::language originalLanguage() const;
        void setOriginalTitle(const QString& i_originalTitle);
        QString originalTitle() const;
        void setOverview(const QString& i_overview);
        QString overview() const;
        void setPopularity(float i_popularity);
        float popularity() const;
        void setPosterPath(const QString& i_posterPath);
        QString posterPath() const;
        void setProductionCompanies(const std::vector<Company>& i_productionCompanies);
        std::vector<Company> productionCompanies() const;
        void setCountries(const std::vector<config::country>& i_countries);
        std::vector<config::country> countries() const;
        void setReleaseDate(const QDate& i_releaseDate);
        QDate releaseDate() const;
        void setRevenue(int i_revenue);
        int revenue() const;
        void setRuntime(int i_runtime);
        int runtime() const;
        void setLanguages(const std::vector<config::language>& i_languages);
        std::vector<config::language> languages() const;
        void setStatus(const QString& i_status);
        QString status() const;
        void setTagline(const QString& i_tagline);
        QString tagline() const;
        void setTitle(const QString& i_title);
        QString title() const;
        void setVideo(bool i_video);
        bool video() const;
        void setVoteAverage(float i_voteAverage);
        float voteAverage() const;
        void setVoteCount(int i_voteCount);
        int voteCount() const;

    protected:
        bool m_adult = true;
        QString m_backdropPath;
        QString m_belongsToCollection;
        int m_budget = 0;
        std::vector<Genre> m_genres;
        QString m_homepage;
        int m_id = 0;
        QString m_imdbID;
        tmdb::config::language m_originalLanguage;
        QString m_originalTitle;
        QString m_overview;
        float m_popularity = 0.0f;
        QString m_posterPath;
        std::vector<Company> m_productionCompanies;
        std::vector<config::country> m_countries;
        QDate m_releaseDate;
        int m_revenue = 0;
        int m_runtime = 0;
        std::vector<config::language> m_languages;
        QString m_status;
        QString m_tagline;
        QString m_title;
        bool m_video = true;
        float m_voteAverage = 0.0f;
        int m_voteCount = 0;
    };
}
#endif //MOVIE_H
