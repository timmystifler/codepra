/*
 * =====================================================================================
 *
 *       Filename:  binsearch.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/29/2013 11:17:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ZhangYue (TimmyStifler), timmystifler@hotmail.com
 *   Organization:  USTC-SSE
 *
 * =====================================================================================
 */

#include <stdio.h>
#include "binsearch.h"


int binsearch_original(int *array, int low, int high, int number)
{
	int left, right;
	int mid;
	left = low;
	right = high;
	while(left <= right)
	{
		mid = left + (right - left)/2;
		
		if (*(array+mid) == number)
		{
			return mid;
		}
		else if (*(array+mid) < number)
		{
			left = mid + 1;
		}
		else
		{
			right = mid -1;
		}
	}
	return -1;
			
}

int binsearch_ver1(int *array, int low, int high, int number)
{
	int left, right, mid;

	left = low - 1;
	right = high + 1;
	//left = 0;
	//right = high+1;

	while((left + 1) != right)
	{
		mid = left + (right - left)/2;
		if (*(array+mid) < number)
			left = mid;
		else
			right = mid;
	}
	int locate = right;
	if (locate >= (high+1) || *(array+locate) != number)
		return -1;
	else
		return locate;
}


int binsearch_ver2(int *array, int number)
{
	int i = 512;
	int l = -1;
	int nexti;

	if (*(array+511) < number)
		l = 1000 - 512;
	
	while(i != l)
	{
		nexti = i/2;
		//.............
	}

}
