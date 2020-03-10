cmake_minimum_required(VERSION 3.10)
project(luna_math)
# Gather all the source code.
file(GLOB SOURCES "src/*.cpp")

file(GLOB HEADERS "src/*.hpp")
				  
include_directories(src)
add_library(luna_math ${SOURCES} ${HEADERS})
