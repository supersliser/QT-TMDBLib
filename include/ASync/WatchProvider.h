//
// Created by t on 27/05/25.
//

#ifndef ASYNC_WATCHPROVIDER_H
#define ASYNC_WATCHPROVIDER_H
#include <QJsonObject>
#include <QString>
#include <QUrl>
#include "ASync/Language.h"

#include "Config.h"

namespace tmdb::ASync
{
    enum ProviderType
    {
        unset = 0,
        flatrate,
        buy,
        rent
    };

    class WatchProvider : public QObject
    {
        Q_OBJECT

    public:
        void setType(ProviderType i_type);
        [[nodiscard]] ProviderType type() const;
        void setLogoPath(const QString& i_logoPath);
        [[nodiscard]] QString logoPath() const;
        void setProviderID(int i_providerID);
        [[nodiscard]] int providerID() const;
        void setProviderName(const QString& i_providerName);
        [[nodiscard]] QString providerName() const;
        void setLink(const QUrl& i_link);
        [[nodiscard]] QUrl link() const;

        WatchProvider();
        WatchProvider(const QString& i_access_token, int i_providerID);

        static WatchProvider* fromJSON(const QJsonObject& i_json);

        ~WatchProvider() override = default;

    public slots:
        void loadWatchProvider(int i_providerID);
        void loadAllWatchProviders(Language* i_language);
        void loadAllMovieProviders(const Language* i_language);
        void loadAllTVProviders(const Language* i_language);
        void loadWatchProvidersForMovie(const QString& i_language, int i_movieID);
        void loadWatchProvidersForTV(const QString& i_language, int i_seriesID);

    private slots:
        void startedLoadingWatchProviderReceived();
        void finishedLoadingWatchProviderReceived(void* i_data);
        void startedLoadingAllWatchProvidersReceived();
        void finishedLoadingAllWatchProvidersReceived(void* i_data);
        void startedLoadingAllMovieProvidersReceived();
        void finishedLoadingAllMovieProvidersReceived(void* i_data);
        void startedLoadingAllTVProvidersReceived();
        void finishedLoadingAllTVProvidersReceived(void* i_data);
        void startedLoadingWatchProvidersForMovieReceived();
        void finishedLoadingWatchProvidersForMovieReceived(void* i_data);
        void startedLoadingWatchProvidersForTVReceived();
        void finishedLoadingWatchProvidersForTVReceived(void* i_data);

    signals:
        void startedLoadingWatchProvider();
        void finishedLoadingWatchProvider(tmdb::ASync::WatchProvider* i_watchProvider);
        void startedLoadingAllWatchProviders();
        void finishedLoadingAllWatchProviders(std::vector<tmdb::ASync::WatchProvider*> i_watchProviders);
        void startedLoadingAllMovieProviders();
        void finishedLoadingAllMovieProviders(std::vector<tmdb::ASync::WatchProvider*> i_watchProviders);
        void startedLoadingAllTVProviders();
        void finishedLoadingAllTVProviders(std::vector<tmdb::ASync::WatchProvider*> i_watchProviders);
        void startedLoadingWatchProvidersForMovie();
        void finishedLoadingWatchProvidersForMovie(std::vector<tmdb::ASync::WatchProvider*> i_watchProviders);
        void startedLoadingWatchProvidersForTV();
        void finishedLoadingWatchProvidersForTV(std::vector<tmdb::ASync::WatchProvider*> i_watchProviders);

    protected:
        aQtmdb m_q;
        ProviderType m_type = unset;
        QString m_logoPath;
        int m_providerID = 0;
        QString m_providerName;
        QUrl m_link;

        QJsonObject* m_tempData = nullptr;
        Language* m_tempLanguage = nullptr;
    };
}

#endif //WATCHPROVIDER_H
