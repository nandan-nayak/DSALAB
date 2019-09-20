#include<stdlib.h>
#include<stddef.h>
#include<assert.h>
#include "dll.h"
#include<stdio.h>




List* dllist_new()
{

	List *list;
	list=(List*)malloc(sizeof(List));

	list->head=NULL;
	list->tail=NULL;
	list->length=0;
	return list;



}



List* dllist_free(List *list)
{
	Node *cur,*p;
	if(dllist_length(list)>0)
	{
		assert(list->head&&list->tail);
		cur=list->head;
		list->head=NULL;
		list->tail=NULL;
	while(cur!=NULL)
	{	
		p=cur;
		cur=cur->next;
		free(p);
		--list->length;
	}


	}


	return list;

}

static Node* _list_node_new_(int32_t data)
{
	Node* node=(Node*)malloc(sizeof(Node));
	node->data=data;
	node->next=NULL;
	node->prev=NULL;
	return node;

}


List* dllist_add_head(List *list,int32_t data)
{
	Node *node=_list_node_new_(data);
	if(list->head==NULL && list->tail==NULL)
	{
		list->head=list->tail=node;
	}
	else
	{

		node->next=list->head;	
		list->head->prev=node;
		node->prev=NULL;
		list->head=node;
	}
	++list->length;
	assert(( list->length==1 && list->head == list->tail ) || list->length>1 && list->head != list->tail);

	
	return list;
}


uint32_t dllist_length(const List *list)
{
	return list->length;

}

uint32_t dllist_lookup(const List *list,int32_t key)
{
	Node *node=list->head;

	for(node=list->head;node!=NULL;node=node->next)
	{
	if(node->data==key)break;

	}
	return (node!=NULL);
}



List* dllist_add_tail(List *list,int32_t data)
{

	Node *node=_list_node_new_(data);


	if(list->head==NULL && list->tail==NULL)
	{
		list->head=list->tail=node;
	}
	else
	{

		list->tail->next=node;
		node->prev=list->tail;
		list->tail=node;
	}


	++list->length;
	return list;
}


List* dllist_delete_head(List *list)
{

	Node *node;
	
	if(list->head==list->tail)
	{
		list->head=list->tail=NULL;		
		
	}	

	else
	{

		node=list->head;
		list->head=list->head->next;
		list->head->prev=NULL;
		node->next=NULL;
		

		--list->length;
	
		free(node);
	}
	return list;


}

 
List* dllist_delete_tail(List *list)
{

	assert(list!=NULL);
	Node *node;
	//Node *tail=list->tail;
	if(list->head==list->tail)
	{
		list->head=list->tail=NULL;
	}

	else
	{
		node=list->tail;
		list->tail=list->tail->prev;
		list->tail->next=NULL;
		node->prev=NULL;

		--list->length;
	}
	return list;


}
























