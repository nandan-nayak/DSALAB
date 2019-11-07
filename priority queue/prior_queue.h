#ifndef _BinHeap_H
#define _BinHeap_H
#include<stdint.h>

typedef int32_t ElementType;
typedef struct _heapstruct_ *PriorityQueue;

PriorityQueue Initialize(int32_t MaxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X,PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int32_t IsEmpty(PriorityQueue H);
int32_t IsFull(PriorityQueue H);
#endif