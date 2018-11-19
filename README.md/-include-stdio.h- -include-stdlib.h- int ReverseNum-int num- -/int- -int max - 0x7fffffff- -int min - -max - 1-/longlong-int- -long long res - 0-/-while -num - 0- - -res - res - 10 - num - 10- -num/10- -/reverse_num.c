//逆转数字并判断是否溢出
#include<stdio.h>
#include<stdlib.h>

int ReverseNum(int num)
{
	//设置int类型的最高位最低位
	int max = 0x7fffffff;
	int min = -max - 1;
	//用longlong类型来检测溢出,如果最后不溢出返回值会强制转换成int类型
	long long res = 0;

	//算法
	while (num != 0)
	{
		res = res * 10 + num % 10;
		num /= 10;
	}

	//判断是否溢出
	if (res > max || res < min)
	{
		printf("已经溢出!\n");
		return 0;
	}
	printf("没有溢出!逆转后的值为%d\n", (int)res);
}

int main()
{
	int num = 231424125;
	ReverseNum(num);
	system("pause");
	return;
}
