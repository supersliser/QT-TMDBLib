//
// Created by t on 25/05/25.
//

#include "Avatar.h"
#include <utility>

Gravatar::Gravatar(QString i_hash)
{
    m_hash = std::move(i_hash);
}

Gravatar::Gravatar(const std::string& i_hash)
{
    m_hash = QString::fromStdString(i_hash);
}

void Gravatar::setHash(QString i_hash)
{
    m_hash = std::move(i_hash);
}

void Gravatar::setHash(const std::string& i_hash)
{
    m_hash = QString::fromStdString(i_hash);
}

QString Gravatar::hash() const
{
    return m_hash;
}