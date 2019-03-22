#pragma once
#include "Country.h"

typedef Country TElement;

typedef struct {
    TElement *elems;
    int length;
    int capacity;

} DynamicArray;

void add(TElement value, DynamicArray *da);
void resize(DynamicArray* da);
void destroy(DynamicArray* da);
DynamicArray* createDynamicArray(int capacity);