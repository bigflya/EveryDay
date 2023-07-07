#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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


static int id_cmp(const void *key,const void *record)
{
	const int *k = key;
	const struct score_st *r =record;
	
	return (*k - r->id);

}


static int name_cmp(const void *key,const void *record)
{
	const char *k = key;
	const struct score_st *r =record;
	
	return strcmp(k,r->name);// if return 0  do.... ,else not do

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
		
		ret =handler->insert(handler,&tmp,LINKLIST_BACKWARD);
		if(ret)
			exit(1);
		
	}
	
	handler->travel(handler,print_s);
	

	printf("\n\n");
	int id =30;
	char *name ="std2";
	ret = handler->del(handler,name,name_cmp);
	if(ret)
		printf("delete failed!\n");
	
	handler->travel(handler,print_s);
#if 0
	int id =15;
	struct score *data;
	data = linklist_find(handler,&id,id_cmp);
	
	if(data ==NULL)
		printf("can not find id :%d\n",id);
	else
		print_s(data);
#endif
	
	linklist_destroy(handler);

	exit(0);
}
