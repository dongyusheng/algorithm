bool BulleSort(int numbers[], int length)
{
	if (numbers == nullptr || length <= 0)
		return false;
	for (int i = 0; i < length-1; ++i)
	{
		for (int j = 0; j < length - 1 - i; ++j) {
			if (numbers[j + 1] < numbers[j]) {
				int temp = numbers[j + 1];
				numbers[j + 1] = numbers[j];
				numbers[j] = temp;
			}
		}
	}
	return true;
}

int main()
{
	int duplication;
	int *arrayList = new int[7]{ 2, 3, 1,0,2, 5, 3 };

	if (BulleSort(arrayList,7)) {
		for (int i = 0; i < 6; ++i) {
			if (arrayList[i] == arrayList[i + 1]) {
				printf("The Same number is %d\n",arrayList[i]);
			}
		}
	}
	else {
		printf("BulleSort Error\n");
	}
	return 0;
}
