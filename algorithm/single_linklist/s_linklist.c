#include "s_linklist.h"
#include "commonlib.h"
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

position find_elem_pos(link_list head, element_type elem)
{
	if(head == NULL)
		return NULL;
	while(head->next)
	{
		if (head->next->elem == elem)
			return head->next;
		else
			head = head->next;
	}
	return NULL;
}

bool_t delete_node_inO1(link_list head, position toBeDeleted)
{
	if(head == NULL || head->next == NULL || toBeDeleted == NULL)
		return FALSE;
	if(toBeDeleted->next != NULL && toBeDeleted != head)
	{
		position temp = toBeDeleted;
		toBeDeleted->elem = toBeDeleted->next->elem;
		toBeDeleted->next = toBeDeleted->next->next;
		free(temp);
		return TRUE;
	}
	if(toBeDeleted->next == NULL && toBeDeleted != head)
	{
		return delete_node_bypos(head, toBeDeleted);
	}
	return FALSE;
}

bool_t delete_node_bypos(link_list head, position pos)
{
	if(head == NULL || head->next == NULL || pos == NULL)
		return FALSE;
	while(head)
	{
		if(head->next == pos)
		{
			head->next = head->next->next;
			free(pos);
			return TRUE;
		}
		head = head->next;
	}
	return FALSE;
}

  
position find_kth_totail(link_list head, int k)
{
	if(k <= 0 || head == NULL)
		return NULL;
	int i = 0;
	position pEnd;
	position pKth;
	pEnd = pKth = head;
	for(i = 0; i < k-1; i++)
	{
		if(pEnd->next != NULL)
			pEnd = pEnd->next;
		else
			return NULL;
	}

	while(pEnd->next != NULL)
	{
		pEnd = pEnd->next;
		pKth = pKth->next;
	}
	return pKth;
}


void reverse_list(link_list* head)
{
	if(*head == NULL || head == NULL)
	{
		fprintf(stderr, "invalid input\n");
		return;
	}
	position pPrev = NULL;
	position pNext;
	position pCurrent = (*head)->next;
	while(pCurrent)
	{
		pNext = pCurrent->next;
		if(pNext == NULL)
			(*head)->next = pCurrent;
		pCurrent->next = pPrev;
		pPrev = pCurrent;
		pCurrent = pNext;
	}

}

void merge_two_lists(link_list list1, link_list list2)
{
	if(list1 == NULL)
		re
	postion plist1, plist2;
	plist1 = head
}
