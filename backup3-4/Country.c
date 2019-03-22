//
// Created by Suciu Patrick on 2019-03-12.
//

#include "Country.h"
#include <string.h>

Country createCountry(char *name, char *continent, double population)
{
    Country c;

    strcpy(c.name, name);
    strcpy(c.continent, continent);
    c.population = population;


    return c;
}
