cmake_minimum_required(VERSION 3.21)
project(space_war)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR </usr/include/SFML>)

include_directories(src)

add_executable(space_war
        src/Components.h
        src/Entity.cpp
        src/Entity.h
        src/EntityManager.cpp
        src/EntityManager.h
        src/Game.cpp
        src/Game.h
        src/main.cpp)

target_link_libraries (space_war sfml-graphics sfml-window sfml-system)