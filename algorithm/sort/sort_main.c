#include "sort.h"
#include "commonlib.h"
#include <stdio.h>
#include <stdlib.h>

#define ARRAYSIZE 1024

void printall(element_type *array, int arraysize);


int main()
{
	element_type array[ARRAYSIZE];
	gernerate_random_array(array, ARRAYSIZE, 0, 500000);
	printf("before sort\n");
	printall(array, ARRAYSIZE);
	//insertion_sort(array, ARRAYSIZE);
	count_sort(array, ARRAYSIZE);
	printf("after sort\n");
	printall(array, ARRAYSIZE);

	return (0);
}


void printall(element_type *array, int arraysize)
{
	int i = 0;
	for(i = 0; i < arraysize; i++)
	{
		printf("%6d%c", *(array+i), (i+1)%8 == 0 ? '\n' : ' ');
	}
	printf("\n");

}
