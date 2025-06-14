//
// Created by t on 07/06/25.
//

#ifndef AQTMDB_H
#define AQTMDB_H
#include <QObject>

#include "Sync/timeWindow.h"
#include <QDate>
#include <QJsonDocument>
#include <fmt/format.h>
#include <QJsonArray>
#include <QtConcurrent/QtConcurrent>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class aQtmdb : public QObject
{
    Q_OBJECT
private:
    const std::string _m_baseUrl = "https://api.themoviedb.org/3/";
    void _runGetRequest(std::string i_request, std::map<std::string, std::string> i_params = {});
    std::string _m_accessToken;
    QNetworkAccessManager* _m_nam;
public:
    /// @brief Default constructor for Qtmdb.
    /// @note For this class to be functional, you must initialise a QApplication object beforehand.
    /// @param i_accessToken The access token for the TMDB API.
    /// @param parent The parent QObject, default is nullptr. (You should probably leave this blank)
    explicit aQtmdb(std::string i_accessToken, QObject* parent = nullptr);
    /// @brief Default destructor for Qtmdb.
    virtual ~aQtmdb() = default;
    /// @brief Get the access token for the TMDB API.
    /// @return The access token for the TMDB API.
    std::string accessToken();
    /// @brief Set the access token for the TMDB API.
    /// @param i_accessToken The access token for the TMDB API.
    void setAccessToken(std::string i_accessToken);

    static std::string getImageURL(std::string i_path, std::string i_size = "original");
    //|-----------------------------------------------------------------------------------------------------|
private slots:
    void _received(QNetworkReply* i_reply);
    signals:

    void startedLoadingData();
    void finishedLoadingData(void* i_data);

public:

    //|------------------------------------- API ENDPOINTS -------------------------------------------------|
    //|-------------------------------------    Account    -------------------------------------------------|
    ///@brief Get the public details of an account on TMDB.
    ///@param account_id The ID of the account.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void account_details(int32_t account_id);

    ///@brief Get a users list of favourite movies.
    ///@param account_id The ID of the account.
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void account_favoriteMovies(int32_t account_id, std::string language = "en-US", int32_t page = 1);

    ///@brief Get a users list of favourite TV shows.
    ///@param account_id The ID of the account.
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void account_favoriteTV(int32_t account_id, std::string language = "en-US", int32_t page = 1);

    ///@brief Get a users list of custom lists.
    ///@param account_id The ID of the account.
    ///@param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void account_lists(int32_t account_id, int32_t page = 1);

    ///@brief Gets the movies rated by an account.
    ///@param account_id The ID of the account.
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void account_ratedMovies(int32_t account_id, std::string language = "en-US", int32_t page = 1);

    ///@brief Gets the TV shows rated by an account.
    ///@param account_id The ID of the account.
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void account_ratedTV(int32_t account_id, std::string language = "en-US", int32_t page = 1);

    ///@brief Gets the TV Episodes rated by an account.
    ///@param account_id The ID of the account.
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void account_ratedTVEpisodes(int32_t account_id, std::string language = "en-US", int32_t page = 1);

    ///@brief Get a list of movies added to a users watchlist.
    ///@param account_id The ID of the account.
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void account_watchlistMovies(int32_t account_id, std::string language = "en-US", int32_t page = 1);

    ///@brief Get a list of TV shows added to a users watchlist.
    ///@param account_id The ID of the account.
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void account_watchlistTV(int32_t account_id, std::string language = "en-US", int32_t page = 1);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Certifications    -------------------------------------------------|
    ///@brief Get an up-to-date list of the officially supported movie certifications on TMDB.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void certifications_movie();

    ///@brief Get an up-to-date list of the officially supported TV certifications on TMDB.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void certifications_tv();
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Changes    -------------------------------------------------|
    ///@brief Get a list of all of the movie ids that have been changed in the past 24 hours.
    ///@param start_date The start date for the changes, default is 2023-10-22.
    ///@param end_date The end date for the changes, default is 2023-10-22.
    ///@param page The page number to retrieve, default is 1.
    ///@note start_date and end_date cannot be more than 14 days apart.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void changes_movie(QDate end_date = QDate(2023, 10, 22), QDate start_date = QDate(2023, 10, 22),
                              int32_t page = 1);

    ///@brief Get a list of all of the people ids that have been changed in the past 24 hours.
    ///@param start_date The start date for the changes, default is 2023-10-22.
    ///@param end_date The end date for the changes, default is 2023-10-22.
    ///@param page The page number to retrieve, default is 1.
    ///@note start_date and end_date cannot be more than 14 days apart.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void changes_people(QDate end_date = QDate(2023, 10, 22), QDate start_date = QDate(2023, 10, 22),
                               int32_t page = 1);

    ///@brief Get a list of all of the TV ids that have been changed in the past 24 hours.
    ///@param start_date The start date for the changes, default is 2023-10-22.
    ///@param end_date The end date for the changes, default is 2023-10-22.
    ///@param page The page number to retrieve, default is 1.
    ///@note start_date and end_date cannot be more than 14 days apart.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void changes_tv(QDate end_date = QDate(2023, 10, 22), QDate start_date = QDate(2023, 10, 22),
                           int32_t page = 1);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Collection    -------------------------------------------------|
    ///@brief Get collection details by ID.
    ///@param collection_id The ID of the collection.
    ///@param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void collection_details(int32_t collection_id, std::string language = "en-US");

    ///@brief Get the images that belong to a collection.
    ///@param collection_id The ID of the collection.
    ///@param language The language to use for the results, default is "en".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void collection_images(int32_t collection_id, std::string language = "en");

    ///@brief Get the translations that belong to a collection.
    ///@param collection_id The ID of the collection.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void collection_translations(int32_t collection_id);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Company    -------------------------------------------------|
    ///@brief Get the company details by ID.
    ///@param company_id The ID of the company.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void company_details(int32_t company_id);

    ///@brief Get the company alternative names by ID.
    ///@param company_id The ID of the company.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void company_alternativeNames(int32_t company_id);

    ///@brief Get the company images by ID.
    ///@param company_id The ID of the company.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void company_images(int32_t company_id);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Configuration    -------------------------------------------------|
    ///@brief Query the API configuration details.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void config_details();

    ///@brief Get the list of countries (ISO 3166-1 tags) used throughout TMDB.
    ///@param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void config_countries(std::string language = "en-US");

    ///@brief Get the list of the jobs and departments we use on TMDB.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void config_jobs();

    ///@brief Get the list of languages (ISO 639-1 tags) used throughout TMDB.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void config_languages();

    ///@brief Get a list of the officially supported translations on TMDB.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void config_primaryTranslations();

    ///@brief Get the list of timezones used throughout TMDB.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void config_timezones();
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Credits    -------------------------------------------------|
    ///@brief Get a movie or TV credit details by ID.
    ///@param credit_id The ID of the credit.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void credits_details(std::string credit_id);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Genres    -------------------------------------------------|
    ///@brief Get the list of official genres for movies.
    ///@param language The language to use for the results, default is "en".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void genres_movie(std::string language = "en");

    ///@brief Get the list of official genres for TV shows.
    ///@param language The language to use for the results, default is "en".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void genres_tv(std::string language = "en");
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Movies    -------------------------------------------------|
    ///@brief Get a list of movies that are currently in theatres.
    ///@param region The region to use for the results, default is "US".
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void movieList_nowPlaying(std::string region, std::string language = "en-US", int32_t page = 1);

    ///@brief Get a list of movies ordered by popularity.
    ///@param region The region to use for the results, default is "US".
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void movieList_popular(std::string region, std::string language = "en-US", int32_t page = 1);

    ///@brief Get a list of movies ordered by rating.
    ///@param region The region to use for the results, default is "US".
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void movieList_topRated(std::string region, std::string language = "en-US", int32_t page = 1);

    ///@brief Get a list of movies that are being released soon.
    ///@param region The region to use for the results, default is "US".
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void movieList_upcoming(std::string region, std::string language = "en-US", int32_t page = 1);

    ///@brief Get the top level details of a movie by ID.
    ///@param movie_id The ID of the movie.
    ///@param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void movie_details(int32_t movie_id, std::string language = "en-US");

    ///@brief Get the alternative titles for a movie.
    ///@param movie_id The ID of the movie.
    ///@param country The country to use for the results, default is "US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void movie_alternativeTitles(int32_t movie_id, std::string country = "");

    ///@brief Get the recent changes for a movie.
    ///@param movie_id The ID of the movie.
    ///@param start_date The start date for the changes, default is 2023-10-22.
    ///@param end_date The end date for the changes, default is 2023-10-22.
    ///@param page The page number to retrieve, default is 1.
    ///@note start_date and end_date cannot be more than 14 days apart.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void movie_changes(int32_t movie_id, QDate start_date = QDate(2023, 10, 22),
                              QDate end_date = QDate(2023, 10, 22), int32_t page = 1);

    ///@brief Get the credits for a movie.
    ///@param movie_id The ID of the movie.
    ///@param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void movie_credits(int32_t movie_id, std::string language = "en-US");

    ///@brief Get the IDs on external services for a movie.
    ///@param movie_id The ID of the movie.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void movie_externalIDs(int32_t movie_id);

    ///@brief Get the images that belong to a movie.
    ///@param movie_id The ID of the movie.
    ///@param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void movie_images(int32_t movie_id, std::string language);

    ///@brief Get the keywords that belong to a movie.
    ///@param movie_id The ID of the movie.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void movie_keywords(int32_t movie_id);

    ///@brief Get the newest movie ID.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void movie_latest();

    ///@brief Get the lists that a movie has been added to.
    ///@param movie_id The ID of the movie.
    ///@param page The page number to retrieve, default is 1.
    ///@param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void movie_lists(int32_t movie_id, int32_t page = 1, std::string language = "en-US");

    ///@brief Get movie recommendations based on a movie ID.
    ///@param movie_id The ID of the movie.
    ///@param page The page number to retrieve, default is 1.
    ///@param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void movie_recommendations(int32_t movie_id, std::string language = "en-US", int32_t page = 1);

    ///@brief Get the release dates and certifications for a movie.
    ///@param movie_id The ID of the movie.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void movie_releaseDates(int32_t movie_id);

    ///@brief Get the user reviews for a movie.
    ///@param movie_id The ID of the movie.
    ///@param page The page number to retrieve, default is 1.
    ///@param language The language to use for the results, default is "en-US"
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void movie_reviews(int32_t movie_id, std::string language = "en-US", int32_t page = 1);

    ///@brief Get the similar movies based on genres and keywords.
    ///@param movie_id The ID of the movie.
    ///@param page The page number to retrieve, default is 1.
    ///@param language The language to use for the results, default is "en-US"
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void movie_similar(int32_t movie_id, std::string language = "en-US", int32_t page = 1);

    ///@brief Get the translations for a movie.
    ///@param movie_id The ID of the movie.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void movie_translations(int32_t movie_id);

    ///@brief Get the videos for a movie.
    ///@param movie_id The ID of the movie.
    ///@param language The language to use for the results, default is "en-US"
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void movie_videos(int32_t movie_id, std::string language = "en-US");

    ///@brief Get the list of streaming providers we have for a movie.
    ///@param movie_id The ID of the movie.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    ///Streaming provider data provided by JustWatch.
    void movie_watchProviders(int32_t movie_id);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Networks    -------------------------------------------------|
    ///@brief Get the details of a network by ID.
    ///@param network_id The ID of the network.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void network_details(int32_t network_id);

    ///@brief Get the alternative names of a network by ID.
    ///@param network_id The ID of the network.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void network_alternativeNames(int32_t network_id);

    ///@brief Get the images of a network by ID.
    ///@param network_id The ID of the network.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void network_images(int32_t network_id);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    People    -------------------------------------------------|
    ///@brief Get a list of people ordered by popularity.
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void people_popular(std::string language = "en-US", int32_t page = 1);

    ///@brief Query the top level details of a person.
    ///@param person_id The ID of the person.
    ///@param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void people_details(int32_t person_id, std::string language = "en-US");

    ///@brief Get the recent changes for a person.
    ///@param person_id The ID of the person.
    ///@param start_date The start date for the changes, default is 2023-10-22.
    ///@param end_date The end date for the changes, default is 2023-10-22.
    ///@param page The page number to retrieve, default is 1.
    ///@note start_date and end_date cannot be more than 14 days apart.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void people_changes(int32_t person_id, QDate start_date = QDate(2023, 10, 22),
                               QDate end_date = QDate(2023, 10, 22), int32_t page = 1);

    ///@brief Get the combined movie and TV credits that belong to a person.
    ///@param person_id The ID of the person.
    ///@param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void people_combinedCredits(int32_t person_id, std::string language = "en-US");

    ///@brief Get the external ID's that belong to a person.
    ///@param person_id The ID of the person.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void people_externalIDs(int32_t person_id);

    ///@brief Get the profile images that belong to a person.
    ///@param person_id The ID of the person.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void people_images(int32_t person_id);

    ///@brief Get the newest created person. This is a live response and will continuously change.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void people_latest();

    ///@brief Get the movie credits for a person.
    ///@param person_id The ID of the person.
    ///@param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void people_movieCredits(int32_t person_id, std::string language = "en-US");

    ///@brief Get the TV credits for a person.
    ///@param person_id The ID of the person.
    ///@param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void people_tvCredits(int32_t person_id, std::string language = "en-US");

    ///@brief Get the translations that belong to a person.
    ///@param person_id The ID of the person.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void people_translations(int32_t person_id);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Reviews    -------------------------------------------------|
    ///@brief Retrieve the details of a movie or TV show review.
    ///@param review_id The ID of the review.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void reviews_details(std::string review_id);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Queryable searchers    -------------------------------------------------|
    ///@brief Search for collections by their original, translated and alternative names.
    ///@param query The search query string.
    ///@param include_adult Whether to include adult content in the results, default is false.
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@param region The region to use for the results, default is an empty string.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void get_collection(std::string query, bool include_adult = false, std::string language = "en-US",
                               int32_t page = 1, std::string region = "");

    ///@brief Search for companies by their original and alternative names.
    ///@param query The search query string.
    ///@param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void get_company(std::string query, int32_t page = 1);

    ///@brief Search for keywords by their name.
    ///@param query The search query string.
    ///@param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void get_keyword(std::string query, int32_t page = 1);

    ///@brief Search for movies by their original, translated and alternative titles.
    ///@param query The search query string.
    ///@param page The page number to retrieve, default is 1.
    /// @param include_adult Whether to include adult content in the results, default is false.
    /// @param language The language to use for the results, default is "en-US".
    /// @param primary_release_year The primary release year to filter the results, this parameter is optional.
    /// @param region The region to use for the results, default is "en-GB".
    /// @param year The year to filter the results, this parameter is optional.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void get_movie(std::string query, bool include_adult = false, std::string language = "en-US",
                          std::string primary_release_year = "", int32_t page = 1, std::string region = "en-GB",
                          std::string year = "");

    ///@brief Search for people by their name and also known as names.
    ///@param query The search query string.
    ///@param page The page number to retrieve, default is 1.
    /// @param include_adult Whether to include adult content in the results, default is false.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void get_person(std::string query, bool include_adult = false, std::string language = "en-US",
                           int32_t page = 1);

    ///@brief Search for TV shows by their original, translated and also known as names.
    ///@param query The search query string.
    ///@param page The page number to retrieve, default is 1.
    /// @param include_adult Whether to include adult content in the results, default is false.
    /// @param language The language to use for the results, default is "en-US".
    /// @param first_air_date_year The year of the first air date to filter the results, this parameter is optional.
    /// @param year The year to filter the results, this parameter is optional.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void get_tv(std::string query, int32_t first_air_date_year = 0, bool include_adult = false,
                       std::string language = "en-US", int32_t page = 1, int32_t year = 0);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Trending    -------------------------------------------------|
    ///@brief Get the trending movies on TMDB.
    /// @param time_window The time window to use for the results, default is "day".
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void trending_movies(tmdb::timeWindow::timeWindow time_window = tmdb::timeWindow::timeWindow::day,
                                std::string language = "en-US");

    ///@brief Get the trending people on TMDB.
    /// @param time_window The time window to use for the results, default is "day".
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void trending_people(tmdb::timeWindow::timeWindow time_window = tmdb::timeWindow::timeWindow::day,
                                std::string language = "en-US");

    ///@brief Get the trending TV shows on TMDB.
    /// @param time_window The time window to use for the results, default is "day".
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void trending_tv(tmdb::timeWindow::timeWindow time_window, std::string language = "en-US");
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    TV Series    -------------------------------------------------|
    ///@brief Get a list of TV shows airing today.
    /// @param language The language to use for the results, default is "en-US".
    /// @param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_series_airingToday(std::string language = "en-US", int32_t page = 1,
                                      std::string timezone = "America/New_York");

    ///@brief Get a list of TV shows that air in the next 7 days.
    /// @param language The language to use for the results, default is "en-US".
    /// @param page The page number to retrieve, default is 1.
    /// @param timezone The timezone to use for the results, default is "America/New_York".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_series_onTheAir(std::string language = "en-US", int32_t page = 1,
                                   std::string timezone = "America/New_York");

    ///@brief Get a list of TV shows ordered by popularity.
    /// @param language The language to use for the results, default is "en-US".
    /// @param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_series_popular(std::string language = "en-US", int32_t page = 1);

    ///@brief Get a list of TV shows ordered by rating.
    /// @param language The language to use for the results, default is "en-US".
    /// @param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_series_topRated(std::string language = "en-US", int32_t page = 1);

    ///@brief Get the details of a TV show.
    /// @param series_id The ID of the TV series.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_series_details(int32_t series_id, std::string language = "en-US");

    ///@brief Get the aggregate credits (cast and crew) that have been added to a TV show.
    /// @param series_id The ID of the TV series.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_series_aggregateCredits(int32_t series_id, std::string language = "en-US");

    ///@brief Get the alternative titles that have been added to a TV show.
    /// @param series_id The ID of the TV series.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_series_alternativeTitles(int32_t series_id);

    ///@brief Get the recent changes for a TV show.
    /// @param series_id The ID of the TV series.
    /// @param start_date The start date for the changes, default is 2023-10-22.
    /// @param end_date The end date for the changes, default is 2023-10-22.
    /// @param page The page number to retrieve, default is 1.
    ///@note start_date and end_date cannot be more than 14 days apart.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_series_changes(int32_t series_id, QDate start_date = QDate(2023, 10, 22),
                                  QDate end_date = QDate(2023, 10, 22), int32_t page = 1);

    ///@brief Get the content ratings that have been added to a TV show.
    /// @param series_id The ID of the TV series.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_series_contentRatings(int32_t series_id);

    ///@brief Get the latest season credits of a TV show.
    /// @param series_id The ID of the TV series.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_series_credits(int32_t series_id, std::string language = "en-US");

    ///@brief Get the episode groups that have been added to a TV show.
    /// @param series_id The ID of the TV series.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_series_episodeGroups(int32_t series_id);

    ///@brief Get a list of external IDs that have been added to a TV show.
    /// @param series_id The ID of the TV series.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_series_externalIDs(int32_t series_id);

    ///@brief Get the images that belong to a TV series.
    /// @param series_id The ID of the TV series.
    /// @param language The language to use for the results, default is "en".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_series_images(int32_t series_id, std::string language = "en");

    ///@brief Get a list of keywords that have been added to a TV show.
    /// @param series_id The ID of the TV series.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_series_keywords(int32_t series_id);

    ///@brief Get the newest TV show ID.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_series_latest();

    ///@brief Get the lists that a TV series has been added to.
    /// @param series_id The ID of the TV series.
    /// @param page The page number to retrieve, default is 1.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_series_lists(int32_t series_id, int32_t page = 1, std::string language = "en-US");

    ///@brief Get a list of recommended TV series based on a TV series ID.
    /// @param series_id The ID of the TV series.
    /// @param page The page number to retrieve, default is 1.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_series_recommendations(int32_t series_id, std::string language = "en-US", int32_t page = 1);

    ///@brief Get the reviews that have been added to a TV show.
    /// @param series_id The ID of the TV series.
    /// @param page The page number to retrieve, default is 1.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_series_reviews(int32_t series_id, std::string language = "en-US", int32_t page = 1);

    ///@brief Get the seasons and episodes that have screened theatrically.
    /// @param series_id The ID of the TV series.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_series_screenedTheatrically(int32_t series_id);

    ///@brief Get the similar TV shows.
    /// @param series_id The ID of the TV series.
    /// @param language The language to use for the results, default is "en-US".
    /// @param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_series_similar(int32_t series_id, std::string language = "en-US", int32_t page = 1);

    ///@brief Get the translations that have been added to a TV show.
    /// @param series_id The ID of the TV series.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_series_translations(int32_t series_id);

    ///@brief Get the videos that belong to a TV show.
    /// @param series_id The ID of the TV series.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_series_videos(int32_t series_id, std::string language = "en-US");

    ///@brief Get the list of streaming providers we have for a TV show.
    /// @param series_id The ID of the TV series.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    ///Streaming provider data provided by JustWatch.
    void tv_series_watchProviders(int32_t series_id);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    TV Season    -------------------------------------------------|
    ///@brief Query the details of a TV season.
    /// @param series_id The ID of the TV series.
    /// @param season_number The season number of the TV series.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_seasons_details(int32_t series_id, int32_t season_number, std::string language = "en-US");

    ///@brief Get the aggregate credits (cast and crew) that have been added to a TV season.
    /// @param series_id The ID of the TV series.
    /// @param season_number The season number of the TV series.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_seasons_aggregateCredits(int32_t series_id, int32_t season_number, std::string language = "en-US");

    ///@brief Get the recent changes for a TV season.
    /// @param season_id The ID of the TV season.
    /// @param start_date The start date for the changes, default is 2023-10-22.
    /// @param end_date The end date for the changes, default is 2023-10-22.
    /// @param page The page number to retrieve, default is 1.
    ///@note start_date and end_date cannot be more than 14 days apart.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_seasons_changes(int32_t season_id, QDate start_date = QDate(2023, 10, 22),
                                   QDate end_date = QDate(2023, 10, 22), int32_t page = 1);

    ///@brief Get the credits (cast and crew) that have been added to the most recent season of the TV show.
    /// @param series_id The ID of the TV series.
    /// @param season_number The season number of the TV series.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_seasons_credits(int32_t series_id, int32_t season_number, std::string language = "en-US");

    ///@brief Get a list of external IDs that have been added to a TV season.
    /// @param series_id The ID of the TV series.
    /// @param season_number The season number of the TV series.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_seasons_externalIDs(int32_t series_id, int32_t season_number);

    ///@brief Get the images that belong to a TV season.
    /// @param series_id The ID of the TV series.
    /// @param season_number The season number of the TV series.
    /// @param language The language to use for the results, default is "en".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_seasons_images(int32_t series_id, int32_t season_number, std::string language = "en");

    ///@brief Get the videos that belong to a TV season.
    /// @param series_id The ID of the TV series.
    /// @param season_number The season number of the TV series.
    /// @param language The language to use for the results, default is "en".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_seasons_videos(int32_t series_id, int32_t season_number, std::string language = "en");

    ///@brief Get the translations for a TV season.
    /// @param series_id The ID of the TV series.
    /// @param season_number The season number of the TV series.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_seasons_translations(int32_t series_id, int32_t season_number);

    ///@brief Get the list of streaming providers we have for a TV season.
    /// @param series_id The ID of the TV series.
    /// @param season_number The season number of the TV series.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    ///Streaming provider data provided by JustWatch.
    void tv_seasons_watchProviders(int32_t series_id, int32_t season_number);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    TV Episode    -------------------------------------------------|
    ///@brief Query the details of a TV episode.
    /// @param series_id The ID of the TV series.
    /// @param season_number The season number of the TV series.
    /// @param episode_number The episode number of the TV series.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_episodes_details(int32_t series_id, int32_t season_number, int32_t episode_number,
                                    std::string language = "en-US");

    ///@brief Get the recent changes for a TV episode.
    /// @param episode_id The ID of the TV episode.
    /// @param start_date The start date for the changes, default is 2023-10-22.
    /// @param end_date The end date for the changes, default is 2023-10-22.
    /// @param page The page number to retrieve, default is 1.
    ///@note start_date and end_date cannot be more than 14 days apart.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_episodes_changes(int32_t episode_id, QDate start_date = QDate(2023, 10, 22),
                                    QDate end_date = QDate(2023, 10, 22), int32_t page = 1);

    ///@brief Query the credits of a TV episode.
    /// @param series_id The ID of the TV series.
    /// @param season_number The season number of the TV series.
    /// @param episode_number The episode number of the TV series.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_episodes_credits(int32_t series_id, int32_t season_number, int32_t episode_number,
                                    std::string language = "en-US");

    ///@brief Get a list of external IDs that have been added to a TV episode.
    /// @param series_id The ID of the TV series.
    /// @param season_number The season number of the TV series.
    /// @param episode_number The episode number of the TV series.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_episodes_externalIDs(int32_t series_id, int32_t season_number, int32_t episode_number);

    ///@brief Get the images that belong to a TV episode.
    /// @param series_id The ID of the TV series.
    /// @param season_number The season number of the TV series.
    /// @param episode_number The episode number of the TV series.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_episodes_images(int32_t series_id, int32_t season_number, int32_t episode_number,
                                   std::string language = "en-US");

    ///@brief Get the translations that have been added to a TV episode.
    /// @param series_id The ID of the TV series.
    /// @param season_number The season number of the TV series.
    /// @param episode_number The episode number of the TV series.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_episodes_translations(int32_t series_id, int32_t season_number, int32_t episode_number);

    ///@brief Get the videos that belong to a TV episode.
    /// @param series_id The ID of the TV series.
    /// @param season_number The season number of the TV series.
    /// @param episode_number The episode number of the TV series.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void tv_episodes_videos(int32_t series_id, int32_t season_number, int32_t episode_number,
                                   std::string language = "en-US");
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Watch Providers    -------------------------------------------------|
    ///@brief Get the list of the countries we have watch provider (OTT/streaming) data for.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void watchProviders_regions(std::string language = "en-US");

    ///@brief Get the list of streaming providers we have for movies.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void watchProviders_movie(std::string language = "en-US");

    ///@brief Get the list of streaming providers we have for TV shows.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    void watchProviders_tv(std::string language = "en-US");
    //|-----------------------------------------------------------------------------------------------------|
    //|-----------------------------------------------------------------------------------------------------|
};
#endif //AQTMDB_H
