cmake_minimum_required(VERSION 3.27)
project(console_formatter)

set(CMAKE_CXX_STANDARD 23)

set(INCLUDE_DIR ./include)


add_executable(console_formatter ./include main.cpp)
