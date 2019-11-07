#include<stdio.h>
#include "prior_queue.c"

void main()
{

PriorityQueue queue=Initialize(5);


Insert(10,queue);
Insert(20,queue);
Insert(30,queue);
//printf("%d",IsEmpty(queue));

assert(IsEmpty(queue)==0);
printf("%d",FindMin(queue));
assert(FindMin(queue)==10);
assert(DeleteMin(queue)==10);

MakeEmpty(queue);

assert(IsEmpty(queue)==1);

}
