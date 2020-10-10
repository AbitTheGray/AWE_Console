cmake_minimum_required(VERSION 3.16)
project(AWE_Console C CXX)

set(CMAKE_CXX_STANDARD 20)
set(BUILD_SHARED_LIBS OFF)

cmake_policy(SET CMP0077 NEW) # set() overrides option()

#--------------------------------
# Debug Options
#--------------------------------

add_compile_options("$<$<CONFIG:DEBUG>:-DDEBUG>") # Define DEBUG in Debug builds

#--------------------------------
# Source
#--------------------------------

file(GLOB_RECURSE PROJECT_SOURCE src/*.hpp src/*.cpp src/*.h src/*.c)

add_library(AWE_Console STATIC ${PROJECT_SOURCE})
target_include_directories(AWE_Console PUBLIC src/)

target_link_libraries(AWE_Console -static-libgcc -static-libstdc++ stdc++fs)

#--------------------------------
# Tests
#--------------------------------

if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()
