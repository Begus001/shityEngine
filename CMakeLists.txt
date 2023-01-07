cmake_minimum_required(VERSION 3.22)

project(shityEngine CXX)

set(ENGINE_SRC_DIR ./src)
set(ENGINE_INCLUDE_DIR ./include)

set(ENGINE_CFLAGS -O2 -Wall -Wextra -Wno-unused -Wno-unused-result -std=c++20 -pedantic -ggdb)

file(GLOB_RECURSE ENGINE_SRCS ${ENGINE_SRC_DIR}/*)

set(ENGINE_LIB shityEngine)

add_library(${ENGINE_LIB} STATIC ${ENGINE_SRCS})
target_compile_options(${ENGINE_LIB} PUBLIC ${ENGINE_CFLAGS})
target_include_directories(${ENGINE_LIB} PUBLIC ${ENGINE_INCLUDE_DIR})
target_link_libraries(${ENGINE_LIB} PUBLIC)

# ====================================================================

set(TEST test)
set(TEST_SRC_DIR ./test)

add_executable(${TEST} test/main.cpp)
target_link_libraries(${TEST} PUBLIC ${ENGINE_LIB} glfw3 GLEW GL)
target_compile_options(${TEST} PUBLIC ${ENGINE_CFLAGS})
target_include_directories(${TEST} PUBLIC ${ENGINE_INCLUDE_DIR})

add_custom_target(run_test ALL
    COMMAND ./${TEST}
    DEPENDS ${TEST}
    WORKING_DIRECTORY ${PROJECT_BUILD_DIR}
)

configure_file(${PROJECT_SOURCE_DIR}/test/vertexShader.glsl ${PROJECT_BINARY_DIR}/vertexShader.glsl)
configure_file(${PROJECT_SOURCE_DIR}/test/fragmentShader.glsl ${PROJECT_BINARY_DIR}/fragmentShader.glsl)