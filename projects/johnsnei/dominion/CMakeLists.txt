cmake_minimum_required(VERSION 3.7)
project(untitled)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES randomTestAdventurer.c dominion.h dominion.c rngs.h rngs.c dominion_helpers.h)
add_executable(untitled ${SOURCE_FILES})