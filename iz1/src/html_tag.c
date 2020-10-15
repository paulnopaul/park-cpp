#include "html_tag/html_tag.h"

#include "my_str/mem.h"
#include "my_str/alg.h"

bool check_html_tag_format(const char *str)
{
    bool ok = str && str[0] == '<';
    if (ok && str[1] == '/')
    {
        size_t closing_pos = str_find(str, '>');
        for (size_t i = 2; ok && i < closing_pos; ++i)
            ok = (ASCII_NAME_ALLOWED[str_find(ASCII_NAME_ALLOWED, str[i])] != '\0');
    } else if (ok)
    {
        size_t name_end = str_first_char_occurence(str, " >");
        for (size_t i = 1; ok && i < name_end; ++i)
           ok = (ASCII_NAME_ALLOWED[str_find(ASCII_NAME_ALLOWED, str[i])] != '\0');

        if (ok)
        {
            size_t closing_pos = str_find(str, '>');
            ok = (str[closing_pos] == '>');
        }

        if (ok)
        {
            size_t attr_end = name_end;
            str += attr_end;
            while (ok && str[0] != '>')
            {
                ok = check_attr_format(str + 1, &attr_end);
                str += attr_end + 1;
            }
        }
    }
    return ok;
}

html_tag *parse_tag(const char *str)
{
    if (!check_html_tag_format(str))
        return NULL;

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
