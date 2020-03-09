cmake_minimum_required(VERSION 3.10)
project(test_luna_math)
file(GLOB SOURCES "src/*.cpp"
                  "src/*.hpp"
                  )
				  

include_directories(include src)
find_package(GTest REQUIRED)
add_executable(test_luna_math ${SOURCES})
if(GTest_FOUND)
   message("found gtest")
endif()
target_link_libraries(test_luna_math GTest::GTest GTest::Main)



