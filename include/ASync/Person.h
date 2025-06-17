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
        explicit Person(const QString& i_access_token);
        Person(const QString& i_access_token, int32_t i_personID);
        ~Person() override = default;
        Person(const QJsonObject& i_json, const QString& i_access_token);
    protected:
        void parseJson(const QJsonObject& i_json, const QString& i_access_token);
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
        std::vector<QString> m_alsoKnownAs = {};
        QString m_biography = "BLANK_BIOGRAPHY";
        QDate m_birthday = QDate();
        QDate m_deathday = QDate();
        Gender m_gender = NA;
        QString m_homepage = "BLANK_HOMEPAGE";
        int m_id = 0;
        QString imdb_id = "BLANK_IMDB_ID";
        QString m_knownFor = "BLANK_KNOWN_FOR";
        QString m_name = "BLANK_NAME";
        QString m_placeOfBirth = "BLANK_PLACE_OF_BIRTH";
        float m_popularity = 0.0f;
        QString m_profilePath = "BLANK_PROFILE_PATH";
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
        Credit(const QJsonObject& i_json, const QString& i_access_token);
    };
}

#endif //ASYNC_PERSON_H
