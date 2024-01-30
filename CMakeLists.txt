cmake_minimum_required(VERSION 3.16)
project(FixedPointNumbers C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

set(CMAKE_POLICY_DEFAULT_CMP0077 NEW) # set() overrides option()



#--------------------------------
# Compiler configuration
#--------------------------------

add_compile_options("$<$<CONFIG:DEBUG>:-DDEBUG>") # Define DEBUG in Debug builds



#--------------------------------
# Source
#--------------------------------

file(GLOB_RECURSE PROJECT_SOURCE
    src/*.hpp
    src/*.cpp
    src/*.h
    src/*.c

    include/*.hpp
    include/*.h
)

add_library(FixedPointNumbers STATIC ${PROJECT_SOURCE})
target_include_directories(FixedPointNumbers PRIVATE src/)
target_include_directories(FixedPointNumbers PUBLIC include/)



#--------------------------------
# Source for GLM
#--------------------------------

file(GLOB_RECURSE PROJECT_SOURCE_GLM
    include_glm/*.hpp
    include_glm/*.h
)

add_library(FixedPointNumbers_GLM STATIC ${PROJECT_SOURCE_GLM})
target_include_directories(FixedPointNumbers_GLM PUBLIC include_glm/)
target_link_libraries(FixedPointNumbers_GLM FixedPointNumbers glm)
