cmake_minimum_required(VERSION 3.10)
project(luna_ray_tracer)

file(GLOB SOURCES "src/*.cpp"
                  "src/*.hpp"
                   "textures/*.jpg")

add_executable(luna_ray_tracer ${SOURCES})

include_directories(src)
include_directories(${luna_math_SOURCE_DIR}/src)
target_link_libraries(luna_ray_tracer luna_math)
target_include_directories(luna_ray_tracer PUBLIC ${CMAKE_CURRENT_LIST_DIR})
