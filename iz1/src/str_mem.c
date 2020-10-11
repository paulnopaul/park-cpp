#include "../include/str_mem.h"

int str_create_copy(char **to_allocate, const char *to_copy)
{
    *to_allocate = (char *)malloc(strlen(to_copy));

    if (to_allocate == NULL)
        return EXIT_FAILURE;

    strcpy(*to_allocate, to_copy);

    return EXIT_SUCCESS;
}

int str_create_ncopy(char **to_allocate, const char *to_copy, size_t n)
{
    *to_allocate = (char *)malloc(strlen(to_copy));

    if (to_allocate == NULL)
        return EXIT_FAILURE;

    for (int i = 0; i < n && to_copy[i] != '\0'; ++i)
        (*to_allocate)[i] = to_copy[i];

    return EXIT_SUCCESS;
}

int str_find(const char *str, char c)
{
    int i = 0;
    while (str[i] != c && str[i] != '\0')
        ++i;
    return str[i] == c ? i : -1;
}

int str_first_char_occurence(const char *str, const char *c)
{
    int i = 0;
    while (str_find(c, str[i]) && str[i] != '\0')
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
