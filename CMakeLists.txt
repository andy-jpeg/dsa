cmake_minimum_required(VERSION 3.28)
project(dsa LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.1.0
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(dsa
        main.cpp
        gameInfo.cpp
        gameData.cpp
        csvreader.cpp
        Heap.cpp
        HeapSort.cpp
        MergeSort.cpp
        TextBox.cpp
        InputTextBox.cpp
        Dropdown.cpp)

target_compile_features(dsa PRIVATE cxx_std_17)

# project folder path, so the csv + font load no matter where it runs from
target_compile_definitions(dsa PRIVATE PROJECT_DIR="${CMAKE_SOURCE_DIR}/")
target_link_libraries(dsa PRIVATE SFML::Graphics)

