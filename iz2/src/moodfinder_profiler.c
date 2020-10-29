#include "moodfinder_profile.h"

#include "moodfinder.h"
#include "moodfinder_errors.h"

#include <stdio.h>
#include <time.h>

void generate_file(const char *filename, int status, int size)
{
    FILE *f = fopen(filename, "w");
    if (!f)
        return;
    char c = (char)(status == NEGATIVE ? '(' : ')');
    if (status == NEUTRAL)
    {
        size /= 2;
        for (int i = 0; i < size; ++i)
            fputs(":(", f);
    }
    for (int i = 0; i < size; ++i)
        fprintf(f, ":%c", c);
    fclose(f);
}


double profile_on_file(const char *filename, int count)
{
    struct timespec start, finish;
    double mean_time = 0;

    for (int i = 0; i < count; ++i)
    {
        clock_gettime(CLOCK_MONOTONIC, &start);
        find_mood(filename);
        clock_gettime(CLOCK_MONOTONIC, &finish);
        double elapsed = (double) (finish.tv_sec - start.tv_sec) + (double)(finish.tv_nsec - start.tv_nsec) / 1000000000.0;
        mean_time += elapsed / (double)count;
    }
    return mean_time;
}

void profile_app(int start_size, int end_size, int step)
{
    const char filename[] = "f.txt";
    for (int size = start_size; size <= end_size; size += step)
    {
        generate_file(filename, NEUTRAL, size);
        double res = profile_on_file(filename, 10);
        printf("%d chars : %lf seconds\n", size, res);
    }
}

