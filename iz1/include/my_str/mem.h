#ifndef IZ1_MEM_H
#define IZ1_MEM_H

#include <stdlib.h>
#include <string.h>


size_t str_create_ncopy(char **to_allocate, const char *to_copy, size_t n);

size_t str_create_word(char **to_allocate, const char *src, const char *sep);

#endif //IZ1_MEM_H
