//
// Created by t on 30/05/25.
//

#ifndef ASYNC_NETWORK_H
#define ASYNC_NETWORK_H

#include "Country.h"


namespace tmdb::ASync::TV
{
    class Network : public QObject
    {
        Q_OBJECT

    public:
        void setHeadquarters(const QString& i_headquarters);
        [[nodiscard]] QString headquarters() const;
        void setHomepage(const QString& i_homepage);
        [[nodiscard]] QString homepage() const;
        void setId(int i_id);
        [[nodiscard]] int id() const;
        void setLogoPath(const QString& i_logoPath);
        [[nodiscard]] QString logoPath() const;
        void setName(const QString& i_name);
        [[nodiscard]] QString name() const;
        void setOriginCountry( tmdb::ASync::Country* i_originCountry);
        [[nodiscard]] tmdb::ASync::Country* originCountry() const;

        Network();
        explicit Network(const QString& i_access_token);
        Network(const QString& i_access_token, int32_t i_networkID);
        ~Network() override = default;
        Network(const QJsonObject& i_json, const QString& i_access_token );
    protected:
        void parseJson(const QJsonObject& i_json, const QString& i_access_token);
    public slots:
        void loadNetwork(int32_t i_networkID);

    private slots:
        void startedLoadingNetworkReceived();
        void finishedLoadingNetworkReceived(void* i_data);

    signals:
        void startedLoadingNetwork();
        void finishedLoadingNetwork(tmdb::ASync::TV::Network* i_network);

    protected:
        aQtmdb m_q;
        QString m_headquarters;
        QString m_homepage;
        int m_id = 0;
        QString m_logoPath;
        QString m_name;
        tmdb::ASync::Country* m_originCountry = nullptr;
    };
}


#endif //ASYNC_NETWORK_H
