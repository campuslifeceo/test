#include <stdio.h>
#include <stdlib.h>
#include "link_list.cpp"
int main(int argc, char** argv)
{
	node *head;
	head = (node*)malloc(sizeof(node));
	create(head);
	printf("\n");
	print(head);
	printf("\n");
	printf("\nNumber of items = %d \n", count(head));
	return 0;
}
