#include "my_str/mem.h"

#include "my_str/alg.h"


size_t str_create_ncopy(char **to_allocate, const char *to_copy, size_t n)
{
    if (!to_copy || !to_allocate)
        return 0;

    size_t to_copy_len = strlen(to_copy);
    size_t allocate_size = (to_copy_len > n ? n : to_copy_len) + 1;
    *to_allocate = (char *) malloc(allocate_size);
    int i;
    for (i = 0; i < n && to_copy[i] != '\0'; ++i)
        (*to_allocate)[i] = to_copy[i];

    (*to_allocate)[i] = '\0';

    return allocate_size;
}

size_t str_create_word(char **to_allocate, const char *src, const char *sep)
{
    if (!src || !to_allocate)
        return 0;

    int word_end = str_first_char_occurence(src, sep);
    return str_create_ncopy(to_allocate, src, word_end);
}
