cmake_minimum_required(VERSION 3.13)
project(MetaHeuristics)

set(CMAKE_CXX_STANDARD 14)

set(MH_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Bundle/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Bundle/lib)

file(GLOB_RECURSE sources ${MH_SOURCES}/*.c ${MH_SOURCES}/*.cpp)
file(GLOB_RECURSE headers ${MH_SOURCES}/*.h ${MH_SOURCES}/*.hpp)
file(GLOB_RECURSE inlines ${MH_SOURCES}/*.inl)

include_directories(${MH_SOURCES})

add_library(MetaHeuristics ${sources} ${headers} ${inlines})
set_target_properties(MetaHeuristics PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(apps)