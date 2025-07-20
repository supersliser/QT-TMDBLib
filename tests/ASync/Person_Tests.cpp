//
// Created by t on 30/05/25.
//

#include <QApplication>

#include "ASync/Person.h"
#include <gtest/gtest.h>

#include "ASync/QTMDB.h"
using namespace tmdb::ASync;

TEST(PersonASyncTests, DefaultConstructor)
{
    Person person;
    EXPECT_EQ(person.id(), 0);
    EXPECT_STREQ(person.name().toStdString().c_str(), "BLANK_NAME");
    EXPECT_TRUE(person.alsoKnownAs().empty());
    EXPECT_STREQ(person.biography().toStdString().c_str(), "BLANK_BIOGRAPHY");
    EXPECT_EQ(person.birthday(), QDate());
    EXPECT_EQ(person.deathday(), QDate());
    EXPECT_EQ(person.gender(), Gender::NA);
    EXPECT_STREQ(person.homepage().toStdString().c_str(), "BLANK_HOMEPAGE");
    EXPECT_STREQ(person.imdbId().toStdString().c_str(), "BLANK_IMDB_ID");
    EXPECT_STREQ(person.knownFor().toStdString().c_str(), "BLANK_KNOWN_FOR");
    EXPECT_STREQ(person.placeOfBirth().toStdString().c_str(), "BLANK_PLACE_OF_BIRTH");
    EXPECT_FLOAT_EQ(person.popularity(), 0.0f);
    EXPECT_STREQ(person.profilePath().toStdString().c_str(), "BLANK_PROFILE_PATH");
}

