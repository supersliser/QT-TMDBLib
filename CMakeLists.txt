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
        src/JSON/Sync/QTMDB.cpp
        include/timeWindow.h
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
        include/Person.h
        src/Person.cpp
        include/Series.h
        include/Network.h
        src/Network.cpp
        include/Season.h
        src/Series.cpp
        include/Episode.h
        src/Season.cpp
        src/Episode.cpp
        include/aQTMDB.h
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
        tests/Account_Tests.cpp
        tests/Company_Tests.cpp
        tests/Config_Tests.cpp
        tests/Genre_Tests.cpp
        tests/Movie_Tests.cpp
        tests/WatchProvider_Tests.cpp
        tests/Person_Tests.cpp
        tests/Network_Tests.cpp
        tests/Series_Tests.cpp
        tests/Season_Tests.cpp
        tests/Episode_Tests.cpp
        tests/JSON/ASync/account.cpp
        tests/JSON/ASync/certifications.cpp
        tests/JSON/ASync/changes.cpp
        tests/JSON/ASync/collection.cpp
        tests/JSON/ASync/company.cpp
        tests/JSON/ASync/credits.cpp
        tests/JSON/ASync/config.cpp
)
target_sources(TMDBTests PRIVATE)
target_link_libraries(TMDBTests PRIVATE GTest::gtest GTest::gtest_main)
target_link_libraries(TMDBTests PRIVATE ${QT_MODULES_NEEDED})
target_link_libraries(TMDBTests PRIVATE fmt::fmt)
gtest_discover_tests(TMDBTests)
