//
// Created by t on 25/05/25.
//

#ifndef AVATAR_H
#define AVATAR_H
#include <QString>

class Gravatar
{
public:
    explicit Gravatar(QString i_hash);
    explicit Gravatar(const std::string& i_hash);
    Gravatar() = default;
    ~Gravatar() = default;

    void setHash(QString i_hash);
    void setHash(const std::string& i_hash);
    [[nodiscard]] QString hash() const;

protected:
    QString m_hash = "";
};

class Tmdb
{
public:
    Tmdb() = default;
    explicit Tmdb(QString i_path);
    explicit Tmdb(const std::string& i_path);
    ~Tmdb() = default;

    void setAvatarPath(QString i_path);
    void setAvatarPath(const std::string& i_path);
    [[nodiscard]] QString avatarPath() const;

protected:
    QString m_avatarPath = "";
};

class Avatar
{
public:
    Avatar() = default;
    Avatar(const Gravatar& i_gravatar, const Tmdb& i_tmdb);
    Avatar(const QString& i_gravatar_hash, const QString& i_tmdb_path);
    ~Avatar() = default;

    void setGravatar(const Gravatar* i_gravatar);
    void setTmdb(const Tmdb* i_tmdb);
    [[nodiscard]] Gravatar& gravatar();
    [[nodiscard]] Tmdb& tmdb();

protected:
    Gravatar m_gravatar;
    Tmdb m_tmdb;
};

#endif //AVATAR_H
