//
// Created by t on 30/05/25.
//

#include "Sync/Person.h"
#include <gtest/gtest.h>

#include "Sync/QTMDB.h"

TEST(PersonSyncTests, DefaultConstructor)
{
    tmdb::Person person;
    EXPECT_EQ(person.id(), 0);
    EXPECT_TRUE(person.name().isEmpty());
    EXPECT_TRUE(person.alsoKnownAs().empty());
    EXPECT_TRUE(person.biography().isEmpty());
    EXPECT_EQ(person.birthday(), QDate());
    EXPECT_EQ(person.deathday(), QDate());
    EXPECT_EQ(person.gender(), tmdb::Gender::NA);
    EXPECT_TRUE(person.homepage().isEmpty());
    EXPECT_TRUE(person.imdbId().isEmpty());
    EXPECT_TRUE(person.knownFor().isEmpty());
    EXPECT_TRUE(person.placeOfBirth().isEmpty());
    EXPECT_FLOAT_EQ(person.popularity(), 0.0f);
    EXPECT_TRUE(person.profilePath().isEmpty());
}

TEST(PersonSyncTests, ParmeterizedConstructor)
{
    tmdb::Person person(1, "John Doe", {"Johnny", "JD"}, "An actor.", QDate(1980, 1, 1), QDate(2020, 1, 1), tmdb::female,
                        "http://example.com", "tt1234567",
                        "Acting", "New York, USA", 8.5f, "/path/to/profile.jpg");
    EXPECT_EQ(person.id(), 1);
    EXPECT_STREQ(person.name().toStdString().c_str(), "John Doe");
    EXPECT_EQ(person.alsoKnownAs().size(), 2);
    EXPECT_STREQ(person.alsoKnownAs()[0].toStdString().c_str(), "Johnny");
    EXPECT_STREQ(person.alsoKnownAs()[1].toStdString().c_str(), "JD");
    EXPECT_STREQ(person.biography().toStdString().c_str(), "An actor.");
    EXPECT_EQ(person.birthday(), QDate(1980, 1, 1));
    EXPECT_EQ(person.deathday(), QDate(2020, 1, 1));
    EXPECT_EQ(person.gender(), tmdb::Gender::female);
    EXPECT_STREQ(person.homepage().toStdString().c_str(), "http://example.com");
    EXPECT_STREQ(person.imdbId().toStdString().c_str(), "tt1234567");
    EXPECT_STREQ(person.knownFor().toStdString().c_str(), "Acting");
    EXPECT_STREQ(person.placeOfBirth().toStdString().c_str(), "New York, USA");
    EXPECT_FLOAT_EQ(person.popularity(), 8.5f);
    EXPECT_STREQ(person.profilePath().toStdString().c_str(), "/path/to/profile.jpg");
}

