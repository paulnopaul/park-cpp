#include "../include/html_tag_attribute.h"

#include "../include/str_mem.h"

// Tag attribute create/delete
void free_attr(tag_attr *attr)
{
    free(attr->name);
    free(attr->value);
}

// Tag attribute array create/delete
void free_attr_arr(tag_attr_arr *arr)
{
    for (int i = 0; i < arr->size; ++i)
        free_attr(arr->data + i);
    arr->size = 0;
    arr->_allocated = 0;
}

// attr_parsing func
int parse_attr_count(const char *str)
{
    return str_count(str, '=');
}

int parse_attr(const char *str, tag_attr *attr)
{
    int attr_name_end = str_find(str, '=');
    int attr_value_end = str_find(str + attr_name_end + 2, '"');

    if (str_create_ncopy(&attr->name,
                         str,
                         attr_name_end) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    if (str_create_ncopy(&attr->name,
                         str + attr_name_end,
                         attr_value_end - attr_name_end + 1) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

