////6.实现memcpy
#include<stdio.h>
#include<stdlib.h>

void* Memcpy(void* dst, const void*src, size_t count)
{
	void *ret = dst;
	//copy from lower addresses to higher addresses
	while (count--)
	{
		*(char*)dst = *(char*)src;
		dst = (char*)dst + 1;
		src = (char*)src + 1;
	}
	return ret;

}

int main()
{
	char a[] = "iiiiiiiiii";
	char b[] = "i love you";
	int len = sizeof(a) / sizeof(a[0]);
	Memcpy(a, b, len);

	printf("%s\n", a);

	system("pause");
	return 0;
}
