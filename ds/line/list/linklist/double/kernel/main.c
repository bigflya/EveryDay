#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define NAMESIZE 32


struct score_st
{
	int id;
	char name[NAMESIZE];
	struct list_head node;
	int math;
	int chinese;

};

static void print_s(struct score_st *d)
{
	printf("%d %s %d %d \n",d->id,d->name,d->math,d->chinese);
	
}
int main()
{
	int i;
	struct score_st *datapointer;
	struct list_head *cur;
	
	LIST_HEAD(head);
	
	for(i=0;i<7;i++)
	{
		datapointer = malloc(sizeof(*datapointer));
		if(datapointer ==NULL)
			exit(1);
		datapointer->id = i;
		snprintf(datapointer->name,NAMESIZE,"std%d",i);
		datapointer->math = rand()%100;
		datapointer->chinese = rand()%100;
		//list_add(&datapointer->node,&head);
		list_add_tail(&datapointer->node,&head);
	}
		
		list_for_each(cur,&head)
		{
		
			datapointer = list_entry(cur,struct score_st,node);
			print_s(datapointer);
		}
		
		
		
		printf("\n");
		list_for_each(cur,&head)
		{
			datapointer = list_entry(cur,struct score_st,node);
			if(datapointer->id == 15)
				break;
		}
		if(cur ==&head)
			printf("can not find\n");
		else
			print_s(datapointer);
}
