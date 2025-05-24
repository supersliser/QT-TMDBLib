# QT-TMDB-Lib

This is a fairly simple library class which which allows for easy connection with the TMDb API. While this library depends on QT Network for network management, you can use this library with any cpp program, including those that do not use QT.

## How To use as a library

1. Within your own project directory, create a new directory (I recommend calling this `external/` but it doesnt matter really.
```sh
mkdir external
```
2. Clone this repository into the `external` directory
```sh
git submodule add https://github.com/supersliser/QT-TMDBLib.git ./external/TMDBLib
cd ./external/TMDBLib
```
3. Install Dependencies

   3.1. For Debian based distros
   ```sh
   sudo apt install -y gtest cmake fmt qtbase6-dev build-essential
   sudo apt-get install -y ninja-build
   ```
   3.2. For Fedora based distros
   ```sh
   sudo dnf install -y ninja-build cmake gtest fmt qt6-qtbase-devel qt6-qtbase-private-devel
   ```
   3.3. For Arch based distros
   ```sh
   sudo pacman -S qt6-base ninja-build gtest cmake fmt
   ```
4. Build the program and run the tests
```sh
cmake -G Ninja -B build .
cd build
ninja
./TMDBTests #This line can be ommitted to avoid running tests
```
5. Add the library to CMakeLists.txt
```
add_library(TMDBLib STATIC IMPORTED)
set_target_properties(TMDBLib PROPERTIES
    IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/external/TMDBLib/build/libQTMDB.a"
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/external/TMDBLib/include"
)

include_directories(include ${CMAKE_CURRENT_SOURCE_DIR}/external/TMDBLib/include)
target_link_libraries(MediaCenter PRIVATE TMDBLib)
```