TEST(PersonSyncTests, APIConstructor)
{
    tmdb::Person person(std::getenv("API_KEY"), 31);
    EXPECT_EQ(person.id(), 31);
    EXPECT_STREQ(person.name().toStdString().c_str(), "Tom Hanks");
    EXPECT_GT(person.alsoKnownAs().size(), 1);
    EXPECT_STREQ(person.biography().toStdString().c_str(), "Thomas Jeffrey Hanks (born July 9, 1956) is an American actor and filmmaker. Known for both his comedic and dramatic roles, Hanks is one of the most popular and recognizable film stars worldwide, and is widely regarded as an American cultural icon.\n\nHanks made his breakthrough with leading roles in the comedies Splash (1984) and Big (1988). He won two consecutive Academy Awards for Best Actor for starring as a gay lawyer suffering from AIDS in Philadelphia (1993) and a young man with below-average IQ in Forrest Gump (1994). Hanks collaborated with film director Steven Spielberg on five films: Saving Private Ryan (1998), Catch Me If You Can (2002), The Terminal (2004), Bridge of Spies (2015), and The Post (2017), as well as the 2001 miniseries Band of Brothers, which launched him as a director, producer, and screenwriter.\n\nHanks' other notable films include the romantic comedies Sleepless in Seattle (1993) and You've Got Mail (1998); the dramas Apollo 13 (1995), The Green Mile (1999), Cast Away (2000), Road to Perdition (2002), and Cloud Atlas (2012); and the biographical dramas Saving Mr. Banks (2013), Captain Phillips (2013), Sully (2016), and A Beautiful Day in the Neighborhood (2019). He has also appeared as the title character in the Robert Langdon film series, and has voiced Sheriff Woody in the Toy Story film series.\n\nDescription above from the Wikipedia article Tom Hanks, licensed under CC-BY-SA, full list of contributors on Wikipedia.");
    EXPECT_EQ(person.birthday(), QDate(1956, 7, 9));
    EXPECT_EQ(person.deathday(), QDate());
    EXPECT_EQ(person.gender(), 2);
    EXPECT_STREQ(person.homepage().toStdString().c_str(), "");
    EXPECT_STREQ(person.imdbId().toStdString().c_str(), "nm0000158");
    EXPECT_STREQ(person.knownFor().toStdString().c_str(), "Acting");
    EXPECT_STREQ(person.placeOfBirth().toStdString().c_str(), "Concord, California, USA");
    EXPECT_GT(person.popularity(), 0.0f);
    EXPECT_STREQ(person.profilePath().toStdString().c_str(), "/eKF1sGJRrZJbfBG1KirPt1cfNd3.jpg");
}

TEST(PersonSyncTests, APIJSON)
{
    Qtmdb q(std::getenv("API_KEY"));
    QJsonObject response = q.people_details(31);
    EXPECT_FALSE(response.isEmpty());
    tmdb::Person person(response);
    EXPECT_EQ(person.id(), 31);
    EXPECT_STREQ(person.name().toStdString().c_str(), "Tom Hanks");
    EXPECT_GT(person.alsoKnownAs().size(), 1);
    EXPECT_STREQ(person.biography().toStdString().c_str(), "Thomas Jeffrey Hanks (born July 9, 1956) is an American actor and filmmaker. Known for both his comedic and dramatic roles, Hanks is one of the most popular and recognizable film stars worldwide, and is widely regarded as an American cultural icon.\n\nHanks made his breakthrough with leading roles in the comedies Splash (1984) and Big (1988). He won two consecutive Academy Awards for Best Actor for starring as a gay lawyer suffering from AIDS in Philadelphia (1993) and a young man with below-average IQ in Forrest Gump (1994). Hanks collaborated with film director Steven Spielberg on five films: Saving Private Ryan (1998), Catch Me If You Can (2002), The Terminal (2004), Bridge of Spies (2015), and The Post (2017), as well as the 2001 miniseries Band of Brothers, which launched him as a director, producer, and screenwriter.\n\nHanks' other notable films include the romantic comedies Sleepless in Seattle (1993) and You've Got Mail (1998); the dramas Apollo 13 (1995), The Green Mile (1999), Cast Away (2000), Road to Perdition (2002), and Cloud Atlas (2012); and the biographical dramas Saving Mr. Banks (2013), Captain Phillips (2013), Sully (2016), and A Beautiful Day in the Neighborhood (2019). He has also appeared as the title character in the Robert Langdon film series, and has voiced Sheriff Woody in the Toy Story film series.\n\nDescription above from the Wikipedia article Tom Hanks, licensed under CC-BY-SA, full list of contributors on Wikipedia.");
    EXPECT_EQ(person.birthday(), QDate(1956, 7, 9));
    EXPECT_EQ(person.deathday(), QDate());
    EXPECT_EQ(person.gender(), 2);
    EXPECT_STREQ(person.homepage().toStdString().c_str(), "");
    EXPECT_STREQ(person.imdbId().toStdString().c_str(), "nm0000158");
    EXPECT_STREQ(person.knownFor().toStdString().c_str(), "Acting");
    EXPECT_STREQ(person.placeOfBirth().toStdString().c_str(), "Concord, California, USA");
    EXPECT_GT(person.popularity(), 0.0f);
    EXPECT_STREQ(person.profilePath().toStdString().c_str(), "/eKF1sGJRrZJbfBG1KirPt1cfNd3.jpg");
}

