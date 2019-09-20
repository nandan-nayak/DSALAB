#include<assert.h>
#include "dll.c"
#include<stdio.h>
void test_dllist()
{
int look;
List *list=dllist_new();


assert(list->length==0);


list=dllist_add_head(list,10);


list=dllist_add_head(list,20);
list=dllist_add_head(list,30);
list=dllist_add_head(list,40);


assert(list->length==4);


list=dllist_delete_head(list);
list=dllist_delete_head(list);
list=dllist_delete_head(list);


assert(list->length==1);
//printf("\n%d",list->length);

list=dllist_add_tail(list,30);

assert(list->length==2);


list=dllist_delete_tail(list);
assert(list->length==1);


list=dllist_add_head(list,20);


list=dllist_add_head(list,20);
list=dllist_add_head(list,20);




look=dllist_lookup(list,20);
assert(look==1);



//printf("%d %p %p %d",list->length,list->head,list->tail,look);
assert(dllist_length(list)==4);
list=dllist_free(list);
assert(list->length==0);
//assert(list->head==NULL && list->tail==NULL);




}










int main()
{

test_dllist();
 

printf("\n executed successfully\n");
return 0;


}
