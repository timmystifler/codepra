#include "s_linklist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	link_list list = create_list();
	insert_node_athead(list, "zhangyue");
	insert_node_athead(list, "zhangyue1");
    show_all_elems(list);
	return 0;
}
