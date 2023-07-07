#include <stdio.h>
#include <stdlib.h>
//有头链表实现多项式加法
struct node_st
{

	int coefficient;
	int exp;
	struct node_st *next;
	
};

struct node_st *poly_create(int a[][2],int n)
{
	struct node_st *me,*newnode,*cur;
	me = malloc(sizeof(*me));
	if(me == NULL)
		return NULL;
	me->next = NULL;
	cur = me;
	
	for(int i =0; i<n; i++)
	{
		newnode = malloc(sizeof(*newnode));
		if(newnode == NULL)
			return NULL;
		newnode->coefficient = a[i][0];
		newnode->exp = a[i][1];
		newnode->next = NULL;
		cur->next =newnode;
		cur = newnode;
	}
	
	return me;
}

struct node_st * poly_union(struct node_st *p1,struct node_st *p2)
{
	struct node_st *p,*q,*r;//r相当于一个专门用来改 p1中 对应地址里面的值，的一个结构体指针
	p = p1->next;
	q = p2->next;
	r = p1;//头节点给r
	while(p && q)
	{
		if(p->exp < q->exp)
		{
			r->next = p;
			r = p;//因为p指向的是p1的next，把p给r相当于把p1头节点的next给r，目的就是让r的地址后移，指向下一位
			
			p = p->next;
			

			
		}	
		else if(p->exp > q->exp)
			{
			r->next = q;
			r = q;
			q = q->next;
			
			}
			else
			{
				p->coefficient +=q->coefficient;
				
				if(p->coefficient)
				{
					r->next =p;
					r=p;
					//p= p->next;
					//q = q->next;
				}
				
				p = p->next;
				q = q->next;
				
			
			}
	}
	if(p ==NULL)
		r->next = q;
	
	else
		r->next = p;
		

}

void poly_show(struct node_st *me)
{
	struct node_st *cur;
	for(cur = me->next;cur !=NULL;cur=cur->next)
	{
		printf("(%d %d)",cur->coefficient,cur->exp);
		
	}
	printf("\n");
}
int main()
{
	int a[][2] = {5,0,2,1,8,8,3,9};
	int b[][2] = {6,1,16,6,-8,8};
	
	struct node_st *p1,*p2;
	
	p1 = poly_create(a,4);
	if(p1 ==NULL)
		exit(1);
		
	p2 = poly_create(b,3);
	if(p2 ==NULL)
		exit(1);
	poly_show(p1);
	poly_show(p2);
	poly_union(p1,p2);
	poly_show(p1);
	exit(0);

}
