#include <QObject>

#include "timeWindow.h"
#include <QDate>
#include <QJsonDocument>
#include <fmt/format.h>
#include <QJsonArray>

/// @file QTMDB.h
/// @class Qtmdb
/// @author Thomas Lower
/// @brief "Qtmdb" is a C++ wrapper for the TMDB API.
/// @details This class provides methods to interact with the TMDB API, allowing users to retrieve information about movies, TV shows, people, and more.
/// It is based on the QT framework and uses its QJson classes for simplicity of design.
/// To be able to use this class, you must have a valid access token from the TMDB API. This can be obtained by creating an account on the TMDB website and generating an API key. [https://www.themoviedb.org/documentation/api] (https://www.themoviedb.org/documentation/api)
/// @note This is a placeholder that will be replaced with true C++ classes and methods, rather than relying on the JSON setup.
/// @cite Special Thanks to JustWatch for access to data for the TMDB API
class Qtmdb : public QObject
{
    Q_OBJECT

public:
    /// @brief Default constructor for Qtmdb.
    /// @note For this class to be functional, you must initialise a QApplication object beforehand.
    /// @param i_accessToken The access token for the TMDB API.
    /// @param parent The parent QObject, default is nullptr. (You should probably leave this blank)
    explicit Qtmdb(std::string i_accessToken, QObject* parent = nullptr);
    /// @brief Default destructor for Qtmdb.
    ~Qtmdb() override = default;
    /// @brief Get the access token for the TMDB API.
    /// @return The access token for the TMDB API.
    std::string accessToken();
    /// @brief Set the access token for the TMDB API.
    /// @param i_accessToken The access token for the TMDB API.
    void setAccessToken(std::string i_accessToken);
    //|-----------------------------------------------------------------------------------------------------|

    //|------------------------------------- API ENDPOINTS -------------------------------------------------|
    //|-------------------------------------    Account    -------------------------------------------------|
    ///@brief Get the public details of an account on TMDB.
    ///@param account_id The ID of the account.
    ///@return A QJsonObject containing the account details.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject account_details(int32_t account_id);

    ///@brief Get a users list of favourite movies.
    ///@param account_id The ID of the account.
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@return A QJsonObject containing the account's favourite movies.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject account_favoriteMovies(int32_t account_id, std::string language = "en-US", int32_t page = 1);

    ///@brief Get a users list of favourite TV shows.
    ///@param account_id The ID of the account.
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@return A QJsonObject containing the account's favourite TV Shows.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject account_favoriteTV(int32_t account_id, std::string language = "en-US", int32_t page = 1);

    ///@brief Get a users list of custom lists.
    ///@param account_id The ID of the account.
    ///@param page The page number to retrieve, default is 1.
    ///@return A QJsonObject containing the account's created lists.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject account_lists(int32_t account_id, int32_t page = 1);

    ///@brief Gets the movies rated by an account.
    ///@param account_id The ID of the account.
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@return A QJsonObject containing the account's rated movies.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject account_ratedMovies(int32_t account_id, std::string language = "en-US", int32_t page = 1);

    ///@brief Gets the TV shows rated by an account.
    ///@param account_id The ID of the account.
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@return A QJsonObject containing the account's rated TV shows.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject account_ratedTV(int32_t account_id, std::string language = "en-US", int32_t page = 1);

    ///@brief Gets the TV Episodes rated by an account.
    ///@param account_id The ID of the account.
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@return A QJsonObject containing the account's rated TV episodes.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject account_ratedTVEpisodes(int32_t account_id, std::string language = "en-US", int32_t page = 1);

    ///@brief Get a list of movies added to a users watchlist.
    ///@param account_id The ID of the account.
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@return A QJsonObject containing the movies from the account's watchlist.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject account_watchlistMovies(int32_t account_id, std::string language = "en-US", int32_t page = 1);

    ///@brief Get a list of TV shows added to a users watchlist.
    ///@param account_id The ID of the account.
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@return A QJsonObject containing the TV shows from the account's watchlist.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject account_watchlistTV(int32_t account_id, std::string language = "en-US", int32_t page = 1);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Certifications    -------------------------------------------------|
    ///@brief Get an up-to-date list of the officially supported movie certifications on TMDB.
    ///@return A QJsonObject containing the certifications for all countries for movies.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject certifications_movie();

