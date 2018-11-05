//将数组A中的内容和数组B中的内容进行交换。（数组一样大）
#include<stdio.h>
#include<stdlib.h>
void  change(int a[], int b[],int leng)
{	
  int t = 0;
	for (int length = 0;length < leng; length++)      
	{
		t = a[length];
		a[length] = b[length]; 
		b[length] = t;
	}
}

int main(){

	int a[4] = { 1, 3, 8, 5 };
	int b[4] = { 2, 3, 4, 5 };
	change(a, b, sizeof(a) / sizeof(a[0]));       //数组长度定义:sizeof(a)/sizeof(a[0])

  for (int i = 0; i <sizeof(a) / sizeof(a[0]); i++)        //数组交换需要写数组长度!
	{
		printf("%d",a[i]);
	}
  printf("\n");
  for (int j = 0; j< sizeof(a) / sizeof(a[0]); j++)
	{
		printf("%d", b[j]);
	}
	system("pause");
  return 0;
}
