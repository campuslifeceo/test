#ifndef _LINK_LIST_H
#define _LINK_LIST_H
struct linked_list
{
	int number;
	struct linked_list* next;
};

typedef struct linked_list node;


void create(node *list);
int count(node* p);
void print(node* p);
#endif

