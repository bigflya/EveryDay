#include <stdio.h>
#include <stdlib.h>
#include "list.h"











list *list_create()
{
	list *me;

	me = malloc(sizeof(*me));
	if(me ==NULL)
		return NULL;
	me->next = NULL;
	return me;
}
int list_insert_at(list *me,int i,datatype *data)
{
	int j =0;
	list *node = me, *newnode;
	if(i<0)
		return -1;
	while(j<i&& node !=NULL)
	{
	
		node = node->next;
		j++;
	
	}
	if(node)
	{
		newnode = malloc(sizeof(*newnode));
		if(newnode == NULL)
			return -2;//申请内存空间失败
		newnode->data = *data;
		newnode->next = node->next;
		node->next = newnode;
		return 0;//插入成功
	}
	else
	
	
	return -3;//给的插入位置i不合理，超出了链表的长度 


	

}
int list_order_insert(list *me,datatype *data)
{
	list *p = me, *q;
	//list *p =me;
	//list *q;
	while(p->next && p->next->data < *data)
		p = p->next;
	q = malloc(sizeof(*q));
	if(q ==  NULL)
		return -1;//申请内存
	q->data = *data;
	q->next = p->next;
	p->next = q;
	return 0;


}
int list_delete_at(list *me,int i,datatype *data)
{
	int j = 0;
	list *p = me,*q;
	
	*data = -1;

	if(i<0)
		return -1;
	while(j<i &&p)
	{
		p = p->next;
		j++;

	}

	if(p)
	{
		q= p->next;
		p->next = q->next;
		*data = q->data;
		free(q);
		q= NULL;

		return 0;
	}
	else
		return -2;//删除的位置超过了数组的长度
}
int list_delete(list *me,datatype *data)
{
	list *p=me, *q;
	while(p->next && p->next->data != *data)
		p = p->next;
	if(p->next ==NULL)
		return -1;
	else
	{
		q = p->next;
		p->next = q->next;
		free(q);
		q = NULL;
	}
}	
int list_isempty(list *me)
{
	if(me->next == NULL)
		return 0;
	return 1;
}
void list_display(list *me)
{
	list *node = me->next;
	if(list_isempty(me) == 0)
		return;
	while(node != NULL)
	{
	
		printf("%d ",node->data);
		node = node->next;
	}
	printf("\n");
	return ;
}

void list_destroy(list *me)
{
	list *node,*next;
	for(node = me->next;node != NULL; node =next)
	{
		next = node->next;
		free(node);
	
	}

	free(me);//or free(node); 头结点销毁
	return ;
}

