cmake_minimum_required(VERSION 3.10)
project(luna_renderer)

file(GLOB SOURCES "src/*.cpp"
                  "src/*.hpp"
                  )


find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})
     message("found glew")
endif()

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
if(glfw3_FOUND)
    include_directories(${GLFW_INCLUDE_DIRS})
    link_libraries(${GLFW_LIBRARIES})
   message("found glfw3")
endif()

add_executable(luna_renderer ${SOURCES})
target_link_libraries(luna_renderer luna_math)
include_directories(src luna_math)
