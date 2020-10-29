cmake_minimum_required(VERSION 3.1)

project(iz1 C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
#
### GCOV
#

if (ENABLE_GCOV)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ftest-coverage -fprofile-arcs")
endif ()


include(configure_test.cmake)
add_subdirectory(test)

if (ENABLE_CPPCHECK)
    include(configure_cppcheck.cmake)
endif ()

##
### Source definitions ###
##

set(libmoodfinder_s_sources
        ${PROJECT_SOURCE_DIR}/include/moodfinder.h
        ${PROJECT_SOURCE_DIR}/include/moodfinder_errors.h
        ${PROJECT_SOURCE_DIR}/src/moodfinder_s.c
        )


include_directories("${PROJECT_SOURCE_DIR}/include")

add_library(libmoodfinder_s STATIC ${libmoodfinder_s_sources})

set(main_sources
        ${PROJECT_SOURCE_DIR}/src/main.c
        ${PROJECT_SOURCE_DIR}/src/moodfinder_profiler.c
        ${PROJECT_SOURCE_DIR}/include/moodfinder_profile.h
        )

add_executable(main ${main_sources})
target_link_libraries(main libmoodfinder_s)


