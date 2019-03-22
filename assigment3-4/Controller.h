//
// Created by Suciu Patrick on 2019-03-16.
//

#ifndef ASSIGMENT3_4_CONTROLLER_H
#define ASSIGMENT3_4_CONTROLLER_H

#include "Repository.h"
#include "OperationStack.h"

typedef struct {
    Repository *da;
    //OperationsStack *undo;
    //OperationsStack *redo;
} Controller;


Controller* createController(Repository *da);
void displayOrderedByPopulation(Repository *da, int greaterThan, char *continent);


#endif //ASSIGMENT3_4_CONTROLLER_H

