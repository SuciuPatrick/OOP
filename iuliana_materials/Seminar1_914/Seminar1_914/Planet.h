#pragma once

typedef struct
{
	char *name, *type;
	int distance;
}Planet;

Planet *create(char *name, char*type, int distance);