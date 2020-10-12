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


void free_attr(tag_attr *attr);

tag_attr *parse_attr(const char *str, int *attr_end );


#endif //IZ1_ATTR_H
