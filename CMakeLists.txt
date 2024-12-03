cmake_minimum_required(VERSION 3.15)
project(advent_of_code LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set input directory path as a compile definition
add_compile_definitions(INPUT_DIR="${CMAKE_SOURCE_DIR}/inputs")

# Add subdirectories
add_subdirectory(src/common)
add_subdirectory(src/day01)
