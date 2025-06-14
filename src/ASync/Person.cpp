//
// Created by t on 30/05/25.
//

#include "ASync/Person.h"
#include "ASync/QTMDB.h"

void tmdb::ASync::Person::setId(int i_id)
{
    m_id = i_id;
}

int tmdb::ASync::Person::id() const
{
    return m_id;
}

void tmdb::ASync::Person::setName(const QString& i_name)
{
    m_name = i_name;
}

QString tmdb::ASync::Person::name() const
{
    return m_name;
}

void tmdb::ASync::Person::setAlsoKnownAs(const std::vector<QString>& i_alsoKnownAs)
{
    m_alsoKnownAs = i_alsoKnownAs;
}

std::vector<QString> tmdb::ASync::Person::alsoKnownAs() const
{
    return m_alsoKnownAs;
}

void tmdb::ASync::Person::setBiography(const QString& i_biography)
{
    m_biography = i_biography;
}

QString tmdb::ASync::Person::biography() const
{
    return m_biography;
}

void tmdb::ASync::Person::setBirthday(const QDate& i_birthday)
{
    m_birthday = i_birthday;
}

QDate tmdb::ASync::Person::birthday() const
{
    return m_birthday;
}

void tmdb::ASync::Person::setDeathday(const QDate& i_deathday)
{
    m_deathday = i_deathday;
}

QDate tmdb::ASync::Person::deathday() const
{
    return m_deathday;
}

void tmdb::ASync::Person::setGender(const Gender& i_gender)
{
    m_gender = i_gender;
}

tmdb::ASync::Gender tmdb::ASync::Person::gender() const
{
    return m_gender;
}

void tmdb::ASync::Person::setHomepage(const QString& i_homepage)
{
    m_homepage = i_homepage;
}

QString tmdb::ASync::Person::homepage() const
{
    return m_homepage;
}

void tmdb::ASync::Person::setImdbId(const QString& i_imdb_id)
{
    imdb_id = i_imdb_id;
}

QString tmdb::ASync::Person::imdbId() const
{
    return imdb_id;
}

void tmdb::ASync::Person::setKnownFor(const QString& i_knownFor)
{
    m_knownFor = i_knownFor;
}

QString tmdb::ASync::Person::knownFor() const
{
    return m_knownFor;
}

void tmdb::ASync::Person::setPlaceOfBirth(const QString& i_placeOfBirth)
{
    m_placeOfBirth = i_placeOfBirth;
}

QString tmdb::ASync::Person::placeOfBirth() const
{
    return m_placeOfBirth;
}

void tmdb::ASync::Person::setPopularity(float i_popularity)
{
    m_popularity = i_popularity;
}

float tmdb::ASync::Person::popularity() const
{
    return m_popularity;
}

void tmdb::ASync::Person::setProfilePath(const QString& i_profilePath)
{
    m_profilePath = i_profilePath;
}

QString tmdb::ASync::Person::profilePath() const
{
    return m_profilePath;
}

tmdb::ASync::Person::Person() : m_q("")
{
    m_q.setParent(this);
}

tmdb::ASync::Person::Person(const QString& i_access_token) : m_q(i_access_token.toStdString())
{
    m_q.setParent(this);
}

tmdb::ASync::Person::Person(const QString& i_access_token, int32_t i_personID) : Person(i_access_token)
{
    loadPerson(i_personID);
}

void tmdb::ASync::Credit::setCharacter(const QString& i_character)
{
    m_character = i_character;
}

QString tmdb::ASync::Credit::character() const
{
    return m_character;
}

void tmdb::ASync::Credit::setCreditID(const QString& i_creditID)
{
    m_creditID = i_creditID;
}

QString tmdb::ASync::Credit::creditID() const
{
    return m_creditID;
}

tmdb::ASync::Person::Person(const QJsonObject& i_json, const QString& i_access_token) : Person(i_access_token)
{
    parseJson(i_json, i_access_token);
}

void tmdb::ASync::Person::parseJson(const QJsonObject& i_json, const QString& i_access_token)
{
    setId(i_json["id"].toInt());
    setName(i_json["name"].toString());
    std::vector<QString> i_alsoKnownAs;
    for (const auto& name : i_json["also_known_as"].toArray()) {
        i_alsoKnownAs.push_back(name.toString());
    }
    setAlsoKnownAs(i_alsoKnownAs);
    setBiography(i_json["biography"].toString());
    setBirthday(QDate::fromString(i_json["birthday"].toString(), Qt::ISODate));
    setDeathday(QDate::fromString(i_json["deathday"].toString(), Qt::ISODate));
    setGender(static_cast<Gender>(i_json["gender"].toInt()));
    setHomepage(i_json["homepage"].toString());
    setImdbId(i_json["imdb_id"].toString());
    setKnownFor(i_json["known_for_department"].toString());
    setPlaceOfBirth(i_json["place_of_birth"].toString());
    setPopularity(i_json["popularity"].toDouble());
    setProfilePath(i_json["profile_path"].toString());
}

void tmdb::ASync::Person::loadPerson(int32_t i_personID)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &tmdb::ASync::Person::startedLoadingPersonReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &tmdb::ASync::Person::finishedLoadingPersonReceived);
    m_q.people_details(i_personID);
}

void tmdb::ASync::Person::startedLoadingPersonReceived()
{
    emit startedLoadingPerson();
}

void tmdb::ASync::Person::finishedLoadingPersonReceived(void* i_data)
{
    parseJson(*static_cast<QJsonObject*>(i_data), m_q.accessToken().c_str());
    emit finishedLoadingPerson(this);
}

tmdb::ASync::Credit::Credit(const QJsonObject& i_json, const QString& i_access_token) : Person(i_access_token)
{
    setCreditID(i_json["credit_id"].toString());
    setCharacter(i_json["character"].toString());
}
