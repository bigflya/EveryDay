#ifndef LINKLIST_H__
#define LINKLIST_H__


#define LINKLIST_FORWARD	1
#define LINKLIST_BACKWARD	2

typedef void linklist_operate(const void *);


struct linklist_node_st
{
	void *data;
	struct linklist_node_st *prev;
	struct linklist_node_st *next;

};

typedef struct
{
	int size;
	//void *data;
	struct linklist_node_st head;

}LINKLIST;


LINKLIST *linklist_create(int initsize);


int linklist_insert(LINKLIST *,const void *data,int mode);

//linklist_find();

//linklist_delete();
//linklist_fetch();
void linklist_travel(LINKLIST *,linklist_operate *);
void linklist_destroy(LINKLIST *);




#endif
