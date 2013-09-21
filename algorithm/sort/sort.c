#include "sort.h"
#include "commonlib.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define MAXCOUNT 1000000


element_type median3(element_type *array, int left, int right);


void q_sort(element_type *array, int left, int right);


void quick_sort_single(element_type *array, int arraysize)
{
	assert(array && arraysize > 0);
	q_sort(array, 0, arraysize-1);
}

void q_sort(element_type *array, int left, int right)
{
	if(left >= right)
		return;
	int i, j;
	element_type pivot = median3(array, left, right);

	i = left;
	j = right+1;
	for(;;)
	{
		while(array[++i] < pivot && i <= right)
			;
		while(array[--j] > pivot)
			;
		if(i < j)
		{
			SWAP(array[i], array[j]);
		}
		else
			break;
	}
	SWAP(array[left],array[j]);
	q_sort(array, left, j-1);
	q_sort(array, j+1, right);
}


void count_sort(element_type *array, int arraysize)
{
	element_type temp_array[MAXCOUNT];
	int i = 0;
	int j = 0;
	for(i = 0; i < MAXCOUNT; i++)
		*(temp_array+i) = 0;

	for(i = 0; i < arraysize; i++)
	{
		int temp = *(array+i);
		temp_array[temp]++;
	}

	int index = 0;

	for(i = 0; i < MAXCOUNT;i++)
	{
		for(j = 0; j < temp_array[i]; j++)
		{
			*(array+index) = i;
			index++;
		}
	}

}

void insertion_sort(element_type *array, int arraysize)
{
	int i, j;
	element_type tmp;
	
	for(i = 1; i < arraysize; i++)
	{
		tmp = *(array+i);
		for(j = i; j > 0 && tmp < *(array+j-1); j--)
		{
				SWAP(*(array+j),*(array+j-1));
		}
		*(array+j) = tmp;
	}
}

void quick_sort_double(element_type *array, int arraysize)
{
}


void shell_sort(element_type *array, int arraysize)
{
	int i, j, increment;
	element_type tmp;

	assert(array && arraysize > 0);

	for(increment = arraysize/2; increment > 0; increment /= 2)
	{
		for(i = increment; i < arraysize; i++)
		{
			tmp = *(array+i);
			for(j = i; j >= increment; j -= increment)
			{
				if(*(array+j) < *(array+j-increment))
				{
					SWAP(*(array+j), *(array+j-increment));
				}
				else
					break;
			}
		}
	}
}

element_type median3(element_type *array, int left, int right)
{
	int center = left + (right-left)/2;
	if(*(array+left) > *(array+right))
	{
		SWAP(*(array+left), *(array+right));
	}
	if(*(array+left) > *(array+center))
	{
		SWAP(*(array+left), *(array+center));
	}
	if(*(array+center) > *(array+right))
	{
		SWAP(*(array+right), *(array+center));
	}

	SWAP(*(array+left), *(array+center));
	return *(array+left);
}


