//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int left = 0;
//	int right = sizeof(a) / sizeof(a[0])-1;
//	int target = 0;
//	printf("请输入你想查的数字:");
//	scanf("%d", &target);
//	while (left<=right){
//		int mid = (left + right) / 2;
//		if (mid > target)
//		{
//			right = mid - 1;
//		}
//		else if (mid < target)
//		{
//			left = mid + 1;
//		}
//		else if (mid == target)
//		{
//			printf("目标函数下标是:%d\n",mid);
//			break;
//		}
//	}
//	if (right < left)
//	{
//		printf("你想查的数字没有找到!\n");
//	}
//	system("pause");
//}