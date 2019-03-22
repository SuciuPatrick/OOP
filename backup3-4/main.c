#include <stdio.h>
#include <stdlib.h>
#include "DynamicArray.h"
#include "Country.h"

int main()
{
    DynamicArray *test;
    test = createDynamicArray(10);
    
    add(createCountry("Cluj", "Europe", 100), test);
    printf("da");
    return 0;
}
/*
int main() {
    DynamicArray *test;
    test = createDynamicArray(2);

    add(createCountry("Cluj", "Europe", 1000), test);

    printf("ok");
    printf("%s %s %lf", test->elems[0].name, test->elems[0].continent, test->elems[0].population);
    return 0;
}*/
