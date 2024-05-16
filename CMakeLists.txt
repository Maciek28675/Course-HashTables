cmake_minimum_required(VERSION 3.12)
project(HashTables)

include_directories("include")

file(GLOB SOURCES "src/*.cpp")

add_executable(HashTables ${SOURCES} "src/main.cpp")