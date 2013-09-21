/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/30/2013 12:22:16 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ZhangYue (TimmyStifler), timmystifler@hotmail.com
 *   Organization:  USTC-SSE
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "binsearch.h"
#include <time.h>
#include <limits.h>
#include <sys/time.h>
#include "count_time.h"


#define LOOPTIME INT_MAX

int int_compare(const void* arg1, const void* arg2)
{
	/*int interger1, interger2;
	interger1 = *(int *)arg1;
	interger2 = *(int *)arg2;

	if(interger1 == interger2)
		return 0;
	else if(interger1 > interger2)
		return 1;
	else 
		return -1;
		*/
	return *(int *)arg1 - *(int *)arg2;
}

int main()
{
	int array[100] = {0, 3 , 4, 6};
	int i = 0;
	int findNumber = 3;
	struct timeval start, end;

	srand(time(0));

	for(i = 0; i < 100; i++)
	{
		array[i] = rand()%100;
	}

	qsort(array, sizeof(array)/sizeof(array[0]), sizeof(int), int_compare);
	for(i = 0; i < 100; i++)
		printf("%d%c", array[i], ((i+1)%10 == 0)?'\n':'\t');

	printf("enter the number you will find:");
	scanf("%d", &findNumber);
	
	//printf("result1:%d\t", binsearch_original(array, 0, 99, findNumber));
	//printf("result2:%d\t", binsearch_ver1(array, 0, 99, findNumber));
	gettimeofday(&start, NULL);
	for(i = 0; i < LOOPTIME ; i++)
		binsearch_original(array, 0, 99, findNumber);
	gettimeofday(&end, NULL);
	count_time_by_usec(end, start, "alg1");

	gettimeofday(&start, NULL);
	for(i = 0; i < LOOPTIME ; i++)
		binsearch_ver1(array, 0, 99, findNumber);
	gettimeofday(&end, NULL);
	count_time_by_usec(end, start, "alg2");

	exit(0);

}
