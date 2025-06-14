//
// Created by t on 26/05/25.
//

#ifndef ASYNC_GENRE_H
#define ASYNC_GENRE_H
#include <QJsonObject>
#include <QString>

#include "QTMDB.h"

namespace tmdb::ASync
{
    class Genre : public QObject
    {
        Q_OBJECT

    public:
        void setID(int32_t i_id);
        [[nodiscard]] int32_t id() const;
        void setName(const QString& i_name);
        [[nodiscard]] QString name() const;

        Genre();
        explicit Genre(const QString& i_access_token);
        Genre(const QString& i_access_token, int32_t i_genreID);
        ~Genre() override = default;

        Genre(const QJsonObject& i_json, const QString& i_access_token);
    protected:
        void parseJson(const QJsonObject& i_json, const QString& i_access_token);
    public slots:
        void loadGenre(int32_t i_genreID);
        void loadAllGenres();
        void loadMovieGenres();
        void loadTvGenres();

    private slots:
        void startedLoadingGenreReceived();
        void finishedLoadingGenreReceived(void* i_data);
        void startedLoadingAllGenresReceived();
        void finishedLoadingAllGenresReceived(void* i_data);
        void startedLoadingMovieGenresReceived();
        void finishedLoadingMovieGenresReceived(void* i_data);
        void startedLoadingTvGenresReceived();
        void finishedLoadingTvGenresReceived(void* i_data);

    signals:
        void startedLoadingGenre();
        void finishedLoadingGenre(tmdb::ASync::Genre* i_genre);
        void startedLoadingAllGenres();
        void finishedLoadingAllGenres(std::vector<tmdb::ASync::Genre*> i_genres);
        void startedLoadingMovieGenres();
        void finishedLoadingMovieGenres(std::vector<tmdb::ASync::Genre*> i_genres);
        void startedLoadingTvGenres();
        void finishedLoadingTvGenres(std::vector<tmdb::ASync::Genre*> i_genres);

    protected:
        int32_t m_id = 0;
        QString m_name;
        aQtmdb m_q;
        QJsonObject m_tempJson;
    };
}

#endif //ASYNC_GENRE_H
