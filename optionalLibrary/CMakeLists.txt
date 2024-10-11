# Required: state minimum version of CMake
cmake_minimum_required(VERSION 3.28)

# Required: Top-level project name. Can be referenced as a variable later.
project(optionalLibrary VERSION 1.0.0)

### Section for optional library ###

# This is a user-configurable option to include a library or not in their build.
option(USE_SIMPLE_MATH_LIBRARY "A library for simple math on ints, floats, and doubles." ON)

# This tells CMake about a subdirectory containing its own CMake file that should be aggregated into this build.
# If you do not add subdirectories here, you will need to run those builds separately first to create the library files.
if(USE_SIMPLE_MATH_LIBRARY)
  add_subdirectory(myLibrary)

  # Create a variable containing a list of directories that can be appended to future target_include_directories commands
  list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/myLibrary")

endif()

### End of optional library section ###

# This tells CMake to generate a header file with the version number in it and place it in the binary directory so the source code knows what version of the code it is.
configure_file(optionalLibraryConfig.h.in optionalLibraryConfig.h)

# Creating executable with entrypoint from main.c
add_executable(${PROJECT_NAME} main.c)

# This tells CMake what directory it should look in for headers to include in the build
# The second of these includes the headers from the binary directory where the versionCodeConfig.h file is generated.
target_include_directories(${PROJECT_NAME}
  PUBLIC ${PROJECT_BINARY_DIR}
  ${EXTRA_INCLUDES}
  )

if(USE_SIMPLE_MATH_LIBRARY)
  # This tells CMake what directory it should look in for libraries to link in future link library commands
  # If we had a target_link_directories command in the non-optional part of this file, we could append this to the existing list of locations as is done with other commands on the next few lines.
  target_link_directories(${PROJECT_NAME} PRIVATE myLibrary/out/build)
  
  # This links our static library
  target_link_libraries(${PROJECT_NAME} simpleMathLibrary)
endif()