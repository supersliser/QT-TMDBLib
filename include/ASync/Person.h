//
// Created by t on 30/05/25.
//

#ifndef ASYNC_PERSON_H
#define ASYNC_PERSON_H
#include "Config.h"

namespace tmdb::ASync
{
    enum Gender
    {
        NA = 0,
        female,
        male,
        nonBinary,
    };

    class Person : public QObject
    {
        Q_OBJECT

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

        Person();
        Person(const QString& i_access_token, int32_t i_personID);
        ~Person() override = default;

        static Person* fromJSON(const QJsonObject& i_json);

    public slots:
        void loadPerson(int32_t i_personID);

    private slots:
        void startedLoadingPersonReceived();
        void finishedLoadingPersonReceived(void* i_data);

    signals:
        void startedLoadingPerson();
        void finishedLoadingPerson(tmdb::ASync::Person* i_person);

    protected:
        aQtmdb m_q;
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

    class Credit : public Person
    {
    protected:
        QString m_character;
        QString m_creditID;

    public:
        void setCharacter(const QString& i_character);
        [[nodiscard]] QString character() const;
        void setCreditID(const QString& i_creditID);
        [[nodiscard]] QString creditID() const;
    };
}

#endif //ASYNC_PERSON_H
