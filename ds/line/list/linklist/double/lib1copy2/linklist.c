#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"

struct linklist_node_st
{
	//void *data;
	struct linklist_node_st *prev;
	struct linklist_node_st *next;
	char data[1];//变长结构体的内容要放在当前结构体的最后一个成员,放在前面也可以，但是偏移地址的计算就是个棘手的问题

};

struct linklist_head_st
{
	int size;
	struct linklist_node_st head;

};




LINKLIST *linklist_create(int initsize)
{
	struct linklist_head_st *new;
	new = malloc(sizeof(*new));
	if(new ==NULL)
		return NULL;
		
	new->size = initsize;
	//new->head.data =NULL;
	new->head.prev = &new->head;
	new->head.next = &new->head;
	return new;

}


int linklist_insert(LINKLIST *p,const void *data,int mode)
{
	struct linklist_node_st *newnode;
	struct linklist_head_st *ptr =p;
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

static struct linklist_node_st *find_(struct linklist_head_st *ptr,const void *key,linklist_cmp *cmp)
{////find_ 用户看不到 ，怎么方便怎么改
	struct linklist_node_st *cur;
	for(cur =ptr->head.next; cur!= &ptr->head;cur = cur->next)
	{
		if(cmp(key,cur->data) ==0)
			break;
	
	}
		return cur;

}
void *linklist_find(LINKLIST *p,const void *key,linklist_cmp *cmp)
{
	struct linklist_node_st *node;
	struct linklist_head_st *ptr =p;
	node = find_(ptr,key,cmp);
	if(node ==&ptr->head)
		return NULL;
	return node->data;

}

int linklist_delete(LINKLIST *p,const void *key,linklist_cmp *cmp)
{
	struct linklist_node_st *node;
	struct linklist_head_st *ptr =p;
	node = find_(ptr,key,cmp);
	if(node == &ptr->head)
		return -1;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	
	//free(node->data);
	free(node);
	return 0; 
}
int linklist_fetch(LINKLIST *p,const void *key,linklist_cmp *cmp,void *data)
{
	struct linklist_node_st *node;
	struct linklist_head_st *ptr =p;
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



void linklist_travel(LINKLIST *p,linklist_operate *op)
{
	struct linklist_node_st *cur;
	struct linklist_head_st *ptr =p;
	for(cur = ptr->head.next;cur != &ptr->head; cur= cur->next)
		op(cur->data);
}


void linklist_destroy(LINKLIST *p)
{
	struct linklist_node_st *cur,*next;
	struct linklist_head_st *ptr =p;
	for(cur = ptr->head.next; cur != &ptr->head;cur=next)
	{
		next = cur->next;
		//free(cur->data);//data是要申请内存空间的，因为data 是一个指针，自己指向一块小空间
		free(cur);
		
	
	}
	//free(ptr->data);
	free(ptr);
}
