cmake_minimum_required(VERSION 3.28)
project(MineSweeperPP LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)

FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
)
FetchContent_MakeAvailable(SFML)

file(GLOB SOURCEDIR src/*.cpp)
file (GLOB GUISRCDIR src/gui/*.cpp)
file (GLOB SCREENSRCDIR src/gui/screens/*.cpp)

add_executable(main ${SOURCEDIR} ${GUISRCDIR})

target_include_directories(main PRIVATE include)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)
