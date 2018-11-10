#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void left_rotate(char *str, int k)
{
	int len=strlen(str);
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



int main()
{
	char str[100] = "abcdefg";
	left_rotate(str, 2);
	printf("%s\n", str);

	system("pause");
	return 0;

}
