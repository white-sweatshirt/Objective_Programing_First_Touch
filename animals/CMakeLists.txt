#add_subdirectory("${PROJECT_SOURCE_DIR}/emplyees")
add_library( Animals 
    animals.h animals.cpp
)
target_include_directories(Animals PUBLIC "${PROJECT_SOURCE_DIR}/people")
target_link_libraries(Animals PUBLIC  People)