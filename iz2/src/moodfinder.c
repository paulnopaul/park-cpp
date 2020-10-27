#include "moodfinder.h"

#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>


int find_mood(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    struct stat st;
    stat(filename, &st);
    size_t file_size = st.st_size;
    char *region = mmap(NULL,
                        file_size,
                        PROT_READ,
                        (unsigned) MAP_SHARED | (unsigned) MAP_POPULATE,
                        fd,
                        0);
    if (region == MAP_FAILED)
    {
        printf("mmap failed\n");
        close(fd);
        return -1;
    }
    long long mood = 0;
    for (size_t i = 0; i < file_size - 1; ++i)
    {
        if (region[i] == ':')
            mood += (region[i + 1] == ')') + -1 * (region[i + 1] == '(');
    }
    return mood > 0 ? POSITIVE : NEGATIVE;
}
