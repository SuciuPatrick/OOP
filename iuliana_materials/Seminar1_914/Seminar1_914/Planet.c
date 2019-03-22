#include "Planet.h"
#include <string.h>

Planet *create(char *name, char*type, int distance)
{
	Planet *new_planet = (Planet*)malloc(sizeof(Planet));

	new_planet->name = (char*)malloc( sizeof(char) * (strlen(name)+1) );
	strcpy(new_planet->name, name);

	new_planet->type = (char*)malloc(sizeof(char) * (strlen(type) + 1));
	strcpy(new_planet->type, type);

	new_planet->distance = distance;

	return new_planet;
}