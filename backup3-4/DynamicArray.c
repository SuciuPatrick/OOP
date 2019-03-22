//
// Created by Suciu Patrick on 2019-03-12.
//
#include "DynamicArray.h"
#include <stdlib.h>

DynamicArray* createDynamicArray(int capacity)
{
    DynamicArray *da = (DynamicArray*)malloc(sizeof(DynamicArray));

    if (da == NULL)
        return NULL;

    da->capacity = capacity;
    da->length = 0;
    da->elems = (TElement*)malloc(sizeof(TElement) * capacity);

    if (da->elems == NULL)
        return NULL;

    return da;
}

void destroy(DynamicArray* da)
{
    if (da == NULL)
        return;

    if (da->elems == NULL)
        return;

    free(da->elems);
    da->elems = NULL;

    free(da);
    da = NULL;
}

void resize(DynamicArray* da)
{
    if (da == NULL)
        return;

    if (da->elems == NULL)
        return;

    da->capacity *= 2;
    TElement *aux = (TElement*)realloc(da->elems, sizeof(TElement) * da->capacity);
    if (aux == NULL)
        return;

    da->elems = aux;
}

void add(TElement value, DynamicArray *da)
{
    if (da == NULL)
        return;

    if (da->elems == NULL)
        return;

    if (da->capacity == da->length)
        resize(da);

    da->elems[da->length] = value;
    da->length++;
}