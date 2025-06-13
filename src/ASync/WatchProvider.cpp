//
// Created by t on 27/05/25.
//

#include "ASync/WatchProvider.h"
#include "ASync/QTMDB.h"

using namespace tmdb::ASync;

void tmdb::ASync::WatchProvider::setType(ProviderType i_type)
{
    m_type = i_type;
}

tmdb::ASync::ProviderType tmdb::ASync::WatchProvider::type() const
{
    return m_type;
}

void tmdb::ASync::WatchProvider::setLogoPath(const QString& i_logoPath)
{
    m_logoPath = i_logoPath;
}

QString tmdb::ASync::WatchProvider::logoPath() const
{
    return m_logoPath;
}

void tmdb::ASync::WatchProvider::setProviderID(int i_providerID)
{
    m_providerID = i_providerID;
}

int tmdb::ASync::WatchProvider::providerID() const
{
    return m_providerID;
}

void tmdb::ASync::WatchProvider::setProviderName(const QString& i_providerName)
{
    m_providerName = i_providerName;
}

QString tmdb::ASync::WatchProvider::providerName() const
{
    return m_providerName;
}

void tmdb::ASync::WatchProvider::setLink(const QUrl& i_link)
{
    m_link = i_link;
}

QUrl tmdb::ASync::WatchProvider::link() const
{
    return m_link;
}

tmdb::ASync::WatchProvider::WatchProvider()
    : m_q("")
{
    m_q.setParent(this);
}

tmdb::ASync::WatchProvider::WatchProvider(const QString& i_access_token, int i_providerID) : m_q(
    i_access_token.toStdString())
{
    m_q.setParent(this);
    loadWatchProvider(i_providerID);
}

tmdb::ASync::WatchProvider* tmdb::ASync::WatchProvider::fromJSON(const QJsonObject& i_json)
{
    auto* provider = new WatchProvider();
    provider->setLogoPath(i_json["logo_path"].toString());
    provider->setProviderID(i_json["provider_id"].toInt());
    provider->setProviderName(i_json["provider_name"].toString());
    return provider;
}

void tmdb::ASync::WatchProvider::loadWatchProvider(int i_providerID)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &WatchProvider::startedLoadingWatchProviderReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &WatchProvider::finishedLoadingWatchProviderReceived);
    m_q.watchProviders_movie();
}

void tmdb::ASync::WatchProvider::startedLoadingWatchProviderReceived()
{
    emit startedLoadingWatchProvider();
}

void tmdb::ASync::WatchProvider::finishedLoadingWatchProviderReceived(void* i_data)
{
    if (m_tempData == nullptr)
    {
        auto* data = static_cast<QJsonObject*>(i_data);
        m_tempData = data;
        if (data->contains("results"))
        {
            auto results = data->value("results").toArray();
            for (const auto& result : results)
            {
                auto provider = result.toObject();
                if (provider["provider_id"].toInt() == m_providerID)
                {
                    setLogoPath(provider["logo_path"].toString());
                    setProviderID(provider["provider_id"].toInt());
                    setProviderName(provider["provider_name"].toString());
                    emit finishedLoadingWatchProvider(this);
                    disconnect(&m_q, &aQtmdb::startedLoadingData, this,
                               &WatchProvider::startedLoadingWatchProviderReceived);
                    disconnect(&m_q, &aQtmdb::finishedLoadingData, this,
                               &WatchProvider::finishedLoadingWatchProviderReceived);
                    return;
                }
            }
        }
        m_q.watchProviders_tv();
    }
    else
    {
        auto* data = static_cast<QJsonObject*>(i_data);
        m_tempData = data;
        if (data->contains("results"))
        {
            auto results = data->value("results").toArray();
            for (const auto& result : results)
            {
                auto provider = result.toObject();
                if (provider["provider_id"].toInt() == m_providerID)
                {
                    setLogoPath(provider["logo_path"].toString());
                    setProviderID(provider["provider_id"].toInt());
                    setProviderName(provider["provider_name"].toString());
                    emit finishedLoadingWatchProvider(this);
                    disconnect(&m_q, &aQtmdb::startedLoadingData, this,
                               &WatchProvider::startedLoadingWatchProviderReceived);
                    disconnect(&m_q, &aQtmdb::finishedLoadingData, this,
                               &WatchProvider::finishedLoadingWatchProviderReceived);
                    return;
                }
            }
        }
        emit finishedLoadingWatchProvider(nullptr);
    }
}

