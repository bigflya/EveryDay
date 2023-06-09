#include <stdio.h>
#include <stdlib.h>

#include "linklist.h"

#define NAMESIZE 32

struct score_st
{
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;
	
};

void print_s(const void  *record)
{
	const struct score_st *r = record;
	printf("%d %s %d %d \n",r->id,r->name,r->math,r->chinese);

}


int main()
{


	LINKLIST *handler;
	struct score_st tmp;
	int ret;

	handler = linklist_create(sizeof(struct score_st));
	if(handler == NULL)
		exit(1);
		

	for(int i = 0;i<7;i++)
	{
		tmp.id = i;
		snprintf(tmp.name,NAMESIZE,"std%d",i);
		tmp.math = rand()%100;
		tmp.chinese = rand()%100;
		
		ret = linklist_insert(handler,&tmp,LINKLIST_FORWARD);
		if(ret)
			exit(1);
		
	}
	
	linklist_travel(handler,print_s);
	
	linklist_destroy(handler);

	exit(0);
}
