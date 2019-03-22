#pragma once
typedef int TElem;

typedef struct
{
	TElem *arr;
	int size, capacity;

}DynamicArray;

DynamicArray * initialize(int capacity);
void destroyArray(DynamicArray*);

void addElement(DynamicArray*, TElem);


