#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "linklist.h"

#define NAMESIZE 32
struct score_st
{
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;

};

static void print_s(const void  *record)
{
	const struct score_st *r = record;
	printf("%d %s %d %d \n",r->id,r->name,r->math,r->chinese);

}


int main()
{
	struct score_st tmp;
	STACK *st;
	st = stack_create(sizeof(struct score_st));
	
	if(st == NULL)
		exit(1);
	
	for(int i=0;i<7;i++)
	{
		tmp.id = i;
		snprintf(tmp.name,NAMESIZE,"std%d",i);
		tmp.math = rand()%100;
		tmp.chinese = rand()%100;
		if(stack_push(st,&tmp))
			exit(1);
		
		
		
	}
	
	while(1)
	{
		int ret = stack_pop(st, &tmp);
		if(ret == -1)
			break;
		print_s(&tmp);	
	}
	
	
	stack_destroy(st);

	exit(0);
}
