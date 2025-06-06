//
// Created by t on 26/05/25.
//

#include "Movie.h"

#include <filesystem>
#include <qimage.h>

#include "Account.h"
#include "Account.h"
#include "QTMDB.h"

tmdb::Movie::Movie(const QString& i_access_token, int32_t i_movieID)
{
    Qtmdb q(i_access_token.toStdString());
    QJsonObject response = q.movie_details(i_movieID);
    *this = Movie(response, i_access_token);
}

tmdb::Movie::Movie(const QJsonObject& i_json, const QString& i_access_token)
{
    if (i_json.contains("adult")) { setAdult(i_json["adult"].toBool()); }
    else { setAdult(false); }
    if (i_json.contains("backdrop_path")) { setBackdropPath(i_json["backdrop_path"].toString()); }
    else { setBackdropPath(""); }
    if (i_json.contains("belongs_to_collection"))
    {
        setBelongsToCollection(i_json["belongs_to_collection"].toObject().value("id").toString());
    }
    else { setBelongsToCollection(""); }
    if (i_json.contains("budget")) { setBudget(i_json["budget"].toInt()); }
    else { setBudget(0); }

    if (i_json.contains("genres"))
    {
        QJsonArray genresArray = i_json["genres"].toArray();
        std::vector<Genre> genres;
        for (const auto& genre : genresArray)
        {
            genres.emplace_back(genre.toObject());
        }
        setGenres(genres);
    }
    else if (i_json.contains("genre_ids"))
    {
        QJsonArray genreIdsArray = i_json["genre_ids"].toArray();
        std::vector<Genre> genres;
        for (const auto& genreId : genreIdsArray)
        {
            genres.emplace_back(Genre::getGenre(i_access_token, genreId.toInt()));
        }
        setGenres(genres);
    }
    else { setGenres({}); }
    if (i_json.contains("homepage")) { setHomepage(i_json["homepage"].toString()); }
    else { setHomepage(""); }
    setId(i_json["id"].toInt());
    if (i_json.contains("imdb_id")) { setImdbID(i_json["imdb_id"].toString()); }
    else { setImdbID(""); }

    if (i_json.contains("original_language"))
    {
        QString originalLanguageStr = i_json["original_language"].toString();
        setOriginalLanguage(config::getLanguage(originalLanguageStr, i_access_token));
    }
    else
    {
        setOriginalLanguage(config::language());
    }

    if (i_json.contains("original_title"))
    {
        setOriginalTitle(i_json["original_title"].toString());
    }
    else
    {
        setOriginalTitle("");
    }

    if (i_json.contains("overview")) { setOverview(i_json["overview"].toString()); }
    else { setOverview(""); }
    if (i_json.contains("popularity"))
    {
        setPopularity(static_cast<float>(i_json["popularity"].toDouble()));
    }
    else
    {
        setPopularity(0.0f);
    }
    if (i_json.contains("poster_path")) { setPosterPath(i_json["poster_path"].toString()); }
    else { setPosterPath(""); }

    if (i_json.contains("production_companies"))
    {
        QJsonArray productionCompaniesArray = i_json["production_companies"].toArray();
        std::vector<Company> productionCompanies;
        for (const auto& company : productionCompaniesArray)
        {
            productionCompanies.emplace_back(company.toObject());
        }
        setProductionCompanies(productionCompanies);
    }
    else
    {
        setProductionCompanies({});
    }

    if (i_json.contains("production_countries"))
    {
        QJsonArray countriesArray = i_json["production_countries"].toArray();
        std::vector<config::country> countries;
        for (const auto& country : countriesArray)
        {
            countries.emplace_back(config::getCountry(country.toObject()));
        }
        setCountries(countries);
    }
    else
    {
        setCountries({});
    }
    if (i_json.contains("release_date"))
    {
        QString releaseDateStr = i_json["release_date"].toString();
        if (!releaseDateStr.isEmpty())
        {
            QDate releaseDate = QDate::fromString(releaseDateStr, Qt::ISODate);
            setReleaseDate(releaseDate);
        }
    }
    else
    {
        setReleaseDate(QDate());
    }
    if (i_json.contains("revenue")) { setRevenue(i_json["revenue"].toInt()); }
    else { setRevenue(0); }
    if (i_json.contains("runtime")) { setRuntime(i_json["runtime"].toInt()); }
    else { setRuntime(0); }
    if (i_json.contains("spoken_languages"))
    {
        QJsonArray languagesArray = i_json["spoken_languages"].toArray();
        std::vector<config::language> languages;
        for (const auto& language : languagesArray)
        {
            languages.emplace_back(config::getLanguage(language.toObject()["iso_639_1"].toString(), i_access_token));
        }
        setLanguages(languages);
    }
    else
    {
        setLanguages({});
    }
    if (i_json.contains("status")) { setStatus(i_json["status"].toString()); }
    else { setStatus(""); }
    if (i_json.contains("tagline")) { setTagline(i_json["tagline"].toString()); }
    else { setTagline(""); }
    if (i_json.contains("title")) { setTitle(i_json["title"].toString()); }
    else { setTitle(""); }
    if (i_json.contains("video")) { setVideo(i_json["video"].toBool()); }
    else { setVideo(false); }
    if (i_json.contains("vote_average"))
    {
        setVoteAverage(static_cast<float>(i_json["vote_average"].toDouble()));
    }
    else
    {
        setVoteAverage(0.0f);
    }
    if (i_json.contains("vote_count")) { setVoteCount(i_json["vote_count"].toInt()); }
    else { setVoteCount(0); }
}

