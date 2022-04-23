#include "timing.hpp"

/**
* @brief Function to get the current time
*
* @return The current time
*/
struct timespec get_time() {
    struct timespec tm;
    if (timespec_get(&tm, TIME_UTC) != TIME_UTC) {
        fprintf(stderr, "ERROR: call to timespec_get failed \n");
        exit(EXIT_FAILURE);
    }

    return tm;
}

/**
* @brief Function to get the time difference between two given times
*
* @param st Staring time
* @param et Ending time
* @return Time Difference in seconds between the given times
*/
double get_time_diff(struct timespec st, struct timespec et) {
    return et.tv_sec - st.tv_sec + (double)(et.tv_nsec - st.tv_nsec) / 1000000000LL;
}