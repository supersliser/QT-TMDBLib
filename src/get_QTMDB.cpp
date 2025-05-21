//
// Created by t on 21/05/25.
//

#include "QTMDB.h"
#include <QJsonObject>

QJsonObject Qtmdb::get_collection(std::string_view query, bool include_adult, std::string_view language, int32_t page, std::string_view region)
{
    std::string_view request = "search/collection";
    std::map<std::string_view, std::string_view> params = {
        {"query", query},
        {"include_adult", include_adult ? "true" : "false"},
        {"language", language},
        {"page", std::to_string(page)},
        {"region", region}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::get_company(std::string_view query, int32_t page)
{
    std::string_view request = "search/company";
    std::map<std::string_view, std::string_view> params = {
        {"query", query},
        {"page", std::to_string(page)}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::get_keyword(std::string_view query, int32_t page)
{
  std::string_view request = "search/keyword";
  std::map<std::string_view, std::string_view> params = {
    {"query", query},
    {"page", std::to_string(page)}
  };
  return _runGetRequest(request, params);
}

QJsonObject Qtmdb::get_movie(std::string_view query, bool include_adult, std::string_view language, std::string_view primary_release_year, int32_t page, std::string_view region, std::string_view year)
{
  std::string_view request = "search/movie";
  std::map<std::string_view, std::string_view> params = {
    {"query", query},
    {"include_adult", std::to_string(include_adult)},
    {"language", language},
    {"primary_release_year", primary_release_year},
    {"page", std::to_string(page)},
    {"region", region},
    {"year", year}
  };
  return _runGetRequest(request, params);
}

QJsonObject Qtmdb::get_person(std::string_view query, bool include_adult, std::string_view language, int32_t page) 
{
  std::string_view request = "search/person";
  std::map<std::string_view, std::string_view> params = {
    {"query", query},
    {"include_adult", std::to_string(include_adult)},
    {"language", language},
    {"page", std::to_string(page)}
  };
  return _runGetRequest(request, params);
}

QJsonObject Qtmdb::get_tv(std::string_view query, int32_t first_air_date_year, bool include_adult, std::string_view language, int32_t page, int32_t year)
{
  std::string_view request = "search/tv";
  std::map<std::string_view, std::string_view> params = {
    {"query", query},
    {"first_air_date_year", std::to_string(first_air_date_year)},
    {"include_adult", std::to_string(include_adult)},
    {"language", language},
    {"page", std::to_string(page)},
    {"year", std::to_string(year)}
  };
  return _runGetRequest(request, params);
}
