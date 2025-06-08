//
// Created by t on 25/05/25.
//

#include "Sync/Account.h"

tmdb::Avatar::Avatar(const Gravatar& i_gravatar, const Tmdb& i_tmdb)
{
    m_gravatar = i_gravatar;
    m_tmdb = i_tmdb;
}

tmdb::Avatar::Avatar(const QString& i_gravatar_hash, const QString& i_tmdb_path)
{
    m_gravatar.setHash(i_gravatar_hash);
    m_tmdb.setAvatarPath(i_tmdb_path);
}

void tmdb::Avatar::setGravatar(const Gravatar* i_gravatar)
{
    m_gravatar = *i_gravatar;
}

void tmdb::Avatar::setTmdb(const Tmdb* i_tmdb)
{
    m_tmdb = *i_tmdb;
}

tmdb::Gravatar& tmdb::Avatar::gravatar()
{
    return m_gravatar;
}

tmdb::Tmdb& tmdb::Avatar::tmdb()
{
    return m_tmdb;
}