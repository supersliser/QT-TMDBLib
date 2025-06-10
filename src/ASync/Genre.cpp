//
// Created by t on 26/05/25.
//

#include "ASync/Genre.h"

#include <unistd.h>

#include "ASync/QTMDB.h"

void tmdb::ASync::Genre::setID(int32_t i_id) {
    m_id = i_id;
}
int32_t tmdb::ASync::Genre::id() const {
    return m_id;
}

void tmdb::ASync::Genre::setName(const QString &i_name) {
    m_name = i_name;
}
QString tmdb::ASync::Genre::name() const {
    return m_name;
}

tmdb::ASync::Genre::Genre(): m_q("")
{
    m_q.setParent(this);
}

tmdb::ASync::Genre::Genre(const QString &i_access_token, int32_t i_genreID) : m_q(i_access_token.toStdString())
{
    m_q.setParent(this);
    loadGenre(i_genreID);
}

tmdb::ASync::Genre *tmdb::ASync::Genre::fromJSON(const QJsonObject &i_json) {
    auto genre = new tmdb::ASync::Genre();
    genre->setID(i_json["id"].toInt());
    genre->setName(i_json["name"].toString());
    return genre;
}

void tmdb::ASync::Genre::loadGenre(int32_t i_genreID) {
    connect(&m_q, &aQtmdb::startedLoadingData, this, &tmdb::ASync::Genre::startedLoadingGenreReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &tmdb::ASync::Genre::finishedLoadingGenreReceived);
    setID(i_genreID);
    m_q.genres_movie();
}

void tmdb::ASync::Genre::startedLoadingGenreReceived()
{
    emit startedLoadingGenre();
}

void tmdb::ASync::Genre::finishedLoadingGenreReceived(void *i_data)
{
    auto json = *static_cast<QJsonObject *>(i_data);
    for (int i = 0; i < json["genres"].toArray().size(); ++i)
    {
        if (json["id"].toInt() == m_id)
        {
            emit finishedLoadingGenre(fromJSON(json["genres"].toArray().at(i).toObject()));
            break;
        }
    }
    if (m_tempJson.isEmpty())
    {
        m_tempJson = json;
        m_q.genres_tv();
    }
    else
    {
        m_tempJson = QJsonObject();
        disconnect(&m_q, &aQtmdb::startedLoadingData, this, &tmdb::ASync::Genre::startedLoadingGenreReceived);
        disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &tmdb::ASync::Genre::finishedLoadingGenreReceived);
    }
}

void tmdb::ASync::Genre::loadAllGenres() {
    connect(&m_q, &aQtmdb::startedLoadingData, this, &tmdb::ASync::Genre::startedLoadingAllGenresReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &tmdb::ASync::Genre::finishedLoadingAllGenresReceived);
    m_q.genres_movie();
}

void tmdb::ASync::Genre::startedLoadingAllGenresReceived()
{
    emit startedLoadingAllGenres();
}

void tmdb::ASync::Genre::finishedLoadingAllGenresReceived(void *i_data)
{
    auto json = *static_cast<QJsonObject *>(i_data);
    if (m_tempJson.isEmpty())
    {
        m_tempJson = json;
        m_q.genres_tv();
        return;
    }
    QList<tmdb::ASync::Genre*> genres;
    for (const auto& genre : json["genres"].toArray())
    {
        genres.append(fromJSON(genre.toObject()));
    }
    for (const auto& genre : m_tempJson["genres"].toArray())
    {
        genres.append(fromJSON(genre.toObject()));
    }
    m_tempJson = QJsonObject();
    emit finishedLoadingAllGenres(genres);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &tmdb::ASync::Genre::startedLoadingAllGenresReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &tmdb::ASync::Genre::finishedLoadingAllGenresReceived);
}

void tmdb::ASync::Genre::loadMovieGenres() {
    connect(&m_q, &aQtmdb::startedLoadingData, this, &tmdb::ASync::Genre::startedLoadingMovieGenresReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &tmdb::ASync::Genre::finishedLoadingMovieGenresReceived);
    m_q.genres_movie();
}

void tmdb::ASync::Genre::startedLoadingMovieGenresReceived()
{
    emit startedLoadingMovieGenres();
}

void tmdb::ASync::Genre::finishedLoadingMovieGenresReceived(void *i_data)
{
    auto json = *static_cast<QJsonObject *>(i_data);
    QList<tmdb::ASync::Genre*> genres;
    for (const auto& genre : json["genres"].toArray())
    {
        genres.append(fromJSON(genre.toObject()));
    }
    emit finishedLoadingMovieGenres(genres);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &tmdb::ASync::Genre::startedLoadingMovieGenresReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &tmdb::ASync::Genre::finishedLoadingMovieGenresReceived);
}

void tmdb::ASync::Genre::loadTvGenres() {
    connect(&m_q, &aQtmdb::startedLoadingData, this, &tmdb::ASync::Genre::startedLoadingTvGenresReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &tmdb::ASync::Genre::finishedLoadingTvGenresReceived);
    m_q.genres_tv();
}

void tmdb::ASync::Genre::startedLoadingTvGenresReceived()
{
    emit startedLoadingTvGenres();
}

void tmdb::ASync::Genre::finishedLoadingTvGenresReceived(void *i_data)
{
    auto json = *static_cast<QJsonObject *>(i_data);
    QList<tmdb::ASync::Genre*> genres;
    for (const auto& genre : json["genres"].toArray())
    {
        genres.append(fromJSON(genre.toObject()));
    }
    emit finishedLoadingTvGenres(genres);
    disconnect(&m_q, &aQtmdb::startedLoadingData, this, &tmdb::ASync::Genre::startedLoadingTvGenresReceived);
    disconnect(&m_q, &aQtmdb::finishedLoadingData, this, &tmdb::ASync::Genre::finishedLoadingTvGenresReceived);
}
