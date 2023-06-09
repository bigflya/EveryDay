#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"

int linklist_insert(LINKLIST *,const void *data,int mode);
void *linklist_find(LINKLIST *,const void *key,linklist_cmp *);
int linklist_delete(LINKLIST *,const void *key,linklist_cmp *);
int linklist_fetch(LINKLIST *,const void *key,linklist_cmp *,void *data);
void linklist_travel(LINKLIST *,linklist_operate *);



LINKLIST *linklist_create(int initsize)
{
	LINKLIST *new;
	new = malloc(sizeof(*new));
	if(new ==NULL)
		return NULL;
		
	new->size = initsize;
	//new->head.data =NULL;
	new->head.prev = &new->head;
	new->head.next = &new->head;
	new->insert = linklist_insert;//linklist_insert()写成这样就成赋值了，现在只是调用
	new->find = linklist_find;
	new->del = linklist_delete;
	new->fetch = linklist_fetch;
	new->travel = linklist_travel;
	return new;

}


int linklist_insert(LINKLIST *ptr,const void *data,int mode)
{
	struct linklist_node_st *newnode;
	
	//newnode = malloc(sizeof(*newnode));
	newnode = malloc(sizeof(*newnode)+ptr->size);
	if(newnode == NULL)
		return -1;
	
//	newnode->data = malloc(ptr->size);
//	if(newnode->data==NULL)
//		return -2;
	
	memcpy(newnode->data, data, ptr->size);
	
	if(mode == LINKLIST_FORWARD)//头节点的位置是不变的，插入的位置要么在头节点的前面（尾部）要么在头节点的后面（首部）,LINKLIST_FORWARD 首部
	{
		newnode->prev = &ptr->head;
		newnode->next = ptr->head.next;
		
		//newnode->prev->next = newnode;
		//newnode->next->prev = newnode;
	}
	else	if(mode == LINKLIST_BACKWARD)
		{
			newnode->prev = ptr->head.prev;
			newnode->next = &ptr->head;
		
			//newnode->prev->next = newnode;
			//newnode->next->prev = newnode;
		
		}
		else
		{
			return -3;
		}
	newnode->prev->next = newnode;
	newnode->next->prev = newnode;
	return 0;
}

static struct linklist_node_st *find_(LINKLIST *ptr,const void *key,linklist_cmp *cmp)
{
	struct linklist_node_st *cur;
	for(cur =ptr->head.next; cur!= &ptr->head;cur = cur->next)
	{
		if(cmp(key,cur->data) ==0)
			break;
	
	}
		return cur;

}
void *linklist_find(LINKLIST *ptr,const void *key,linklist_cmp *cmp)
{
	struct linklist_node_st *node;
	
	node = find_(ptr,key,cmp);
	if(node ==&ptr->head)
		return NULL;
	return node->data;

}

int linklist_delete(LINKLIST *ptr,const void *key,linklist_cmp *cmp)
{
	struct linklist_node_st *node;
	node = find_(ptr,key,cmp);
	if(node == &ptr->head)
		return -1;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	
	//free(node->data);
	free(node);
	return 0; 
}
int linklist_fetch(LINKLIST *ptr,const void *key,linklist_cmp *cmp,void *data)
{
	struct linklist_node_st *node;
	node = find_(ptr,key,cmp);
	if(node == &ptr->head)
		return -1;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	if(data !=NULL)
		memcpy(data,node->data,ptr->size);
	
	//free(node->data);
	free(node);
	return 0;

}



void linklist_travel(LINKLIST *ptr,linklist_operate *op)
{
	struct linklist_node_st *cur;
	for(cur = ptr->head.next;cur != &ptr->head; cur= cur->next)
		op(cur->data);
}


void linklist_destroy(LINKLIST *ptr)
{
	struct linklist_node_st *cur,*next;
	for(cur = ptr->head.next; cur != &ptr->head;cur=next)
	{
		next = cur->next;
		//free(cur->data);//data是要申请内存空间的，因为data 是一个指针，自己指向一块小空间
		free(cur);
		
	
	}
	//free(ptr->data);
	free(ptr);
}
