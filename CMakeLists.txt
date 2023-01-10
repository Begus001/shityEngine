cmake_minimum_required(VERSION 3.22)

project(shityEngine CXX)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(ENGINE_SRC_DIR ./src)
set(ENGINE_INCLUDE_DIR ./include)

set(ENGINE_CFLAGS -O2 -Wall -Wextra -Wno-unused -Wno-unused-result -std=c++20 -pedantic -ggdb)

file(GLOB_RECURSE ENGINE_SRCS ${ENGINE_SRC_DIR}/*)

set(ENGINE_LIB shityEngine)

add_library(${ENGINE_LIB} STATIC ${ENGINE_SRCS})
target_compile_options(${ENGINE_LIB} PUBLIC ${ENGINE_CFLAGS})
target_include_directories(${ENGINE_LIB} PUBLIC ${ENGINE_INCLUDE_DIR})
target_include_directories(${ENGINE_LIB} PUBLIC ${ENGINE_INCLUDE_DIR}/imgui)
target_link_libraries(${ENGINE_LIB} PUBLIC)
target_compile_definitions(${ENGINE_LIB} PUBLIC "SHITY_DEBUG")

# ====================================================================

set(TEST test)
set(TEST_SRC_DIR ./test)
file(GLOB_RECURSE TEST_SRCS ${TEST_SRC_DIR}/*)

add_executable(${TEST} ${TEST_SRCS})
target_link_libraries(${TEST} PUBLIC ${ENGINE_LIB} glfw3 GLEW GL)
target_compile_options(${TEST} PUBLIC ${ENGINE_CFLAGS})
target_include_directories(${TEST} PUBLIC ${ENGINE_INCLUDE_DIR})

configure_file(${PROJECT_SOURCE_DIR}/test/triangleVert.glsl ${PROJECT_BINARY_DIR}/triangleVert.glsl)
configure_file(${PROJECT_SOURCE_DIR}/test/triangleFrag.glsl ${PROJECT_BINARY_DIR}/triangleFrag.glsl)