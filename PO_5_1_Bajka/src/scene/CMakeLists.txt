add_library(Scene scene.cpp)
target_link_libraries(Scene PUBLIC Actors )
target_include_directories(Scene PUBLIC "${headersFolder}")