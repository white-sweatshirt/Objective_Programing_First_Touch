set(QUEST_SOURCES
    Quest.cpp
    HuntingQuest.cpp
    SearchQuest.cpp
    KillingQuest.cpp
)

add_library(Quests DYNAMIC ${QUEST_SOURCES})