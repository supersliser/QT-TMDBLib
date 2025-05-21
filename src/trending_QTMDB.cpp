#include "QTMDB.h"
#include "timeWindow.h"
#include <QJsonObject>

QJsonObject Qtmdb::trending_movies(timeWindow time_window, std::string_view language)
{
  std::string_view request = "trending/movies";
  std::map<std::string_view, std::string_view> params = {
    {"time_window",static_cast<std::string>(time_window)},
    {"language", language}
  };
  return _runGetRequest(request, params);
}

QJsonObject Qtmdb::trending_people(timeWindow time_window, std::string_view language)
{
  std::string_view request = "trending/people";
  std::map<std::string_view, std::string_view> params = {
    {"time_window",static_cast<std::string>(time_window)},
    {"language", language}
  };
  return _runGetRequest(request, params);
}

QJsonObject Qtmdb::trending_tv(timeWindow time_window, std::string_view language)
{
  std::string_view request = "trending/tv";
  std::map<std::string_view, std::string_view> params = {
    {"time_window",static_cast<std::string>(time_window)},
    {"language", language}
  };
  return _runGetRequest(request, params);
}