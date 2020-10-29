#include "moodfinder.h"
#include "moodfinder_errors.h"

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>


int find_mood(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
        return FILE_NOT_EXIST_ERROR;
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
        close(fd);
        if (file_size == 0)
            return EMPTY_FILE_ERROR;
        return MMAP_FAILED;
    }
    long long mood = 0;
    for (size_t i = 0; i < file_size - 1; ++i)
    {
        if (region[i] == ':')
            mood += (region[i + 1] == ')') + -1 * (region[i + 1] == '(');
    }
    munmap(region, file_size);
    close(fd);
    return mood > 0 ? POSITIVE : (mood == 0 ? NEUTRAL : NEGATIVE);
}