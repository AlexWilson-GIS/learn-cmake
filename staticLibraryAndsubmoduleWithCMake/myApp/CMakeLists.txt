# Required: state minimum version of CMake
cmake_minimum_required(VERSION 3.28)

# Required: Top-level project name. Can be referenced as a variable later.
project(staticLibraryAndSubmodule)

# Creating executable with entrypoint from main.cpp
add_executable(staticLibraryAndSubmodule main.cpp)

# This tells CMake what subdirectories containing their own CMake files should be aggregated into this build.
# If you do not add these subdirectories here, you will need to run those builds separately first to create the library files.
add_subdirectory(${PROJECT_SOURCE_DIR}/../myLibrary ${PROJECT_SOURCE_DIR}/../myLibrary/out/build)

# This tells CMake what directory it should look in for headers to include in the build
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/../myLibrary)

# This tells CMake what directory it should look in for libraries to link in future link library commands
target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/../myLibrary/out/build)

# This links our static library
target_link_libraries(${PROJECT_NAME} Addition)