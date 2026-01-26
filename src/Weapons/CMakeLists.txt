set(WEAPON_SOURCES
    Weapon.cpp
    MeeleWeapon.cpp
    RangedWeapon.cpp
    MagicWeapon.cpp
)

add_library(Weapons ${WEAPON_SOURCES})
target_include_directories(Weapons ${Headers})