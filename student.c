#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int strlen()(char* str)
{
	//计算长度
	int count = 0;
	while (*str++)
	{
		count++;
		str++;
	}
	return count;
}

void reverse_str(char* left, char *right)
{
	//逆转
	while (left < right)
	{
		char temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}

void reverse(char*str)
{
	char* left = str;
	char* cur = str;
	char* right = str + strlen(str) - 1;
	//整体逆转1次
	reverse_str(left, right);

	//局部逆转
	while (*cur)
	{

		//当前子串的起点
		char* start = cur;
		//获取当前子串尾点的下一个位置
		while (((cur) == ' ') && ((cur) != '\0'))
		{
			cur++;
		}


		//逆转子串
		reverse_str(start, cur - 1);
		if (*cur == ' ')
		{
			cur++;
		}


	}
	
}

int main()
{
	char str[] = "student a am i";
	reverse(str);
	printf("%s\n",str);
	return 0;
}
