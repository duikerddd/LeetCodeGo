//将三个数按从大到小输出。
#include<stdio.h>
#include<stdlib.h>
int main(){

	int a, b, c, t;
	scanf("%d %d %d", &a, &b, &c);
	if (a>b) t = a, a = b, b = t;
	if (b>c) t = b, b = c, c = t;
	if (a>b) t = a, a = b, b = t;
	printf("%d %d %d", a, b, c);

	return 0;
}
