add_library( Employees 
    employees.h employees.cpp
)
target_include_directories(Employees PUBLIC 
"${PROJECT_SOURCE_DIR}/clients")
target_link_libraries(Employees PUBLIC Clients)