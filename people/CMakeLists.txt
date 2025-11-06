add_library( People 
    people.h people.cpp
)
target_include_directories(People PUBLIC 
"${PROJECT_SOURCE_DIR}/animals")
target_link_libraries(Peple PUBLIC Animals)