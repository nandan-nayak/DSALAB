#include<assert.h>

#include "linkedlist.c"
#include<stdio.h>
void test_slist()
{
int look;
List *list=slist_new();


assert(list->length==0);


list=slist_add_head(list,10);
showstack(list);
list=slist_add_head(list,20);
showstack(list);
list=slist_add_head(list,30);
showstack(list);
list=slist_add_head(list,40);
showstack(list);

assert(list->length==4);



list=slist_delete_head(list);
showstack(list);
list=slist_delete_head(list);
showstack(list);
list=slist_delete_head(list);
showstack(list);

assert(list->length==1);







list=slist_add_head(list,20);
showstack(list);

list=slist_add_head(list,20);
showstack(list);
list=slist_add_head(list,20);
showstack(list);



look=slist_lookup(list,20);
assert(look==1);
//printf("%d %p %p %d",list->length,list->head,list->tail,look);
assert(slist_length(list)==4);
list=slist_free(list);
assert(list->length==0);
//assert(list->head==NULL && list->tail==NULL);

}










int main()
{

test_slist();
 

printf("\n executed successfully\n");
return 0;


}