tmdb::Movie tmdb::Movie::getMovie(const QString& i_access_token, int32_t i_movieID)
{
    return Movie(i_access_token, i_movieID);
}

std::vector<tmdb::Movie> tmdb::Movie::searchForMovies(const QString& i_access_token, const QString& i_query,
                                                      int32_t i_page, int32_t i_year, int32_t i_primaryReleaseYear,
                                                      bool i_includeAdult,
                                                      const QString& i_country,
                                                      const QString& i_language)
{
    Qtmdb q(i_access_token.toStdString());
    auto response = q.get_movie(i_query.toStdString(), i_includeAdult, i_language.toStdString(),
                                i_primaryReleaseYear == 0 ? "" : std::to_string(i_primaryReleaseYear), i_page,
                                i_country.toStdString(),
                                i_year == 0 ? "" : std::to_string(i_year));
    std::vector<Movie> movies;
    for (const auto& item : response["results"].toArray())
    {
        movies.emplace_back(q.movie_details(item.toObject()["id"].toInt()), i_access_token);
    }
    return movies;
}

void tmdb::Movie::setAdult(bool i_adult) { m_adult = i_adult; }
bool tmdb::Movie::adult() const { return m_adult; }

void tmdb::Movie::setBackdropPath(const QString& i_backdropPath) { m_backdropPath = i_backdropPath; }
QString tmdb::Movie::backdropPath() const { return m_backdropPath; }

void tmdb::Movie::setBelongsToCollection(const QString& i_belongsToCollection)
{
    m_belongsToCollection = i_belongsToCollection;
}

QString tmdb::Movie::belongsToCollection() const { return m_belongsToCollection; }

void tmdb::Movie::setBudget(int i_budget) { m_budget = i_budget; }
int tmdb::Movie::budget() const { return m_budget; }

void tmdb::Movie::setGenres(const std::vector<Genre>& i_genres) { m_genres = i_genres; }
std::vector<tmdb::Genre> tmdb::Movie::genres() const { return m_genres; }

void tmdb::Movie::setHomepage(const QString& i_homepage) { m_homepage = i_homepage; }
QString tmdb::Movie::homepage() const { return m_homepage; }

void tmdb::Movie::setId(int i_id) { m_id = i_id; }
int tmdb::Movie::id() const { return m_id; }

void tmdb::Movie::setImdbID(const QString& i_imdbID) { m_imdbID = i_imdbID; }
QString tmdb::Movie::imdbID() const { return m_imdbID; }

void tmdb::Movie::setOriginalLanguage(const tmdb::config::language& i_originalLanguage)
{
    m_originalLanguage = i_originalLanguage;
}

