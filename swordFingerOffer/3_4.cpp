#include <stdio.h>


int countRange(const int* numbers,int length,int start,int end);
int getDuplication(const int* numbers,int length);

int main()
{
	int array[]={2,3,5,4,3,2,6,7};

	int num=getDuplication(array,8);
	printf("%d\n",num);

	return 0;
}

int countRange(const int* numbers,int length,int start,int end)
{
	if(numbers==NULL)
		return -1;
	int count=0;
	for(int i=0;i<length;++i)
	{
		//所有出现在start到end值区间的数字都统计一遍
		if((numbers[i]>=start) && (numbers[i]<=end))
			count++;
	}
	return count;
}

int getDuplication(const int* numbers,int length)
{
	if((numbers==NULL) || length<=0)
		return -1;

	int start=1;
	int end=length-1;
	int middle;//中间的数字
	int count=0;
	while(start<=end)
	{
		middle=((end-start)>>1)+start;
		count=countRange(numbers,length,start,middle);
		//如果起点与终点到一起了
		if(end==start)
		{
			//判断查找的次数是否大于1
			if(count>1)
				return start;
			else
				break;
		}

		//如果查找的次数，大于这个区间的个数，那么这个区间就一定有重复的数字，就向做区间查找
		if(count>(middle-start+1)){
			end=middle;
		}
		//否则就向右区间查找
		else{
			start=middle+1;
		}
	}
	return -1;
}
