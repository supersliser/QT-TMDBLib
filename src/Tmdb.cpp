//
// Created by t on 25/05/25.
//

#include "Sync/Avatar.h"
#include <utility>

tmdb::Tmdb::Tmdb(QString i_path)
{
    m_avatarPath = std::move(i_path);
}

tmdb::Tmdb::Tmdb(const std::string& i_path)
{
    m_avatarPath = QString::fromStdString(i_path);
}

void tmdb::Tmdb::setAvatarPath(QString i_path)
{
    m_avatarPath = std::move(i_path);
}

void tmdb::Tmdb::setAvatarPath(const std::string& i_path)
{
    m_avatarPath = QString::fromStdString(i_path);
}

QString tmdb::Tmdb::avatarPath() const
{
    return m_avatarPath;
}