tmdb::config::language tmdb::Movie::originalLanguage() const { return m_originalLanguage; }

void tmdb::Movie::setOriginalTitle(const QString& i_originalTitle) { m_originalTitle = i_originalTitle; }
QString tmdb::Movie::originalTitle() const { return m_originalTitle; }

void tmdb::Movie::setOverview(const QString& i_overview) { m_overview = i_overview; }
QString tmdb::Movie::overview() const { return m_overview; }

void tmdb::Movie::setPopularity(float i_popularity) { m_popularity = i_popularity; }
float tmdb::Movie::popularity() const { return m_popularity; }

void tmdb::Movie::setPosterPath(const QString& i_posterPath) { m_posterPath = i_posterPath; }
QString tmdb::Movie::posterPath() const { return m_posterPath; }

void tmdb::Movie::setProductionCompanies(const std::vector<Company>& i_productionCompanies)
{
    m_productionCompanies = i_productionCompanies;
}

std::vector<tmdb::Company> tmdb::Movie::productionCompanies() const { return m_productionCompanies; }

void tmdb::Movie::setCountries(const std::vector<config::country>& i_countries) { m_countries = i_countries; }
std::vector<tmdb::config::country> tmdb::Movie::countries() const { return m_countries; }

void tmdb::Movie::setReleaseDate(const QDate& i_releaseDate) { m_releaseDate = i_releaseDate; }
QDate tmdb::Movie::releaseDate() const { return m_releaseDate; }

void tmdb::Movie::setRevenue(int i_revenue) { m_revenue = i_revenue; }
int tmdb::Movie::revenue() const { return m_revenue; }

void tmdb::Movie::setRuntime(int i_runtime) { m_runtime = i_runtime; }
int tmdb::Movie::runtime() const { return m_runtime; }

void tmdb::Movie::setLanguages(const std::vector<config::language>& i_languages) { m_languages = i_languages; }
std::vector<tmdb::config::language> tmdb::Movie::languages() const { return m_languages; }

void tmdb::Movie::setStatus(const QString& i_status) { m_status = i_status; }
QString tmdb::Movie::status() const { return m_status; }

void tmdb::Movie::setTagline(const QString& i_tagline) { m_tagline = i_tagline; }
QString tmdb::Movie::tagline() const { return m_tagline; }

void tmdb::Movie::setTitle(const QString& i_title) { m_title = i_title; }
QString tmdb::Movie::title() const { return m_title; }

void tmdb::Movie::setVideo(bool i_video) { m_video = i_video; }
bool tmdb::Movie::video() const { return m_video; }

void tmdb::Movie::setVoteAverage(float i_voteAverage) { m_voteAverage = i_voteAverage; }
float tmdb::Movie::voteAverage() const { return m_voteAverage; }

void tmdb::Movie::setVoteCount(int i_voteCount) { m_voteCount = i_voteCount; }
int tmdb::Movie::voteCount() const { return m_voteCount; }

std::vector<tmdb::Movie> tmdb::Movie::getNowPlaying(const QString& i_access_token,
                                                    const config::language& i_language,
                                                    int32_t i_page, const config::country& i_region)
{
    std::vector<tmdb::Movie> movies;
    Qtmdb q(i_access_token.toStdString());
    auto response = q.movieList_nowPlaying(i_region.iso_3166_1.toStdString(), i_language.iso_639_1.toStdString(),
                                           i_page);
    for (const auto& movie : response["results"].toArray())
    {
        movies.emplace_back(q.movie_details(movie.toObject()["id"].toInt()), i_access_token);
    }
    return movies;
}

std::vector<tmdb::Movie> tmdb::Movie::getPopular(const QString& i_access_token,
                                                 const tmdb::config::language& i_language,
                                                 int32_t i_page, const tmdb::config::country& i_region)
{
    std::vector<tmdb::Movie> movies;
    Qtmdb q(i_access_token.toStdString());
    auto response = q.movieList_popular(i_region.iso_3166_1.toStdString(), i_language.iso_639_1.toStdString(),
                                        i_page);
    for (const auto& movie : response["results"].toArray())
    {
        movies.emplace_back(q.movie_details(movie.toObject()["id"].toInt()), i_access_token);
    }
    return movies;
}

