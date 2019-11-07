#include"prior_queue.h"
#include<stdlib.h>
#include<stddef.h>
#include<assert.h>
#define MinPQSize (4)
#define MinData (-32767)

struct _heapstruct_
{
	uint32_t capacity;
	uint32_t size;
	ElementType *Elements;
};

PriorityQueue Initialize(int32_t MaxElements)
{
	PriorityQueue H;
	assert(MaxElements>MinPQSize);
	H=malloc(sizeof(struct _heapstruct_));
	assert(H!=NULL);
	H->Elements=malloc ((MaxElements+1)* sizeof(ElementType));
	assert(H->Elements!=NULL);
	H->capacity=MaxElements;
	H->size=0;
	H->Elements[0]=MinData;
	return H;
}

void MakeEmpty(PriorityQueue H)
{
	H->size=0;
}

void Insert(ElementType X,PriorityQueue H)
{
	int32_t i;
	if(!(IsFull(H)))
	{
		for(i=++H->size;H->Elements[i/2]>X;i=i/2)
			H->Elements[i]=H->Elements[i/2];
		H->Elements[i]=X;
	}
}

ElementType DeleteMin(PriorityQueue H)
{
	int32_t i,child;
	ElementType MinElement,LastElement;
	if(!(IsEmpty(H)))
	{
		MinElement=H->Elements[1];
		LastElement=H->Elements[H->size--];
		for(i=1;i*2<=H->size;i=child)
		{
			child=i*2;
			if(child!=H->size && H->Elements[child+1] < H->Elements[child])
				child++;
			if(LastElement>H->Elements[child])
				H->Elements[i]=H->Elements[child];
			else
				break;
		}
		H->Elements[i]=LastElement;
		return MinElement;
	}
	else
	{
		return H->Elements[0];
	}

}

ElementType FindMin(PriorityQueue H)
{
	if(!IsEmpty(H))
		return H->Elements[1];
	return H->Elements[0];
}

int32_t IsEmpty(PriorityQueue H)
{
	return H->size==0;
}

int32_t IsFull(PriorityQueue H)
{
	return H->size==H->capacity;
}

void Destroy(PriorityQueue H)
{
	free(H->Elements);
	free(H);
}
