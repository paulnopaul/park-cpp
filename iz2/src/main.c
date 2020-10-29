/*
Сравните и выведите в консоль время работы последовательного и параллельного с использованием
нескольких процессов алгоритмов, каждый из которых выделяет в динамической памяти символьный
массив размером 100 Мб и, рассматривая его содержимое как абстрактную переписку, определяет
эмоциональную окраску последней. Переписка считается оптимистичной, если диграфов :) в ней
больше, чем диграфов :(; в противном случае переписка признается пессимистичной.
 */

#include "moodfinder.h"
#include <time.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    struct timespec start, finish;
    double elapsed;
    clock_gettime(CLOCK_MONOTONIC, &start);
    int mood = find_mood(argv[1]);
    clock_gettime(CLOCK_MONOTONIC, &finish);
    if (mood != -1)
        printf("Mood: %d\n", mood);
    elapsed = (double)(finish.tv_sec - start.tv_sec);
    elapsed += (double)(finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("Work time: %lf\n", elapsed);
    return 0;
}