void tmdb::ASync::WatchProvider::loadAllWatchProviders(Language* i_language)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &WatchProvider::startedLoadingAllWatchProvidersReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &WatchProvider::finishedLoadingAllWatchProvidersReceived);
    m_tempLanguage = i_language;
    m_q.watchProviders_movie(i_language->iso6391().toStdString());
}

void tmdb::ASync::WatchProvider::startedLoadingAllWatchProvidersReceived()
{
    emit startedLoadingAllWatchProviders();
}

void tmdb::ASync::WatchProvider::finishedLoadingAllWatchProvidersReceived(void* i_data)
{
    if (m_tempData == nullptr)
    {
        auto* data = static_cast<QJsonObject*>(i_data);
        m_tempData = data;
        m_q.watchProviders_tv(m_tempLanguage->iso6391().toStdString());
    }
    else
    {
        auto* data = static_cast<QJsonObject*>(i_data);
        auto results = data->value("results").toArray();
        auto providers = std::vector<WatchProvider*>();
        for (const auto& result : results)
        {
            providers.push_back(fromJSON(result.toObject()));
        }
        for (const auto result : m_tempData->value("results").toArray())
        {
            providers.push_back(fromJSON(result.toObject()));
        }
        emit finishedLoadingAllWatchProviders(providers);
    }
}

void tmdb::ASync::WatchProvider::loadAllMovieProviders(const Language* i_language)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &WatchProvider::startedLoadingAllMovieProvidersReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &WatchProvider::finishedLoadingAllMovieProvidersReceived);
    m_q.watchProviders_movie(i_language->iso6391().toStdString());
}
void tmdb::ASync::WatchProvider::startedLoadingAllMovieProvidersReceived()
{
    emit startedLoadingAllMovieProviders();
}
void tmdb::ASync::WatchProvider::finishedLoadingAllMovieProvidersReceived(void* i_data)
{
    auto* data = static_cast<QJsonObject*>(i_data);
    m_tempData = data;
    if (data->contains("results"))
    {
        auto results = data->value("results").toArray();
        auto providers = std::vector<WatchProvider*>();
        providers.reserve(results.size());
        for (const auto& result : results)
        {
            providers.push_back(fromJSON(result.toObject()));
        }
        emit finishedLoadingAllMovieProviders(providers);
    }
}

void tmdb::ASync::WatchProvider::loadAllTVProviders(const Language* i_language)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &WatchProvider::startedLoadingAllTVProvidersReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &WatchProvider::finishedLoadingAllTVProvidersReceived);
    m_q.watchProviders_tv(i_language->iso6391().toStdString());
}

void tmdb::ASync::WatchProvider::startedLoadingAllTVProvidersReceived()
{
    emit startedLoadingAllTVProviders();
}

void tmdb::ASync::WatchProvider::finishedLoadingAllTVProvidersReceived(void* i_data)
{
    auto* data = static_cast<QJsonObject*>(i_data);
    m_tempData = data;
    if (data->contains("results"))
    {
        auto results = data->value("results").toArray();
        auto providers = std::vector<WatchProvider*>();
        providers.reserve(results.size());
        for (const auto& result : results)
        {
            providers.push_back(fromJSON(result.toObject()));
        }
        emit finishedLoadingAllTVProviders(providers);
    }
}

