//
// Created by t on 27/05/25.
//

#include "Sync/WatchProvider.h"
#include "Sync/QTMDB.h"

void tmdb::WatchProvider::setType(ProviderType i_type)
{
    m_type = i_type;
}

tmdb::ProviderType tmdb::WatchProvider::type() const
{
    return m_type;
}

void tmdb::WatchProvider::setLogoPath(const QString& i_logoPath)
{
    m_logoPath = i_logoPath;
}

QString tmdb::WatchProvider::logoPath() const
{
    return m_logoPath;
}

void tmdb::WatchProvider::setProviderID(int i_providerID)
{
    m_providerID = i_providerID;
}

int tmdb::WatchProvider::providerID() const
{
    return m_providerID;
}

void tmdb::WatchProvider::setProviderName(const QString& i_providerName)
{
    m_providerName = i_providerName;
}

QString tmdb::WatchProvider::providerName() const
{
    return m_providerName;
}

void tmdb::WatchProvider::setLink(const QUrl& i_link)
{
    m_link = i_link;
}

QUrl tmdb::WatchProvider::link() const
{
    return m_link;
}

tmdb::WatchProvider::WatchProvider(ProviderType i_type, QString i_logoPath, int i_providerID, QString i_providerName,
                                   QUrl i_link)
    : m_type(i_type), m_logoPath(std::move(i_logoPath)), m_providerID(i_providerID),
      m_providerName(std::move(i_providerName)), m_link(std::move(i_link))
{
}

tmdb::WatchProvider::WatchProvider(const QString& i_access_token, int i_providerID)
{
    *this = getWatchProvider(i_access_token, i_providerID);
}

tmdb::WatchProvider::WatchProvider(const QJsonObject& i_json)
{
    m_type = unset;
    m_logoPath = i_json["logo_path"].toString();
    m_providerID = i_json["provider_id"].toInt();
    m_providerName = i_json["provider_name"].toString();
}

tmdb::WatchProvider tmdb::WatchProvider::getWatchProvider(const QString& i_access_token, int i_providerID)
{
    Qtmdb q(i_access_token.toStdString());
    auto providers = q.watchProviders_movie();
    for (const auto& provider : providers["results"].toArray())
    {
        if (provider.toObject()["provider_id"] == i_providerID)
        {
            return {
                tmdb::unset, provider.toObject()["logo_path"].toString(),
                provider.toObject()["provider_id"].toInt(),
                provider.toObject()["provider_name"].toString(), QUrl()
            };
        }
    }
    providers = q.watchProviders_tv();
    for (const auto& provider : providers["results"].toArray())
    {
        if (provider.toObject()["provider_id"] == i_providerID)
        {
            return {
                tmdb::unset, provider.toObject()["logo_path"].toString(),
                provider.toObject()["provider_id"].toInt(),
                provider.toObject()["provider_name"].toString(), QUrl()
            };
        }
    }
    return {};
}

std::vector<tmdb::WatchProvider> tmdb::WatchProvider::getAllWatchProviders(
    const QString& i_access_token, ProviderType i_type, config::language i_language)
{
    Qtmdb q(i_access_token.toStdString());
    std::vector<WatchProvider> providers;
    auto mProviders = q.watchProviders_movie(i_language.iso_639_1.toStdString());
    auto tProviders = q.watchProviders_tv(i_language.iso_639_1.toStdString());
    auto amProviders = mProviders["results"].toArray();
    auto atProviders = tProviders["results"].toArray();
    providers.reserve(amProviders.size() + atProviders.size());
    for (const auto& provider : amProviders)
    {
        providers.emplace_back(provider.toObject());
    }
    for (const auto& provider : atProviders)
    {
        providers.emplace_back(provider.toObject());
    }
    return providers;
}

std::vector<tmdb::WatchProvider> tmdb::WatchProvider::getAllMovieProviders(
    const QString& i_access_token, config::language i_language)
{
    Qtmdb q(i_access_token.toStdString());
    std::vector<WatchProvider> providers;
    auto mProviders = q.watchProviders_movie(i_language.iso_639_1.toStdString());
    auto amProviders = mProviders["results"].toArray();
    providers.reserve(amProviders.size());
    for (const auto& provider : amProviders)
    {
        providers.emplace_back(provider.toObject());
    }
    return providers;
}

std::vector<tmdb::WatchProvider> tmdb::WatchProvider::getAllTVProviders(const QString& i_access_token,
                                                                        const config::language& i_language)
{
    Qtmdb q(i_access_token.toStdString());
    std::vector<WatchProvider> providers;
    auto tProviders = q.watchProviders_tv(i_language.iso_639_1.toStdString());
    auto atProviders = tProviders["results"].toArray();
    providers.reserve(atProviders.size());
    for (const auto& provider : atProviders)
    {
        providers.emplace_back(provider.toObject());
    }
    return providers;
}

