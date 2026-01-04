add_library(People membersOfGroup.cpp PlatformAdmin.cpp User.cpp)
target_include_directories(People PUBLIC ${headersFolder})
target_link_libraries(People PUBLIC EventOnWebsite)