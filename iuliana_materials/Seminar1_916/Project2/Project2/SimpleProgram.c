#include <stdio.h>
#include <windows.h>

typedef struct {
	int array[20];
	int length;
} vector;

int readNumber()
{
	char sentenceToRead[20];
	int validNumber = 0;
	

	printf("Give a number: ");
	scanf("%s", sentenceToRead);

	while (!sscanf(sentenceToRead, "%d", &validNumber))
	{
		printf("Give a number: ");
		scanf("%s", sentenceToRead);
	}
	
	return validNumber;
}

vector readVector()
{
	vector newVector;
	int currentNumber = readNumber();
	newVector.length = 0;

	while (currentNumber != 0)
	{
		newVector.array[newVector.length++] = currentNumber;
		currentNumber = readNumber();
	}

	return newVector;
}


void longestSequence(vector v, int *startingPoint, int*endPoint) {
	*startingPoint = 0;
	*endPoint = 0;
	int start = 0;
	int end = 0;
	int i = 0;
	int number = 0;
	int maximum = 1;
	while (i < v.length - 1) {
		number = 0;
		start = i;
		while (i < v.length - 1 && v.array[i] == v.array[i + 1]) {
			number++;
			i++;
		}
		end = i;
		if (number > maximum) {
			*startingPoint = start;
			*endPoint = end;
			maximum = number;
		}
		i++;
	}

}


void printSequence(vector v, int start, int end) {
	for (int i = start; i <= end; i++) {
		printf("%d ", v.array[i]);
	}
}

int main()
{
	int start = 0, end = 0;
	vector mainVector = readVector();
	longestSequence(mainVector, &start, &end);
	printSequence(mainVector, start, end);
	system("pause");
	return 0;
}