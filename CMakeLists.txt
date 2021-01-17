cmake_minimum_required(VERSION 3.0.0)
project(state VERSION 0.1.0)

file(GLOB_RECURSE SOURCES "src/*.cpp" "include/*.hpp") # directory of source files

add_executable(state ${SOURCES})

target_include_directories(state PUBLIC include)