    ///@brief Get an up-to-date list of the officially supported TV certifications on TMDB.
    ///@return A QJsonObject containing the certifications for all countries for TV shows.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject certifications_tv();
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Changes    -------------------------------------------------|
    ///@brief Get a list of all of the movie ids that have been changed in the past 24 hours.
    ///@param start_date The start date for the changes, default is 2023-10-22.
    ///@param end_date The end date for the changes, default is 2023-10-22.
    ///@param page The page number to retrieve, default is 1.
    ///@return A QJsonObject containing the list of movies which have been changed on TMDB.
    ///@note start_date and end_date cannot be more than 14 days apart.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject changes_movie(QDate end_date = QDate(2023, 10, 22), QDate start_date = QDate(2023, 10, 22),
                              int32_t page = 1);

    ///@brief Get a list of all of the people ids that have been changed in the past 24 hours.
    ///@param start_date The start date for the changes, default is 2023-10-22.
    ///@param end_date The end date for the changes, default is 2023-10-22.
    ///@param page The page number to retrieve, default is 1.
    ///@return A QJsonObject containing the list of people which have been changed on TMDB.
    ///@note start_date and end_date cannot be more than 14 days apart.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject changes_people(QDate end_date = QDate(2023, 10, 22), QDate start_date = QDate(2023, 10, 22),
                               int32_t page = 1);

    ///@brief Get a list of all of the TV ids that have been changed in the past 24 hours.
    ///@param start_date The start date for the changes, default is 2023-10-22.
    ///@param end_date The end date for the changes, default is 2023-10-22.
    ///@param page The page number to retrieve, default is 1.
    ///@return A QJsonObject containing the list of TV shows which have been changed on TMDB.
    ///@note start_date and end_date cannot be more than 14 days apart.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject changes_tv(QDate end_date = QDate(2023, 10, 22), QDate start_date = QDate(2023, 10, 22),
                           int32_t page = 1);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Collection    -------------------------------------------------|
    ///@brief Get collection details by ID.
    ///@param collection_id The ID of the collection.
    ///@param language The language to use for the results, default is "en-US".
    ///@return A QJsonObject containing the collection details.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject collection_details(int32_t collection_id, std::string language = "en-US");

    ///@brief Get the images that belong to a collection.
    ///@param collection_id The ID of the collection.
    ///@param language The language to use for the results, default is "en".
    ///@return A QJsonObject containing the collection images.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject collection_images(int32_t collection_id, std::string language = "en");

    ///@brief Get the translations that belong to a collection.
    ///@param collection_id The ID of the collection.
    ///@return A QJsonObject containing the collection translations.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject collection_translations(int32_t collection_id);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Company    -------------------------------------------------|
    ///@brief Get the company details by ID.
    ///@param company_id The ID of the company.
    ///@return A QJsonObject containing the company details.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject company_details(int32_t company_id);

    ///@brief Get the company alternative names by ID.
    ///@param company_id The ID of the company.
    ///@return A QJsonObject containing the company alternative names.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject company_alternativeNames(int32_t company_id);

    ///@brief Get the company images by ID.
    ///@param company_id The ID of the company.
    ///@return A QJsonObject containing the company images.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject company_images(int32_t company_id);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Configuration    -------------------------------------------------|
    ///@brief Query the API configuration details.
    ///@return A QJsonObject containing some of the required information you'll need as you integrate our API.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject config_details();

    ///@brief Get the list of countries (ISO 3166-1 tags) used throughout TMDB.
    ///@param language The language to use for the results, default is "en-US".
    ///@return A QJsonArray containing the list of countries.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonArray config_countries(std::string language = "en-US");

    ///@brief Get the list of the jobs and departments we use on TMDB.
    ///@return A QJsonArray containing the list of departments and associated jobs.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonArray config_jobs();

    ///@brief Get the list of languages (ISO 639-1 tags) used throughout TMDB.
    ///@return A QJsonArray containing the list of languages on TMDB.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonArray config_languages();

    ///@brief Get a list of the officially supported translations on TMDB.
    ///@return A QJsonArray containing the translations we support for localizing the website with which means they are "primary" translations.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonArray config_primaryTranslations();

    ///@brief Get the list of timezones used throughout TMDB.
    ///@return A QJsonArray containing the list of timezones.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonArray config_timezones();
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Credits    -------------------------------------------------|
    ///@brief Get a movie or TV credit details by ID.
    ///@return A QJsonObject containing the credit details.
    ///@param credit_id The ID of the credit.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject credits_details(std::string credit_id);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Genres    -------------------------------------------------|
    ///@brief Get the list of official genres for movies.
    ///@return A QJsonObject containing the list of genres for movies.
    ///@param language The language to use for the results, default is "en".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject genres_movie(std::string language = "en");

    ///@brief Get the list of official genres for TV shows.
    ///@return A QJsonObject containing the list of genres for TV shows.
    ///@param language The language to use for the results, default is "en".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject genres_tv(std::string language = "en");
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Movies    -------------------------------------------------|
    ///@brief Get a list of movies that are currently in theatres.
    ///@return A QJsonObject containing the list of movies.
    ///@param region The region to use for the results, default is "US".
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject movieList_nowPlaying(std::string region, std::string language = "en-US", int32_t page = 1);

    ///@brief Get a list of movies ordered by popularity.
    ///@return A QJsonObject containing the list of movies.
    ///@param region The region to use for the results, default is "US".
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject movieList_popular(std::string region, std::string language = "en-US", int32_t page = 1);

    ///@brief Get a list of movies ordered by rating.
    ///@return A QJsonObject containing the list of movies.
    ///@param region The region to use for the results, default is "US".
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject movieList_topRated(std::string region, std::string language = "en-US", int32_t page = 1);

    ///@brief Get a list of movies that are being released soon.
    ///@return A QJsonObject containing the list of movies.
    ///@param region The region to use for the results, default is "US".
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject movieList_upcoming(std::string region, std::string language = "en-US", int32_t page = 1);

    ///@brief Get the top level details of a movie by ID.
    ///@return A QJsonObject containing the movie details.
    ///@param movie_id The ID of the movie.
    ///@param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject movie_details(int32_t movie_id, std::string language = "en-US");

    ///@brief Get the alternative titles for a movie.
    ///@return A QJsonObject containing the alternative titles.
    ///@param movie_id The ID of the movie.
    ///@param country The country to use for the results, default is "US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject movie_alternativeTitles(int32_t movie_id, std::string country = "");

    ///@brief Get the recent changes for a movie.
    ///@return A QJsonObject containing the recent changes for a movie.
    ///@param movie_id The ID of the movie.
    ///@param start_date The start date for the changes, default is 2023-10-22.
    ///@param end_date The end date for the changes, default is 2023-10-22.
    ///@param page The page number to retrieve, default is 1.
    ///@note start_date and end_date cannot be more than 14 days apart.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject movie_changes(int32_t movie_id, QDate start_date = QDate(2023, 10, 22),
                              QDate end_date = QDate(2023, 10, 22), int32_t page = 1);

    ///@brief Get the credits for a movie.
    ///@return A QJsonObject containing the credits for a movie.
    ///@param movie_id The ID of the movie.
    ///@param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject movie_credits(int32_t movie_id, std::string language = "en-US");

    ///@brief Get the IDs on external services for a movie.
    ///@return A QJsonObject containing the IDs.
    ///@param movie_id The ID of the movie.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject movie_externalIDs(int32_t movie_id);

    ///@brief Get the images that belong to a movie.
    ///@return A QJsonObject containing the IDs.
    ///@param movie_id The ID of the movie.
    ///@param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject movie_images(int32_t movie_id, std::string language);

    ///@brief Get the keywords that belong to a movie.
    ///@return A QJsonObject containing the keywords.
    ///@param movie_id The ID of the movie.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject movie_keywords(int32_t movie_id);

    ///@brief Get the newest movie ID.
    ///@return A QJsonObject containing the movie.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject movie_latest();

    ///@brief Get the lists that a movie has been added to.
    ///@return A QJsonObject containing the lists.
    ///@param movie_id The ID of the movie.
    ///@param page The page number to retrieve, default is 1.
    ///@param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject movie_lists(int32_t movie_id, int32_t page = 1, std::string language = "en-US");

    ///@brief Get movie recommendations based on a movie ID.
    ///@return A QJsonObject containing the other movies.
    ///@param movie_id The ID of the movie.
    ///@param page The page number to retrieve, default is 1.
    ///@param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject movie_recommendations(int32_t movie_id, std::string language = "en-US", int32_t page = 1);

    ///@brief Get the release dates and certifications for a movie.
    ///@return A QJsonObject containing the movie release dates and certifications.
    ///@param movie_id The ID of the movie.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject movie_releaseDates(int32_t movie_id);

    ///@brief Get the user reviews for a movie.
    ///@return A QJsonObject containing the movie reviews.
    ///@param movie_id The ID of the movie.
    ///@param page The page number to retrieve, default is 1.
    ///@param language The language to use for the results, default is "en-US"
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject movie_reviews(int32_t movie_id, std::string language = "en-US", int32_t page = 1);

    ///@brief Get the similar movies based on genres and keywords.
    ///@return A QJsonObject containing the movies.
    ///@param movie_id The ID of the movie.
    ///@param page The page number to retrieve, default is 1.
    ///@param language The language to use for the results, default is "en-US"
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject movie_similar(int32_t movie_id, std::string language = "en-US", int32_t page = 1);

    ///@brief Get the translations for a movie.
    ///@return A QJsonObject containing the translations.
    ///@param movie_id The ID of the movie.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject movie_translations(int32_t movie_id);

    ///@brief Get the videos for a movie.
    ///@return A QJsonObject containing the videos.
    ///@param movie_id The ID of the movie.
    ///@param language The language to use for the results, default is "en-US"
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject movie_videos(int32_t movie_id, std::string language = "en-US");

    ///@brief Get the list of streaming providers we have for a movie.
    ///@return A QJsonObject containing the streaming videos per country.
    ///@param movie_id The ID of the movie.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    ///Streaming provider data provided by JustWatch.
    QJsonObject movie_watchProviders(int32_t movie_id);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Networks    -------------------------------------------------|
    ///@brief Get the details of a network by ID.
    ///@return A QJsonObject containing the network details.
    ///@param network_id The ID of the network.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject network_details(int32_t network_id);

    ///@brief Get the alternative names of a network by ID.
    ///@return A QJsonObject containing the network names.
    ///@param network_id The ID of the network.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject network_alternativeNames(int32_t network_id);

    ///@brief Get the images of a network by ID.
    ///@return A QJsonObject containing the network images.
    ///@param network_id The ID of the network.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject network_images(int32_t network_id);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    People    -------------------------------------------------|
    ///@brief Get a list of people ordered by popularity.
    ///@return A QJsonObject containing the people.
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject people_popular(std::string language = "en-US", int32_t page = 1);

    ///@brief Query the top level details of a person.
    ///@return A QJsonObject containing the person details.
    ///@param person_id The ID of the person.
    ///@param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject people_details(int32_t person_id, std::string language = "en-US");

    ///@brief Get the recent changes for a person.
    ///@return A QJsonObject containing the person changes.
    ///@param person_id The ID of the person.
    ///@param start_date The start date for the changes, default is 2023-10-22.
    ///@param end_date The end date for the changes, default is 2023-10-22.
    ///@param page The page number to retrieve, default is 1.
    ///@note start_date and end_date cannot be more than 14 days apart.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject people_changes(int32_t person_id, QDate start_date = QDate(2023, 10, 22),
                               QDate end_date = QDate(2023, 10, 22), int32_t page = 1);

    ///@brief Get the combined movie and TV credits that belong to a person.
    ///@return A QJsonObject containing the person credits.
    ///@param person_id The ID of the person.
    ///@param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject people_combinedCredits(int32_t person_id, std::string language = "en-US");

    ///@brief Get the external ID's that belong to a person.
    ///@return A QJsonObject containing the persons IDs.
    ///@param person_id The ID of the person.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject people_externalIDs(int32_t person_id);

    ///@brief Get the profile images that belong to a person.
    ///@return A QJsonObject containing the persons images.
    ///@param person_id The ID of the person.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject people_images(int32_t person_id);

    ///@brief Get the newest created person. This is a live response and will continuously change.
    ///@return A QJsonObject containing the latest person details.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject people_latest();

    ///@brief Get the movie credits for a person.
    ///@return A QJsonObject containing the person credits.
    ///@param person_id The ID of the person.
    ///@param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject people_movieCredits(int32_t person_id, std::string language = "en-US");

    ///@brief Get the TV credits for a person.
    ///@return A QJsonObject containing the person credits.
    ///@param person_id The ID of the person.
    ///@param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject people_tvCredits(int32_t person_id, std::string language = "en-US");

    ///@brief Get the translations that belong to a person.
    ///@return A QJsonObject containing the persons translations.
    ///@param person_id The ID of the person.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject people_translations(int32_t person_id);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Reviews    -------------------------------------------------|
    ///@brief Retrieve the details of a movie or TV show review.
    ///@return A QJsonObject containing the details of the review.
    ///@param review_id The ID of the review.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject reviews_details(std::string review_id);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Queryable searchers    -------------------------------------------------|
    ///@brief Search for collections by their original, translated and alternative names.
    ///@return A QJsonObject containing the collections.
    ///@param query The search query string.
    ///@param include_adult Whether to include adult content in the results, default is false.
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@param region The region to use for the results, default is an empty string.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject get_collection(std::string query, bool include_adult = false, std::string language = "en-US",
                               int32_t page = 1, std::string region = "");

    ///@brief Search for companies by their original and alternative names.
    ///@return A QJsonObject containing the companies.
    ///@param query The search query string.
    ///@param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject get_company(std::string query, int32_t page = 1);

    ///@brief Search for keywords by their name.
    ///@return A QJsonObject containing the keywords.
    ///@param query The search query string.
    ///@param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject get_keyword(std::string query, int32_t page = 1);

    ///@brief Search for movies by their original, translated and alternative titles.
    ///@return A QJsonObject containing the movies.
    ///@param query The search query string.
    ///@param page The page number to retrieve, default is 1.
    /// @param include_adult Whether to include adult content in the results, default is false.
    /// @param language The language to use for the results, default is "en-US".
    /// @param primary_release_year The primary release year to filter the results, this parameter is optional.
    /// @param region The region to use for the results, default is "en-GB".
    /// @param year The year to filter the results, this parameter is optional.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject get_movie(std::string query, bool include_adult = false, std::string language = "en-US",
                          std::string primary_release_year = "", int32_t page = 1, std::string region = "en-GB",
                          std::string year = "");

    ///@brief Search for people by their name and also known as names.
    ///@return A QJsonObject containing the people.
    ///@param query The search query string.
    ///@param page The page number to retrieve, default is 1.
    /// @param include_adult Whether to include adult content in the results, default is false.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject get_person(std::string query, bool include_adult = false, std::string language = "en-US",
                           int32_t page = 1);

    ///@brief Search for TV shows by their original, translated and also known as names.
    ///@return A QJsonObject containing the TV shows.
    ///@param query The search query string.
    ///@param page The page number to retrieve, default is 1.
    /// @param include_adult Whether to include adult content in the results, default is false.
    /// @param language The language to use for the results, default is "en-US".
    /// @param first_air_date_year The year of the first air date to filter the results, this parameter is optional.
    /// @param year The year to filter the results, this parameter is optional.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject get_tv(std::string query, int32_t first_air_date_year = 0, bool include_adult = false,
                       std::string language = "en-US", int32_t page = 1, int32_t year = 0);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Trending    -------------------------------------------------|
    ///@brief Get the trending movies on TMDB.
    ///@return A QJsonObject containing the movies.
    /// @param time_window The time window to use for the results, default is "day".
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject trending_movies(tmdb::timeWindow::timeWindow time_window = tmdb::timeWindow::timeWindow::day,
                                std::string language = "en-US");

    ///@brief Get the trending people on TMDB.
    ///@return A QJsonObject containing the people.
    /// @param time_window The time window to use for the results, default is "day".
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject trending_people(tmdb::timeWindow::timeWindow time_window = tmdb::timeWindow::timeWindow::day,
                                std::string language = "en-US");

    ///@brief Get the trending TV shows on TMDB.
    ///@return A QJsonObject containing the TV shows.
    /// @param time_window The time window to use for the results, default is "day".
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject trending_tv(tmdb::timeWindow::timeWindow time_window, std::string language = "en-US");
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    TV Series    -------------------------------------------------|
    ///@brief Get a list of TV shows airing today.
    ///@return A QJsonObject containing the TV shows.
    /// @param language The language to use for the results, default is "en-US".
    /// @param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_series_airingToday(std::string language = "en-US", int32_t page = 1,
                                      std::string timezone = "America/New_York");

    ///@brief Get a list of TV shows that air in the next 7 days.
    ///@return A QJsonObject containing the TV shows.
    /// @param language The language to use for the results, default is "en-US".
    /// @param page The page number to retrieve, default is 1.
    /// @param timezone The timezone to use for the results, default is "America/New_York".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_series_onTheAir(std::string language = "en-US", int32_t page = 1,
                                   std::string timezone = "America/New_York");

    ///@brief Get a list of TV shows ordered by popularity.
    ///@return A QJsonObject containing the TV shows.
    /// @param language The language to use for the results, default is "en-US".
    /// @param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_series_popular(std::string language = "en-US", int32_t page = 1);

    ///@brief Get a list of TV shows ordered by rating.
    ///@return A QJsonObject containing the TV shows.
    /// @param language The language to use for the results, default is "en-US".
    /// @param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_series_topRated(std::string language = "en-US", int32_t page = 1);

    ///@brief Get the details of a TV show.
    ///@return A QJsonObject containing the TV show.
    /// @param series_id The ID of the TV series.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_series_details(int32_t series_id, std::string language = "en-US");

    ///@brief Get the aggregate credits (cast and crew) that have been added to a TV show.
    ///@return A QJsonObject containing the TV show cast and crew.
    /// @param series_id The ID of the TV series.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_series_aggregateCredits(int32_t series_id, std::string language = "en-US");

    ///@brief Get the alternative titles that have been added to a TV show.
    ///@return A QJsonObject containing the TV shows alternative titles.
    /// @param series_id The ID of the TV series.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_series_alternativeTitles(int32_t series_id);

    ///@brief Get the recent changes for a TV show.
    ///@return A QJsonObject containing the TV shows recent changes.
    /// @param series_id The ID of the TV series.
    /// @param start_date The start date for the changes, default is 2023-10-22.
    /// @param end_date The end date for the changes, default is 2023-10-22.
    /// @param page The page number to retrieve, default is 1.
    ///@note start_date and end_date cannot be more than 14 days apart.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_series_changes(int32_t series_id, QDate start_date = QDate(2023, 10, 22),
                                  QDate end_date = QDate(2023, 10, 22), int32_t page = 1);

    ///@brief Get the content ratings that have been added to a TV show.
    ///@return A QJsonObject containing the TV shows content ratings.
    /// @param series_id The ID of the TV series.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_series_contentRatings(int32_t series_id);

    ///@brief Get the latest season credits of a TV show.
    ///@return A QJsonObject containing the TV shows credits.
    /// @param series_id The ID of the TV series.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_series_credits(int32_t series_id, std::string language = "en-US");

    ///@brief Get the episode groups that have been added to a TV show.
    ///@return A QJsonObject containing the TV shows episode groups.
    /// @param series_id The ID of the TV series.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_series_episodeGroups(int32_t series_id);

    ///@brief Get a list of external IDs that have been added to a TV show.
    ///@return A QJsonObject containing the TV shows IDs on other sites.
    /// @param series_id The ID of the TV series.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_series_externalIDs(int32_t series_id);

    ///@brief Get the images that belong to a TV series.
    ///@return A QJsonObject containing the TV shows images.
    /// @param series_id The ID of the TV series.
    /// @param language The language to use for the results, default is "en".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_series_images(int32_t series_id, std::string language = "en");

    ///@brief Get a list of keywords that have been added to a TV show.
    ///@return A QJsonObject containing the TV shows keywords.
    /// @param series_id The ID of the TV series.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_series_keywords(int32_t series_id);

    ///@brief Get the newest TV show ID.
    ///@return A QJsonObject containing the TV show.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_series_latest();

    ///@brief Get the lists that a TV series has been added to.
    ///@return A QJsonObject containing the lists.
    /// @param series_id The ID of the TV series.
    /// @param page The page number to retrieve, default is 1.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_series_lists(int32_t series_id, int32_t page = 1, std::string language = "en-US");

    ///@brief Get a list of recommended TV series based on a TV series ID.
    ///@return A QJsonObject containing the TV shows.
    /// @param series_id The ID of the TV series.
    /// @param page The page number to retrieve, default is 1.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_series_recommendations(int32_t series_id, std::string language = "en-US", int32_t page = 1);

    ///@brief Get the reviews that have been added to a TV show.
    ///@return A QJsonObject containing the TV show's reviews.
    /// @param series_id The ID of the TV series.
    /// @param page The page number to retrieve, default is 1.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_series_reviews(int32_t series_id, std::string language = "en-US", int32_t page = 1);

    ///@brief Get the seasons and episodes that have screened theatrically.
    ///@return A QJsonObject containing the TV seasons and episodes.
    /// @param series_id The ID of the TV series.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_series_screenedTheatrically(int32_t series_id);

    ///@brief Get the similar TV shows.
    ///@return A QJsonObject containing the TV shows.
    /// @param series_id The ID of the TV series.
    /// @param language The language to use for the results, default is "en-US".
    /// @param page The page number to retrieve, default is 1.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_series_similar(int32_t series_id, std::string language = "en-US", int32_t page = 1);

    ///@brief Get the translations that have been added to a TV show.
    ///@return A QJsonObject containing the TV show's translations.
    /// @param series_id The ID of the TV series.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_series_translations(int32_t series_id);

    ///@brief Get the videos that belong to a TV show.
    ///@return A QJsonObject containing the TV show's videos.
    /// @param series_id The ID of the TV series.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_series_videos(int32_t series_id, std::string language = "en-US");

    ///@brief Get the list of streaming providers we have for a TV show.
    ///@return A QJsonObject containing the TV show's watch providers.
    /// @param series_id The ID of the TV series.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    ///Streaming provider data provided by JustWatch.
    QJsonObject tv_series_watchProviders(int32_t series_id);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    TV Season    -------------------------------------------------|
    ///@brief Query the details of a TV season.
    ///@return A QJsonObject containing the TV series details.
    /// @param series_id The ID of the TV series.
    /// @param season_number The season number of the TV series.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_seasons_details(int32_t series_id, int32_t season_number, std::string language = "en-US");

    ///@brief Get the aggregate credits (cast and crew) that have been added to a TV season.
    ///@return A QJsonObject containing the TV series credits.
    /// @param series_id The ID of the TV series.
    /// @param season_number The season number of the TV series.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_seasons_aggregateCredits(int32_t series_id, int32_t season_number, std::string language = "en-US");

    ///@brief Get the recent changes for a TV season.
    ///@return A QJsonObject containing the changes for a TV season. By default only the last 24 hours are returned.
    /// @param season_id The ID of the TV season.
    /// @param start_date The start date for the changes, default is 2023-10-22.
    /// @param end_date The end date for the changes, default is 2023-10-22.
    /// @param page The page number to retrieve, default is 1.
    ///@note start_date and end_date cannot be more than 14 days apart.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_seasons_changes(int32_t season_id, QDate start_date = QDate(2023, 10, 22),
                                   QDate end_date = QDate(2023, 10, 22), int32_t page = 1);

    ///@brief Get the credits (cast and crew) that have been added to the most recent season of the TV show.
    ///@return A QJsonObject containing the TV series credits.
    /// @param series_id The ID of the TV series.
    /// @param season_number The season number of the TV series.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_seasons_credits(int32_t series_id, int32_t season_number, std::string language = "en-US");

    ///@brief Get a list of external IDs that have been added to a TV season.
    ///@return A QJsonObject containing the TV series' external IDs.
    /// @param series_id The ID of the TV series.
    /// @param season_number The season number of the TV series.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_seasons_externalIDs(int32_t series_id, int32_t season_number);

    ///@brief Get the images that belong to a TV season.
    ///@return A QJsonObject containing the TV series' images.
    /// @param series_id The ID of the TV series.
    /// @param season_number The season number of the TV series.
    /// @param language The language to use for the results, default is "en".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_seasons_images(int32_t series_id, int32_t season_number, std::string language = "en");

    ///@brief Get the videos that belong to a TV season.
    ///@return A QJsonObject containing the TV series' videos.
    /// @param series_id The ID of the TV series.
    /// @param season_number The season number of the TV series.
    /// @param language The language to use for the results, default is "en".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_seasons_videos(int32_t series_id, int32_t season_number, std::string language = "en");

    ///@brief Get the translations for a TV season.
    ///@return A QJsonObject containing the TV series' translations.
    /// @param series_id The ID of the TV series.
    /// @param season_number The season number of the TV series.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_seasons_translations(int32_t series_id, int32_t season_number);

    ///@brief Get the list of streaming providers we have for a TV season.
    ///@return A QJsonObject containing the TV series' streaming providers.
    /// @param series_id The ID of the TV series.
    /// @param season_number The season number of the TV series.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    ///Streaming provider data provided by JustWatch.
    QJsonObject tv_seasons_watchProviders(int32_t series_id, int32_t season_number);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    TV Episode    -------------------------------------------------|
    ///@brief Query the details of a TV episode.
    ///@return A QJsonObject containing the TV episode details.
    /// @param series_id The ID of the TV series.
    /// @param season_number The season number of the TV series.
    /// @param episode_number The episode number of the TV series.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_episodes_details(int32_t series_id, int32_t season_number, int32_t episode_number,
                                    std::string language = "en-US");

    ///@brief Get the recent changes for a TV episode.
    ///@return A QJsonObject containing the changes for a TV episode. By default only the last 24 hours are returned.
    /// @param episode_id The ID of the TV episode.
    /// @param start_date The start date for the changes, default is 2023-10-22.
    /// @param end_date The end date for the changes, default is 2023-10-22.
    /// @param page The page number to retrieve, default is 1.
    ///@note start_date and end_date cannot be more than 14 days apart.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_episodes_changes(int32_t episode_id, QDate start_date = QDate(2023, 10, 22),
                                    QDate end_date = QDate(2023, 10, 22), int32_t page = 1);

    ///@brief Query the credits of a TV episode.
    ///@return A QJsonObject containing the TV episode credits.
    /// @param series_id The ID of the TV series.
    /// @param season_number The season number of the TV series.
    /// @param episode_number The episode number of the TV series.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_episodes_credits(int32_t series_id, int32_t season_number, int32_t episode_number,
                                    std::string language = "en-US");

    ///@brief Get a list of external IDs that have been added to a TV episode.
    ///@return A QJsonObject containing the IDs of a TV episode on other sites.
    /// @param series_id The ID of the TV series.
    /// @param season_number The season number of the TV series.
    /// @param episode_number The episode number of the TV series.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_episodes_externalIDs(int32_t series_id, int32_t season_number, int32_t episode_number);

    ///@brief Get the images that belong to a TV episode.
    ///@return A QJsonObject containing the TV episode's images.
    /// @param series_id The ID of the TV series.
    /// @param season_number The season number of the TV series.
    /// @param episode_number The episode number of the TV series.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_episodes_images(int32_t series_id, int32_t season_number, int32_t episode_number,
                                   std::string language = "en-US");

    ///@brief Get the translations that have been added to a TV episode.
    ///@return A QJsonObject containing the translations of a TV episode.
    /// @param series_id The ID of the TV series.
    /// @param season_number The season number of the TV series.
    /// @param episode_number The episode number of the TV series.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_episodes_translations(int32_t series_id, int32_t season_number, int32_t episode_number);

    ///@brief Get the videos that belong to a TV episode.
    ///@return A QJsonObject containing the TV episode's videos.
    /// @param series_id The ID of the TV series.
    /// @param season_number The season number of the TV series.
    /// @param episode_number The episode number of the TV series.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject tv_episodes_videos(int32_t series_id, int32_t season_number, int32_t episode_number,
                                   std::string language = "en-US");
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Watch Providers    -------------------------------------------------|
    ///@brief Get the list of the countries we have watch provider (OTT/streaming) data for.
    ///@return A QJsonObject containing the countries and their available watch providers.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject watchProviders_regions(std::string language = "en-US");

    ///@brief Get the list of streaming providers we have for movies.
    ///@return A QJsonObject containing the watch provider (OTT/streaming) data we have available for movies.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject watchProviders_movie(std::string language = "en-US");

    ///@brief Get the list of streaming providers we have for TV shows.
    ///@return A QJsonObject containing the watch provider (OTT/streaming) data we have available for TV shows.
    /// @param language The language to use for the results, default is "en-US".
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject watchProviders_tv(std::string language = "en-US");
    //|-----------------------------------------------------------------------------------------------------|
    //|-----------------------------------------------------------------------------------------------------|
private:
    const std::string _m_baseUrl = "https://api.themoviedb.org/3/";
    QJsonObject _runGetRequest(std::string i_request, std::map<std::string, std::string> i_params = {});
    QJsonArray _runGetRequestArray(std::string i_request, std::map<std::string, std::string> i_params = {});
    std::string _m_accessToken;
};
