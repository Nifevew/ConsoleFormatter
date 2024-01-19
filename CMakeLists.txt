cmake_minimum_required(VERSION 3.27)
project(console_formatter)

set(CMAKE_CXX_STANDARD 23)

include_directories(./include)

set(HEADERS TextFormatting.hpp)


add_executable(console_formatter main.cpp ./include)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/f8d7d77c06936315286eb55f8de22cd23c188571.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        TextColorTest
        test/TextStyleTest.cpp
)

target_link_libraries(
        TextColorTest
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(TextColorTest)
