#include "s_linklist.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

link_list create_list()
{
	link_list head = malloc(sizeof(node));
	if(head)
	{
		printf("create linklist with dummy node\n");
		head->next = NULL;
		head->elem = NULL;
		return head;
	}
	else
	{
		fprintf(stderr, "initiate linklist unsuccessfully,exit...");
		exit(-1);
	}
}

bool_t insert_node_athead(link_list head, element_type elem)
{
	node *pnode = malloc(sizeof(node));
	if(!pnode)
	{
		fprintf(stderr, "insert node failed");
		return -1;
	}
	else
	{
		pnode->elem = malloc(strlen((char*)elem)+1);
		if(!pnode->elem)
		{
			fprintf(stderr,"allocate memory for element failed, clear current node");
			free(pnode);
			return -1;
		}
		strcpy(pnode->elem, (char*)elem);
		pnode->next = head->next;
		head->next = pnode;
		return 0;
	}
}


void show_all_elems(link_list head)
{
	int i = 0;
	while(head->next)
	{
		++i;
		printf("%3d:%10s\n", i, (char *)head->next->elem);
		head = head->next;
	}
}


bool_t destory_list(link_list *head)
{
	if(*head == NULL || head == NULL)
	{
		fprintf(stderr,"destory linklist failed.\n");

		return -1;
	}

	position pnode = *head;
	while(pnode)
	{
		position ptemp = pnode;
		pnode = pnode->next;
		free(ptemp);
	}
	*head = NULL;
	printf("destory linklist.")
	return 0;
}

bool_t insert_node_attail(link_list head, element_type elem)
{
	if(head == NULL)
	{
		fprintf(stderr, "insert node failed.\n");
		return -1;
	}
	position pnode = malloc(sizeof(node));
	if(!pnode)
	{
		fprintf(stderr, "allocate memory for node failed.\n");
		return -1;
	}
	pnode->elem = malloc(strlen((char*)elem)+1);
	if(!pnode->elem)
	{
		free(pnode);
		fprintf(stderr, "allocate memory for element failed\n");
		return -1;
	}
	strcpy((char *)pnode->elem, (char*)elem);

	position temp = head;
	while(temp->next)
	{
		temp = temp->next;
	}
	temp->next = pnode;
	pnode->next = NULL;
	return 0;
}



