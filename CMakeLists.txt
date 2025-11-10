cmake_minimum_required(VERSION 3.10.0)
project(Veterinary VERSION 0.2.1  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)# for constexpr
set(CMAKE_CXX_STANDARD_REQUIRED True)

set (stdheaderFolder "${PROJECT_SOURCE_DIR}/stdHeader")
set (organismFolder "${PROJECT_SOURCE_DIR}/livingOrganism")

add_subdirectory("${organismFolder}")
add_subdirectory("${PROJECT_SOURCE_DIR}/clients")
add_subdirectory("${PROJECT_SOURCE_DIR}/employes")

add_executable(Veterinary main.cpp)

target_include_directories(Veterinary PUBLIC "${PROJECT_SOURCE_DIR}/clients"
 PUBLIC "${PROJECT_SOURCE_DIR}/employes")
target_link_libraries(Veterinary PUBLIC Animals PUBLIC People)


include(CTest)
enable_testing()
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
