add_library(EventOnWebsite Post.cpp Event.cpp  UserGroup.cpp membersOfGroup)
target_include_directories(EventOnWebsite PUBLIC ${headersFolder})