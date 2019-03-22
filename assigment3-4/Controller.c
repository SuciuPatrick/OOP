//
// Created by Suciu Patrick on 2019-03-16.
//
#include "Repository.h"
#include "Controller.h"
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include <string.h>

Controller* createController(Repository *das)
{
    Controller *controller = (Controller*)malloc(sizeof(Controller));
    if (controller == NULL)
        return NULL;
    controller->da = createRepository(das->capacity);

            //controller->da.length = das->length;

    for (int i = 0; i < das->length; i++)
    {
        strcpy(controller->da->elems[i].name, das->elems[i].name);
        strcpy(controller->da->elems[i].continent, das->elems[i].continent);
        controller->da->elems[i].population = das->elems[i].population;
    }

    return controller;

}

/*
The application should allow displaying all the countries on a given continent
(if the continent is empty, all states should be considered), whose populations are greater
than a given value, sorted ascending by population.
*/

void displayOrderedByPopulation(Repository *da, int greaterThan, char *continent)
{
    for(int i = 0; i < da->length; i++)
        if (strcmp(da->elems[i].continent, continent) == 0 && da->elems[i].population >= greaterThan)
            printf("%s %f\n", da->elems[i].name, da->elems[i].population);
}