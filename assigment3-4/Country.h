#pragma once

typedef struct {
    char *name;
    char *continent;
    double population;
} Country;

Country* createCountry(char *new_name, char *new_continent, double new_population);
char* getContinent(Country* p);
char* getName(Country* p);
double getPopulation(Country* p);
void toString(Country p);
Country* copyCountry(Country* p);