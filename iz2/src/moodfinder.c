#include "moodfinder.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>

int find_mood(const char *filename)
{
    struct stat st;
    if (stat(filename, &st))
        return 0;

    char *file = (char *)malloc(st.st_size);
    return st.st_size;
}
