cmake_minimum_required(VERSION 3.10)
project(luna_renderer)

file(GLOB SOURCES "src/*.cpp"
                  "src/*.hpp"
                  )
				  


find_package(glfw3 3.3 REQUIRED)
find_package(glew REQUIRED)

if(glew_FOUND)
   message("found glew")
endif()

if(glfw3_FOUND)
   message("found glfw3")
endif()
add_executable(luna_renderer ${SOURCES})
target_link_libraries(luna_renderer glfw3 glew luna_math)
include_directories(src)