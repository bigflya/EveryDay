#include <stdio.h>
#include <stdlib.h>

#include "sqstack.h"



static void compute(sqstack *snum,datatype *op)
{
	datatype n1,n2,result;
	st_pop(snum,&n2);
	st_pop(snum,&n1);
	switch(*op)
	{
		case '+':
			result = n1 + n2;
			break;
		case '-':
			result = n1 - n2;
			break;
		case '*':
			result = n1 * n2;
			break;
		case '/':
			result = n1 / n2;
			break;
		default:
			exit(1);
	
	}
	
	st_push(snum,&result);

}

static void deal_bracket(sqstack *snum,sqstack *sop)
{
	datatype old_op;
	
	st_top(sop,&old_op);
	while(old_op !='(')
	{	
		st_pop(sop,&old_op);
		compute(snum,&old_op);
		st_top(sop,&old_op);
		
	}
	st_pop(sop,&old_op);

}

static int get_pri(int op)
{

	switch(op)
	{
		case '(':
			return 0;
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		
	
	}
}
static void deal_op(sqstack *snum,sqstack *sop, int op)
{
	
	datatype old_op;
	if(st_isempty(sop)|| op =='(')
	{
		st_push(sop,&op);
		return ;
	}
	st_top(sop,&old_op);
	
	if(get_pri(op)>get_pri(old_op))
	{
		st_push(sop,&op);
		return;
	}
	while(get_pri(op)<= get_pri(old_op))
	{
		st_pop(sop,&old_op);
		compute(snum,&old_op);
		if(st_isempty(sop))
			break;
		
		st_top(sop,&old_op);
	
	}
	st_push(sop,&op);

}
int main()
{
	
	int i =0;
	int flag=0;
	int value =0;
	datatype old_op;
	char s1[MAXSIZE];
	char s2[MAXSIZE];
	printf("this is a simple calculator implemented through the stack ,char str[] = (11+3)*2-1\n");

	char str[] = "(11+3)*2-1";
	sqstack *snum,*sop;

	
	
	snum = st_create();
	if(snum == NULL)
		exit(1);
		
	sop = st_create();
	if(sop == NULL)
		exit(1);
		
	while(str[i] !='\0')
	{
		if(str[i]>'0'&& str[i]<'9')
		{
			value = value*10 + (str[i] -'0');
			flag =1;
		
		}
		else
		{
			if(flag)
			{
				st_push(snum,&value);
				flag = 0;
				value =0;
			}
			
			if(str[i] ==')')
			{
				deal_bracket(snum,sop);
			
			}
			else//  ( +-*/
			{
				deal_op(snum,sop,str[i]);
			}
		
		}
		
		i++;
	
	}
	if(flag)
		st_push(snum,&value);
	
	while(!st_isempty(sop))
	{
		st_pop(sop,&old_op);
		compute(snum,&old_op);
		if(st_isempty(sop))
			break;
		
		st_top(sop,&old_op);
	
	}
	
	st_top(snum,&value);
	printf("result is: %d\n",value);
	
	st_destroy(snum);
	st_destroy(sop);

}
