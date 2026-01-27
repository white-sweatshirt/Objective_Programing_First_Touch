set(WEAPON_SOURCES
    Weapon.cpp
)

add_library(Weapons ${WEAPON_SOURCES})
target_include_directories(Weapons PUBLIC ${Headers})