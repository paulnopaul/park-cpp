/*
 * Создать структуру для хранения информации об HTML-теге: его имени, признаке «открывающий/закрывающий»
 * и атрибутах тега. Составить с ее использованием программу, включающую в себя функцию, принимающую на
 * вход текстовую строку с одним тегом. На выход функция должна возвращать указатель на инициализированную структуру.
 *
 * Примеры тегов
 * <a>
 * <a href="abc">
 * </a>
 * <tag_name attribute1=value attribute2=value>
 * <tag_name attribute1="value1 value2" attribute2="value3 value4">
 * </tag_name>
 */

#ifndef IZ1_HTML_TAG_H
#define IZ1_HTML_TAG_H

#include <stdbool.h>
#include <stdlib.h>

#include "html_tag_attribute.h"

typedef struct
{
    char *name;
    bool is_opening;
    tag_attr *attributes;
} html_tag;

html_tag *parse_tag(const char *str);

int parse_status(const char *str, html_tag *tag);

int parse_name(const char *str, html_tag *tag);


#endif //IZ1_HTML_TAG_H
