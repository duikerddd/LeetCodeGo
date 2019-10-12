#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 15

int arr[SIZE] = { 0 };
int dp[SIZE][SIZE] = { 0 };
int flag[SIZE][SIZE] = { 0 };
int d[SIZE] = { 0 };
static int countp = 0;

void Print(int i, int j)
{
	countp++;
	if (i == 0 || j == 0)///递归终止条件
	{
		return;
	}
	if (flag[i][j]==0)
	{
		Print(i - 1, j - 1);
		printf("%d ", arr[i - 1]);
	}
	else if (flag[i][j] == 1)
	{
		Print(i - 1, j);
	}
	else if (flag[i][j] == 2)
	{
		Print(i, j - 1);
	}
}


int main()
{
	int size=0;				    //arr数组长度
	int i, j;
	scanf_s("%d", &size);
	//arr数组赋值
	for (j = 0; j < size; ++j)
	{
		scanf_s("%d", &arr[j]);
	}
	//a数组赋值给d
	for (i = 0; i<size; ++i)
	{
		d[i] = arr[i];
	}

	//d数组排序
	for (i = size; i>0; --i)
	{
		for (j = 0; j < i-1; ++j)
		{
			if (d[j]>d[j + 1])
			{
				int tmp = d[j];
				d[j] = d[j + 1];
				d[j + 1] = tmp;
			}//end of if
		}//end of for j
	}//end of for i

	//d数组去重
	for (i = 0; i < size; ++i)
	{
		if (d[i] == d[i + 1])
		{
			j = i;
			while (d[j]!=0)
			{
				d[j] = d[j + 1];
				++j;
				--i;
			}
		}
	}
	//计算d数组大小
	int sized = 0;
	for (i = 0; i < size; ++i)
	{
		if (d[i] == 0)
		{
			break;
		}
		sized++;
	}
	
	//dp表生成 计算lcs  dp[i][j]为路径长度  flag[i][j]的值记录他是由哪个子问题的解得到的
	for (i = 1; i <= size; i++)
	{
		for (j = 1; j <= sized; j++)
		{
			//如果相等则加1,此位置lcs
			if (arr[i - 1] == d[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				flag[i][j] = 0;	//来自于左上方
			}
			//不相等则选取最大的lcs
			else
			{
				if (dp[i - 1][j]>dp[i][j - 1])
				{
					dp[i][j] = dp[i - 1][j];
					flag[i][j] = 1;	//来自于上方
				}
				else
				{
					dp[i][j] = dp[i][j - 1];
					flag[i][j] = 2;	//来自于左方
				}
			}
		}	
	}
	Print(size, sized);

	system("pause");
	return 0;
}
