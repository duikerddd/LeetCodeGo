//实现strchr(查找)
#include<stdio.h>
#include<stdlib.h>

char* Strchr(char *a, char b, int len)
{

	for (int i = 0; i < len; i++)
	{
		if (a[i] == b)
		{
			return a + i;
		}
		if ((a[i + 1] == '\0')&&(b != '\0'))
		{
			return NULL;
		}
	}

}

int main()
{
	char a[] = "i love you";
	char b = 'y';
	int len = sizeof(a) / sizeof(a[0]);
	printf("%p\n", a);
	printf("%p\n",Strchr(a, b, len));

	

	system("pause");
	return 0;
}
