#include "html_tag/attr.h"

#include <stddef.h>

#include "my_str/mem.h"

// Tag attribute create/delete
void free_attr(tag_attr *attr)
{
    free(attr->name);
    free(attr->value);
}

tag_attr *parse_attr(const char *str, int *attr_end)
{
    const char *str_start = str;
    tag_attr *attr = (tag_attr *) malloc(sizeof(tag_attr));

    str += str_create_word(&attr->name, str, '=');
    if (*str == '"')
        str += str_create_word(&attr->value, str + 1, '"');
    else
        str += str_create_word(&attr->value, str, ' ');

    ptrdiff_t attr_end_ = str - str_start;
    *attr_end -= (int)(attr_end_);

    return attr;
}