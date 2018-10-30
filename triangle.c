//3.在屏幕上打印杨辉三角。
// 1	1
// 2    1 1
// 3    1 2 1
// 4    1 3 3 1

#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[10][10] = { 1 };
	for (int line = 2; line < 8; line++)     //行
	{
		for (int i = 1; i < line; i++)         //列标号
		{
			if (i == 1)
			{
				a[line][i] = 1;
				printf("%d ", a[line][i]);
			}
			else if (i == line - 1)
			{
				a[line][i] = 1;
				printf("%d ", a[line][i]);
			}
			else if (i < line-1){
				a[line][i] = a[line - 1][i] + a[line - 1][i - 1];
				printf("%d ", a[line][i]);
			}	
		}
		printf("\n");   //每行换一个
	}
	system("pause");
}
