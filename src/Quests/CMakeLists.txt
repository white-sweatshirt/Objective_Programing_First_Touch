set(QUEST_SOURCES
    Quest.cpp
)

add_library(Quests   ${QUEST_SOURCES})
target_include_directories(Quests PRIVATE ${Headers})