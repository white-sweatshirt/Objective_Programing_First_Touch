cmake_minimum_required(VERSION 3.14)

project(SimpleRPG VERSION 0.99)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# I know its leazy but it works. in future should be segeregated
set (Headers ${PROJECT_SOURCE_DIR}/headers 
    ${PROJECT_SOURCE_DIR}/headers/npc
    ${PROJECT_SOURCE_DIR}/headers/player
)

add_subdirectory(src)

add_executable(SimpleRPG main.cpp)
target_link_libraries(SimpleRPG Items Quests Players NPC General)
target_include_directories(SimpleRPG PUBLIC ${Headers})