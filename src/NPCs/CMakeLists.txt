SET NPC_SOURCES
(
    NPC.cpp
    NPCTrader.cpp
)

add_library(NPCs DYNAMIC NPC_SOURCES)
target_include_directories(NPCs ${Headers})