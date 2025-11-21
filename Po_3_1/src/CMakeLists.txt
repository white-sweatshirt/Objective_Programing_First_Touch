add_library(listLibrary STATIC list.cpp)
target_include_directories(listLibrary PUBLIC "${headersFolder}")