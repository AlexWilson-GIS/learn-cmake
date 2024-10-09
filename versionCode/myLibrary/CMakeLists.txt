# Required: state minimum version of CMake
cmake_minimum_required(VERSION 3.28)

# Required: Top-level project name. Can be referenced as a variable later.
project(staticLibrary)

# rather than using add_executable, we are using this to add a library.
add_library(simpleMathLibrary simpleMath.c)