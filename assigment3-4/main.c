#include <stdio.h>
#include <stdlib.h>
#include "Repository.h"
#include "Country.h"
#include "Controller.h"
#include <string.h>

void showMenuBased()
{

    printf("1. Add a new country. \n");
    printf("2. Remove a country. \n");
    printf("3. Migration.\n");
    printf("4. Display all the countries whose names contain a given string. \n");
    printf("5. Display all countries on a given continent, sorted ascending by country name. \n");
    printf("6. Exit.\n");

}

void showMenu()
{
    printf("\t\t ~ examples ~\n");
    printf("add France Europe 78493023");
    printf("\ndelete France");
    printf("\nprint - it prints all the inputs.");
    printf("\nmigration from France to Romania 3000");
    printf("\ndisplay \"Ro\"(Display all the countries whose names contain a given string.)");
    printf("\nordered display Europe(Display all countries on a given continent, sorted ascending by country name.)");
    printf("\nexit.");
    printf("\n\n --------------------------- \n");
}
void addIntoDynamicArray(Repository *da){
    add(*createCountry("Algeria", "Africa", 103553300), da);
    add(*createCountry("Uganda", "Africa", 200), da);
    add(*createCountry("Egipt", "Africa", 34245439), da);
    add(*createCountry("Romania", "Europe", 3000), da);
    add(*createCountry("Hungary", "Europe", 1234043242), da);
    add(*createCountry("Spain", "Europe", 10321330), da);
    add(*createCountry("Ukraine", "Europe", 6056477340), da);
    add(*createCountry("USA", "North America", 45213213300), da);
    add(*createCountry("Canada", "North America", 32313430), da);
    add(*createCountry("India", "Asia", 99999999), da);
    add(*createCountry("China", "Asia", 486540339), da);
    add(*createCountry("Israel", "Asia", 304392192), da);
    add(*createCountry("Japan", "Asia", 30943205), da);
}
int main() {
    Repository *repo = createRepository(15);
    Controller *controller = createController(repo);
    addIntoDynamicArray(controller->da);
    char input[50], *word, words[10][30];
    int cnt;
    showMenu();
    while (1)
    {
        gets(input);
        cnt = 0;
        word = strtok(input, " ");
        while (word != NULL)
        {
            strcpy(words[cnt], word);
            word = strtok(NULL, " ");
            cnt++;
        }
        //add France Europe 12345
        if (strcmp(words[0], "add") ==  0)
        {
            add(*createCountry(words[1], words[2], atoi(words[3])), controller->da);
        }
        //update France with Belgium
        else if (strcmp(words[0], "update") == 0)
        {
            update(controller->da, words[1], words[3]);
        }
        //delete France
        else if (strcmp(words[0], "delete") == 0)
        {
            ft_remove(words[1], controller->da);
        }
        //migration from France to Romania 3000
        else if (strcmp(words[0], "migration") == 0)
        {
            migration(controller->da, words[2], atoi(words[5]), words[4]);
        }
        //print
        else if(strcmp(words[0], "print") == 0)
        {
            for (int i = 0; i < controller->da->length; i++)
            {
                printf("%s ", controller->da->elems[i].name);
                printf("%s ", controller->da->elems[i].continent);
                printf("%f\n", controller->da->elems[i].population);
            }
        }
        //display Ro
        else if (strcmp(words[0], "display") == 0)
        {
            printCountriesContaingStr(controller->da, words[1]);
        }
        //orderded display Europe
        else if (strcmp(words[0], "ordered") == 0)
        {
            printOrderedCountries(controller->da, words[2]);
        }
        //oana europe 5000
        else if(strcmp(words[0], "oana") == 0)
        {
            displayOrderedByPopulation(controller->da, atoi(words[2]), words[1]);
        }
        else if (strcmp(words[0], "exit") == 0)
            break;

    }

    /*
    while (1) {
        printf("Insert a choice from menu-> ");
        scanf("%d", &value);
        if (value == 6)
            break;
        else if(value == 1)
        {
            char country[30], continent[30];
            int pop;

            printf("Insert country: ");
            scanf("%s", country);
            printf("\nInsert continent: ");
            scanf("%s", continent);
            printf("\nInsert population: ");
            scanf("%d", &pop);
            add(createCountry(country, continent, pop), da);
        }
        else if (value == 2)
        {
            char country[30];

            printf("Insert country to remove: ");
            scanf("%s", country);
            ft_remove(country, da);
        }
        else if (value == 3)
        {
            char country[30], migratingTo[30];
            int peopleMigrating;

            printf("Insert country from where people leave: ");
            scanf("%s", country);
            printf("Insert migrating to country: ");
            scanf("%s", migratingTo);
            printf("Number of people migrating: ");
            scanf("%d", &peopleMigrating);
            migration(da, country, peopleMigrating, migratingTo);
        }
        else if (value == 4)
        {
            char str[30];
            printf("Insert substring: ");
            scanf("%s", str);

            printCountriesContaingStr(da, str);
        }
        else if (value == 5)
        {
            char continent[30];
            printf("Insert continent: ");
            scanf("%s", continent);

            printOrderedCountries(da, continent);
        }
    }*/

    /*
    printOrderedCountries(da, "Africa");
    printCountriesContaingStr(da, "e");

    //void migration(DynamicArray *da, char *country, int peopleMigrating, char *migratingToCountry);
    migration(da, "Uganda", 100, "Romania");

    printCountriesContaingStr(da, "");
     */

    return 0;
}