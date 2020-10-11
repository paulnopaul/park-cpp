#include "../include/html_tag.h"

#include "../include/str_mem.h"

html_tag *parse_tag(const char *str)
{
    html_tag *tag = (html_tag *)malloc(sizeof(html_tag));

    if (tag == NULL)
        return NULL;

    str += parse_status(str, tag);
    parse_name(str, tag);

    return tag;
}

int parse_status(const char *str, html_tag *tag)
{
    int i = 0;
    if (str[i] == '<')
    {
        ++i;
        if (str[i + 1] == '/')
        {
            tag->is_opening = false;
            ++i;
        }
        else
            tag->is_opening = true;
    }
    return i;
}

int parse_name(const char *str, html_tag *tag)
{
    int i = str_first_char_occurence(str, " >");
    str_create_ncopy(&tag->name, str, i);
    return i;
}

int parse_attribute(const char *str, html_tag *tag)
{
    int eq_pos = str_find(str, '=');
    int end_pos = str_find(str + eq_pos + 2, '"');

    return end_pos;
};

