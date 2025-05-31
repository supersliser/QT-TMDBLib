//
// Created by t on 30/05/25.
//

#ifndef NETWORK_H
#define NETWORK_H
#include "Config.h"

namespace tmdb
{
    namespace TV
    {
        class Network
        {
        public:
            void setHeadquarters(const QString &i_headquarters);
            [[nodiscard]] QString headquarters() const;
            void setHomepage(const QString &i_homepage);
            [[nodiscard]] QString homepage() const;
            void setId(int i_id);
            [[nodiscard]] int id() const;
            void setLogoPath(const QString &i_logoPath);
            [[nodiscard]] QString logoPath() const;
            void setName(const QString &i_name);
            [[nodiscard]] QString name() const;
            void setOriginCountry(const tmdb::config::country &i_originCountry);
            [[nodiscard]] tmdb::config::country originCountry() const;

            Network() = default;
            Network(const QString &i_headquarters, const QString &i_homepage, int id,
                    const QString &i_logoPath, const QString &i_name,
                    const tmdb::config::country &i_originCountry);
            Network(const QString& i_access_token, int32_t i_networkID);
            explicit Network(const QJsonObject &i_json);
            ~Network() = default;

            static Network getNetwork(const QString& i_access_token, int32_t i_networkID);


        protected:
            QString m_headquarters;
            QString m_homepage;
            int m_id = 0;
            QString m_logoPath;
            QString m_name;
            tmdb::config::country m_originCountry;
        };
    }
}

#endif //NETWORK_H
