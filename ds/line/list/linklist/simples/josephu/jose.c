#include <stdio.h>
#include <stdlib.h>


#define JOSE_NUM 8  //无头的单向环链(循环) 链表
struct node_st
{
	int data;
	struct node_st *next;

};
struct node_st *jose_create(int n)
{
	struct node_st *me,*newnode,*cur;
	int i =1;
	me = malloc(sizeof(*me));
	if(me == NULL)
		return NULL;
	me->data = i;
	
	me->next = me;
	i++;
	cur = me;
	for(;i<=n;i++)
	{
		newnode = malloc(sizeof(*newnode));
		if(newnode ==NULL)
			return NULL;
		newnode->data = i;
		newnode->next = me;
		cur->next = newnode;
		cur = newnode;
		
	
	
	}
	return me;
}
void jose_show(struct node_st *me)
{
	struct node_st *list= me;
	
	
	do
	{
	
		printf("%d ",list->data);
		list = list->next;
		
	}while(list != me);
	
	
	printf("\n");

}

void jose_kill(struct node_st **me,int kill)
{
	struct node_st *cur =*me,*node;
	int i=1;
	
	while(cur !=cur->next)
	{
	
	while(i<kill)
	{
		node = cur;
		cur = cur->next;
		i++;
		
	}
	printf("%d ",cur->data);
	node->next=cur->next;
	free(cur);
	
	cur = node->next;
	
	i =1;
	}
	*me = cur;//改变二级指针的一级目标
	printf("\n");
}
int main()
{
	struct node_st *list;
	int kill =3;
	list = jose_create(JOSE_NUM);
	
	if(list ==NULL)
		exit(1);
	jose_show(list);
	jose_kill(&list,kill);
	
	jose_show(list);
	exit(0);
}
