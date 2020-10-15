/*
 * Создать структуру для хранения информации об HTML-теге: его имени, признаке «открывающий/закрывающий»
 * и атрибутах тега. Составить с ее использованием программу, включающую в себя функцию, принимающую на
 * вход текстовую строку с одним тегом. На выход функция должна возвращать указатель на инициализированную структуру.
 */
#include <stdio.h>

#include "html_tag/html_tag.h"

#define MAX_STR_LEN 256

int main()
{
    char str[MAX_STR_LEN];
    fgets(str, sizeof(str), stdin);
    html_tag *tag = parse_tag(str);
    if (!tag)
        puts("Wrong tag format!");
    else
    {
        printf("Tag name = \"%s\"\n", tag->name);
        if (tag->is_opening)
            puts("Opening tag");
        else
            puts("Closing tag");
        if (tag->attributes_count)
        {
            puts("Attributes:");
            for (size_t i = 0; i < tag->attributes_count; ++i)
                printf("%s=\"%s\"\n", tag->attributes[i]->name, tag->attributes[i]->value);
        }
        free_tag(&tag);
    }
    return 0;
}