cmake_minimum_required(VERSION 3.18)
project(FLECS_test)

include(CMakePrintHelpers)

### Finding FLECS files
find_file(FLECS_C flecs.c ${CMAKE_CURRENT_SOURCE_DIR}/deps/flecs)
find_file(FLECS_H flecs.h ${CMAKE_CURRENT_SOURCE_DIR}/deps/flecs)
find_path(FLECS_INCLUDE_PATH flecs.h ${CMAKE_CURRENT_SOURCE_DIR}/deps/flecs)

### Finding own src & header files
file(GLOB_RECURSE SRC_FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h")
file(GLOB_RECURSE INCLUDE_FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")

cmake_print_variables(FLECS_C FLECS_H FLECS_INCLUDE_PATH)

set(CMAKE_CXX_STANDARD 20)

add_executable(FLECS_test
        ${SRC_FILES}
        ${INCLUDE_FILES}

        ${FLECS_C}
        ${FLECS_H}
        )

target_include_directories(FLECS_test
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src
            ${FLECS_INCLUDE_PATH}
        )
