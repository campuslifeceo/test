#include "link_list.h"
#include <stdio.h>
#include <stdlib.h>

void create(node* list)
{
	printf("Input a number\n");
	printf("(type -999 at end): ");
	scanf("%d" ,&list->number);

	if(list->number == -999)
		list->next = NULL;
	else
	{
		list->next = (node*)malloc(sizeof(node));
		create(list->next);
	}
	return;
}

void print(node* list)
{
	if(list->next != NULL)
	{
		printf("%d-->",list->number);
		if(list->next->next == NULL)
			printf("%d", list->next->number);
		print(list->next);
	}
	return;
}

int count(node* list)
{
	if(list->next == NULL)
		return 0;
	else
		return (1+count(list->next));
}
