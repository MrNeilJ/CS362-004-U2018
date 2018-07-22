cmake_minimum_required(VERSION 3.7)
project(projects/johnsnei/dominion)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES projects/johnsnei/dominion/unitTest1.c)
add_executable(unitTest1 ${SOURCE_FILES})
