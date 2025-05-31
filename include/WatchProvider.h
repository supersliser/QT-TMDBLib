//
// Created by t on 27/05/25.
//

#ifndef WATCHPROVIDER_H
#define WATCHPROVIDER_H
#include <QJsonObject>
#include <QString>
#include <QUrl>

#include "Config.h"

namespace tmdb
{
    enum ProviderType
    {
        unset = 0,
        flatrate,
        buy,
        rent
    };

    class WatchProvider
    {
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

        WatchProvider() = default;
        WatchProvider(ProviderType i_type, QString i_logoPath, int i_providerID, QString i_providerName, QUrl i_link);
        WatchProvider(const QString& i_access_token, int i_providerID);
        explicit WatchProvider(const QJsonObject& i_json);

        static WatchProvider getWatchProvider(const QString& i_access_token, int i_providerID);
        static std::vector<WatchProvider> getAllWatchProviders(const QString& i_access_token,
                                                               ProviderType i_type = unset,
                                                               config::language i_language = config::getLanguage(
                                                                   "en-US"));
        static std::vector<WatchProvider> getAllMovieProviders(const QString& i_access_token,
                                                               config::language i_language = config::getLanguage(
                                                                   "en-US"));
        static std::vector<WatchProvider> getAllTVProviders(const QString& i_access_token,
                                                            const config::language& = config::getLanguage("en-US"));
        static std::vector<WatchProvider> getWatchProvidersForMovie(const QString& i_access_token,
                                                                    const QString& i_language, int i_movieID);
        static std::vector<WatchProvider> getWatchProvidersForTV(const QString& i_access_token,
                                                                 const QString& i_language, int i_seriesID);

    protected:
        ProviderType m_type = unset;
        QString m_logoPath;
        int m_providerID = 0;
        QString m_providerName;
        QUrl m_link;
    };
}

#endif //WATCHPROVIDER_H
