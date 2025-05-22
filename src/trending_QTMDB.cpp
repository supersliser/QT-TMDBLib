#include "QTMDB.h"
#include "timeWindow.h"
#include <QJsonObject>

QJsonObject Qtmdb::trending_movies(timeWindow::timeWindow time_window, std::string language)
{
  std::string request = "trending/movies";
  std::map<std::string, std::string> params = {
    {"time_window",timeWindow::to_string(time_window)},
    {"language", language}
  };
  return _runGetRequest(request, params);
}

QJsonObject Qtmdb::trending_people(timeWindow::timeWindow time_window, std::string language)
{
  std::string request = "trending/people";
  std::map<std::string, std::string> params = {
    {"time_window",timeWindow::to_string(time_window)},
    {"language", language}
  };
  return _runGetRequest(request, params);
}

QJsonObject Qtmdb::trending_tv(timeWindow::timeWindow time_window, std::string language)
{
  std::string request = "trending/tv";
  std::map<std::string, std::string> params = {
    {"time_window",timeWindow::to_string(time_window)},
    {"language", language}
  };
  return _runGetRequest(request, params);
}