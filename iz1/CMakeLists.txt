cmake_minimum_required(VERSION 3.17)
project(iz1 C)

set(CMAKE_C_STANDARD 11)

add_executable(iz1 src/main.c src/html_tag.c include/html_tag.h src/str_mem.c include/str_mem.h src/html_tag_attribute.c include/html_tag_attribute.h)