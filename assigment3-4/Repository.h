#pragma once
#include "Country.h"

typedef Country TElement;

typedef struct {
    TElement *elems;
    int length;
    int capacity;

} Repository;

void add(TElement value, Repository *da);
void resize(Repository* da);
void destroy(Repository* da);
Repository* createRepository(int capacity);
void ft_remove(char *country, Repository *da);
void printOrderedCountries(Repository *da, char *nameContinent);
void printCountriesContaingStr(Repository *da, char* sub);
void migration(Repository *da, char *country, int peopleMigrating, char *migratingToCountry);
void update(Repository *da, char *country, char *newCountry);