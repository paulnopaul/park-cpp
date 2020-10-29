#ifndef IZ1_MOODFINDER_PROFILE_H
#define IZ1_MOODFINDER_PROFILE_H

void generate_file(const char *filename, int status, int size);

double profile_on_file(const char *filename, int count);

void profile_app(int start_size, int end_size, int step);

#endif //IZ1_MOODFINDER_PROFILE_H
