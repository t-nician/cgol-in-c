cmake_minimum_required(VERSION 3.10)

project(cgolProject C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

file(GLOB_RECURSE SOURCES src/*.c)

# Define an executable target
add_executable(cgolProject ${SOURCES})

# Add include directory for 'my_app'
target_include_directories(
    cgolProject PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)