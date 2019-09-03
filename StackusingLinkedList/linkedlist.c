#include<stdlib.h>
#include<stddef.h>
#include<assert.h>
#include "linkedlist.h"
#include<stdio.h>




List* slist_new()
{

List *list;
list=(List*)malloc(sizeof(List));

list->head=NULL;

list->length=0;
return list;



}



List* slist_free(List *list)
{
Node *cur,*p;
if(slist_length(list)>0)
{
assert(list->head);
cur=list->head;
list->head=NULL;

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
return node;

}


List* slist_add_head(List *list,int32_t data)
{
Node *node=_list_node_new_(data);
node->next=list->head;
list->head=node;

++list->length;
assert(( list->length==1 ) || list->length>0 );
//printf("added %d\n",data);
return list;
}


uint32_t slist_length(const List *list)
{
return list->length;

}

uint32_t slist_lookup(const List *list,int32_t key)
{
Node *node=list->head;

for(node=list->head;node!=NULL;node=node->next)
{
if(node->data==key)break;

}
return (node!=NULL);
}





List* slist_delete_head(List *list)
{

Node *node;
if(list->head!=NULL)
{

node=list->head;
list->head=list->head->next;
assert(list->length>0);

--list->length;

if(list->head==NULL)
{

assert(list->length==0);

}
free(node);
}
return list;


}



void showstack(List *list)
{

Node *temp;
printf("\n");
for(temp=list->head;temp!=NULL;temp=temp->next)
printf("\t%d",temp->data);




}























