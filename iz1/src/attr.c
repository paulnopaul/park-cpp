#include "html_tag/attr.h"

#include <stddef.h>

#include "my_str/mem.h"
#include "my_str/alg.h"

bool check_attr_format(const char *str, size_t *attr_end)
{
    if (!str || !attr_end)
        return false;

    size_t eq_pos = str_find(str, '=');
    if (str[eq_pos] == '\0')
        return false;

    for (int i = 0; i < eq_pos; ++i)
    {
        if (str[i] == ' ')
            return false;
    }

    eq_pos++;
    if (str[eq_pos] == '\"')
        *attr_end = str_find(str + eq_pos + 1, '\"') + 2;
    else
        *attr_end = str_first_char_occurence(str + eq_pos, " >");

    *attr_end += eq_pos;
    return str[*attr_end] != '\0';
}

void free_attr(tag_attr_t **attr)
{
    free((*attr)->name);
    free((*attr)->value);
    free(*attr);
    *attr = NULL;
}

tag_attr_t *parse_attr(const char *str, int *attr_end)
{
    const char *str_start = str;
    tag_attr_t *attr = (tag_attr_t *) malloc(sizeof(tag_attr_t));

    str += str_create_word(&attr->name, str, "=");
    if (*str == '"')
        str += str_create_word(&attr->value, str + 1, "\"") + 2;
    else
        str += str_create_word(&attr->value, str, " >");

    ptrdiff_t attr_end_ = str - str_start;
    *attr_end = (int) (attr_end_);

    return attr;
}

tag_attr_t **parse_attr_arr(const char *str, size_t count)
{
    tag_attr_t **attr_arr = (tag_attr_t **) malloc(count * sizeof(tag_attr_t *));
    for (size_t i = 0; i < count; ++i)
    {
        int attr_end = 0;
        attr_arr[i] = parse_attr(str, &attr_end);
        str += attr_end;
    }
    return attr_arr;
}
