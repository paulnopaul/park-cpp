#include "html_tag/html_tag.h"

#include "my_str/mem.h"
#include "my_str/alg.h"

html_tag *parse_tag(const char *str)
{
    html_tag *tag = (html_tag *) malloc(sizeof(html_tag));

    if (tag == NULL)
        return NULL;

    str += parse_status(str, tag);
    tag->attributes_count = str_count(str, '=');

    if (!tag->is_opening || tag->attributes_count == 0)
        str += str_create_word(&tag->name, str, ">");
    else
        str += str_create_word(&tag->name, str, " ");

    tag->attributes = parse_attr_arr(str, tag->attributes_count);

    return tag;
}

size_t parse_status(const char *str, html_tag *tag)
{
    int i = 0;
    if (str[i] == '<')
    {
        ++i;
        if (str[i] == '/')
        {
            tag->is_opening = false;
            ++i;
        } else
            tag->is_opening = true;
    }
    return i;
}

void free_tag(html_tag **tag)
{
    free((*tag)->name);
    for (size_t i = 0; i < (*tag)->attributes_count; ++i)
        free_attr((*tag)->attributes + i);
    free((*tag)->attributes);
    free(*tag);
    *tag = NULL;
}
