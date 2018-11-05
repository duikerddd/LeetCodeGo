//求两个数的最大公约数。
//
#include<stdio.h>
#include<stdlib.h>
int Fac(int a, int b)
{
	if (a <= 0 || b <= 0)
		return -1;
	else if (a>b)
		return Fac(a - b, b);
	else if (a<b)
		return Fac(a, b - a);
	else
		return a;
}
int main()
{
	int a, b, factor;
	printf("Input a,b:");
	scanf_s("%d,%d", &a, &b);
	factor = Fac(a, b);
	if (factor == -1)
		printf("请输入同符号数!\n");
	else
		printf("%d和%d的最大公因数为%d\n", a, b,factor);
	
	system("pause");
}
