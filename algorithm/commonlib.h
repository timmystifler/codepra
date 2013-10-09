#ifndef _TIME_COUNT_H_
#define _TIME_COUNT_H_
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>

#define SWAP(a, b) int t = (a);\
(a) = (b);(b) = t;

#define MEASURETIME 10
#define TRUE 0
#define FALSE -1
#define MEASURE_C(T, text)      \
{	                            \
	int loop_count = 0;         \
	int lastPtr = 0;            \
	int currentPtr = 0;         \
	printf("%s\t", "text");     \
	printf("%d\t", sizeof(T));  \
	for(loop_count = 0; loop_count < MEASURETIME; loop_count++){  \
		T* measurePtr = malloc(sizeof(T));                        \
		currentPtr = (int)measurePtr;                             \
		if(lastPtr != 0)                                          \
			printf("%d ", currentPtr - lastPtr);                  \
		lastPtr = currentPtr;                                     \
	}                                                             \
	printf("\n");                                                 \
}

void count_time_bysec(time_t time1, time_t time2, char* message);
void swap(int* , int*);
void swap_char(char* , char*);

void count_time_by_usec(struct timeval tvstart, struct timeval tvend, char* message);
void gernerate_random_array(int* array, int arraysize, int floor, int upper);
#endif
