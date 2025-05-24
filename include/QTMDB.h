#include <QObject>

#include "timeWindow.h"
#include <QDate>
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
/// @cite Special THanks to JustWatch for access to data for the TMDB API
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
    ///@brief Get the details of an account.
    ///@param account_id The ID of the account.
    ///@return A QJsonObject containing the account details.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject account_details(int32_t account_id);

    ///@brief Gets the favorite movies of an account.
    ///@param account_id The ID of the account.
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@return A QJsonObject containing the account's favourite movies.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject account_favoriteMovies(int32_t account_id, std::string language = "en-US", int32_t page = 1);

    ///@brief Gets the favorite TV Shows of an account.
    ///@param account_id The ID of the account.
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@return A QJsonObject containing the account's favourite TV Shows.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject account_favoriteTV(int32_t account_id, std::string language = "en-US", int32_t page = 1);

    ///@brief Gets the lists created by an account.
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

    ///@brief Gets the movies from the account's watchlist.
    ///@param account_id The ID of the account.
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@return A QJsonObject containing the movies from the account's watchlist.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject account_watchlistMovies(int32_t account_id, std::string language = "en-US", int32_t page = 1);

    ///@brief Gets the TV shows from the account's watchlist.
    ///@param account_id The ID of the account.
    ///@param language The language to use for the results, default is "en-US".
    ///@param page The page number to retrieve, default is 1.
    ///@return A QJsonObject containing the TV shows from the account's watchlist.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject account_watchlistTV(int32_t account_id, std::string language = "en-US", int32_t page = 1);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Certifications    -------------------------------------------------|
    ///@brief Gets the certifications for movies for all countries.
    ///@return A QJsonObject containing the certifications for all countries for movies.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject certifications_movie();
    ///@brief Gets the certifications for TV Shows for all countries.
    ///@return A QJsonObject containing the certifications for all countries for TV shows.
    ///@details For more information, see the TMDB API documentation: @link https://developers.themoviedb.org/3/accounts/get-account-details @endlink
    QJsonObject certifications_tv();
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Changes    -------------------------------------------------|
    QJsonObject changes_movie(QDate end_date = QDate(2023, 10, 22), QDate start_date = QDate(2023, 10, 22),
                              int32_t page = 1);
    QJsonObject changes_people(QDate end_date = QDate(2023, 10, 22), QDate start_date = QDate(2023, 10, 22),
                               int32_t page = 1);
    QJsonObject changes_tv(QDate end_date = QDate(2023, 10, 22), QDate start_date = QDate(2023, 10, 22),
                           int32_t page = 1);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Collection    -------------------------------------------------|
    QJsonObject collection_details(int32_t collection_id, std::string language = "en-US");
    QJsonObject collection_images(int32_t collection_id, std::string language = "en");
    QJsonObject collection_translations(int32_t collection_id);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Company    -------------------------------------------------|
    QJsonObject company_details(int32_t company_id);
    QJsonObject company_alternativeNames(int32_t company_id);
    QJsonObject company_images(int32_t company_id);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Configuration    -------------------------------------------------|
    QJsonObject config_details();
    QJsonArray config_countries(std::string language = "en-US");
    QJsonArray config_jobs();
    QJsonArray config_languages();
    QJsonArray config_primaryTranslations();
    QJsonArray config_timezones();
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Credits    -------------------------------------------------|
    QJsonObject credits_details(std::string credit_id);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Genres    -------------------------------------------------|
    QJsonObject genres_movie(std::string language = "en");
    QJsonObject genres_tv(std::string language = "en");
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Movies    -------------------------------------------------|
    QJsonObject movieList_nowPlaying(std::string region, std::string language = "en-US", int32_t page = 1);
    QJsonObject movieList_popular(std::string region, std::string language = "en-US", int32_t page = 1);
    QJsonObject movieList_topRated(std::string region, std::string language = "en-US", int32_t page = 1);
    QJsonObject movieList_upcoming(std::string region, std::string language = "en-US", int32_t page = 1);

    QJsonObject movie_details(int32_t movie_id, std::string language = "en-US");
    QJsonObject movie_alternativeTitles(int32_t movie_id, std::string country = "US");
    QJsonObject movie_changes(int32_t movie_id, QDate start_date = QDate(2023, 10, 22),
                              QDate end_date = QDate(2023, 10, 22), int32_t page = 1);
    QJsonObject movie_credits(int32_t movie_id, std::string language = "en-US");
    QJsonObject movie_externalIDs(int32_t movie_id);
    QJsonObject movie_images(int32_t movie_id, std::string language);
    QJsonObject movie_keywords(int32_t movie_id);
    QJsonObject movie_latest();
    QJsonObject movie_lists(int32_t movie_id, int32_t page = 1, std::string language = "en-US");
    QJsonObject movie_recommendations(int32_t movie_id, std::string language = "en-US", int32_t page = 1);
    QJsonObject movie_releaseDates(int32_t movie_id);
    QJsonObject movie_reviews(int32_t movie_id, std::string language = "en-US", int32_t page = 1);
    QJsonObject movie_similar(int32_t movie_id, std::string language = "en-US", int32_t page = 1);
    QJsonObject movie_translations(int32_t movie_id);
    QJsonObject movie_videos(int32_t movie_id, std::string language = "en-US");
    QJsonObject movie_watchProviders(int32_t movie_id);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Networks    -------------------------------------------------|
    QJsonObject network_details(int32_t network_id);
    QJsonObject network_alternativeNames(int32_t network_id);
    QJsonObject network_images(int32_t network_id);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    People    -------------------------------------------------|
    QJsonObject people_popular(std::string language = "en-US", int32_t page = 1);
    QJsonObject people_details(int32_t person_id, std::string language = "en-US");
    QJsonObject people_changes(int32_t person_id, QDate start_date = QDate(2023, 10, 22),
                               QDate end_date = QDate(2023, 10, 22), int32_t page = 1);
    QJsonObject people_combinedCredits(int32_t person_id, std::string language = "en-US");
    QJsonObject people_externalIDs(int32_t person_id);
    QJsonObject people_images(int32_t person_id);
    QJsonObject people_latest();
    QJsonObject people_movieCredits(int32_t person_id, std::string language = "en-US");
    QJsonObject people_tvCredits(int32_t person_id, std::string language = "en-US");
    QJsonObject people_taggedImages(int32_t person_id, int32_t page = 1);
    QJsonObject people_translations(int32_t person_id);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Reviews    -------------------------------------------------|
    QJsonObject reviews_details(std::string review_id);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Queryable searchers    -------------------------------------------------|
    QJsonObject get_collection(std::string query, bool include_adult = false, std::string language = "en-US",
                               int32_t page = 1, std::string region = "");
    QJsonObject get_company(std::string query, int32_t page = 1);
    QJsonObject get_keyword(std::string query, int32_t page = 1);
    QJsonObject get_movie(std::string query, bool include_adult = false, std::string language = "en-US",
                          std::string primary_release_year = "", int32_t page = 1, std::string region = "en-GB",
                          std::string year = "");
    QJsonObject get_person(std::string query, bool include_adult = false, std::string language = "en-US",
                           int32_t page = 1);
    QJsonObject get_tv(std::string query, int32_t first_air_date_year = 0, bool include_adult = false,
                       std::string langauge = "en-US", int32_t page = 1, int32_t year = 0);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Trending    -------------------------------------------------|
    QJsonObject trending_movies(timeWindow::timeWindow time_window = timeWindow::timeWindow::day,
                                std::string language = "en-US");
    QJsonObject trending_people(timeWindow::timeWindow time_window = timeWindow::timeWindow::day,
                                std::string language = "en-US");
    QJsonObject trending_tv(timeWindow::timeWindow time_window, std::string language = "en-US");
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    TV Series    -------------------------------------------------|
    QJsonObject tv_series_airingToday(std::string language = "en-US", int32_t page = 1,
                                      std::string timezone = "America/New_York");
    QJsonObject tv_series_onTheAir(std::string language = "en-US", int32_t page = 1,
                                   std::string timezone = "America/New_York");
    QJsonObject tv_series_popular(std::string language = "en-US", int32_t page = 1);
    QJsonObject tv_series_topRated(std::string language = "en-US", int32_t page = 1);

    QJsonObject tv_series_details(int32_t series_id, std::string language = "en-US");
    QJsonObject tv_series_aggregateCredits(int32_t series_id, std::string language = "en-US");
    QJsonObject tv_series_alternativeTitles(int32_t series_id);
    QJsonObject tv_series_changes(int32_t series_id, QDate start_date = QDate(2023, 10, 22),
                                  QDate end_date = QDate(2023, 10, 22), int32_t page = 1);
    QJsonObject tv_series_contentRatings(int32_t series_id);
    QJsonObject tv_series_credits(int32_t series_id, std::string language = "en-US");
    QJsonObject tv_series_episodeGroups(int32_t series_id);
    QJsonObject tv_series_externalIDs(int32_t series_id);
    QJsonObject tv_series_images(int32_t series_id, std::string language = "en");
    QJsonObject tv_series_keywords(int32_t series_id);
    QJsonObject tv_series_latest();
    QJsonObject tv_series_lists(int32_t series_id, int32_t page = 1, std::string language = "en-US");
    QJsonObject tv_series_recommendations(int32_t series_id, std::string language = "en-US", int32_t page = 1);
    QJsonObject tv_series_reviews(int32_t series_id, std::string language = "en-US", int32_t page = 1);
    QJsonObject tv_series_screenedTheatrically(int32_t series_id);
    QJsonObject tv_series_similar(int32_t series_id, std::string language = "en-US", int32_t page = 1);
    QJsonObject tv_series_translations(int32_t series_id);
    QJsonObject tv_series_videos(int32_t series_id, std::string language = "en-US");
    QJsonObject tv_series_watchProviders(int32_t series_id);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    TV Season    -------------------------------------------------|
    QJsonObject tv_seasons_details(int32_t series_id, int32_t season_number, std::string language = "en-US");
    QJsonObject tv_seasons_aggregateCredits(int32_t series_id, int32_t season_number, std::string language = "en-US");
    QJsonObject tv_seasons_changes(int32_t season_id, QDate start_date = QDate(2023, 10, 22),
                                   QDate end_date = QDate(2023, 10, 22), int32_t page = 1);
    QJsonObject tv_seasons_credits(int32_t series_id, int32_t season_number, std::string language = "en-US");
    QJsonObject tv_seasons_externalIDs(int32_t series_id, int32_t season_number);
    QJsonObject tv_seasons_images(int32_t series_id, int32_t season_number, std::string language = "en");
    QJsonObject tv_seasons_videos(int32_t series_id, int32_t season_number, std::string language = "en");
    QJsonObject tv_seasons_translations(int32_t series_id, int32_t season_number);
    QJsonObject tv_seasons_watchProviders(int32_t series_id, int32_t season_number);
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    TV Episode    -------------------------------------------------|
    QJsonObject tv_episodes_details(int32_t series_id, int32_t season_number, int32_t episode_number,
                                    std::string language = "en-US");
    QJsonObject tv_episodes_changes(int32_t episode_id, QDate start_date = QDate(2023, 10, 22),
                                    QDate end_date = QDate(2023, 10, 22), int32_t page = 1);
    QJsonObject tv_episodes_credits(int32_t series_id, int32_t season_number, int32_t episode_number,
                                    std::string language = "en-US");
    QJsonObject tv_episodes_externalIDs(int32_t series_id, int32_t season_number, int32_t episode_number);
    QJsonObject tv_episodes_images(int32_t series_id, int32_t season_number, int32_t episode_number,
                                   std::string language = "en-US");
    QJsonObject tv_episodes_translations(int32_t series_id, int32_t season_number, int32_t episode_number);
    QJsonObject tv_episodes_videos(int32_t series_id, int32_t season_number, int32_t episode_number,
                                   std::string language = "en-US");
    //|-----------------------------------------------------------------------------------------------------|

    //|-------------------------------------    Watch Providers    -------------------------------------------------|
    QJsonObject watchProviders_regions(std::string language = "en-US");
    QJsonObject watchProviders_movie(std::string language = "en-US");
    QJsonObject watchProviders_tv(std::string language = "en-US");

private:
    const std::string _m_baseUrl = "https://api.themoviedb.org/3/";
    QJsonObject _runGetRequest(std::string i_request, std::map<std::string, std::string> i_params = {});
    QJsonArray _runGetRequestArray(std::string i_request, std::map<std::string, std::string> i_params = {});
    std::string _m_accessToken;
};
