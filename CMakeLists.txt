cmake_minimum_required(VERSION 3.27)
project(console_formatter)

set(CMAKE_CXX_STANDARD 23)

include_directories(./include)

set(HEADERS TextFormatting.hpp)


add_executable(console_formatter main.cpp ./include)
