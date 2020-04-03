cmake_minimum_required(VERSION 3.10)
project(Luna)

# Export compiler commands to compile_commands.json.
# This is pretty much only for Zack; he needs it
# for syntactical completion in Vim (yeah, yeah, I know).
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add each project subdirectory.
add_subdirectory(luna_renderer)
add_subdirectory(luna_math)
add_subdirectory(luna_ray_tracer)

# Add unit tests.
add_subdirectory(test_luna_math)
