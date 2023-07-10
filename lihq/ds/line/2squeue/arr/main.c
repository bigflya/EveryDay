#include <stdio.h>
#include <stdlib.h>

#include "squeue.h"


int main()
{
	queue *sq;
	datatype arr[] = {2,34,89,12};
	int i;
	sq = qu_create();
	if(sq == NULL)
		exit(1);
	for(i=0;i<sizeof(arr)/sizeof(*arr);i++)
	
		qu_enqueue(sq,&arr[i]);
	
	qu_travel(sq);
/*
	datatype val =32;
	int ret = qu_enqueue(sq,&val);
	if(ret == -1)
		printf("queue is full!\n");
	else
		qu_travel(sq);
*/
	datatype tmp;
	
	qu_dequeue(sq,&tmp);
	printf("de_queue:%d\n",tmp);
	qu_travel(sq);
	qu_destroy(sq);
	
	
	
	
	exit(0);

}
