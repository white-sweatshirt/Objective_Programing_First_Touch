set(PLAYER_SOURCES
    Player.cpp
    PlayerClasses.cpp
    SubLocation.cpp
)

add_library(Players  ${PLAYER_SOURCES} )
target_include_directories(Players PRIVATE ${Headers})
target_link_libraries(Players General Numbers)