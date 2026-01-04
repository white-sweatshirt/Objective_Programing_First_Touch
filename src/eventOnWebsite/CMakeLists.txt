add_library(EventOnWebsite Event.cpp Post.cpp UserGroup.cpp)
target_include_directories(EventOnWebsite PUBLIC ${headersFolder})