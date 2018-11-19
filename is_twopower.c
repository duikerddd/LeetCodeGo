//给出一个整数,判断它是否是2的幂
#include<stdio.h>
#include<stdlib.h>

void IsTwoPower(int num)
{
	int count = 0;
	for (int i = 0; i < 32;i++)
	{
		if ((num >> i) & 1 == 1)
		{
			count++;
		}
	}
	if (count == 1)
	{
		printf("是2的幂!\n");
		return;
	}
	printf("不是2的幂!\n");
	return;
}

int main()
{
	int num = 5;
	IsTwoPower(num);
	system("pause");
	return 0;
}
