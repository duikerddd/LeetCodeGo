//模拟实现strcat
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

char *Strcat(char *dest, char  *src)
{
	char* ret = dest;
	assert(*dest != NULL);
	assert(*src != NULL);
	//寻找dest的'\0'位置
	while (*dest)
	{
		dest++;
	}
	//src的内容依次拷贝到dest的内容后面
	while (*dest++ = *src++)
		;
	return ret;
}

int main()
{
	char a[100] = "i love you";
	char *b = " very much!";
	Strcat(a,b);

	printf("%s\n", a);
	printf("%s\n", b);
	system("pause");
	return 0;
}
