#include <stdio.h>

#include "stack.h"

STACK *stack_create(int initsize)
{
	
	return linklist_create(initsize);

}


int stack_push(STACK *ptr,const void *data)
{
	return linklist_insert(ptr,data,LINKLIST_FORWARD);
}

static int always_match(const void *p1,const void *p2)
{
	return 0;
}
int stack_pop(STACK *ptr,void *data)
{
	return  linklist_fetch(ptr,(void *)0,always_match,data);
	

}

void stack_destroy(STACK *ptr)
{
	linklist_destroy(ptr);

}
