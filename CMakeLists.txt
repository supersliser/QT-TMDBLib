cmake_minimum_required(VERSION 3.16)

project(QTMDB VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Network Widgets)
find_package(fmt REQUIRED)

set(PROJECT_SOURCES
      include/QTMDB.h
        src/JSON/QTMDB.cpp
        include/timeWindow.h
        src/JSON/account_QTMDB.cpp
        src/JSON/certifications_QTMDB.cpp
        src/JSON/changes_QTMDB.cpp
        src/JSON/collection_QTMDB.cpp
        src/JSON/company_QTMDB.cpp
        src/JSON/config_QTMDB.cpp
        src/JSON/credits_QTMDB.cpp
        src/JSON/genres_QTMDB.cpp
        src/JSON/movieList_QTMDB.cpp
        src/JSON/people_QTMDB.cpp
        src/JSON/movie_QTMDB.cpp
        src/JSON/network_QTMDB.cpp
        src/JSON/reviews_QTMDB.cpp
        src/JSON/trending_QTMDB.cpp
        src/JSON/get_QTMDB.cpp
        src/JSON/tv_series_QTMDB.cpp
        src/JSON/tv_seasons_QTMDB.cpp
        src/JSON/tv_episodes_QTMDB.cpp
        src/JSON/watchProviders_QTMDB.cpp
        include/Account.h
        include/Avatar.h
        src/Account.cpp
        src/Gravatar.cpp
        src/Tmdb.cpp
        src/Avatar.cpp
        include/Company.h
        src/Company.cpp
        include/Config.h
        src/Config.cpp
        include/Genre.h
        src/Genre.cpp
        include/Movie.h
        src/Movie.cpp
        include/WatchProvider.h
        src/WatchProvider.cpp
)

set(QT_MODULES_NEEDED
        Qt6::Core
        Qt6::Widgets
        Qt6::Network
)

include_directories(include)
add_library(QTMDB STATIC
      ${PROJECT_SOURCES}
)


target_link_libraries(QTMDB PRIVATE ${QT_MODULES_NEEDED})
target_link_libraries(QTMDB PRIVATE fmt::fmt)

include(GNUInstallDirs)
install(TARGETS QTMDB
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
  qt_finalize_executable(QTMDB)
endif()

find_package(GTest CONFIG REQUIRED)
include(GoogleTest)
enable_testing()
add_executable(TMDBTests
        ${PROJECT_SOURCES}
        tests/main.cpp
        tests/JSON/account.cpp
        tests/JSON/certifications.cpp
        tests/JSON/changes.cpp
        tests/JSON/collection.cpp
        tests/JSON/company.cpp
        tests/JSON/config.cpp
        tests/JSON/credits.cpp
        tests/JSON/genres.cpp
        tests/JSON/movieList.cpp
        tests/JSON/movie.cpp
        tests/JSON/networks.cpp
        tests/JSON/people.cpp
        tests/JSON/reviews.cpp
        tests/JSON/get.cpp
        tests/JSON/trending.cpp
        tests/JSON/tvSeries.cpp
        tests/JSON/tvSeasons.cpp
        tests/JSON/tvEpisodes.cpp
        tests/JSON/watchProviders.cpp
        tests/Account_Tests.cpp
        tests/Company_Tests.cpp
        tests/Config_Tests.cpp
        tests/Genre_Tests.cpp
        tests/Movie_Tests.cpp
)
target_sources(TMDBTests PRIVATE)
target_link_libraries(TMDBTests PRIVATE GTest::gtest GTest::gtest_main)
target_link_libraries(TMDBTests PRIVATE ${QT_MODULES_NEEDED})
target_link_libraries(TMDBTests PRIVATE fmt::fmt)
gtest_discover_tests(TMDBTests)
