# Required: state minimum version of CMake
cmake_minimum_required(VERSION 3.28.3)

# Required: Top-level project name. Can be referenced as a variable later.
project(basic)

# 
add_executable(${PROJECT_NAME} main.c)