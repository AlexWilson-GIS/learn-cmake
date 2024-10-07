# Required: state minimum version of CMake
cmake_minimum_required(VERSION 3.28)

# Required: Top-level project name. Can be referenced as a variable later.
project(staticLibrary)

# Creating executable with entrypoint from main.c
add_executable(staticLibrary main.c)

# This tells CMake what directory it should look in for libraries to link in future link library commands
target_link_directories(staticLibrary PRIVATE ${CMAKE_SOURCE_DIR}/../myLibrary/out/build)

# This links our static library
target_link_libraries(staticLibrary simpleMathLibrary)