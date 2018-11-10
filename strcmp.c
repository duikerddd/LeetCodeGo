//5.实现strcmp
#include<stdio.h>
#include<stdlib.h>

int Strcmp(char const*a, char const *b, int len)
{
	for (int i = 0; i < len; i++)
	{
		
		if (a[i] == b[i])
		{
			//遇到第一个不同,比较字典序
			if (a[i + 1] != b[i + 1])
			{
				if (a[i + 1]>b[i + 1])
				{
					return 1;
				}
				else
					return -1;
			}
			//全相等,返回0
			if (a[i + 1] == '\0' && b[i + 1] == '\0')
			{
				return 0;
			}
			//没有b长,返回小于1;
			if (a[i + 1] == '\0'&&b[i + 1] != '\0')
			{
				return -1;
			}
			continue;
		}

	}
}

int main()
{
	char a[] = "i love you";
	char b[] = "i love yoa";
	int len = sizeof(a) / sizeof(a[0]);
	printf("%d\n",Strcmp(a, b, len));

	system("pause");
	return 0;
}
