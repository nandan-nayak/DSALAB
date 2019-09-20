#ifndef  _INCLUDED_DLLIST_
#define _INCLUDED_DLLIST_
#include<stdint.h>
typedef struct _node_ Node;
typedef struct _dllist_ List;

struct _dllist_
{
	Node *head;
	Node *tail;

	uint32_t length;
};

struct _node_
{
	int32_t data;
	Node *next;
	Node *prev;
};


List* dllist_new();
uint32_t dllist_length(const List *list);
List* dllist_free(List*);
uint32_t dllist_lookup(const List *list,int32_t key);
List* dllist_add_head(List *list,int32_t data);
List* dllist_add_tail(List *list,int32_t data);
List* dllist_delete_head(List *list);
List* dllist_delete_tail(List *list);
#endif





