#include "s_linklist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	link_list list = create_list();
	insert_node_athead(list, "zhangyue");
	insert_node_athead(list, "zhangyue1");
	insert_node_athead(list, "zhangyue2");
	insert_node_athead(list, "zhangyue3");
	insert_node_athead(list, "zhangyue4");
	insert_node_athead(list, "zhangyue5");
	insert_node_athead(list, "zhangyue6");
	insert_node_athead(list, "zhangyue7");
    //show_all_elems(list);
	reverse_list(&list);
	show_all_elems(list);
	position pKth = find_kth_totail(list, 5);
	printf("the kth is %s\n", pKth->elem);
	delete_node_inO1(list, pKth);
	show_all_elems(list);
	link_list list2 = create_list();
	insert_node_athead(list2, "zhangyue5");
	insert_node_athead(list2, "zhangyue4");
	link_list merge_list = merge_two_lists(list, list2);
	show_all_elems(merge_list);
	return 0;
}
