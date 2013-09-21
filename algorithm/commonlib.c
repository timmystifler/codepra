#include "commonlib.h"
#include <time.h>
#include <sys/time.h>
#include <stdio.h>


void count_time_by_sec(time_t time1, time_t time2, char* message)
{
	double timegap = difftime(time1, time2);
	puts((char *)message);
	printf("cost %10.2lf sec\n", timegap);
}

void count_time_by_usec(struct timeval tvstart, struct timeval tvend, char* message)
{
	double timegap = 1000000 * (tvstart.tv_sec - tvend.tv_sec) + (tvstart.tv_usec - tvend.tv_usec);
	puts(message);
	printf("cost %10.2lf microsec\n", timegap);
}

void gernerate_random_array(int* array, int arraysize, int floor, int upper)
{
	int i = 0;
	srand(time(0));
	for(i = 0; i < arraysize; i++)
	{
		*(array+i) = floor + rand()%(upper - floor);
	}
}

void swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
void swap_char(char *num1, char *num2)
{
	char temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
