#include "dynamicVector.h"
#include <crtdbg.h>

int main()
{
	DynamicArray *array1 = initialize(2);
	addElement(array1, 4);
	addElement(array1, 5);
	addElement(array1, 6);

	destroyArray(array1);

	_CrtDumpMemoryLeaks();

	
	return 0;
}