TEST(PersonSyncTests, StaticConstructor)
{
    tmdb::Person person = tmdb::Person::getPerson(std::getenv("API_KEY"), 31);
       EXPECT_EQ(person.id(), 31);
    EXPECT_STREQ(person.name().toStdString().c_str(), "Tom Hanks");
    EXPECT_GT(person.alsoKnownAs().size(), 1);
    EXPECT_STREQ(person.biography().toStdString().c_str(), "Thomas Jeffrey Hanks (born July 9, 1956) is an American actor and filmmaker. Known for both his comedic and dramatic roles, Hanks is one of the most popular and recognizable film stars worldwide, and is widely regarded as an American cultural icon.\n\nHanks made his breakthrough with leading roles in the comedies Splash (1984) and Big (1988). He won two consecutive Academy Awards for Best Actor for starring as a gay lawyer suffering from AIDS in Philadelphia (1993) and a young man with below-average IQ in Forrest Gump (1994). Hanks collaborated with film director Steven Spielberg on five films: Saving Private Ryan (1998), Catch Me If You Can (2002), The Terminal (2004), Bridge of Spies (2015), and The Post (2017), as well as the 2001 miniseries Band of Brothers, which launched him as a director, producer, and screenwriter.\n\nHanks' other notable films include the romantic comedies Sleepless in Seattle (1993) and You've Got Mail (1998); the dramas Apollo 13 (1995), The Green Mile (1999), Cast Away (2000), Road to Perdition (2002), and Cloud Atlas (2012); and the biographical dramas Saving Mr. Banks (2013), Captain Phillips (2013), Sully (2016), and A Beautiful Day in the Neighborhood (2019). He has also appeared as the title character in the Robert Langdon film series, and has voiced Sheriff Woody in the Toy Story film series.\n\nDescription above from the Wikipedia article Tom Hanks, licensed under CC-BY-SA, full list of contributors on Wikipedia.");
    EXPECT_EQ(person.birthday(), QDate(1956, 7, 9));
    EXPECT_EQ(person.deathday(), QDate());
    EXPECT_EQ(person.gender(), 2);
    EXPECT_STREQ(person.homepage().toStdString().c_str(), "");
    EXPECT_STREQ(person.imdbId().toStdString().c_str(), "nm0000158");
    EXPECT_STREQ(person.knownFor().toStdString().c_str(), "Acting");
    EXPECT_STREQ(person.placeOfBirth().toStdString().c_str(), "Concord, California, USA");
    EXPECT_GT(person.popularity(), 0.0f);
    EXPECT_STREQ(person.profilePath().toStdString().c_str(), "/eKF1sGJRrZJbfBG1KirPt1cfNd3.jpg");
}

TEST(PersonSyncTests, setGetters)
{
    tmdb::Person person;
    person.setId(1);
    person.setName("Jane Doe");
    person.setAlsoKnownAs({"Janey", "JD"});
    person.setBiography("An actress.");
    person.setBirthday(QDate(1990, 5, 15));
    person.setDeathday(QDate(2020, 5, 15));
    person.setGender(tmdb::Gender::nonBinary);
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
    EXPECT_EQ(person.gender(), tmdb::Gender::nonBinary);
    EXPECT_STREQ(person.homepage().toStdString().c_str(), "http://example.com");
    EXPECT_STREQ(person.imdbId().toStdString().c_str(), "tt7654321");
    EXPECT_STREQ(person.knownFor().toStdString().c_str(), "Acting");
    EXPECT_STREQ(person.placeOfBirth().toStdString().c_str(), "Los Angeles, USA");
    EXPECT_FLOAT_EQ(person.popularity(), 7.5f);
    EXPECT_STREQ(person.profilePath().toStdString().c_str(), "/path/to/profile2.jpg");
}