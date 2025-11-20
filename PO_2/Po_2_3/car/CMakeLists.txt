add_library(Car car.h car.cpp)
target_include_directories(Car PUBLIC "${engineFolder}")
target_link_libraries(Car PUBLIC Engine)