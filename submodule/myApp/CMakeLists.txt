# Required: state minimum version of CMake
cmake_minimum_required(VERSION 3.28)

# Required: Top-level project name. Can be referenced as a variable later.
project(gitSubmodule)

# Creating executable with entrypoint from main.c
add_executable(${PROJECT_NAME} main.c)

# Tells CMake where the headers are in other directories that should be included, in this case in the git submodule library
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/../submodules/SimpleMath/src/include)

# This tells CMake what directory it should look in for libraries to link in future add or link library commands
target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/../submodules/SimpleMath/build/src/test)

# This basically forwards the pre-existing object file on to the linker.
# Because this library did not use CMake, but instead just used Make, I don't yet know how to tell CMake to compile the library in when building the main component.
# Instead, I built it in my own build.sh script and then used this command to link them.
add_library(simpleMath OBJECT IMPORTED main.c.o)