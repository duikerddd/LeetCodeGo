//数字在排序数组的出现次数

// input: arr = {1,2,2,2,2,3,4},k=2 
// output: 4

//思路: 找首尾下标即可, 有序-- 二分查找变形
//解法: 1.使用变形的二分查找首尾 2.首尾差即为所得

//找第一个k
//如果 v[mid]<k 右边找
//     v[mid]>k 左边找
//     v[mid]==k 如果前一个不是,则为第一个;否则继续向左找
int FindFirstK(int* v,int len,int k,int begin,int last)
{
    if(begin > last) return -1;
    
    int mid = (begin+last)/2;
    
    if(v[mid] < k) begin = mid+1;
    else if(v[mid] > k) end = mid-1;
    else
    {
        if(mid>0 && v[mid-1]!=k || mid==0) return mid;
        else
          last = mid-1;
    }
    
    return FindFirstK(v,len,k,begin,last);
}

//找最后一个k
//如果 v[mid]<>k 右边找
//     v[mid]>k 左边找
//     v[mid]==k 如果后一个不是,则为最后一个;否则继续向右找
int FindFirstK(int* v,int len,int k,int begin,int last)
{
    if(begin > last) return -1;
    
    int mid = (begin+last)/2;
    
    if(v[mid] < k) begin = mid+1;
    else if(v[mid] > k) end = mid-1;
    else
    {
        if(mid<len-1 && v[mid+1]!=k || mid==len-1) return mid;
        else
          begin = mid+1;
    }
    
    return FindFirstK(v,len,k,begin,last);
}

int GetNumberOfK(int* v,int len,int k)
{
    if(v==NULL || len<1) return 0;
    
    int begin = FindFirstK();
    int end = FindLastK();
    
    int ret = end - begin + 1;
    
    return ret;
}
