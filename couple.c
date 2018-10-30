//3.编程实现：
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int arr[] = { 1, 5, 5, 1, 7, 6, 7, 8, 8, 9, 9 };
	int i = 0;
	int len = sizeof(arr) / sizeof(arr[0]);

	for (i = 1; i < len; i++)
	{
		arr[0] = arr[0] ^ arr[i];    //^异或运算符，相同数字的每一位^为0,留下单独那个数字的值  
	}

	printf("the single number is:%d", arr[0]);
	system("pause");
	return 0;
}
