cmake_minimum_required(VERSION 3.10.0)
project(Divsion VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(headersFolder "${PROJECT_SOURCE_DIR}/headers")
set (srcFolder "${PROJECT_SOURCE_DIR}/src")

add_subdirectory(src)

add_executable(Divsion main.cpp)

target_include_directories(Divsion PUBLIC headersFolder PUBLIC src)
target_link_libraries(Divsion PUBLIC DivisonOfBank)


include(CTest)
enable_testing()
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
