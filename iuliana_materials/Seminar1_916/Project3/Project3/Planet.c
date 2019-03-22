#include "Planet.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Planet createPlanet(char name[], char type[], int distanceFromEarth) {
	Planet planet;
	strcpy(planet.name, name);
	strcpy(planet.type, type);
	planet.distanceFromEarth = distanceFromEarth;
	return planet;
}

char* toString(Planet planet) {
	char *planetToString = (char*)malloc(100 * sizeof(char));
	sprintf(planetToString, "Planet: %s type: %s distance: %d", planet.name, planet.type, planet.distanceFromEarth);
	return planetToString;
}

char* getName(Planet planet) {
	return planet.name;
}