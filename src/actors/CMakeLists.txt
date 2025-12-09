add_library(Actors actors.cpp protagonists.cpp villans.cpp)
target_link_libraries(Actors PUBLIC McGuffin )
target_include_directories(Actors PUBLIC "${headersFolder}")