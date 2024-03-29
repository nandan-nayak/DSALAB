#include<assert.h>
#include<stddef.h>
#include "queue.h"

Queue queue_new(uint32_t size)
{
size=(size>0 && size<MAX_QUEUE_LEN) ? size : MAX_QUEUE_LEN;
Queue s={size,0,0,0,{0}};
return s;

}

uint32_t queue_full(Queue *q)
{

assert(q!=NULL && q->count<=q->size);
return (q->count==q->size);

}



uint32_t queue_empty(Queue *q)
{

//printf("\n count = %d ",q->tail);
return (q->count==0 && q->head==q->tail);
//return 1;

}









Queue* queue_add(Queue *q,int32_t data,QueueResult *result)
{

assert(q!=NULL && q->count<=q->size);

if(q->count<q->size)
{
q->q[q->tail]=data;
q->tail=(q->tail+1)%q->size;
++q->count;
result->status=QUEUE_OK;

}

else
{

result->status=QUEUE_FULL;

}

assert(result->status==QUEUE_OK || q->count==q->size);

return q;

}

Queue* queue_remove(Queue *q,QueueResult *result)
{
assert(q!=NULL && q->count<=q->size);

if(q->count>0)
{
result->data=q->q[q->head];
result->status=QUEUE_OK;
q->head=(q->head+1)%q->size;
q->count--;

}

else
{

result->status ==QUEUE_OK;
}
assert(q->count<q->size);
assert(result->status==QUEUE_OK|| q->count==0);

return q;
}









