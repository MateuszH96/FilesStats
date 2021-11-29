cmake_minimum_required(VERSION 3.22)
project(FileStats VERSION 1.0.0)

add_executable(FileStats main.cpp ReadFile.cpp ReadDirectory.cpp)

target_compile_features(FileStats PRIVATE cxx_std_17)
