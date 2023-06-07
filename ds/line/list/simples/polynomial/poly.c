#include <stdio.h>
#include <stdlib.h>

struct node_st
{

	int coefficient;
	int exp;
	struct node_st *next;
	
};

struct node_st *poly_create(int a[][2],int n)
{
	struct node_st *me;
	me = malloc(sizeof(*me));
	if(me == NULL)
		return NULL;
	
	
	return me;
}

int main()
{
	int a[][2] = {5,0,2,1,8,8,3,16};
	int b[][2] = {6,1,16,6,-8,8};
	
	struct node_st *p1,*p2;
	
	poly_create();
	poly_show();
	poly_union();
	poly_show();
	exit(0);

}
