//
// Created by Pavel Cheklin on 11/10/2020.
//

#ifndef IZ1_ATTR_H
#define IZ1_ATTR_H

#include <stdlib.h>

typedef struct
{
    char *name;
    char *value;
} tag_attr;

tag_attr *parse_attr(const char *str, int *attr_end);

tag_attr **parse_attr_arr(const char *str, size_t count);

void free_attr(tag_attr **attr);

#endif //IZ1_ATTR_H
