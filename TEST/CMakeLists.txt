cmake_minimum_required(VERSION 3.22)
set(This FilesStats)
project(${This}) 
# Locate GTest
find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIR})
set(CMAKE_CXX_FLAGS "-std=c++17")
# Link runTests with what we want to test and the GTest and pthread library
add_executable(${This} main.cpp ReadDirectory.cpp ReadFile.cpp)
target_link_libraries(${This} ${GTEST_LIBRARIES} pthread)