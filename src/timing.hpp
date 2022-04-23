#include <time.h>
#include<ctime>
#include <sys/types.h>
#include <iostream>

using namespace std;
/**
* @brief Function to get the current time
*
* @return The current time
*/
struct timespec get_time();

/**
* @brief Function to get the time difference between two given times
*
* @param st Staring time
* @param et Ending time
* @return Time Difference in seconds between the given times
*/
double get_time_diff(struct timespec st, struct timespec et);