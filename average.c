//2.不使用（a + b） / 2这种方式，求两个数的平均值。
#include <stdio.h>
#include<stdlib.h>
int ave1(int a,int b)
{
	if (a > b)
	{
		b = ((a - b) / 2) + b;
		return b;
	}

	else
	{
		a = ((b - a) / 2) + a;

		return a;
	}
}

int ave2(int x, int y)
{
	return (x & y) + ((x ^ y) >> 1);     //&找出相同的位 + ^不同的位 除2分给一半给没有的
}										 

int ave3(int x, int y)
{
	return (x + y) >> 1;
}

int main()
{
	int a = 2;
	int b = 3;
	printf("%d\n", ave1(a, b));
	printf("%d\n",ave2(a,b));
	system("pause");
	return 0;
}
