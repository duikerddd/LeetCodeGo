//将数的二进制每一位都打印出来
#include<stdio.h>
#include<stdlib.h>
int print_one_bits01(unsigned int value){                   //0000 1111  
														  // & 0000 0001   15右移i次 每次和1&运算
	int count = 0;
	int i = 0;
	for (; i <32; i++)
	{
		if (((value >> i) & 1) == 1)
			count++;
	}
	return count;
}
int print_one_bits02(unsigned int value){                //移位操作符不会改变值大小,需要用=赋值
	int count = 0;										 //思路:  i=0000 0001
	int i = 1;											 //       15=0000 1111  比较完
	for (i = 1; i != 0;i<<=1)							//        15>>=0000 0111
	{                                                   //        i=0000 0010 i只是测定是否溢出  15自己右移和1比较
		if ((value & 1) == 1)
		{
			count++;
		}
		value = value >> 1;
	}

	return count;
}
int print_one_bits03(unsigned int n)
{
	int count = 0;
	while (n!=0){
		n = n&(n - 1);
		count++;
	}
	return count;
}
int main(){
	printf("%d\n", print_one_bits01(15));
	printf("%d\n", print_one_bits02(15));
	printf("%d\n", print_one_bits03(15));
	system("pause");
	return 0;
}
