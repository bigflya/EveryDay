#include <stdio.h>
#include <stdlib.h>

#include "list.h"


int main()
{
	list *l;
	datatype arr[] = {11,22,33,4,55,66,77,8,99,9};
	l = list_create();

	if(l ==NULL)
		exit(1);

	for(int i= 0;i<sizeof(arr)/sizeof(*arr);i++)
	{

		if(list_order_insert(l,&arr[i]))
			return -9;//失败
	
	}
	
	int err;
	list_display(l);
	datatype value;
	err = list_delete_at(l,2,&value);
	if(err)
		exit(1);

	list_display(l);
	printf("delete element is :%d\n",value);

	// list_insert_at(l,0,&arr[i]);
#if 0 
 	int value = 4;
	list_delete(l,&value);
	list_display(l);
#endif
	list_destroy(l);

	exit(0);
}
