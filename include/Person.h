//
// Created by t on 30/05/25.
//

#ifndef PERSON_H
#define PERSON_H
#include <QDate>
#include <QString>

#include "Config.h"

namespace tmdb
{
    enum Gender
    {
        NA = 0,
        female,
        male,
        nonBinary,
    };

    class Person
    {
    public:
        void setId(int i_id);
        [[nodiscard]] int id() const;
        void setName(const QString& i_name);
        [[nodiscard]] QString name() const;
        void setAlsoKnownAs(const std::vector<QString>& i_alsoKnownAs);
        [[nodiscard]] std::vector<QString> alsoKnownAs() const;
        void setBiography(const QString& i_biography);
        [[nodiscard]] QString biography() const;
        void setBirthday(const QDate& i_birthday);
        [[nodiscard]] QDate birthday() const;
        void setDeathday(const QDate& i_deathday);
        [[nodiscard]] QDate deathday() const;
        void setGender(const Gender& i_gender);
        [[nodiscard]] Gender gender() const;
        void setHomepage(const QString& i_homepage);
        [[nodiscard]] QString homepage() const;
        void setImdbId(const QString& i_imdb_id);
        [[nodiscard]] QString imdbId() const;
        void setKnownFor(const QString& i_knownFor);
        [[nodiscard]] QString knownFor() const;
        void setPlaceOfBirth(const QString& i_placeOfBirth);
        [[nodiscard]] QString placeOfBirth() const;
        void setPopularity(float i_popularity);
        [[nodiscard]] float popularity() const;
        void setProfilePath(const QString& i_profilePath);
        [[nodiscard]] QString profilePath() const;

        Person() = default;
        Person(int i_id, QString i_name, std::vector<QString> i_alsoKnownAs,
               QString i_biography, QDate i_birthday, QDate i_death, Gender i_gender, QString i_homepage,
               QString i_imdb_id,
               QString i_knownFor, QString i_placeOfBirth, float i_popularity, QString i_profilePath);
        Person(const QString& i_access_token, int32_t i_personID);
        explicit Person(const QJsonObject& i_json);
        ~Person() = default;

        static Person getPerson(const QString& i_access_token, int32_t i_genreID);

    protected:
        bool m_idAdult = true;
        std::vector<QString> m_alsoKnownAs;
        QString m_biography;
        QDate m_birthday;
        QDate m_deathday;
        Gender m_gender = Gender::NA;
        QString m_homepage;
        int m_id = 0;
        QString imdb_id;
        QString m_knownFor;
        QString m_name;
        QString m_placeOfBirth;
        float m_popularity = 0.0f;
        QString m_profilePath;
    };
}

#endif //PERSON_H
