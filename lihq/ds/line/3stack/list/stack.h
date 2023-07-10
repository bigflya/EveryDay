#ifndef STACK_H__
#define STACK_H__

#include "linklist.h"


typedef LINKLIST STACK;

STACK *stack_create(int);

int stack_push(STACK *,const void *data);

int stack_pop(STACK *,void *data);

void stack_destroy(STACK *ptr);





#endif
