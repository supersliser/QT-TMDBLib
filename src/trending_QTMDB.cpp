#include "QTMDB.h"
#include "timeWindow.h"
#include <QJsonObject>

QJsonObject Qtmdb::trending_movies(timeWindow::timeWindow time_window, std::string language)
{
  std::string request = fmt::format("{}{}", "trending/movie/", timeWindow::to_string(time_window));
  std::map<std::string, std::string> params = {
    {"language", language}
  };
  return _runGetRequest(request, params);
}

QJsonObject Qtmdb::trending_people(timeWindow::timeWindow time_window, std::string language)
{
  std::string request = fmt::format("{}{}", "trending/person/", timeWindow::to_string(time_window));
  std::map<std::string, std::string> params = {
    {"language", language}
  };
  return _runGetRequest(request, params);
}

QJsonObject Qtmdb::trending_tv(timeWindow::timeWindow time_window, std::string language)
{
  std::string request = fmt::format("{}{}", "trending/tv/", timeWindow::to_string(time_window));
  std::map<std::string, std::string> params = {
    {"language", language}
  };
  return _runGetRequest(request, params);
}