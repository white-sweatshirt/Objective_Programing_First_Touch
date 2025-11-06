cmake_minimum_required(VERSION 3.10.0)
project(Veterinary VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory("${PROJECT_SOURCE_DIR}/animals")
add_subdirectory("${PROJECT_SOURCE_DIR}/people")
add_executable(Veterinary main.cpp)

target_include_directories(Veterinary PUBLIC "${PROJECT_SOURCE_DIR}/animals"
 PUBLIC "${PROJECT_SOURCE_DIR}")
target_link_libraries(Veterinary PUBLIC Animals PUBLIC People)


include(CTest)
enable_testing()
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
