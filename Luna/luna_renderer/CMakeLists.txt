cmake_minimum_required(VERSION 3.10)
project(luna_renderer)

file(GLOB SOURCES "src/*.cpp"
                  "src/*.hpp"
                  )

#find_package(glfw3 3.3 REQUIRED)
#find_package(glew REQUIRED)
find_package(OpenGL REQUIRED)
# if(glew_FOUND)
   # message("found glew")
# endif()

# if(glfw3_FOUND)
   # message("found glfw3")
# endif()

include_directories("glfw/include")
include_directories("glew/include")

set( ENKITS_BUILD_EXAMPLES OFF CACHE BOOL "Build basic example applications" )
set( GLFW_BUILD_EXAMPLES OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_BUILD_TESTS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_BUILD_INSTALL OFF CACHE BOOL  "GLFW lib only" )

add_subdirectory( glfw )
add_subdirectory( glew/build/cmake )

add_executable(luna_renderer ${SOURCES})
target_link_libraries(luna_renderer glfw ${GLFW_LIBRARIES} glew luna_math)
include_directories(src)