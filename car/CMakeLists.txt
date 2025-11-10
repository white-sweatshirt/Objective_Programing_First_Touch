add_library(Car car.cpp car.h)
target_include_directories(Car PUBLIC mechanicFolder)
target_link_libraries(Car PUBLIC Mechanic)