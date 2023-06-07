#include <stdio.h>
#include <stdlib.h>
#include "nohead.h"




struct node_st * list_insert(struct node_st *list,struct score_st *data)
{
	struct node_st *new;
	new = malloc(sizeof(*new));
	if(new == NULL)
		return NULL;
	
	new->data = *data;
	//new->next = NULL;
	
	new->next = list;
	list = new;
	return list;


}//如果有多种错误，返回的错误码都是空 ，这样不利于找错误原因

int list_insert1(struct node_st **list,struct score_st *data)
{
	struct node_st *new;
	new = malloc(sizeof(*new));
	if(new == NULL)
		return -1;
	
	new->data = *data;// *data是 数据的地址
	//new->next = NULL;
	
	new->next = *list;//改变一级指针的
	*list = new;//把new给了二级指针的一级目标
	return 0;


}

void list_show(struct node_st *list)
{
	struct node_st *cur;
	for(cur = list;cur !=NULL;cur=cur->next)
	{
		printf("%d %s %d %d \n",cur->data.id, cur->data.name,cur->data.math,cur->data.chinese);
	}

}


int list_delete(struct node_st **list)
{
	struct node_st *cur;
	if(*list == NULL)
		return -1;
	cur = *list;	
	*list = (*list)->next;
	free(cur);
	return 0;
}

struct score_st * list_find(struct node_st * list ,int id)
{

	struct node_st *cur;
	
	for(cur = list;cur != NULL; cur = cur->next)
	{
		
		if(cur->data.id == id)
		{
			
			return &(cur->data);
		
		}
			
	}
	

	return NULL;
	

}


void list_destroy(struct node_st *list)
{
	struct node_st *cur;
	if(list == NULL)
		return ;
	for(cur=list;cur!=NULL;cur=list)
	{
		list = cur->next;
		
		free(cur);
	}
}
