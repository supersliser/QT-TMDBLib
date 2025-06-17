//
// Created by t on 25/05/25.
//

#ifndef ASYNC_ADULT_H
#define ASYNC_ADULT_H
#include <QJsonObject>

#include "Sync/Avatar.h"
#include "QTMDB.h"

namespace tmdb::ASync
{
    class Account : public QObject
    {
        Q_OBJECT

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

        Account();
        explicit Account(const QString& i_access_token);
        Account(const QJsonObject& i_json, const QString& i_access_token);
        Account(const QString& i_access_token, int32_t i_accountID);


        ~Account() override = default;
    protected:
        void parseJson(const QJsonObject& i_json, const QString& i_access_token);

    public slots:
        void loadAccount(int32_t i_accountID);

    private slots:
        void startedLoadingAccountReceived();
        void finishedLoadingAccountReceived(void* i_data);

    signals:
        void startedLoadingAccount();
        void finishedLoadingAccount(tmdb::ASync::Account* i_account);

    protected:
        aQtmdb m_q;
        Avatar m_avatar;
        int32_t m_id = 0;
        QString m_iso_639_1 = "BLANK_ISO_639_1";
        QString m_iso_3166_1 = "BLANK_ISO_3166_1";
        QString m_name = "BLANK_NAME";
        QString m_username = "BLANK_USERNAME";
        bool m_include_adult = true;
    };
}

#endif //ASYNC_ADULT_H
