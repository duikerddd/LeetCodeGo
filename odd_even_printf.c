#include<stdio.h>    //把一个数的二进制奇数位和偶数位输出
#include<stdlib.h>
int main(){
	int a = 3;
	for (int odd = 31; odd >= 0; odd -= 2)
	{
		printf("%d", (a >> odd) & 1);
	}
	printf("\n");
	for (int even = 31; even >= 1; even -= 2)
	{
		printf("%d", (a >> even) & 1);
	}
	system("pause");
	return 0;
}
