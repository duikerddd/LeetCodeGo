//1.一个数组中只有两个数字是出现一次，
//其他所有数字都出现了两次。
//找出这两个数字，编程实现。a

//^=单独两个数的^结果
//单独出现的两个数不同位的标记
//position:   ^结果中第一个出现1的位置
//position位两个数肯定有一个为0 ,一个为1
//把数组分成两部分
//1:position为1
//2:position为0
//每一部分都有一个只出现一次的数字,其他的都是成对出现
//每一部分^结果为单独出现的数字
#include<stdio.h>
#include<stdlib.h>


int main()
{
	int arr[] = { 1, 3, 4, 5, 6, 6, 5, 1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int ret = 0;
	int i = 0;
	int pos = 0;
	int x = 0;
	int y = 0;
	//整体^一次
	for (i = 0; i < len; i++)
	{
		ret ^= arr[i];
	}
	//寻找第一个1的位置
	for (i = 0; i < 32; i++)
	{
		if ((ret >> i) & 1 == 1)
		{
			pos = i;
			break;
		}
	}
	//把数组分成两部分
	for (i = 0; i < len; i++)
	{
		//如果pos位置为1
		if (((arr[i] >> pos)&1)==1)
		{
			x ^= arr[i];
		}
		//位置为0
		else
		{
			y ^= arr[i];
		}
	}
	printf("%d %d", x, y);
	system("pause");
	return 0;
}