void tmdb::ASync::WatchProvider::loadWatchProvidersForMovie(const QString& i_language, int i_movieID)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &WatchProvider::startedLoadingWatchProvidersForMovieReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &WatchProvider::finishedLoadingWatchProvidersForMovieReceived);
    m_q.movie_watchProviders(i_movieID);
}
void tmdb::ASync::WatchProvider::startedLoadingWatchProvidersForMovieReceived()
{
    emit startedLoadingWatchProvidersForMovie();
}
void tmdb::ASync::WatchProvider::finishedLoadingWatchProvidersForMovieReceived(void* i_data)
{
    auto* data = static_cast<QJsonObject*>(i_data);
    m_tempData = data;
    if (data->contains("results"))
    {
        auto amProviders = data->value("results").toObject();
        auto watchProviders = std::vector<WatchProvider*>();
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
            WatchProvider temp;
            temp.setType(flatrate);
            temp.setLogoPath(provider.toObject()["logo_path"].toString());
            temp.setProviderID(provider.toObject()["provider_id"].toInt());
            temp.setProviderName(provider.toObject()["provider_name"].toString());
            temp.setLink(link);
            watchProviders.push_back(&temp);
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
            WatchProvider temp;
            temp.setType(buy);
            temp.setLogoPath(provider.toObject()["logo_path"].toString());
            temp.setProviderID(provider.toObject()["provider_id"].toInt());
            temp.setProviderName(provider.toObject()["provider_name"].toString());
            temp.setLink(link);
            watchProviders.push_back(&temp);
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
            WatchProvider temp;
            temp.setType(rent);
            temp.setLogoPath(provider.toObject()["logo_path"].toString());
            temp.setProviderID(provider.toObject()["provider_id"].toInt());
            temp.setProviderName(provider.toObject()["provider_name"].toString());
            temp.setLink(link);
            watchProviders.push_back(&temp);
        }
        emit finishedLoadingWatchProvidersForMovie(watchProviders);
        disconnect(&m_q, &aQtmdb::startedLoadingData, this,
                   &WatchProvider::startedLoadingWatchProvidersForMovieReceived);
        disconnect(&m_q, &aQtmdb::finishedLoadingData, this,
                   &WatchProvider::finishedLoadingWatchProvidersForMovieReceived);
    }
}

void tmdb::ASync::WatchProvider::loadWatchProvidersForTV(const QString& i_language, int i_seriesID)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &WatchProvider::startedLoadingWatchProvidersForTVReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &WatchProvider::finishedLoadingWatchProvidersForTVReceived);
    m_q.tv_series_watchProviders(i_seriesID);
}
void tmdb::ASync::WatchProvider::startedLoadingWatchProvidersForTVReceived()
{
    emit startedLoadingWatchProvidersForTV();
}
void tmdb::ASync::WatchProvider::finishedLoadingWatchProvidersForTVReceived(void* i_data)
{
    auto* data = static_cast<QJsonObject*>(i_data);
    m_tempData = data;
    if (data->contains("results"))
    {
        auto amProviders = data->value("results").toObject();
        auto watchProviders = std::vector<WatchProvider*>();
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
            WatchProvider temp;
            temp.setType(flatrate);
            temp.setLogoPath(provider.toObject()["logo_path"].toString());
            temp.setProviderID(provider.toObject()["provider_id"].toInt());
            temp.setProviderName(provider.toObject()["provider_name"].toString());
            temp.setLink(link);
            watchProviders.push_back(&temp);
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
            WatchProvider temp;
            temp.setType(buy);
            temp.setLogoPath(provider.toObject()["logo_path"].toString());
            temp.setProviderID(provider.toObject()["provider_id"].toInt());
            temp.setProviderName(provider.toObject()["provider_name"].toString());
            temp.setLink(link);
            watchProviders.push_back(&temp);
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
            WatchProvider temp;
            temp.setType(rent);
            temp.setLogoPath(provider.toObject()["logo_path"].toString());
            temp.setProviderID(provider.toObject()["provider_id"].toInt());
            temp.setProviderName(provider.toObject()["provider_name"].toString());
            temp.setLink(link);
            watchProviders.push_back(&temp);
        }
        emit finishedLoadingWatchProvidersForTV(watchProviders);
        disconnect(&m_q, &aQtmdb::startedLoadingData, this,
                   &WatchProvider::startedLoadingWatchProvidersForTVReceived);
        disconnect(&m_q, &aQtmdb::finishedLoadingData, this,
                   &WatchProvider::finishedLoadingWatchProvidersForTVReceived);
    }
}