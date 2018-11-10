//3.实现strstr(查找子串)
#include<stdio.h>
#include<stdlib.h>

char* Strstr(char *a, char const *b, int len)
{
	int j = 0;
	for (int i = 0; i < len; i++)
	{
		//空字符串返回原字符串
		if (b[i] == '\0')
		{
			printf("%s\n", a);
			return 'no';
		}

		if (a[i] == b[j])
		{
			//固定起点地址
			const char *yes = a+i;
			while (1)
			{
				
				//若都相同,返回起点地址
				if (a[i] == b[j])
				{
					if (b[j + 1] == '\0')
					{
						return j = yes;
					}
					continue;
				}
				//若不相同,返回NULL
				else
					return NULL;
				i++;
				j++;
			}
		}

	}
}

int main()
{
	char a[] = "i love you";
	char b[] = "i";
	int len = sizeof(a) / sizeof(a[0]);
	if (Strstr(a, b, len) != 'no')
	{
		printf("%p\n", a);
		printf("%p\n", Strstr(a, b, len));
	}

	system("pause");
	return 0;
}
