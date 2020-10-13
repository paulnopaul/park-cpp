#include "my_str/alg.h"

#include <string.h>

int str_find(const char *str, char c)
{
    int i = 0;
    while (str[i] != c && str[i] != '\0')
        ++i;
    return i; // str[i] == c ? i : -1;
}

int str_first_char_occurence(const char *str, const char *c)
{
    int i = 0;
    while (c[str_find(c, str[i])] == '\0' && str[i] != '\0')
        ++i;
    return i;
}

int str_count(const char *str, char c)
{
    int count = 0;
    while (*str != '\0')
        count += (*(str++) == c);
    return count;
}
