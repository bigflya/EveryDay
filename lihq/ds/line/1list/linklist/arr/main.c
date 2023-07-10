#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"



int main()
{

	sqlist *list=NULL,*list1=NULL;
	datatype arr[] = {12,23,3,55,47,36};
	datatype arr1[] = {23,58,66,44,77};
	int i,err;
	//list = sqlist_create();
	sqlist_create1(&list);

	if(list == NULL)
	{
		fprintf(stderr,"sqlist_create() failed!\n");
		exit(1);
	
	}
	list1 = sqlist_create();
	if(list1 == NULL)
	{
		fprintf(stderr,"sqlist_create() failed!\n");
                exit(1);

	}
	//printf("%d %d \n",__LINE__,sizeof(arr)/sizeof(*arr));
	for(i = 0; i<sizeof(arr)/sizeof(*arr); i++)
		if((err = sqlist_insert(list,0,&arr[i])) != 0)
		{
			if(err == -1)
			fprintf(stderr,"The arr is full.\n");
			else if (err == -2)
				fprintf(stderr,"The pos you want to insert is wrong!\n");
			     else
				fprintf(stderr,"ERR!\n");
			exit(1);
		}

	sqlist_display(list);
	
	for(i=0; i<sizeof(arr1)/sizeof(*arr1); i++)
	{
		sqlist_insert(list1,0,&arr1[i]);
		
	}

	sqlist_display(list1);

	sqlist_union(list,list1);
	sqlist_display(list);	
//	sqlist_delete(list,1);
//	sqlist_display(list);
	
	sqlist_destroy(list);
	sqlist_destroy(list1);


	exit(0);
}
