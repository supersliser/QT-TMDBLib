//
// Created by t on 25/05/25.
//

#ifndef ADULT_H
#define ADULT_H
#include <QJsonObject>

#include "Avatar.h"

class Account
{
public:
    void setAvatar(const Avatar* i_avatar);
    [[nodiscard]] Avatar* avatar() const;
    void setID(int i_id);
    [[nodiscard]] int id() const;
    void setISO6391(const QString& i_iso_639_1);
    [[nodiscard]] QString iso6391() const;
    void setISO31661(const QString& i_iso_3166_1);
    [[nodiscard]] QString iso31661() const;
    void setName(const QString& i_name);
    [[nodiscard]] QString name() const;
    void setUsername(const QString& i_username);
    [[nodiscard]] QString username() const;
    void setIncludeAdult(bool i_include_adult);
    [[nodiscard]] bool includeAdult() const;

    Account() = default;
    Account(int i_id, const QString& i_iso_639_1, const QString& i_iso_3166_1, const QString& i_name,
            const QString& i_username, bool i_include_adult = true);
    explicit Account(const QString& i_access_token, int32_t i_accountID);
    explicit Account(const QJsonObject& i_json);

    static Account getAccount(const QString& i_access_token, int32_t i_accountID);

    ~Account() = default;
protected:
    Avatar m_avatar;
    int32_t m_id = 0;
    QString m_iso_639_1;
    QString m_iso_3166_1;
    QString m_name;
    QString m_username;
    bool m_include_adult = true;
};

#endif //ADULT_H
