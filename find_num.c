//从0到n取出n个数 找出漏掉的那个数 这n个数乱序
#include<stdio.h>
#include<stdlib.h>


void FindNum(int *a, int n)
{
	int i = 0;
	int res = 0;
	//有2n+1个元素,利用连续^消除成对的数找落单的那个数
	for (i = 0; i <= n; i++)
	{
		res ^= i;
	}
	for (i = 0; i < n; i++)
	{
		res ^= a[i];
	}
	printf("%d是漏掉的数!\n",res);
	return;
}

int main()
{
	int a[10] = { 0,1, 2, 3, 4, 5, 6, 7, 9,10 };
	FindNum(a,9);
	system("pause");
	return 0;
}