TEST(PersonASyncTests, APIConstructor)
{
    bool f = false;
    Person* person = new Person(std::getenv("API_KEY"));
    QObject::connect(person, &Person::finishedLoadingPerson, [&f](Person* p)
    {
        EXPECT_EQ(p->id(), 31);
        EXPECT_STREQ(p->name().toStdString().c_str(), "Tom Hanks");
        EXPECT_GT(p->alsoKnownAs().size(), 1);
        EXPECT_STREQ(p->biography().toStdString().c_str(),
                     "Thomas Jeffrey Hanks (born July 9, 1956) is an American actor and filmmaker. Known for both his comedic and dramatic roles, Hanks is one of the most popular and recognizable film stars worldwide, and is widely regarded as an American cultural icon.\n\nHanks made his breakthrough with leading roles in the comedies Splash (1984) and Big (1988). He won two consecutive Academy Awards for Best Actor for starring as a gay lawyer suffering from AIDS in Philadelphia (1993) and a young man with below-average IQ in Forrest Gump (1994). Hanks collaborated with film director Steven Spielberg on five films: Saving Private Ryan (1998), Catch Me If You Can (2002), The Terminal (2004), Bridge of Spies (2015), and The Post (2017), as well as the 2001 miniseries Band of Brothers, which launched him as a director, producer, and screenwriter.\n\nHanks' other notable films include the romantic comedies Sleepless in Seattle (1993) and You've Got Mail (1998); the dramas Apollo 13 (1995), The Green Mile (1999), Cast Away (2000), Road to Perdition (2002), and Cloud Atlas (2012); and the biographical dramas Saving Mr. Banks (2013), Captain Phillips (2013), Sully (2016), and A Beautiful Day in the Neighborhood (2019). He has also appeared as the title character in the Robert Langdon film series, and has voiced Sheriff Woody in the Toy Story film series.\n\nDescription above from the Wikipedia article Tom Hanks, licensed under CC-BY-SA, full list of contributors on Wikipedia.");
        EXPECT_EQ(p->birthday(), QDate(1956, 7, 9));
        EXPECT_EQ(p->deathday(), QDate());
        EXPECT_EQ(p->gender(), 2);
        EXPECT_STREQ(p->homepage().toStdString().c_str(), "");
        EXPECT_STREQ(p->imdbId().toStdString().c_str(), "nm0000158");
        EXPECT_STREQ(p->knownFor().toStdString().c_str(), "Acting");
        EXPECT_STREQ(p->placeOfBirth().toStdString().c_str(), "Concord, California, USA");
        EXPECT_GT(p->popularity(), 0.0f);
        EXPECT_FALSE(p->profilePath().isNull());
        f = true;
    });
    person->loadPerson(31);
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(PersonASyncTests, APIJSON)
{
    bool f = false;
    aQtmdb q(std::getenv("API_KEY"));
    QObject::connect(&q, &aQtmdb::finishedLoadingData, [&f](void* response)
    {
        QJsonObject data = *static_cast<QJsonObject*>(response);
        EXPECT_FALSE(data.isEmpty());
        Person* person = new Person(data, std::getenv("API_KEY"));
        EXPECT_EQ(person->id(), 31);
        EXPECT_STREQ(person->name().toStdString().c_str(), "Tom Hanks");
        EXPECT_GT(person->alsoKnownAs().size(), 1);
        EXPECT_STREQ(person->biography().toStdString().c_str(),
                     "Thomas Jeffrey Hanks (born July 9, 1956) is an American actor and filmmaker. Known for both his comedic and dramatic roles, Hanks is one of the most popular and recognizable film stars worldwide, and is widely regarded as an American cultural icon.\n\nHanks made his breakthrough with leading roles in the comedies Splash (1984) and Big (1988). He won two consecutive Academy Awards for Best Actor for starring as a gay lawyer suffering from AIDS in Philadelphia (1993) and a young man with below-average IQ in Forrest Gump (1994). Hanks collaborated with film director Steven Spielberg on five films: Saving Private Ryan (1998), Catch Me If You Can (2002), The Terminal (2004), Bridge of Spies (2015), and The Post (2017), as well as the 2001 miniseries Band of Brothers, which launched him as a director, producer, and screenwriter.\n\nHanks' other notable films include the romantic comedies Sleepless in Seattle (1993) and You've Got Mail (1998); the dramas Apollo 13 (1995), The Green Mile (1999), Cast Away (2000), Road to Perdition (2002), and Cloud Atlas (2012); and the biographical dramas Saving Mr. Banks (2013), Captain Phillips (2013), Sully (2016), and A Beautiful Day in the Neighborhood (2019). He has also appeared as the title character in the Robert Langdon film series, and has voiced Sheriff Woody in the Toy Story film series.\n\nDescription above from the Wikipedia article Tom Hanks, licensed under CC-BY-SA, full list of contributors on Wikipedia.");
        EXPECT_EQ(person->birthday(), QDate(1956, 7, 9));
        EXPECT_EQ(person->deathday(), QDate());
        EXPECT_EQ(person->gender(), 2);
        EXPECT_STREQ(person->homepage().toStdString().c_str(), "");
        EXPECT_STREQ(person->imdbId().toStdString().c_str(), "nm0000158");
        EXPECT_STREQ(person->knownFor().toStdString().c_str(), "Acting");
        EXPECT_STREQ(person->placeOfBirth().toStdString().c_str(), "Concord, California, USA");
        EXPECT_GT(person->popularity(), 0.0f);
        EXPECT_FALSE(person->profilePath().isNull());
        f = true;
    });
    q.people_details(31);
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(PersonASyncTests, setGetters)
{
    Person person;
    person.setId(1);
    person.setName("Jane Doe");
    person.setAlsoKnownAs({"Janey", "JD"});
    person.setBiography("An actress.");
    person.setBirthday(QDate(1990, 5, 15));
    person.setDeathday(QDate(2020, 5, 15));
    person.setGender(Gender::nonBinary);
    person.setHomepage("http://example.com");
    person.setImdbId("tt7654321");
    person.setKnownFor("Acting");
    person.setPlaceOfBirth("Los Angeles, USA");
    person.setPopularity(7.5f);
    person.setProfilePath("/path/to/profile2.jpg");
    EXPECT_EQ(person.id(), 1);
    EXPECT_STREQ(person.name().toStdString().c_str(), "Jane Doe");
    EXPECT_EQ(person.alsoKnownAs().size(), 2);
    EXPECT_STREQ(person.alsoKnownAs()[0].toStdString().c_str(), "Janey");
    EXPECT_STREQ(person.alsoKnownAs()[1].toStdString().c_str(), "JD");
    EXPECT_STREQ(person.biography().toStdString().c_str(), "An actress.");
    EXPECT_EQ(person.birthday(), QDate(1990, 5, 15));
    EXPECT_EQ(person.deathday(), QDate(2020, 5, 15));
    EXPECT_EQ(person.gender(), Gender::nonBinary);
    EXPECT_STREQ(person.homepage().toStdString().c_str(), "http://example.com");
    EXPECT_STREQ(person.imdbId().toStdString().c_str(), "tt7654321");
    EXPECT_STREQ(person.knownFor().toStdString().c_str(), "Acting");
    EXPECT_STREQ(person.placeOfBirth().toStdString().c_str(), "Los Angeles, USA");
    EXPECT_FLOAT_EQ(person.popularity(), 7.5f);
    EXPECT_STREQ(person.profilePath().toStdString().c_str(), "/path/to/profile2.jpg");
}
