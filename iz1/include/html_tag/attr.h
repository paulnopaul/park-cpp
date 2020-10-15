#ifndef IZ1_ATTR_H
#define IZ1_ATTR_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    char *name;
    char *value;
} tag_attr_t;

// Функция проверки аттрибута тега (тег располагается в начале строкии и
// заканчивается либо символом '>', либо пробелом. Конец аттрибута записывается
// в переменную attr_end
bool check_attr_format(const char *str, size_t *attr_end);

tag_attr_t *parse_attr(const char *str, int *attr_end);

tag_attr_t **parse_attr_arr(const char *str, size_t count);

void free_attr(tag_attr_t **attr);

#endif //IZ1_ATTR_H
