#include <stdio.h>

int getDuplication(int *numbers, const int length);

int main()
{
	int array[8] = {2, 3, 5, 4, 3, 2, 6, 7};

	int num = getDuplication(array, 8);
	printf("%d\n", num);

	return 0;
}

int getDuplication(int *numbers, int length)
{
	int *tempArray = new int[length];
	int number;

	for (int i = 0; i < length; i++)
	{
		number = numbers[i];
		if (tempArray[number] == number)
		{
			return number;
		}
		tempArray[number] = number;
	}

	return -1;
}
