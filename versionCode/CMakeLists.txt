# Required: state minimum version of CMake
cmake_minimum_required(VERSION 3.28)

# Required: Top-level project name. Can be referenced as a variable later.
project(versionCode VERSION 1.0.0)

# This tells CMake to generate a header file with the version number in it and place it in the binary directory so the source code knows what version of the code it is.
configure_file(versionCodeConfig.h.in versionCodeConfig.h)

# Creating executable with entrypoint from main.c
add_executable(${PROJECT_NAME} main.c)

# This tells CMake about a subdirectory containing its own CMake file that should be aggregated into this build.
# If you do not add subdirectories here, you will need to run those builds separately first to create the library files.
add_subdirectory(myLibrary)

# This tells CMake what directory it should look in for headers to include in the build
# The first of these includes the headers from the static library.
# The second of these includes the headers from the binary directory where the versionCodeConfig.h file is generated.
target_include_directories(${PROJECT_NAME}
  PUBLIC myLibrary
  PUBLIC ${PROJECT_BINARY_DIR})

# This tells CMake what directory it should look in for libraries to link in future link library commands
target_link_directories(${PROJECT_NAME} PRIVATE myLibrary/out/build)

# This links our static library
target_link_libraries(${PROJECT_NAME} simpleMathLibrary)