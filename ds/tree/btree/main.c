#include <stdio.h>
#include <stdlib.h>



struct score_st
{
	int id;

	char name[NAMESIZE];
	int math;
	int chinese;

};

struct node_st
{
	struct score_st *data;
	struct node_st *l,*r;

}


insert(struct node_st **root,struct score_st *data)
{
	if(data->id <=)


}



int main()
{
	int arr[] = {1,2,3,7,6,5,9,8,4};
	struct node_st *tree =NULL;
	
	for(i=0;i<sizeof(arr)/sizeof(*arr);i++)
	{
		tmp.id = arr[i];
		snprintf(tmp.name,NAMESIZE,"stu%d",arr[i]);
		tmp.math =rand()%100;
		tmp.chinese = rand()%100;

		insert(&tree,&tmp);//为什么传树的地址？因为这里的树不带头节点，所以 起始位置会变化，所以传树的地址过去
	
	}

	
	exit(0);
}
