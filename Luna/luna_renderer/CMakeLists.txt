cmake_minimum_required(VERSION 3.10)
project(luna_renderer)

file(GLOB SOURCES "src/*.cpp"
                  "src/*.hpp"
                  )
add_executable(luna_renderer ${SOURCES})

find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})
    target_link_libraries(luna_renderer ${GLEW_LIBRARIES})
     message("found glew")
endif()


find_package(glfw3 REQUIRED)
if(glfw3_FOUND)
    include_directories(${GLFW_INCLUDE_DIRS})
    link_libraries(${GLFW_LIBRARIES})
   message("found glfw3")
   target_link_libraries(luna_renderer glfw)
endif()


find_package(OpenGL REQUIRED)
if(OPENGL_FOUND)
    message("found opengl")
    message(STATUS "OPENGL_INCLUDE_DIR:= ${OPENGL_INCLUDE_DIR}")
    message(STATUS "OPENGL_LIBRARY:= ${OPENGL_LIBRARY}")
    message(STATUS "OPENGL_LIBRARIES:= ${OPENGL_LIBRARIES}")
    include_directories(${OPENGL_INCLUDE_DIR})
    #$link_libraries(${OPENGL_LIBRARIES})
    target_link_libraries(luna_renderer ${OPENGL_LIBRARIES})
endif()


include_directories(src)
include_directories(${luna_math_SOURCE_DIR}/src)
target_link_libraries(luna_renderer luna_math)
target_include_directories(luna_renderer PUBLIC ${CMAKE_CURRENT_LIST_DIR})
