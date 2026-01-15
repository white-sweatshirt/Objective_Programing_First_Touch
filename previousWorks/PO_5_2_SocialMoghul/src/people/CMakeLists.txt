add_library(People PlatformAdmin.cpp User.cpp)
target_include_directories(People PUBLIC ${headersFolder})
target_link_libraries(People  EventOnWebsite)