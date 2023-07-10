#ifndef QUEUE_H__
#define QUEUE_H__

#include "linklist.h"
typedef LINKLIST QUEUE;

QUEUE *queue_create();


int queue_en(QUEUE *,const void *);
int queue_de(QUEUE *,void *);

void queue_destroy(QUEUE *);




#endif
