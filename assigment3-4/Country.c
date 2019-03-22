//
// Created by Suciu Patrick on 2019-03-12.
//

#include <stdio.h>
#include "Country.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Country* createCountry(char *new_name, char *new_continent, double new_population)
{
    Country* p = (Country*)malloc(sizeof(Country));
    p->name = (char*)malloc(sizeof(char) * (strlen(new_name) + 1));
    strcpy(p->name, new_name);
    p->continent = (char*)malloc(sizeof(char) * (strlen(new_continent) + 1));
    strcpy(p->continent, new_continent);
    p->population = new_population;

    return p;
    /*
    strcpy(c.name, new_name);
    strcpy(c.continent, new_continent);
    c.population = new_population;
     */
}

char* getName(Country* p)
{
    return p->name;
}

char* getContinent(Country* p)
{
    return p->continent;
}

double getPopulation(Country* p)
{
    return p->population;
}

Country* copyCountry(Country* p)
{
    if (p == NULL)
        return NULL;

    Country *newCountry = createCountry(getName(p), getContinent(p), getPopulation(p));
    return newCountry;
}

void toString(Country p)
{
    printf("Name = %s, continent = %s, popupation = %f\n", p.name, p.continent, p.population);
}