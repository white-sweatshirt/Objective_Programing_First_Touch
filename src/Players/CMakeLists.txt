set(PLAYER_SOURCES
    Player.cpp
    SubLocation.cpp
)

add_library(Players  ${PLAYER_SOURCES} )
target_include_directories(Players PUBLIC ${Headers})
target_link_libraries(Players General)