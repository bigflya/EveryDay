#include <stdio.h>
#include <stdlib.h>

#include "sqstack.h"


int main()
{
	datatype arr[] = {19,23,45,67};
	sqstack *st;
	
	st = st_create();
	if(st ==NULL)
		exit(1);
		
	for(int i=0;i<sizeof(arr)/sizeof(*arr);i++)
		
		st_push(st,&arr[i]);
		

	st_travel(st);
	
	datatype tmp;
	
	
	
	while(st_pop(st,&tmp)==0)
	{
		printf("POP:%d\n",tmp);
	
	}
	

/*
	datatype tmp = 1;
	st_push(st,&tmp);
	int ret = st_push(st,&tmp);
	if(ret !=0)
		printf("st_push faild!");
	else
		st_travel(st);
*/	
	st_destroy(st);
	
	
	
	
	exit(0);

}
