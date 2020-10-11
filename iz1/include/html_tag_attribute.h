//
// Created by Pavel Cheklin on 11/10/2020.
//

#ifndef IZ1_HTML_TAG_ATTRIBUTE_H
#define IZ1_HTML_TAG_ATTRIBUTE_H

#include <stdlib.h>

typedef struct
{
    char *name;
    char *value;
} tag_attr;

typedef struct
{
    tag_attr *data;
    size_t size;
    size_t _allocated;
} tag_attr_arr;

// Tag attribute create/delete
void free_attr(tag_attr *attr);

// Tag attribute array create/delete
void free_attr_arr(tag_attr_arr *arr);

int parse_attr_count(const char *str);

int parse_attr(const char *str, tag_attr *attr);


#endif //IZ1_HTML_TAG_ATTRIBUTE_H
