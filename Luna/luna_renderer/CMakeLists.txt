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


find_package(glfw3 REQUIRED)
if(glfw3_FOUND)
    include_directories(${GLFW_INCLUDE_DIRS})
    link_libraries(${GLFW_LIBRARIES})
   message("found glfw3")
endif()


find_package(OpenGL REQUIRED)
if(OpenGl_FOUND)
    include_directories(${OpenGL_INCLUDE_DIRS})
    link_libraries(${OpenGL_LIBRARIES})
endif()

add_executable(luna_renderer ${SOURCES})
include_directories(src)
include_directories(${luna_math_SOURCE_DIR}/src)
target_link_libraries(luna_renderer luna_math)
target_include_directories(luna_renderer PUBLIC ${CMAKE_CURRENT_LIST_DIR})
