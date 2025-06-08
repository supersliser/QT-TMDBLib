#include "Async/QTMDB.h"
#include "Sync/timeWindow.h"
#include <QJsonObject>

void aQtmdb::trending_movies(tmdb::timeWindow::timeWindow time_window, std::string language)
{
  std::string request = fmt::format("{}{}", "trending/movie/", tmdb::timeWindow::to_string(time_window));
  std::map<std::string, std::string> params = {
    {"language", language}
  };
   _runGetRequest(request, params);
}

void aQtmdb::trending_people(tmdb::timeWindow::timeWindow time_window, std::string language)
{
  std::string request = fmt::format("{}{}", "trending/person/", tmdb::timeWindow::to_string(time_window));
  std::map<std::string, std::string> params = {
    {"language", language}
  };
   _runGetRequest(request, params);
}

void aQtmdb::trending_tv(tmdb::timeWindow::timeWindow time_window, std::string language)
{
  std::string request = fmt::format("{}{}", "trending/tv/", tmdb::timeWindow::to_string(time_window));
  std::map<std::string, std::string> params = {
    {"language", language}
  };
   _runGetRequest(request, params);
}