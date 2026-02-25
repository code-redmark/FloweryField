cmake_minimum_required(VERSION 3.28)
project(MineSweeperPP LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_BUILD_TYPE Debug)

# Address sanitizer stuff
set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

set(SRCDIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

include(FetchContent)

FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
)
FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE SOURCEFILES "${SRCDIR}/*.cpp")


add_executable(main ${SOURCEFILES})

target_include_directories(main PRIVATE include)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics SFML::Audio SFML::System)

add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)


