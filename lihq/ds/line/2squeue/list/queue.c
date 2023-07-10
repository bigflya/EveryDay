#include "queue.h"




QUEUE *queue_create(int size)
{
	return linklist_create(size);

}


int queue_en(QUEUE *ptr,const void *data)
{
	return linklist_insert(ptr,data,LINKLIST_BACKWARD);

}

static int always_match(const void *p1,const void *p2)
{
	return 0;

}


int queue_de(QUEUE *ptr,void *data)
{
	return linklist_fetch(ptr,(void *)0,always_match,data);

}


void queue_destroy(QUEUE *ptr)
{
	linklist_destroy(ptr);
}




