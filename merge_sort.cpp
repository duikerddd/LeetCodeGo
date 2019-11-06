#include<stdlib.h>

void Merge(int* a,int begin,int mid,int end,int* tmp)
{
    int begin1 = begin;
    int begin2 = mid+1;
    int index = begin;
    //比较插入
    while(begin1<=mid && begin2<=end)
    {
        if(a[begin1]<=a[begin2]) 
            tmp[index++] = a[begin1++];
         else
            tmp[index++] = a[begin2++];
    }
    //剩余插入
    while(begin1<=mid)
    {
         tmp[index++] = a[begin1++];
    }
    while(begin2<=end)
    {
         tmp[index++] = a[begin2++];
    }
    //拷贝到原数组
    index = begin;
    while(begin<=end)
    {
        a[index++] = tmp[begin++];
    }
}

//分到最小解,begin和end是下标
void Sort(int* a,int begin,int end,int* tmp)
{
    int mid = begin + (end-begin)>>2;
    Sort(a,begin,mid,tmp);
    Sort(a,mid+1,end,tmp);
    //归并,子序列排序
    Merge(a,begin,mid,end,tmp);
}

//归并排序
void MergeSort(int* arr,int n)
{
      int* tmp = (int*)malloc(sizeof(int)*n);
      Sort(arr,0,n-1,tmp);
      free(tmp);
}be
