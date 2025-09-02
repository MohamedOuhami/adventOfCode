cmake_minimum_required(VERSION 3.50)

project(AdventOfCode2024)

# Define a macro for the source 1 files
file(GLOB SOURCES "src/*.cpp")

add_executable(AdventOfCode2024 ${SOURCES})

# Add the include files
target_include_directories(AdventOfCode2024 PRIVATE include)



