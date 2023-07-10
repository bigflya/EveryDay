#ifndef LINKLIST_H__
#define LINKLIST_H__


#define LINKLIST_FORWARD	1
#define LINKLIST_BACKWARD	2

typedef void linklist_operate(const void *);

typedef int linklist_cmp(const void *,const void *);
//利用typedef定义一些统一的接口，来让用户写回调函数，这样是为了抽象程序，使得程序不是为一个人写，增强了复用性

struct linklist_node_st
{
	//void *data;
	struct linklist_node_st *prev;
	struct linklist_node_st *next;
	char data[1];//变长结构体的内容要放在当前结构体的最后一个成员,放在前面也可以，但是偏移地址的计算就是个棘手的问题

};

typedef struct
{
	int size;
	struct linklist_node_st head;

}LINKLIST;


LINKLIST *linklist_create(int initsize);


int linklist_insert(LINKLIST *,const void *data,int mode);

void *linklist_find(LINKLIST *,const void *key,linklist_cmp *);

int linklist_delete(LINKLIST *,const void *key,linklist_cmp *);
int linklist_fetch(LINKLIST *,const void *key,linklist_cmp *,void *data);
void linklist_travel(LINKLIST *,linklist_operate *);
void linklist_destroy(LINKLIST *);




#endif
