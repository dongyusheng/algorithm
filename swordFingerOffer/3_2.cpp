// 参数:
//        numbers:     一个整数数组
//        length:      数组的长度
//        duplication: (输出) 数组中的一个重复的数字
// 返回值:             
//        true  - 输入有效，并且数组中存在重复的数字
//        false - 输入无效，或者数组中没有重复的数字
bool duplicate(int numbers[], int length, int* duplication)
{
	if (numbers == nullptr || length <= 0)
		return false;

	for (int i = 0; i < length; ++i)
	{
		if (numbers[i] < 0 || numbers[i] > length - 1)
			return false;
	}

	for (int i = 0; i < length; ++i)
	{
		while (numbers[i] != i)
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				return true;
			}

			// 交换numbers[i]和numbers[numbers[i]]             
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}

	return false;
}

int main()
{
	int duplication;
	int *arrayList = new int[7]{ 2, 3, 1,0,2, 5, 3 };
	if (duplicate(arrayList, 7, &duplication)) {
		printf("Number is %d\n", duplication);
	}
	else {
		printf("No Same Number\n");
	}
	return 0;
}
