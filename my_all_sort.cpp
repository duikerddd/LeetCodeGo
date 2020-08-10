#include <stdio.h>
struct Stu
{
	char name[10];
	int age;

};

int cmp3(void* e1, void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

void swap(char* p1,char* p2,int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2++;
	}
}

void bubble_sort(void* arr, int sz, int width, int (*cmp3)(void* e1,void* e2))
{
	int i = 0;
	//冒泡排序的趟数
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		//每一趟冒泡排序
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp3((char*)arr + j*width, (char*)arr + (j + 1)*width)>0)
			{
				swap((char*)arr + j*width, (char*)arr + (j + 1)*width,width);
			}			
		}
	}
}

int main()
{
	struct Stu s[3] = { { "zhangsan", 20 }, { "lisi", 30 }, { "wangwu", 10 } };
	int sz3 = sizeof(s) / sizeof(s[0]);
	int j = 0;
	bubble_sort(s, sz3, sizeof(s[0]), cmp3);
	for (j = 0; j < sz3; j++)
	{
		printf("%d ", s[j].age);
	}
	return 0;
}
