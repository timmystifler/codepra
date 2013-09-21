#include "hashlink.h"
#include <stdio.h>
#include <stdlib.h>
#define MULT 32
#define TABLESIZE 29989

hashtable create_hashtable(int tablesize)
{
	int i = 0;
	hashtable ht = (hashtable)malloc(sizeof(node_ptr) * tablesize);
	if(ht)
	{
		printf("create hashtable ok, then init it ...\n");
	}
	else
	{
		fprintf(stderr, "error for create hashtable");
		exit(EXIT_FAILURE);
	}
	for(i = 0; i < tablesize; i++)
		*(ht + i) = NULL;
	printf("ok for use\n");
}


unsigned int hash_function(char *word, int tablesize)
{
	unsigned int hashnum = 0;
	for(; *word; word++)
		p = p*MULT + *word;
	return p%tablesize;
}

boot_t insert_node(hashtable ht, int tablesize,char *buf)
{
	unsigned int h = hash_function(buf);
	node_ptr pnode = *(ht + h);
	while(pnode)
	{
		if(strcmp(pnode->word, buf) == 0)
		{
			pnode->count++;
			return 0;
		}
		pnode = pnode->next_node;
	}

	pnode = (node_ptr)malloc(sizeof(node));
	if(pnode)
	{
		strcpy(pnode->word, buf);
		pnode->count = 1;
		pnode->next_node = *(ht+h);
		*(ht+h) = pnode;
		return 0;
	}
	else
	{
		fprintf(stderr, "insert node failed");
		return 1;
	}
}

void print_allwords(hashtable ht, int tablesize)
{
	int i = 0;
	for(i = 0; i < tablesize; i++)
	{
		node_ptr pnode = *(ht + i);
		while(pnode)
		{
			printf("")
		}
	}
}
