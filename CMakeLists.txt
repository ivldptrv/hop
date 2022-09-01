cmake_minimum_required(VERSION 3.23.2)

project(hop)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY dlib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY slib)

FILE(GLOB SOURCES src/*.cc inc/*.hpp)

add_executable(${PROJECT_NAME} ${SOURCES})