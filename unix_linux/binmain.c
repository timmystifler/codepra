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



int main()
{
	int array[100] = {0, 3 , 4, 6};
	int i = 0;
	int findNumber = 3;
	//srand(time(0));


/*	for(i = 0; i < 100; i++)
	{
		array[i] = rand()%100;
		printf("%d%c", array[i], ((i+1)%10 == 0)?'\n':'\t');
	}
	*/
	printf("enter the number you will find:");
	scanf("%d", &findNumber);
	printf("\n%d\n", findNumber);
	//fflush(stdin);
	
	//printf("ok");
	printf("result1:%d\t", binsearch_original(array, 0, 99, findNumber));
	printf("result2:%d\t", binsearch_ver1(array, 0, 99, findNumber));

	exit(0);

}
