//判断一个字符串是否为回文字符串 
//要求:不适用额外数组和字符串
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void IsPalindrome(char *arr)
{
	char *start = arr;
	//如果不减1,将会是\0
	char *end = arr + strlen(arr)-1;

	//第一个和最后一个比较 循环遍历到中间
	while (start<end)
	{
		if (*start != *end)
		{
			printf("不是回文数!\n");
			return;
		}
		start++;
		end--;
	}

	printf("是回文数!\n");
	return;
}

int main()
{
	char arr[] = "aa";
	IsPalindrome(arr);
	system("pause");
	return 0;
}
