//
// Created by t on 25/05/25.
//

#include "Sync/Avatar.h"
#include <utility>

tmdb::Gravatar::Gravatar(QString i_hash)
{
    m_hash = std::move(i_hash);
}

tmdb::Gravatar::Gravatar(const std::string& i_hash)
{
    m_hash = QString::fromStdString(i_hash);
}

void tmdb::Gravatar::setHash(QString i_hash)
{
    m_hash = std::move(i_hash);
}

void tmdb::Gravatar::setHash(const std::string& i_hash)
{
    m_hash = QString::fromStdString(i_hash);
}

QString tmdb::Gravatar::hash() const
{
    return m_hash;
}