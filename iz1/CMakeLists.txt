cmake_minimum_required(VERSION 3.1)

project(iz1 C CXX)

set (CMAKE_C_STANDARD 99)
set (CMAKE_CXX_STANDARD 17)

##
### Test definitions ###
##

configure_file(CMakeLists.txt.in
        googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build)

enable_testing()
add_subdirectory(test)

##
### Source definitions ###
##

include_directories("${PROJECT_SOURCE_DIR}/include")

file(GLOB sources
        "${PROJECT_SOURCE_DIR}/include/html_tag/*.h"
        "${PROJECT_SOURCE_DIR}/include/my_str/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.c")

add_executable(iz1 ${sources} )