std::vector<tmdb::Movie> tmdb::Movie::getTopRated(const QString& i_access_token,
                                                 const tmdb::config::language& i_language,
                                                 int32_t i_page, const tmdb::config::country& i_region)
{
    std::vector<tmdb::Movie> movies;
    Qtmdb q(i_access_token.toStdString());
    auto response = q.movieList_topRated(i_region.iso_3166_1.toStdString(), i_language.iso_639_1.toStdString(),
                                        i_page);
    for (const auto& movie : response["results"].toArray())
    {
        movies.emplace_back(q.movie_details(movie.toObject()["id"].toInt()), i_access_token);
    }
    return movies;
}

std::vector<tmdb::Movie> tmdb::Movie::getUpcoming(const QString& i_access_token,
                                                 const tmdb::config::language& i_language,
                                                 int32_t i_page, const tmdb::config::country& i_region)
{
    std::vector<tmdb::Movie> movies;
    Qtmdb q(i_access_token.toStdString());
    auto response = q.movieList_upcoming(i_region.iso_3166_1.toStdString(), i_language.iso_639_1.toStdString(),
                                        i_page);
    for (const auto& movie : response["results"].toArray())
    {
        movies.emplace_back(q.movie_details(movie.toObject()["id"].toInt()), i_access_token);
    }
    return movies;
}

std::vector<tmdb::AlternateTitle> tmdb::Movie::alternateTitles(const QString& i_access_token) const
{
    Qtmdb q(i_access_token.toStdString());
    auto response = q.movie_alternativeTitles(m_id);
    std::vector<tmdb::AlternateTitle> titles;
    for (const auto& item : response["titles"].toArray())
    {
        QJsonObject titleObj = item.toObject();
        titles.emplace_back(AlternateTitle{config::getCountry(titleObj["iso_3166_1"].toString(), i_access_token), titleObj["title"].toString(), titleObj["type"].toString()});
    }
    return titles;
}

std::array<QString, 5> tmdb::Movie::externalIDs(const QString& i_access_token) const
{
    Qtmdb q(i_access_token.toStdString());
    auto response = q.movie_externalIDs(m_id);
    std::array<QString, 5> externalIDs = {
        response["imdb_id"].toString(),
        response["wikidata_id"].toString(),
        response["facebook_id"].toString(),
        response["instagram_id"].toString(),
        response["twitter_id"].toString(),
    };
    return externalIDs;
}

std::vector<QPixmap> tmdb::Movie::backdrops(const QString& i_access_token, const QString& i_size) const
{
    Qtmdb q(i_access_token.toStdString());
    auto response = q.movie_images(m_id, "en");
    std::vector<QPixmap> backdrops;
    for (const auto& item : response["backdrops"].toArray())
    {
        QJsonObject backdropObj = item.toObject();
        QString filePath = backdropObj["file_path"].toString();
        backdrops.emplace_back(config::getPixmapFromUrl(QUrl(q.getImageURL(filePath.toStdString(), i_size.toStdString()).c_str())));
    }
    return backdrops;
}

QPixmap tmdb::Movie::backdrop(const QString& i_access_token, int i_index, const QString& i_size) const
{
    Qtmdb q(i_access_token.toStdString());
    auto response = q.movie_images(m_id, "en");
    if (i_index < 0 || i_index >= response["backdrops"].toArray().size())
    {
        return QPixmap();
    }
    QJsonObject backdropObj = response["backdrops"].toArray()[i_index].toObject();
    QString filePath = backdropObj["file_path"].toString();
    return config::getPixmapFromUrl(QUrl(q.getImageURL(filePath.toStdString(), i_size.toStdString()).c_str()));
}

std::vector<QPixmap> tmdb::Movie::posters(const QString& i_access_token, const QString& i_size) const
{
    Qtmdb q(i_access_token.toStdString());
    auto response = q.movie_images(m_id, "en");
    std::vector<QPixmap> posters;
    for (const auto& item : response["posters"].toArray())
    {
        QJsonObject backdropObj = item.toObject();
        QString filePath = backdropObj["file_path"].toString();
        posters.emplace_back(config::getPixmapFromUrl(QUrl(q.getImageURL(filePath.toStdString(), i_size.toStdString()).c_str())));
    }
    return posters;
}

