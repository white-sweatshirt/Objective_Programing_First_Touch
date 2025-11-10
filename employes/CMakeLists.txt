add_library( Employes 
    employes.h employes.cpp
)
target_include_directories(Employes PUBLIC 
"${PROJECT_SOURCE_DIR}/clients" PUBLIC "${organismFolder}/person")
target_link_libraries(Employes PUBLIC Clients PUBLIC Person PUBLIC "${stdHeader}" )