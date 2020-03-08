cmake_minimum_required(VERSION 3.10)
project(Luna)

# Export compiler commands to compile_commands.json.
# This is pretty much only for Zack; he needs it
# for syntactical completion in Vim (yeah, yeah, I know).
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# GLFW configuration.
set(GLFW_BUILD_DOCS OFF)     # Don't build documentation.
set(GLFW_BUILD_TESTS OFF)    # Don't build tests.
set(GLFW_BUILD_EXAMPLES OFF) # Don't build examples.

# GLM configuration.
set(GLM_TEST_ENABLE OFF) # Don't build GLM unit tests.

# GTest configuration.
set(BUILD_GMOCK OFF) # Don't build the Google Mock subproject.
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) # TODO: does this work on Linux?

# Add any and all third-party libraries.
add_subdirectory(3rd_party/glfw-3.3.2)
add_subdirectory(3rd_party/glew-2.1.0/build/cmake)
add_subdirectory(3rd_party/glm-0.9.9.7)
add_subdirectory(3rd_party/googletest-1.10.0)

# Set the runtime and binary output directories.
# This is done after adding subdirectories so any .dll's
# end up in the same directory as the executable.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)

# TODO: create each Luna subdirectory with their own CMakeLists.txt
# Add each project subdirectory.
# add_subdirectory(luna_core)
# add_subdirectory(luna_math)

# Add unit tests.
# add_subdirectory(test_luna_math)

# TODO: this is temporary until the above TODO is taken care of;
# ideally, Luna will consist of several different projects (so that
# the unit tests and such don't have to be rebuilt each time
# we need to compile).

# Gather all the source code.
file(GLOB SOURCES "luna_core/src/*.cpp"
                  "luna_core/src/*.hpp"
                  "luna_core/src/*.h"
                  "luna_math/src/*.cpp"
                  "luna_math/src/*.hpp"
                  "luna_math/src/*.h"
                  "luna_test_math/src/*.cpp"
                  "luna_test_math/src/*.hpp"
                  "luna_test_math/src/*.h")

# Add the Luna executable.
add_executable(Luna ${SOURCES})

# Link any and all third-party libraries.
target_link_libraries(Luna glfw glew glm gtest_main)

# Include any and all headers.
target_include_directories(Luna
                           PUBLIC
                           luna_core/src
                           luna_math/src
                           luna_test_math/src
                           3rd_party/glfw-3.3.2/include
                           3rd_party/glew-2.1.0/include
                           3rd_party/googletest/googletest-1.10.0/include/gtest)

# Copy the resources folder to the binary directory.
#TODO: temporary hack to put resources in the right place
if(MSVC)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources
	DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin/Debug/)
else()
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources
          DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin/)
endif()