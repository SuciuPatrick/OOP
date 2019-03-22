#include <stdio.h>

typedef struct
{
	int arr[100];
	int len;
} vector;

int read_number()
{
	char string[100];
	int number = 0;
	printf("Input a number :");
	scanf("%s", string);
	while (!sscanf(string, "%d", &number))
	{
		printf("Input a number :");
		scanf("%s", string);
	}
	return number;

}

vector read_vector()
{
	vector v;
	v.len = 0;
	int number = read_number();
	while (number != 0)
	{
		v.arr[v.len] = number;
		v.len++;
		number = read_number();
	} 
	return v;
}

int longest_subsequence(vector v, int *start, int *end)
{
	int current_length = 0, max_len = 0, current_number = 0, current_end = 0;
	current_number = v.arr[0];
	*start = 0;
	for (int i = 1; i < v.len; i++)
	{
		if (current_number == v.arr[i])
		{
			current_length++;
			current_end = i;
		}
		else 
		{
			if (current_length > max_len)
			{
				max_len = current_length;
				*end = current_end;
			}
			*start = i;
			current_length = 0;
		}
	}
	*start = *end - max_len;
	
}

void print_subsequence(vector v, int start, int end)
{
	for (int i = start; i <= end; i++)
		printf("%d ", v.arr[i]);
}
int main()
{
	vector vect;
	int start=0, end=0;
	vect = read_vector();
	longest_subsequence(vect, &start, &end);
	print_subsequence(vect, start, end);
	system("pause");
	return 0;
}