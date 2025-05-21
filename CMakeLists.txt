cmake_minimum_required(VERSION 3.16)

project(TMDBlib VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Network Widgets)

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
add_library(TMDBLib STATIC
      ${PROJECT_SOURCES}
)


target_link_libraries(TMDBLib PRIVATE ${QT_MODULES_NEEDED})

include(GNUInstallDirs)
install(TARGETS TMDBLib
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(TMDBLib)
endif()

find_package(GTest CONFIG REQUIRED)
include(GoogleTest)
enable_testing()
add_executable(TMDBTests
        ${PROJECT_SOURCES}
        tests/main.cpp
)
target_sources(TMDBTests PRIVATE)
target_link_libraries(TMDBTests PRIVATE GTest::gtest GTest::gtest_main)
target_link_libraries(TMDBTests PRIVATE ${QT_MODULES_NEEDED})
gtest_discover_tests(TMDBTests)
