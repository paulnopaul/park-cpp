#include "html_tag/tag.h"

#include "my_str/mem.h"

html_tag *parse_tag(const char *str)
{
    html_tag *tag = (html_tag *)malloc(sizeof(html_tag));

    if (tag == NULL)
        return NULL;

    str += parse_status(str, tag);
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

