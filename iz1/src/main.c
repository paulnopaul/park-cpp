/*
 * Создать структуру для хранения информации об HTML-теге: его имени, признаке «открывающий/закрывающий»
 * и атрибутах тега. Составить с ее использованием программу, включающую в себя функцию, принимающую на
 * вход текстовую строку с одним тегом. На выход функция должна возвращать указатель на инициализированную структуру.
 */
#include <stdio.h>

#include "html_tag/tag.h"

#define MAX_STR_LEN 256

int main()
{
    char line[MAX_STR_LEN] = "o>";
//    fgets(line, MAX_STR_LEN, stdin);
    html_tag *tag = parse_tag(line);
    printf("line = '%s'\n", line);
    printf("Tag:\nname: \t\t'%s'\nis_opening: \t'%d'\n", tag->name, tag->is_opening);
    return 0;
}
