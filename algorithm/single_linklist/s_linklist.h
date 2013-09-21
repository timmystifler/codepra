#ifndef LINKLIST_H_
#define LINKLIST_H_

typedef void* element_type;
typedef int bool_t;

typedef struct node
{
	struct node *next;
	element_type elem;
}node;

typedef node* link_list;
typedef node* position;

link_list create_list();
bool_t destory_list(link_list *head);
bool_t insert_node_athead(link_list head, element_type elem);
bool_t insert_node_attail(link_list head, element_type elem);
bool_t delete_node_byelem(link_list head, element_type elem);
bool_t delete_node_bypos(link_list head, position *pos);
void show_all_elems(link_list head);
position find_elem_pos(link_list head, element_type elem);



#endif
