#include<stdio.h>
#include "Planet.h"
#include <windows.h>
#include <stdlib.h>
#include <crtdbg.h>

int main() {
	Planet planet;
	planet = createPlanet("#859AHGT", "unknown", 85568);
	char* str = toString(planet);
	printf("%s", str);
	free(str);
	system("pause");

	_CrtDumpMemoryLeaks();

	return 0;
}
