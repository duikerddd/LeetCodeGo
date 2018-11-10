//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
//给20元，可以多少汽水。
//编程实现
#include<stdio.h>
#include<stdlib.h>
int count = 0;

int Drink(int num, int drink)
{
	/*
		金钱恒减,每次-1元,喝一瓶,可以喝20瓶
		瓶子变成两个的时候,喝一瓶,并且瓶子数量归1个
	*/
	for (num = 20;  num>0; num--)
	{
		drink++;
		count++;
		if (count == 2)
		{
			drink++;
			count = 1;
		}
	}
	return drink;
}

int main()
{
	int num = 20;
	int drink = 0;
	printf("%d\n",Drink(num,drink));
	
	system("pause");
	return 0;
}
