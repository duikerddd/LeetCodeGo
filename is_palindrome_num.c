//判断一个数是否为回文数
#include<stdio.h>
#include<stdlib.h>


void IsPalindromeNum(int num)
{
	int div = 1;
	//让div成为num的最高位的数量级
	while (num / div >= 10)
	{
		div *= 10;
	}

	while(num > 9)
	{
		if (num / div != num % 10)
		{
			printf("不是回文数!\n");
			return;
		}
		//去头去尾继续比较
		num %= div;
		num /= 10;
		div /= 10;
	}
	printf("是回文数!\n");
}

int main()
{
	int num = 202;
	IsPalindromeNum(num);
	system("pause");
	return 0;
}
