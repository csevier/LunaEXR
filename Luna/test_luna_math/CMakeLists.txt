cmake_minimum_required(VERSION 3.10)
project(test_luna_math)
file(GLOB SOURCES "src/*.cpp"
                  "src/*.hpp"
                  )

include_directories(include src)
add_executable(test_luna_math ${SOURCES})
add_subdirectory( gtest )
include_directories("gtest/googletest/include")
target_include_directories(luna_renderer PUBLIC ${CMAKE_CURRENT_LIST_DIR})
include_directories(${luna_math_SOURCE_DIR}/src)
target_link_libraries(test_luna_math luna_math gtest)



