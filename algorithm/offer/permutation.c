#include "commonlib.h"
#include <assert.h>
#include <stdlib.h>


void permutation(char *str, char *begin);
void perm(char *str)
{
	assert(str != NULL);
	permutation(str, str);
}

void permutation(char *str, char *begin)
{
	if(*begin == '\0')
	{
		puts(str);
	}
	else
	{
		char *pswap;
		for(pswap = begin; *pswap != '\0'; pswap++)
		{
			swap_char(begin, pswap);
			permutation(str, begin+1);
			swap_char(begin, pswap);
		}
	}
}


int main()
{
	char p[] = "test1";
	//char *p;
	//p = malloc(sizeof(100));
	//gets(p);
	perm(p);
	//free(p);
}
