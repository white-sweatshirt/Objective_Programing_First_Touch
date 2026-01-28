set(WEAPON_SOURCES
    Item.cpp
)

add_library(Weapons ${WEAPON_SOURCES})
target_include_directories(Weapons PUBLIC ${Headers})