cmake_minimum_required(VERSION 3.16)

project(QTMDB VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Network Widgets Concurrent)
find_package(fmt REQUIRED)

set(PROJECT_SOURCES
        include/Sync/QTMDB.h
        src/JSON/Sync/QTMDB.cpp
        include/Sync/timeWindow.h
        src/JSON/Sync/account_QTMDB.cpp
        src/JSON/Sync/certifications_QTMDB.cpp
        src/JSON/Sync/changes_QTMDB.cpp
        src/JSON/Sync/collection_QTMDB.cpp
        src/JSON/Sync/company_QTMDB.cpp
        src/JSON/Sync/config_QTMDB.cpp
        src/JSON/Sync/credits_QTMDB.cpp
        src/JSON/Sync/genres_QTMDB.cpp
        src/JSON/Sync/movieList_QTMDB.cpp
        src/JSON/Sync/people_QTMDB.cpp
        src/JSON/Sync/movie_QTMDB.cpp
        src/JSON/Sync/network_QTMDB.cpp
        src/JSON/Sync/reviews_QTMDB.cpp
        src/JSON/Sync/trending_QTMDB.cpp
        src/JSON/Sync/get_QTMDB.cpp
        src/JSON/Sync/tv_series_QTMDB.cpp
        src/JSON/Sync/tv_seasons_QTMDB.cpp
        src/JSON/Sync/tv_episodes_QTMDB.cpp
        src/JSON/Sync/watchProviders_QTMDB.cpp
        include/Sync/Account.h
        include/Sync/Avatar.h
        src/Sync/Account.cpp
        src/Sync/Gravatar.cpp
        src/Sync/Tmdb.cpp
        src/Sync/Avatar.cpp
        include/Sync/Company.h
        src/Sync/Company.cpp
        include/Sync/Config.h
        src/Sync/Config.cpp
        include/Sync/Genre.h
        src/Sync/Genre.cpp
        include/Sync/Movie.h
        src/Sync/Movie.cpp
        include/Sync/WatchProvider.h
        src/Sync/WatchProvider.cpp
        include/Sync/Person.h
        src/Sync/Person.cpp
        include/Sync/Series.h
        include/Sync/Network.h
        src/Sync/Network.cpp
        include/Sync/Season.h
        src/Sync/Series.cpp
        include/Sync/Episode.h
        src/Sync/Season.cpp
        src/Sync/Episode.cpp
        src/JSON/ASync/QTMDB.cpp
        src/JSON/ASync/account_QTMDB.cpp
        src/JSON/ASync/certifications_QTMDB.cpp
        src/JSON/ASync/changes_QTMDB.cpp
        src/JSON/ASync/collection_QTMDB.cpp
        src/JSON/ASync/company_QTMDB.cpp
        src/JSON/ASync/config_QTMDB.cpp
        src/JSON/ASync/credits_QTMDB.cpp
        src/JSON/ASync/genres_QTMDB.cpp
        src/JSON/ASync/movieList_QTMDB.cpp
        src/JSON/ASync/people_QTMDB.cpp
        src/JSON/ASync/movie_QTMDB.cpp
        src/JSON/ASync/network_QTMDB.cpp
        src/JSON/ASync/reviews_QTMDB.cpp
        src/JSON/ASync/trending_QTMDB.cpp
        src/JSON/ASync/get_QTMDB.cpp
        src/JSON/ASync/tv_series_QTMDB.cpp
        src/JSON/ASync/tv_seasons_QTMDB.cpp
        src/JSON/ASync/tv_episodes_QTMDB.cpp
        src/JSON/ASync/watchProviders_QTMDB.cpp
        include/ASync/Account.h
        include/ASync/Company.h
        include/ASync/Config.h
        include/ASync/Episode.h
        include/ASync/Genre.h
        include/ASync/Movie.h
        include/ASync/Network.h
        include/ASync/Person.h
        include/ASync/Season.h
        include/ASync/Series.h
        include/ASync/WatchProvider.h
        include/ASync/QTMDB.h
        src/ASync/Account.cpp
        src/ASync/Company.cpp
        src/ASync/Config.cpp
        include/ASync/Country.h
        src/ASync/Country.cpp
        include/ASync/Department.h
        src/ASync/Department.cpp
        include/ASync/Language.h
        src/ASync/Language.cpp
        include/ASync/Image.h
        src/ASync/Image.cpp
        src/ASync/Episode.cpp
        src/ASync/Genre.cpp
        src/ASync/Movie.cpp
        src/ASync/Network.cpp
        src/ASync/Person.cpp
        src/ASync/Season.cpp
        src/ASync/Series.cpp
        src/ASync/WatchProvider.cpp
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

if (QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QTMDB)
endif ()

find_package(GTest CONFIG REQUIRED)
include(GoogleTest)
enable_testing()

add_executable(TMDBTests
        ${PROJECT_SOURCES}
        tests/main.cpp
        tests/JSON/Sync/account.cpp
        tests/JSON/Sync/certifications.cpp
        tests/JSON/Sync/changes.cpp
        tests/JSON/Sync/collection.cpp
        tests/JSON/Sync/company.cpp
        tests/JSON/Sync/config.cpp
        tests/JSON/Sync/credits.cpp
        tests/JSON/Sync/genres.cpp
        tests/JSON/Sync/movieList.cpp
        tests/JSON/Sync/movie.cpp
        tests/JSON/Sync/networks.cpp
        tests/JSON/Sync/people.cpp
        tests/JSON/Sync/reviews.cpp
        tests/JSON/Sync/get.cpp
        tests/JSON/Sync/trending.cpp
        tests/JSON/Sync/tvSeries.cpp
        tests/JSON/Sync/tvSeasons.cpp
        tests/JSON/Sync/tvEpisodes.cpp
        tests/JSON/Sync/watchProviders.cpp
        tests/Sync/Account_Tests.cpp
        tests/Sync/Company_Tests.cpp
        tests/Sync/Config_Tests.cpp
        tests/Sync/Genre_Tests.cpp
        tests/Sync/Movie_Tests.cpp
        tests/Sync/WatchProvider_Tests.cpp
        tests/Sync/Person_Tests.cpp
        tests/Sync/Network_Tests.cpp
        tests/Sync/Series_Tests.cpp
        tests/Sync/Season_Tests.cpp
        tests/Sync/Episode_Tests.cpp
        tests/JSON/ASync/account.cpp
        tests/JSON/ASync/certifications.cpp
        tests/JSON/ASync/changes.cpp
        tests/JSON/ASync/collection.cpp
        tests/JSON/ASync/company.cpp
        tests/JSON/ASync/credits.cpp
        tests/JSON/ASync/config.cpp
        tests/JSON/ASync/get.cpp
        tests/JSON/ASync/movie.cpp
        tests/JSON/Sync/movieList.cpp
        tests/JSON/Sync/movie.cpp
        tests/JSON/Sync/networks.cpp
        tests/JSON/Sync/people.cpp
        tests/JSON/Sync/reviews.cpp
        tests/JSON/Sync/get.cpp
        tests/JSON/Sync/trending.cpp
        tests/JSON/Sync/tvSeries.cpp
        tests/JSON/Sync/tvSeasons.cpp
        tests/JSON/Sync/tvEpisodes.cpp
        tests/JSON/Sync/watchProviders.cpp
        tests/ASync/Account_Tests.cpp
        tests/ASync/Company_Tests.cpp
        tests/ASync/Config_Tests.cpp
        tests/ASync/Country_Tests.cpp
        tests/ASync/Department_Tests.cpp
        tests/ASync/Episode_Tests.cpp
        tests/ASync/Genre_Tests.cpp
        tests/JSON/ASync/genres.cpp
        tests/JSON/ASync/movieList.cpp
        tests/JSON/ASync/networks.cpp
        tests/JSON/ASync/people.cpp
        tests/JSON/ASync/reviews.cpp
        tests/JSON/ASync/trending.cpp
        tests/JSON/ASync/tvEpisodes.cpp
        tests/JSON/ASync/tvSeasons.cpp
        tests/JSON/ASync/tvSeries.cpp
        tests/JSON/ASync/watchProviders.cpp
        tests/ASync/Language_Tests.cpp
        tests/ASync/Movie_Tests.cpp
        tests/ASync/Network_Tests.cpp
        tests/ASync/Person_Tests.cpp
        tests/ASync/Season_Tests.cpp
        tests/ASync/Series_Tests.cpp
        tests/ASync/WatchProvider_Tests.cpp
)

target_sources(TMDBTests PRIVATE)
target_link_libraries(TMDBTests PRIVATE GTest::gtest GTest::gtest_main)
target_link_libraries(TMDBTests PRIVATE ${QT_MODULES_NEEDED})
target_link_libraries(TMDBTests PRIVATE fmt::fmt)
gtest_discover_tests(TMDBTests)
