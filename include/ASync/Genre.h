//
// Created by t on 26/05/25.
//

#ifndef ASYNC_GENRE_H
#define ASYNC_GENRE_H
#include <QJsonObject>
#include <QString>

namespace tmdb
{
    class Genre
    {
    public:
        void setID(int32_t i_id);
        [[nodiscard]] int32_t id() const;
        void setName(const QString &i_name);
        [[nodiscard]] QString name() const;

        Genre() = default;
        Genre(int32_t id, QString name);
        Genre(const QString& i_access_token, int32_t i_genreID);
        explicit Genre(const QJsonObject &i_json);
        ~Genre() = default;

        static Genre getGenre(const QString& i_access_token, int32_t i_genreID);
        static std::vector<Genre> getAllGenres(const QString& i_access_token);
        static std::vector<Genre> getMovieGenres(const QString& i_access_token);
        static std::vector<Genre> getTvGenres(const QString& i_access_token);

    protected:
        int32_t m_id = 0;
        QString m_name;
    };
}

#endif //GENRE_H
