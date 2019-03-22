//
// Created by Suciu Patrick on 2019-03-20.
//

#pragma once
#include "Country.h"
#include "Repository.h"
#include "Controller.h"
#include <string.h>

typedef struct
{
    Country* Country;
    char* operationType;
} Operation;

Operation* createOperation(Country* p, char* operationType);
void destroyOperation(Operation* o);
Operation* copyOperation(Operation* o);
char* getOperationType(Operation* o);
Country* getCountry(Operation* o);

typedef struct
{
    Operation* operations[100];
    int length;
} OperationsStack;

OperationsStack* createStack();
void destroyStack(OperationsStack* s);
void push(OperationsStack* s, Operation* o);
Operation* pop(OperationsStack* s);
int isEmpty(OperationsStack* s);
int isFull(OperationsStack* s);
