#add_subdirectory("${PROJECT_SOURCE_DIR}/emplyees")
add_library( Clients STATIC
    clients.h clients.cpp
)
target_include_directories(Clients PUBLIC "${organismFolder}/person" 
PUBLIC "${organismFolder}/paitients"
PUBLIC "${PROJECT_SOURCE_DIR}/employes"
PUBLIC "${stdheaderFolder}" )
target_link_libraries(Clients PUBLIC StdHeader PUBLIC Person PUBLIC Paitients PUBLIC Employes ) 