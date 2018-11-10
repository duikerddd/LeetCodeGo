//模拟实现strcpy
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

char *Strcpy(char *dest,char const *src)
{
	char* ret = dest;
	assert(*dest != NULL);
	assert(*src != NULL);
	//对应位置拷贝
	while (*dest++ = *src++)
		;
	return ret;
}

int main()
{
	char a[] = "iiiiiiiiiiiii";
	char *b = "i love you";
	Strcpy(a, b);

	printf("%s\n", a);
	system("pause");
	return 0;
}
