cmake_minimum_required(VERSION 3.10.0)
project(Car VERSION 0.2.1 LANGUAGES CXX)


set(carFolder "${PROJECT_SOURCE_DIR}/car")
add_subdirectory(car)


add_executable(End main.cpp)
target_include_directories(End PUBLIC ${carFolder} PUBLIC ${mechanicFolder})
target_link_libraries(End PUBLIC Car PUBLIC Mechanic)