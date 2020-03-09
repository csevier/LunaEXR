cmake_minimum_required(VERSION 3.10)
project(test_luna_math)
file(GLOB SOURCES "src/*.cpp"
                  "src/*.hpp"
                  )

include_directories(include src)
add_executable(test_luna_math ${SOURCES})
add_subdirectory( gtest )
include_directories("gtest/googletest/include" luna_math)
target_link_libraries(test_luna_math gtest luna_math)



