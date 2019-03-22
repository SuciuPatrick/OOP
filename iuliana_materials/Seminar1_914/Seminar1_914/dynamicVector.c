#include "dynamicVector.h"
#include <stdlib.h>


DynamicArray * initialize(int capacity)
{
	DynamicArray *dynamicVector = (DynamicArray*)malloc(sizeof(DynamicArray));

	dynamicVector->arr = (TElem*)malloc(capacity * sizeof(TElem));

	dynamicVector->size = 0;
	dynamicVector->capacity = capacity;

	return dynamicVector;
}

void destroyArray(DynamicArray* dynamicVector)
{
	if (dynamicVector != NULL)
		free(dynamicVector->arr);
	
	free(dynamicVector);
}

void resize(DynamicArray* dynamicVector)
{
	dynamicVector->capacity *= 2;
	TElem* arr2 = (TElem*)malloc(dynamicVector->capacity * sizeof(TElem));
	for (int i = 0; i < dynamicVector->size; i++)
		arr2[i] = dynamicVector->arr[i];
	free(dynamicVector->arr);
	dynamicVector->arr = arr2;
}

void addElement(DynamicArray* dynamicVector, TElem element)
{ 
	if (dynamicVector->size >= dynamicVector->capacity)
		resize(dynamicVector);
	dynamicVector->arr[dynamicVector->size++] = element;
}
