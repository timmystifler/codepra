#ifndef HASHLINK_H_
#define HASHLINK_H_


typedef int bool_t;
typedef struct node *node_ptr;
typedef node_ptr *hashtable;
typedef struct node
{
	int count;
	char *word;
	node_ptr next_node;
}node;

hashtable create_hashtable(int tablesize);
bool_t destory_hashtable(int tablesize,hashtable ht);
bool_t insert_node(hashtable ht, int tablesize, char *buf);
node_ptr find_node(hashtable ht, int tablesize, char *word);
void print_allwords(hashtable ht, int tablesize);
bool_t delete_node(hashtable ht, int tablesize, char *buf);
unsigned int hash_function(char* word, int tablesize);

#endif
