
SET ( NPC_SOURCES
    
    NPC.cpp
    NPCTrader.cpp
)

add_library(NPC  ${NPC_SOURCES})
target_include_directories(NPC PUBLIC ${Headers})