QPixmap tmdb::Movie::poster(const QString& i_access_token, int i_index, const QString& i_size) const
{
    Qtmdb q(i_access_token.toStdString());
    auto response = q.movie_images(m_id, "en");
    if (i_index < 0 || i_index >= response["posters"].toArray().size())
    {
        return QPixmap();
    }
    QJsonObject backdropObj = response["posters"].toArray()[i_index].toObject();
    QString filePath = backdropObj["file_path"].toString();
    return config::getPixmapFromUrl(QUrl(q.getImageURL(filePath.toStdString(), i_size.toStdString()).c_str()));
}

std::vector<QPixmap> tmdb::Movie::logos(const QString& i_access_token, const QString& i_size) const
{
    Qtmdb q(i_access_token.toStdString());
    auto response = q.movie_images(m_id, "en");
    std::vector<QPixmap> logos;
    for (const auto& item : response["logos"].toArray())
    {
        QJsonObject backdropObj = item.toObject();
        QString filePath = backdropObj["file_path"].toString();
        logos.emplace_back(config::getPixmapFromUrl(QUrl(q.getImageURL(filePath.toStdString(), i_size.toStdString()).c_str())));
    }
    return logos;
}

QPixmap tmdb::Movie::logo(const QString& i_access_token, int i_index, const QString& i_size) const
{
    Qtmdb q(i_access_token.toStdString());
    auto response = q.movie_images(m_id, "en");
    if (i_index < 0 || i_index >= response["logos"].toArray().size())
    {
        return QPixmap();
    }
    QJsonObject backdropObj = response["logos"].toArray()[i_index].toObject();
    QString filePath = backdropObj["file_path"].toString();
    return config::getPixmapFromUrl(QUrl(q.getImageURL(filePath.toStdString(), i_size.toStdString()).c_str()));
}

std::map<int, QString> tmdb::Movie::keywords(const QString& i_access_token) const
{
    Qtmdb q(i_access_token.toStdString());
    auto response = q.movie_keywords(m_id);
    std::map<int, QString> keywords;
    for (const auto& item : response["keywords"].toArray())
    {
        QJsonObject keywordObj = item.toObject();
        keywords[keywordObj["id"].toInt()] = keywordObj["name"].toString();
    }
    return keywords;
}

std::vector<tmdb::Movie> tmdb::Movie::similar(const QString& i_access_token, int32_t i_page) const
{
    Qtmdb q(i_access_token.toStdString());
    auto response = q.movie_similar(m_id, "en-US", i_page);
    std::vector<Movie> movies;
    for (const auto& item : response["results"].toArray())
    {
        movies.emplace_back(q.movie_details(item.toObject()["id"].toInt()), i_access_token);
    }
    return movies;
}

std::vector<tmdb::Movie> tmdb::Movie::recommendations(const QString& i_access_token, int32_t i_page) const
{
    Qtmdb q(i_access_token.toStdString());
    auto response = q.movie_recommendations(m_id, "en-US", i_page);
    std::vector<Movie> movies;
    for (const auto& item : response["results"].toArray())
    {
        movies.emplace_back(q.movie_details(item.toObject()["id"].toInt()), i_access_token);
    }
    return movies;
}

std::vector<tmdb::WatchProvider> tmdb::Movie::watchProviders(const QString& i_access_token, const config::country& i_region) const
{
    return WatchProvider::getWatchProvidersForMovie(i_access_token, i_region.iso_3166_1, m_id);
}

std::vector<tmdb::Credit> tmdb::Movie::credits(const QString& i_access_token) const
{
    Qtmdb q(i_access_token.toStdString());
    auto response = q.movie_credits(m_id);
    std::vector<Credit> credits;
    for (const auto& item : response["cast"].toArray())
    {
        credits.emplace_back(Credit(item.toObject()));
    }
    for (const auto& item : response["crew"].toArray())
    {
        credits.emplace_back(Credit(item.toObject()));
    }
    return credits;
}