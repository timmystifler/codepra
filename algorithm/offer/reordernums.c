#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "commonlib.h"
int is_even(int n);
void reordernums(int *data, int length, int (*func)(int))
{
	assert(length>0 && data);

	int *p_begin = data;
	int *p_end = data+length-1;

	while(p_begin < p_end)
	{
		while(p_begin < p_end && !(*func)(*p_begin))
			p_begin++;
		while(p_begin < p_end && (*func)(*p_end))
			p_end--;
		if(p_begin < p_end)
		{
			swap(p_begin, p_end);
		}
	}
}

int is_even(int n)
{
	return (n&1) == 0;
}


int main()
{
	int array[10] = {0};
	int i = 0;

	for(i = 0; i < 10; i++)
		scanf("%d", array+i);
	reordernums(array, 10, is_even);
	for(i = 0; i < 10; i++)
		printf("%d ", *(array+i));
}
