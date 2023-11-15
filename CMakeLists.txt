include_directories(${CMAKE_SOURCE_DIR}/src)

cmake_minimum_required(VERSION 3.24)
project(Ps_Group11_Assignment1)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Always pull the latest Google Test version
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(GrayScottTests
        tests/test.cpp
        src/gs.cpp
)

target_link_libraries(
        GrayScottTests
        GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(GrayScottTests)
