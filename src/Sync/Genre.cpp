//
// Created by t on 26/05/25.
//

#include "Sync/Genre.h"
#include "Sync/QTMDB.h"

void tmdb::Genre::setID(int32_t i_id) {
    m_id = i_id;
}
int32_t tmdb::Genre::id() const {
    return m_id;
}

void tmdb::Genre::setName(const QString &i_name) {
    m_name = i_name;
}
QString tmdb::Genre::name() const {
    return m_name;
}

tmdb::Genre::Genre(int32_t id, QString name)
    : m_id(id), m_name(std::move(name)) {}

tmdb::Genre::Genre(const QString &i_access_token, int32_t i_genreID)
{
    auto genre = getGenre(i_access_token, i_genreID);
    if (genre.id() != 0) {
        setID(genre.id());
        setName(genre.name());
    } else {
        setID(0);
        setName(QString());
    }
}

tmdb::Genre::Genre(const QJsonObject &i_json)
{
    m_id = i_json["id"].toInt();
    m_name = i_json["name"].toString();
}

tmdb::Genre tmdb::Genre::getGenre(const QString &i_access_token, int32_t i_genreID)
{
    Qtmdb q(i_access_token.toStdString());
    auto genres = getAllGenres(i_access_token);
    for (const auto &genre : genres) {
        if (genre.id() == i_genreID) {
            return genre;
        }
    }
    return Genre();
}

std::vector<tmdb::Genre> tmdb::Genre::getAllGenres(const QString &i_access_token)
{
    Qtmdb q(i_access_token.toStdString());
    auto mGenres = q.genres_movie();
    auto tGenres = q.genres_tv();
    std::vector<Genre> genres;
    auto amGenres = mGenres["genres"].toArray();
    auto atGenres = tGenres["genres"].toArray();
    genres.reserve(amGenres.size() + atGenres.size());
    for (const auto &genre : amGenres) {
        genres.emplace_back(genre.toObject().value("id").toInt(), genre.toObject().value("name").toString());
    }
    for (const auto &genre : atGenres) {
        genres.emplace_back(genre.toObject().value("id").toInt(), genre.toObject().value("name").toString());
    }
    return genres;
}

std::vector<tmdb::Genre> tmdb::Genre::getMovieGenres(const QString &i_access_token)
{
    Qtmdb q(i_access_token.toStdString());
    auto mGenres = q.genres_movie()["genres"].toArray();
    std::vector<Genre> genres;
    genres.reserve(mGenres.size());
    for (const auto &genre : mGenres) {
        genres.emplace_back(genre.toObject().value("id").toInt(), genre.toObject().value("name").toString());
    }
    return genres;
}

std::vector<tmdb::Genre> tmdb::Genre::getTvGenres(const QString &i_access_token)
{
    Qtmdb q(i_access_token.toStdString());
    auto tGenres = q.genres_tv()["genres"].toArray();
    std::vector<Genre> genres;
    genres.reserve(tGenres.size());
    for (const auto &genre : tGenres) {
        genres.emplace_back(genre.toObject().value("id").toInt(), genre.toObject().value("name").toString());
    }
    return genres;
}