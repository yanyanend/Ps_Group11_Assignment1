include_directories(${CMAKE_SOURCE_DIR}/src)

cmake_minimum_required(VERSION 3.24)
project(Ps_Group11_Assignment1)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.10.0.zip
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

add_executable(GrayScottSim src/gs.cpp
        main.cpp
)

add_executable(GrayScottTests
        tests/test.cpp
        src/gs.cpp
)

target_link_libraries(GrayScottTests gtest_main)

include(GoogleTest)

gtest_discover_tests(GrayScottTests)
