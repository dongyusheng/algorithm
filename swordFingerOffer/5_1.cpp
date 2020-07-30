#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ReplaceBlank(char str[], int length);

int main()
{
	char arr[50] = "We are happy.";
	printf("oldArray is : %s\n", arr);

	ReplaceBlank(arr, 50);
	printf("newArray is : %s\n", arr);
	return 0;
}

void ReplaceBlank(char str[], int length)
{
	if (str == NULL && length <= 0)
		return;

	//计算字符串的长度，以及空白字符数
	int i = 0;
	int strLength = 0;
	int numberOfBlank = 0;
	while (str[i] != '\0')
	{
		strLength++;
		if (str[i] == ' ')
			numberOfBlank++;
		++i;
	}

	int newLength = strLength + 2 * numberOfBlank;

	if (newLength <= strLength)
		return;

	int indexOfOrigin = strLength;
	int indexOfNew = newLength;

	while (indexOfOrigin >= 0 && indexOfNew > indexOfOrigin)
	{
		if (str[indexOfOrigin] == ' ')
		{
			str[indexOfNew--] = '0';
			str[indexOfNew--] = '2';
			str[indexOfNew--] = '%';
		}
		else if (str[indexOfOrigin] != ' ')
			str[indexOfNew--] = str[indexOfOrigin];

		indexOfOrigin--;
	}
}
