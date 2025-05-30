//
// Created by t on 30/05/25.
//

#include "Person.h"
#include "QTMDB.h"

void tmdb::Person::setId(int i_id) {
    m_id = i_id;
}
int tmdb::Person::id() const {
    return m_id;
}

void tmdb::Person::setName(const QString &i_name) {
    m_name = i_name;
}
QString tmdb::Person::name() const {
    return m_name;
}

void tmdb::Person::setAlsoKnownAs(const std::vector<QString> &i_alsoKnownAs) {
    m_alsoKnownAs = i_alsoKnownAs;
}
std::vector<QString> tmdb::Person::alsoKnownAs() const {
    return m_alsoKnownAs;
}

void tmdb::Person::setBiography(const QString &i_biography) {
    m_biography = i_biography;
}
QString tmdb::Person::biography() const {
    return m_biography;
}

void tmdb::Person::setBirthday(const QDate &i_birthday) {
    m_birthday = i_birthday;
}
QDate tmdb::Person::birthday() const {
    return m_birthday;
}

void tmdb::Person::setDeathday(const QDate &i_deathday) {
    m_deathday = i_deathday;
}
QDate tmdb::Person::deathday() const {
    return m_deathday;
}

void tmdb::Person::setGender(const Gender& i_gender)
{
    m_gender = i_gender;
}
tmdb::Gender tmdb::Person::gender() const
{
    return m_gender;
}

void tmdb::Person::setHomepage(const QString &i_homepage) {
    m_homepage = i_homepage;
}
QString tmdb::Person::homepage() const {
    return m_homepage;
}

void tmdb::Person::setImdbId(const QString &i_imdb_id) {
    imdb_id = i_imdb_id;
}
QString tmdb::Person::imdbId() const {
    return imdb_id;
}

void tmdb::Person::setKnownFor(const QString &i_knownFor) {
    m_knownFor = i_knownFor;
}
QString tmdb::Person::knownFor() const {
    return m_knownFor;
}

void tmdb::Person::setPlaceOfBirth(const QString &i_placeOfBirth) {
    m_placeOfBirth = i_placeOfBirth;
}
QString tmdb::Person::placeOfBirth() const {
    return m_placeOfBirth;
}

void tmdb::Person::setPopularity(float i_popularity) {
    m_popularity = i_popularity;
}
float tmdb::Person::popularity() const {
    return m_popularity;
}

void tmdb::Person::setProfilePath(const QString &i_profilePath) {
    m_profilePath = i_profilePath;
}
QString tmdb::Person::profilePath() const {
    return m_profilePath;
}

tmdb::Person::Person(int i_id, QString i_name, std::vector<QString> i_alsoKnownAs,
       QString i_biography, QDate i_birthday, QDate i_death, tmdb::Gender i_gender, QString i_homepage,
       QString i_imdb_id,
       QString i_knownFor, QString i_placeOfBirth, float i_popularity, QString i_profilePath)
{
    setId(i_id);
    setName(std::move(i_name));
    setAlsoKnownAs(std::move(i_alsoKnownAs));
    setBiography(std::move(i_biography));
    setBirthday(i_birthday);
    setDeathday(i_death);
    setGender(i_gender);
    setHomepage(std::move(i_homepage));
    setImdbId(std::move(i_imdb_id));
    setKnownFor(std::move(i_knownFor));
    setPlaceOfBirth(std::move(i_placeOfBirth));
    setPopularity(i_popularity);
    setProfilePath(std::move(i_profilePath));
}

tmdb::Person::Person(const QString &i_access_token, int32_t i_personID)
{
    *this = tmdb::Person::getPerson(i_access_token, i_personID);
}

tmdb::Person::Person(const QJsonObject &i_json)
{
    setId(i_json["id"].toInt());
    setName(i_json["name"].toString());
    std::vector<QString> knownAs;
    for (const auto& name : i_json["also_known_as"].toArray()) {
        knownAs.push_back(name.toString());
    }
    setAlsoKnownAs(knownAs);
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

tmdb::Person tmdb::Person::getPerson(const QString &i_access_token, int32_t i_personID)
{
    Qtmdb q(i_access_token.toStdString());
    QJsonObject response = q.people_details(i_personID);
    return tmdb::Person(response);
}

tmdb::Credit::Credit(const QJsonObject& i_json) : Person(i_json)
{
setCharacter(i_json["character"].toString());
    setCreditID(i_json["credit_id"].toString());
}

void tmdb::Credit::setCharacter(const QString& i_character) {
    m_character = i_character;
}
QString tmdb::Credit::character() const {
    return m_character;
}

void tmdb::Credit::setCreditID(const QString& i_creditID) {
    m_creditID = i_creditID;
}
QString tmdb::Credit::creditID() const {
    return m_creditID;
}
