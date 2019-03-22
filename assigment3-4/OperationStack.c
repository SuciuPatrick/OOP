//
// Created by Suciu Patrick on 2019-03-20.
//

#include "OperationStack.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

Operation* createOperation(Country* p, char* operationType)
{
    Operation* o = (Operation*)malloc(sizeof(Operation));
    o->Country = copyCountry(p);

    if (operationType != NULL)
    {
        o->operationType = (char*)malloc(sizeof(char) * (strlen(operationType) + 1));
        strcpy(o->operationType, operationType);
    }
    else
        o->operationType = NULL;

    return o;
}

void destroyOperation(Operation* o)
{
    if (o == NULL)
        return;

    // first destroy the Country
    //destroyCountry(o->Country);
    // then the operationType
    free(o->operationType);
    // then free the operation
    free(o);
}

Operation* copyOperation(Operation * o)
{
    // TODO
    return NULL;
}

char* getOperationType(Operation* o)
{
    return o->operationType;
}

Country* getCountry(Operation* o)
{
    return o->Country;
}

// ---------------------------------------------------------------

OperationsStack* createStack()
{
    OperationsStack* s = (OperationsStack*)malloc(sizeof(OperationsStack));
    s->length = 0;

    return s;
}

void destroyStack(OperationsStack* s)
{
    if (s == NULL)
        return;

    // first deallocate memory of operations (this is allocated when a new operation is pushed onto the stack)
    for (int i = 0; i < s->length; i++)
        destroyOperation(s->operations[i]);

    // then free the stack
    free(s);
}

void push(OperationsStack* s, Operation* o)
{
    // TODO
}

Operation* pop(OperationsStack* s)
{
    // TODO
    return NULL;
}

int isEmpty(OperationsStack* s)
{
    return (s->length == 0);
}

int isFull(OperationsStack* s)
{
    return s->length == 100;
}