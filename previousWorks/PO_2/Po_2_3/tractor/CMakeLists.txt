add_library(Tractor tractor.cpp tractor.h)
target_include_directories(Tractor PUBLIC "${carFolder}" PUBLIC "${engineFolder}" )
target_link_libraries(Tractor PUBLIC  Engine PUBLIC Car)