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
      src/QTMDB.cpp
        include/timeWindow.h
        src/account_QTMDB.cpp
        src/certifications_QTMDB.cpp
        src/changes_QTMDB.cpp
        src/collection_QTMDB.cpp
        src/company_QTMDB.cpp
        src/config_QTMDB.cpp
        src/credits_QTMDB.cpp
        src/genres_QTMDB.cpp
        src/movieList_QTMDB.cpp
        src/people_QTMDB.cpp
        src/movie_QTMDB.cpp
        src/network_QTMDB.cpp
        src/reviews_QTMDB.cpp
        src/trending_QTMDB.cpp
        src/get_QTMDB.cpp
        src/tv_series_QTMDB.cpp
        src/tv_seasons_QTMDB.cpp
        src/tv_episodes_QTMDB.cpp
        src/watchProviders_QTMDB.cpp
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
        tests/account.cpp
        tests/certifications.cpp
        tests/changes.cpp
        tests/collection.cpp
        tests/company.cpp
        tests/config.cpp
        tests/credits.cpp
        tests/genres.cpp
        tests/movieList.cpp
        tests/movie.cpp
        tests/networks.cpp
        tests/people.cpp
        tests/reviews.cpp
        tests/get.cpp
        tests/trending.cpp
        tests/tvSeries.cpp
        tests/tvSeasons.cpp
        tests/tvEpisodes.cpp
        tests/watchProviders.cpp
)
target_sources(TMDBTests PRIVATE)
target_link_libraries(TMDBTests PRIVATE GTest::gtest GTest::gtest_main)
target_link_libraries(TMDBTests PRIVATE ${QT_MODULES_NEEDED})
target_link_libraries(TMDBTests PRIVATE fmt::fmt)
gtest_discover_tests(TMDBTests)
