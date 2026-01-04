cmake_minimum_required(VERSION 3.10.0)
project(socialMedia VERSION 0.1.0 LANGUAGES C CXX)
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (headersFolder "${PROJECT_SOURCE_DIR}/headersa")

add_subdirectory(src)
add_executable(socialMedia main.cpp)
target_link_libraries(socialMedia People EventOnWebsite)
target_include_directories(socialMedia PUBLIC ${headersFolder})
include(CTest)
enable_testing()

