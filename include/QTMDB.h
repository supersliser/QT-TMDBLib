#include <QObject>

#include "timeWindow.h"
#include "timeWindow.h"

class Qtmdb : public QObject
{
    Q_OBJECT
public:
    explicit Qtmdb(std::string_view i_accessToken, QObject *parent = nullptr);
    ~Qtmdb() override = default;
    std::string_view accessToken();
    void setAccessToken(std::string_view i_accessToken);

    QJsonObject account_details(int32_t account_id);
    QJsonObject account_favoriteMovies(int32_t account_id, std::string_view language = "en-US", int32_t page = 1);
    QJsonObject account_favoriteTV(int32_t account_id, std::string_view language = "en-US", int32_t page = 1);
    QJsonObject account_lists(int32_t account_id, int32_t page = 1);
    QJsonObject account_ratedMovies(int32_t account_id, std::string_view language = "en-US", int32_t page = 1);
    QJsonObject account_ratedTV(int32_t account_id, std::string_view language = "en-US", int32_t page = 1);
    QJsonObject account_ratedTVEpisodes(int32_t account_id, std::string_view language = "en-US", int32_t page = 1);
    QJsonObject account_watchlistMovies(int32_t account_id, std::string_view language = "en-US", int32_t page = 1);
    QJsonObject account_watchlistTV(int32_t account_id, std::string_view language = "en-US", int32_t page = 1);

    QJsonObject certifications_movie();
    QJsonObject certifications_tv();

    QJsonObject changes_movie(QDate end_date = "2023-10-22", QDate start_date = "2023-10-22", int32_t page = 1);
    QJsonObject changes_people(QDate end_date = "2023-10-22", QDate start_date = "2023-10-22", int32_t page = 1);
    QJsonObject changes_tv(QDate end_date = "2023-10-22", QDate start_date = "2023-10-22", int32_t page = 1);

    QJsonObject collection_details(int32_t collection_id, std::string_view language = "en-US");
    QJsonObject collection_images(int32_t collection_id, std::string_view language = "en-US");
    QJsonObject collection_translations(int32_t collection_id);

    QJsonObject company_details(int32_t company_id);
    QJsonObject company_alternativeNames(int32_t company_id);
    QJsonObject company_images(int32_t company_id);

    QJsonObject config_details();
    QJsonObject config_countries(std::string_view language = "en-US");
    QJsonObject config_jobs();
    QJsonObject config_languages();
    QJsonObject config_primaryTranslations();
    QJsonObject config_timezones();

    QJsonObject credits_details(int32_t credit_id);

    QJsonObject genres_movie(std::string_view language = "en");
    QJsonObject genres_tv(std::string_view language = "en");

    QJsonObject movieList_nowPlaying(std::string_view language = "en-US", int32_t page = 1, std::string_view region);
    QJsonObject movieList_popular(std::string_view language = "en-US", int32_t page = 1, std::string_view region);
    QJsonObject movieList_topRated(std::string_view language = "en-US", int32_t page = 1, std::string_view region);
    QJsonObject movieList_upcoming(std::string_view language = "en-US", int32_t page = 1, std::string_view region);

    QJsonObject movie_details(int32_t movie_id, std::string_view language = "en-US");
    QJsonObject movie_alternativeTitles(int32_t movie_id, std::string_view country = "US");
    QJsonObject movie_changes(int32_t movie_id, QDate start_date = "2023-10-22", QDate end_date = "2023-10-22", int32_t page = 1);
    QJsonObject movie_credits(int32_t movie_id, std::string_view language = "en-US");
    QJsonObject movie_externalIDs(int32_t movie_id);
    QJsonObject movie_images(int32_t movie_id, std::string_view language);
    QJsonObject movie_keywords(int32_t movie_id);
    QJsonObject movie_latest();
    QJsonObject movie_lists(int32_t movie_id, int32_t page = 1, std::string_view language = "en-US");
    QJsonObject movie_recommendations(int32_t movie_id, std::string_view language = "en-US", int32_t page = 1);
    QJsonObject movie_releaseDates(int32_t movie_id);
    QJsonObject movie_reviews(int32_t movie_id, std::string_view language = "en-US", int32_t page = 1);
    QJsonObject movie_similar(int32_t movie_id, std::string_view language = "en-US", int32_t page = 1);
    QJsonObject movie_translations(int32_t movie_id);
    QJsonObject movie_videos(int32_t movie_id, std::string_view language = "en-US");
    QJsonObject movie_watchProviders(int32_t movie_id);

    QJsonObject network_details(int32_t network_id);
    QJsonObject network_alternativeNames(int32_t network_id);
    QJsonObject network_images(int32_t network_id);

    QJsonObject people_popular(std::string_view language = "en-US", int32_t page = 1);
    QJsonObject people_details(int32_t person_id, std::string_view language = "en-US");
    QJsonObject people_changes(int32_t person_id, QDate start_date = "2023-10-22", QDate end_date = "2023-10-22", int32_t page = 1);
    QJsonObject people_combinedCredits(int32_t person_id, std::string_view language = "en-US");
    QJsonObject people_externalIDs(int32_t person_id);
    QJsonObject people_images(int32_t person_id);
    QJsonObject people_latest();
    QJsonObject people_movieCredits(int32_t person_id, std::string_view language = "en-US");
    QJsonObject people_tvCredits(int32_t person_id, std::string_view language = "en-US");
    QJsonObject people_taggedImages(int32_t person_id, int32_t page = 1);
    QJsonObject people_translations(int32_t person_id);

    QJsonObject reviews_details(std::string_view review_id);

