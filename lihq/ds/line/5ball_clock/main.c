#include <stdio.h>
#include <stdlib.h>
#include "sqstack.h"
#include "squeue.h"

#define NR_BALL 27





static int check(queue *qu)
{

	int i = (qu->head+1)%MAXSIZE;//表示当前现有第一个元素  (i+1)%MAXSIZE,可以防止越界
	while(i != qu->tail)
	{
		if(qu->data[i]> qu->data[(i+1)%MAXSIZE])
			return 0;
		i = (i+1)%MAXSIZE; 
	
	}
	return 1;

}





int main()
{
	queue *qu;
	sqstack *st_min,*st_5min,*st_hour;
	int i;
	int t,value;
	int time =0;
	qu = qu_create();
	if(qu == NULL)
		exit(1);
		
	st_min = st_create();
	if(st_min == NULL)
		exit(1);
	st_5min = st_create();
	if(st_5min == NULL)
		exit(1);
	st_hour = st_create();
	if(st_hour == NULL)
		exit(1);
	for(i=1;i<=NR_BALL;i++)
	{
		qu_enqueue(qu,&i);
	}
	qu_travel(qu);

	while(1)
	{
		qu_dequeue(qu,&t);
		
		time++;
		if(st_min->top  !=3)// ->  == (*p).
			st_push(st_min,&t);
		
		else
		{
			while(!st_isempty(st_min))
			{
				st_pop(st_min,&value);
				qu_enqueue(qu,&value);
			
			}
			if(st_5min->top !=10)
				st_push(st_5min,&t);
			
			else
			{
				while(!st_isempty(st_5min))
				{
					st_pop(st_5min,&value);
					qu_enqueue(qu,&value);
				
				}
				if(st_hour->top !=10)
					st_push(st_hour,&t);
				else
				{
					while(!st_isempty(st_hour))
					{
						st_pop(st_hour,&value);
						qu_enqueue(qu,&value);
					}
					qu_enqueue(qu,&t);
					//qu_travel(qu);
					if(check(qu))
						break;
				}
				
			}
		}
	
	}

	
	
	printf("time= %d\n",time);
	qu_destroy(qu);
	st_destroy(st_min);
	st_destroy(st_5min);
	st_destroy(st_hour);
	exit(0);
}
