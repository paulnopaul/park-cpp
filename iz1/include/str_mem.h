//
// Created by Pavel Cheklin on 10/10/2020.
//

#ifndef IZ1_STR_MEM_H
#define IZ1_STR_MEM_H

#include <stdlib.h>
#include <string.h>

int str_create_copy(char **to_allocate, const char *to_copy);

int str_create_ncopy(char **to_allocate, const char *to_copy, size_t n);

int str_find(const char *str, char c);

int str_first_char_occurence(const char *str, const char *c);

int str_count(const char *str, char c);

#endif //IZ1_STR_MEM_H
