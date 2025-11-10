cmake_minimum_required(VERSION 3.10.0)
project(Car VERSION 0.2.1 LANGUAGES CXX)

add_subdirectory(mechanic)
set(mechanicFolder "${PROJECT_SOURCE_DIR}/mechanic")
set(carFolder "${PROJECT_SOURCE_DIR}/car")
add_subdirectory(car)


add_executable(Car main.cpp)
target_include_directories(Car PUBLIC ${carFolder}PUBLIC ${mechanicFolder})