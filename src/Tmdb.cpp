//
// Created by t on 25/05/25.
//

#include "Avatar.h"
#include <utility>

Tmdb::Tmdb(QString i_path)
{
    m_avatarPath = std::move(i_path);
}

Tmdb::Tmdb(const std::string& i_path)
{
    m_avatarPath = QString::fromStdString(i_path);
}

void Tmdb::setAvatarPath(QString i_path)
{
    m_avatarPath = std::move(i_path);
}

void Tmdb::setAvatarPath(const std::string& i_path)
{
    m_avatarPath = QString::fromStdString(i_path);
}

QString Tmdb::avatarPath() const
{
    return m_avatarPath;
}