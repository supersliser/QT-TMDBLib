//
// Created by t on 21/05/25.
//

#include "QTMDB.h"
#include <QJsonObject>

QJsonObject Qtmdb::get_collection(std::string query, bool include_adult, std::string language, int32_t page, std::string region)
{
    std::string request = "search/collection";
    std::map<std::string, std::string> params = {
        {"query", query},
        {"include_adult", include_adult ? "true" : "false"},
        {"language", language},
        {"page", std::to_string(page)},
        {"region", region}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::get_company(std::string query, int32_t page)
{
    std::string request = "search/company";
    std::map<std::string, std::string> params = {
        {"query", query},
        {"page", std::to_string(page)}
    };
    return _runGetRequest(request, params);
}

QJsonObject Qtmdb::get_keyword(std::string query, int32_t page)
{
  std::string request = "search/keyword";
  std::map<std::string, std::string> params = {
    {"query", query},
    {"page", std::to_string(page)}
  };
  return _runGetRequest(request, params);
}

QJsonObject Qtmdb::get_movie(std::string query, bool include_adult, std::string language, std::string primary_release_year, int32_t page, std::string region, std::string year)
{
  std::string request = "search/movie";
  std::map<std::string, std::string> params = {
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

QJsonObject Qtmdb::get_person(std::string query, bool include_adult, std::string language, int32_t page) 
{
  std::string request = "search/person";
  std::map<std::string, std::string> params = {
    {"query", query},
    {"include_adult", std::to_string(include_adult)},
    {"language", language},
    {"page", std::to_string(page)}
  };
  return _runGetRequest(request, params);
}

QJsonObject Qtmdb::get_tv(std::string query, int32_t first_air_date_year, bool include_adult, std::string language, int32_t page, int32_t year)
{
  std::string request = "search/tv";
  std::map<std::string, std::string> params = {
    {"query", query},
    {"first_air_date_year", std::to_string(first_air_date_year)},
    {"include_adult", std::to_string(include_adult)},
    {"language", language},
    {"page", std::to_string(page)},
    {"year", std::to_string(year)}
  };
  return _runGetRequest(request, params);
}
