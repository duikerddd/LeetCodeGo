//方法一
//每次左旋一次,判断旋转之后字符串是否与目标字符串是否一致 
//旋转一圈  没有找到返回0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void left_rotate(char *str, int k)
{
	int len = strlen(str);
	k %= len;//减少重复次数

	char temp = 0;
	char *cur = str;
	while (k--)
	{

		//左旋一次
		temp = *str;
		cur = str;
		while (*(cur + 1) != '\0')
		{
			//每个字符向前推一个
			*cur = *(cur + 1);
			cur++;
		}

		*cur = temp;
	}
}

int is_rotate(char *dest, char* src)
{
	if (strlen(dest) != strlen(src))
	{
		printf("不是旋转过的!\n");
		return 0;
	}
	if (!strcmp(dest, src))
	{
		printf("旋转过的!\n");
		return 1;
	}

	int k = strlen(dest);
	k--;
	while (k--)
	{
		//每次旋转一次 判断
		left_rotate(src, 1);
		//判断旋转之后的内容是否和目标一致
		if (!strcmp(dest, src))
		{
			printf("旋转过的!\n");
			return 1;
		}
	}
	printf("不是旋转过的!\n");
	return 0;

}

//方法二 dest--->abcd 把目标串拼接相同的内容abcdabcd   判断源串是否为目标串的子串 
//                                  src---->cdab
int is_rotate02(char *dest, char* src)
{
	if (strlen(dest) != strlen(src))
	{
		printf("不是旋转过后的!\n");
		return 0;
	}
	strncat(dest, dest,strlen(dest));
	if (strstr(dest, src) != NULL)
	{
		printf("是旋转过后的!\n");
		return 1;
	}
	printf("不是旋转过后的!\n");
	return 0;

}

int main()
{
	char dest[100] = "sssss";
	char src[100] = "avdasf";
	is_rotate02(dest, src);
	
	system("pause");
	return 0;
}
