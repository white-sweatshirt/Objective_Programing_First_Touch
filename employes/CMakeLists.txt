add_library( Employes 
    employes.h employes.cpp
)
target_include_directories(Employes 
    PUBLIC "${organismFolder}/paitients"
    PUBLIC "${organismFolder}/person" 
    PUBLIC "${stdheaderFolder}")

target_link_libraries(Employes PUBLIC Paitients PUBLIC Person)