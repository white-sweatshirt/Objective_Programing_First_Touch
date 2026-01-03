cmake_minimum_required(VERSION 3.20)
project(listProject VERSION 2.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED 11)
set(headersFolder "${PROJECT_SOURCE_DIR}/headers")
set(srcFolder "${PROJECT_SOURCE_DIR}/src")

add_subdirectory(src)

add_executable(fairyTale main.cpp)
target_include_directories(fairyTale PUBLIC "${headersFolder}")
target_link_libraries(fairyTale  PUBLIC Actors PUBLIC Scene )
