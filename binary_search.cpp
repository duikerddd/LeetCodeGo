#pragma once
#include<stdio.h>

typedef int ssize_t;
typedef unsigned int size_t;

ssize_t BinarySearchR(int array[], size_t size, int data)   //递归
{
	if (size <= 0)
	{
		return -1;
	}
	size_t mid = left + (right - left) / 2;
	if (data == array[mid])
	{
		return mid;
	}
	if (data < array[mid])
	{
		return BinarySearchR(array, mid, data);
	}
	else{
		return BinarySearchR(array + mid + 1, size - mid - 1,data);
	}
}



ssize_t BinarySearch(int array[], size_t size, int data)      //常规
{
	//[left,right)
	size_t left = 0;
	size_t right = size;

	while (left <= right)
	{
		//考虑地址
		size_t mid = left + (right - left / 2);
		if(array[mid]==data)
		{
			return mid;
		}
		if (data < array[mid])
		{
			right = mid;
		}
		else{
			left = mid + 1;
		}
		return -1;
	}
}