std::vector<tmdb::WatchProvider> tmdb::WatchProvider::getWatchProvidersForMovie(
    const QString& i_access_token, const QString& i_language, int i_movieID)
{
    Qtmdb q(i_access_token.toStdString());
    auto providers = q.movie_watchProviders(i_movieID);
    std::vector<WatchProvider> watchProviders;
    auto amProviders = providers["results"].toObject()[i_language].toObject();
    std::vector<config::LinkInfo> possibleLinks = config::extractLinksFromUrl(amProviders["link"].toString());
    for (const auto& provider : amProviders["flatrate"].toArray())
    {
        QString link;
        for (const auto& possibleLink : possibleLinks)
        {
            if (possibleLink.title.contains(provider.toObject()["provider_name"].toString()) &&
                possibleLink.title.contains("Watch ") && possibleLink.href.contains("click.justwatch.com"))
            {
                link = possibleLink.href;
                break;
            }
        }
        WatchProvider temp(flatrate, provider.toObject()["logo_path"].toString(),
                           provider.toObject()["provider_id"].toInt(), provider.toObject()["provider_name"].toString(),
                           link);
        watchProviders.emplace_back(temp);
    }
    for (const auto& provider : amProviders["buy"].toArray())
    {
        QString link;
        for (const auto& possibleLink : possibleLinks)
        {
            if (possibleLink.title.contains(provider.toObject()["provider_name"].toString()) &&
                possibleLink.title.contains("Buy ") && possibleLink.href.contains("click.justwatch.com"))
            {
                link = possibleLink.href;
                break;
            }
        }
        WatchProvider temp(buy, provider.toObject()["logo_path"].toString(),
                           provider.toObject()["provider_id"].toInt(), provider.toObject()["provider_name"].toString(),
                           link);
        watchProviders.emplace_back(temp);
    }
    for (const auto& provider : amProviders["rent"].toArray())
    {
        QString link;
        for (const auto& possibleLink : possibleLinks)
        {
            if (possibleLink.title.contains(provider.toObject()["provider_name"].toString()) &&
                possibleLink.title.contains("Rent ") && possibleLink.href.contains("click.justwatch.com"))
            {
                link = possibleLink.href;
                break;
            }
        }
        WatchProvider temp(rent, provider.toObject()["logo_path"].toString(),
                           provider.toObject()["provider_id"].toInt(), provider.toObject()["provider_name"].toString(),
                           link);
        watchProviders.emplace_back(temp);
    }
    return watchProviders;
}

std::vector<tmdb::WatchProvider> tmdb::WatchProvider::getWatchProvidersForTV(
    const QString& i_access_token, const QString& i_language, int i_seriesID)
{
    Qtmdb q(i_access_token.toStdString());
    auto providers = q.tv_series_watchProviders(i_seriesID);
    std::vector<WatchProvider> watchProviders;
    auto amProviders = providers["results"].toObject()[i_language].toObject();
    std::vector<config::LinkInfo> possibleLinks = config::extractLinksFromUrl(amProviders["link"].toString());
    for (const auto& provider : amProviders["flatrate"].toArray())
    {
        QString link;
        for (const auto& possibleLink : possibleLinks)
        {
            if (possibleLink.title.contains(provider.toObject()["provider_name"].toString()) &&
                possibleLink.title.contains("Watch ") && possibleLink.href.contains("click.justwatch.com"))
            {
                link = possibleLink.href;
                break;
            }
        }
        WatchProvider temp(flatrate, provider.toObject()["logo_path"].toString(),
                           provider.toObject()["provider_id"].toInt(), provider.toObject()["provider_name"].toString(),
                           link);
        watchProviders.emplace_back(temp);
    }
    for (const auto& provider : amProviders["buy"].toArray())
    {
        QString link;
        for (const auto& possibleLink : possibleLinks)
        {
            if (possibleLink.title.contains(provider.toObject()["provider_name"].toString()) &&
                possibleLink.title.contains("Buy ") && possibleLink.href.contains("click.justwatch.com"))
            {
                link = possibleLink.href;
                break;
            }
        }
        WatchProvider temp(buy, provider.toObject()["logo_path"].toString(),
                           provider.toObject()["provider_id"].toInt(), provider.toObject()["provider_name"].toString(),
                           link);
        watchProviders.emplace_back(temp);
    }
    for (const auto& provider : amProviders["rent"].toArray())
    {
        QString link;
        for (const auto& possibleLink : possibleLinks)
        {
            if (possibleLink.title.contains(provider.toObject()["provider_name"].toString()) &&
                possibleLink.title.contains("Rent ") && possibleLink.href.contains("click.justwatch.com"))
            {
                link = possibleLink.href;
                break;
            }
        }
        WatchProvider temp(rent, provider.toObject()["logo_path"].toString(),
                           provider.toObject()["provider_id"].toInt(), provider.toObject()["provider_name"].toString(),
                           link);
        watchProviders.emplace_back(temp);
    }
    return watchProviders;
}