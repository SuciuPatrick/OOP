#pragma once
typedef struct {
	char name[20], type[20];
	int distanceFromEarth;
} Planet;

Planet createPlanet(char name[], char type[], int distanceFromEarth);
char* toString(Planet planet);
char* getName(Planet planet);