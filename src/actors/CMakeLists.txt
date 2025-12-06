add_library(Actors actors.cpp protagonists.cpp villans.cpp)
target_include_directories(Actors PUBLIC "${headersFolder}")