set(PLAYER_SOURCES
    Player.cpp
    Items.cpp
    ImportantPlace.cpp
)

add_library(Players ${PLAYER_SOURCES} )
target_include_directories(Players ${Headers})