    QJsonObject get_collection(std::string_view query, bool include_adult = false, std::string_view language = "en-US", int32_t page = 1, std::string_view region = "");
    QJsonObject get_company(std::string_view query, int32_t page = 1);
    QJsonObject get_keyword(std::string_view query, int32_t page = 1);
    QJsonObject get_movie(std::string_view query, bool include_adult = false, std::string_view language = "en-US", std::string primary_release_year = "", int32_t page = 1, std::string_view region = "", std::string_view year = "");
    QJsonObject get_person(std::string_view query, bool include_adult = false, std::string_view language = "en-US", int32_t page = 1);
    QJsonObject get_tv(std::string_view query, int32_t first_air_date_year = 0, bool include_adult = false, std::string_view langauge = "en-US", int32_t page = 1, int32_t year = 0);

    QJsonObject trending_movies(timeWindow time_window, std::string_view language = "en-US");
    QJsonObject trending_people(timeWindow time_window, std::string_view language = "en-US");
    QJsonObject trending_tv(timeWindow time_window, std::string_view language = "en-US");

    QJsonObject tv_series_airingToday(std::string_view language = "en-US", int32_t page = 1, std::string_view timezone = "America/New_York");
    QJsonObject tv_series_onTheAir(std::string_view language = "en-US", int32_t page = 1, std::string_view timezone = "America/New_York");
    QJsonObject tv_series_popular(std::string_view language = "en-US", int32_t page = 1);
    QJsonObject tv_series_topRated(std::string_view language = "en-US", int32_t page = 1);

    QJsonObject tv_series_details(int32_t series_id, std::string_view language = "en-US");
    QJsonObject tv_series_aggregateCredits(int32_t series_id, std::string_view language = "en-US");
    QJsonObject tv_series_alternativeTitles(int32_t series_id);
    QJsonObject tv_series_changes(int32_t series_id, QDate start_date = "2023-10-22", QDate end_date = "2023-10-22", int32_t page = 1);
    QJsonObject tv_series_contentRatings(int32_t series_id);
    QJsonObject tv_series_credits(int32_t series_id, std::string_view language = "en-US");
    QJsonObject tv_series_episodeGroups(int32_t series_id);
    QJsonObject tv_series_externalIDs(int32_t series_id);
    QJsonObject tv_series_images(int32_t series_id, std::string_view language = "en-US");
    QJsonObject tv_series_keywords(int32_t series_id);
    QJsonObject tv_series_latest();
    QJsonObject tv_series_lists(int32_t series_id, int32_t page = 1, std::string_view language = "en-US");
    QJsonObject tv_series_recommendations(int32_t series_id, std::string_view language = "en-US", int32_t page = 1);
    QJsonObject tv_series_reviews(int32_t series_id, std::string_view language = "en-US", int32_t page = 1);
    QJsonObject tv_series_screenedTheatrically(int32_t series_id);
    QJsonObject tv_series_similar(int32_t series_id, std::string_view language = "en-US", int32_t page = 1);
    QJsonObject tv_series_translations(int32_t series_id);
    QJsonObject tv_series_videos(int32_t series_id, std::string_view language = "en-US");
    QJsonObject tv_series_watchProviders(int32_t series_id);

    QJsonObject tv_seasons_details(int32_t series_id, int32_t season_number, std::string_view language = "en-US");
    QJsonObject tv_seasons_aggregateCredits(int32_t series_id, int32_t season_number, std::string_view language = "en-US");
    QJsonObject tv_seasons_changes(int32_t season_id, QDate start_date = "2023-10-22", QDate end_date = "2023-10-22", int32_t page = 1);
    QJsonObject tv_seasons_credits(int32_t series_id, int32_t season_number, std::string_view language = "en-US");
    QJsonObject tv_seasons_externalIDs(int32_t series_id, int32_t season_number);
    QJsonObject tv_seasons_images(int32_t series_id, int32_t season_number, std::string_view language = "en-US");
    QJsonObject tv_seasons_videos(int32_t series_id, int32_t season_number, std::string_view language = "en-US");
    QJsonObject tv_seasons_translations(int32_t series_id, int32_t season_number);
    QJsonObject tv_seasons_watchProviders(int32_t series_id, int32_t season_number);

    QJsonObject tv_episodes_details(int32_t series_id, int32_t season_number, int32_t episode_number, std::string_view language = "en-US");
    QJsonObject tv_episodes_changes(int32_t episode_id, QDate start_date = "2023-10-22", QDate end_date = "2023-10-22", int32_t page = 1);
    QJsonObject tv_episodes_credits(int32_t series_id, int32_t season_number, int32_t episode_number, std::string_view language = "en-US");
    QJsonObject tv_episodes_externalIDs(int32_t series_id, int32_t season_number, int32_t episode_number);
    QJsonObject tv_episodes_images(int32_t series_id, int32_t season_number, int32_t episode_number, std::string_view language = "en-US");
    QJsonObject tv_episodes_translations(int32_t series_id, int32_t season_number, int32_t episode_number);
    QJsonObject tv_episodes_videos(int32_t series_id, int32_t season_number, int32_t episode_number, std::string_view language = "en-US");

    QJsonObject watchProviders_regions(std::string_view language = "en-US");
    QJsonObject watchProviders_movie(std::string_view language = "en-US");
    QJsonObject watchProviders_tv(std::string_view language = "en-US");

private:
    static constexpr std::string_view _m_baseUrl = "https://api.themoviedb.org/3/";
    QJsonObject _runGetRequest(std::string_view i_request, std::map<std::string_view, std::string_view> i_params = {});
    std::string_view _m_accessToken;
};
