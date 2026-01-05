add_library(EventOnWebsite  Post.cpp    UserGroup.cpp membersOfGroup.cpp Event.cpp)
target_include_directories(EventOnWebsite PUBLIC ${headersFolder})