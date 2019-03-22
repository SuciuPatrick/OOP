//
// Created by Suciu Patrick on 2019-03-12.
//
#include "Repository.h"
#include "OperationStack.h"
#include "Controller.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Repository* createRepository(int capacity)
{
    Repository *da = (Repository*)malloc(sizeof(Repository));

    if (da == NULL)
        return NULL;

    da->capacity = capacity;
    da->length = 0;
    da->elems = (TElement*)malloc(sizeof(TElement) * capacity);

    if (da->elems == NULL)
        return NULL;

    return da;
}

void destroy(Repository* da)
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

void resize(Repository* da)
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

void add(TElement value, Repository *da)
{
    if (da == NULL)
        return;

    if (da->elems == NULL)
        return;

    if (da->capacity == da->length)
        resize(da);

    da->elems[da->length] = value;
    da->length++;
    Operation *oper = createOperation(&value, "add");
}

void ft_remove(char *country, Repository *da)
{
    if (da == NULL)
        return;

    if (da->elems == NULL)
        return;

    for (int i = 0; i < da->length; i++)
        if (strcmp(da->elems[i].name, country) == 0)
            for (int j = i + 1; j < da->length; j++)
            {
                strcpy(da->elems[j - 1].name, da->elems[j].name);
                strcpy(da->elems[j - 1].continent, da->elems[j].continent);
                da->elems[j-1].population = da->elems[j].population;
            }
    da->length--;
}

void printOrderedCountries(Repository *da, char *nameContinent)
{
    char vector[da->length][50];
    int cnt = 0;

    for (int i = 0; i < da->length; i++) {
        if (strcmp(nameContinent, da->elems[i].continent) == 0) {
            // printf("%s \n",  da->elems[i].name);
            strcpy(vector[cnt], da->elems[i].name);
           // printf("%s\n",vector[i]);
            cnt++;
        }
    }

    char aux[50];
    for (int i = 0; i < cnt - 1; i++)
        for (int j = i + 1; j < cnt; j++)
            if (strcmp(vector[i], vector[j]) > 0) {
                strcpy(aux, vector[i]);
                strcpy(vector[i], vector[j]);
                strcpy(vector[j], aux);
            }

    for (int i = 0; i < cnt; i++) {
        printf("%s \n", vector[i]);
    }
    printf("\n");
}

void printCountriesContaingStr(Repository *da, char* sub)
{
    for (int i = 0; i < da->length; i++)
        if (strstr(da->elems[i].name, sub))
            printf("%s population = %f\n ", da->elems[i].name, da->elems[i].population);
}

void migration(Repository *da, char *country, int peopleMigrating, char *migratingToCountry)
{
    for (int i = 0; i < da->length; i++)
    {
        if (strcmp(da->elems[i].name, country) == 0) {
            da->elems[i].population -= peopleMigrating;
        }
        if (strcmp(da->elems[i].name, migratingToCountry) == 0)
            da->elems[i].population += peopleMigrating;
    }
}

void update(Repository *da, char *country, char *newCountry)
{
    for (int i = 0; i < da->length; i++)
        if (strcmp(da->elems[i].name, country) == 0) {
            strcpy(da->elems[i].name, newCountry);
            return;
        }

}