////2.获取一个数二进制序列中所有的偶数位和奇数位，
////分别输出二进制序列。
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	char arr1[16];
//	char arr2[16];
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 32; i += 2)
//	{
//		arr1[j] = ((num >> i) & 1);//奇数位
//		j++;
//	}
//	j = 0;
//	for (i = 1; i < 32; i += 2)
//	{
//		arr2[j] = ((num >> i) & 1);//偶数位
//		j++;
//	}
//	for (i = 15; i >= 0; i--)
//	{
//		printf("%d", arr1[i]);
//		
//	}
//	printf("\n");
//	for (i = 15; i >= 0; i--)
//	{
//		printf("%d", arr2[i]);
//	}
//	system("pause");
//	}
//	
