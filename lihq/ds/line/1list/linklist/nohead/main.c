#include <stdio.h>
#include <stdlib.h>
#include "nohead.h"



int main()
{
	struct node_st *list =NULL;
	struct score_st tmp;
	for(int i=0;i<7;i++)
	{
		tmp.id =i;
		snprintf(tmp.name,NAMESIZE,"stu%d",i);
		tmp.math = rand() %100;
		tmp.chinese =rand() %100;
		int ret =list_insert1(&list,&tmp);
		if(ret !=0)
			break;//错误
	
	}
	int id =6;
	struct score_st *ptr;
	list_show(list);
	ptr = list_find(list,id);
	if(ptr == NULL)
		printf("the id of %d can not found\n",id);
	else
		printf("%d %s %d %d \n",ptr->id, ptr->name,ptr->math,ptr->chinese);
//	list_delete(&list);
//	list_show(list);
	list_destroy(list);
	exit(0);


}
