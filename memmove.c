////7.实现memmove
#include<stdio.h>
#include<stdlib.h>

void *Memmove(void* dst, const void* src, size_t count)
{
	void*ret = dst;

	if (dst <= src || (char*)dst >= ((char*)src + count))
	{
		//Non-overload lapping Buffers
		//copy from lower addresses to higher addresses
		while (count--)
		{
			*(char*)dst = *(char*)src;
			dst = (char*)dst + 1;
			src = (char*)src + 1;
		}
	}

	else{
		dst = (char*)dst + count - 1;
		src = (char*)src + count - 1;
		while (count--)
		{
			*(char*)dst = *(char*)src;
			dst = (char*)dst - 1;
			src = (char*)src - 1;
		}
	}

	return(ret);
}

int main()
{
	char a[] = "iiiiiiiiiiiiiii";
	char b[] = "i love you";
	int len = sizeof(a) / sizeof(a[0]);
	Memmove(a, b, len);

	printf("%s\n", a);

	system("pause");
	return 0;
}
