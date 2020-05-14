//选择一个递增数组 : {3,4,5,1,2}
//求数组最小值

//3 4 5 1 2
//p1  mid p2

//3 4 5 1 2
//   p1   p2
//     mid         

//3 4 5 1 2
//    p1p2

//二分查找 : 三指针
//mid>=p1 --> p1=mid 找右边界,最大值
//mid<=p2 --> p2=mid 找左边界,最小值
//p1与p2相邻则,p2已经执向了min

//特殊情况
// 1 1 1 0 1
// p1  mid  p2
// 递增不严谨,有相同值,直接顺序查找

int Min(vector<int> nums)
{
    //无效输入
    if(nums.empty()) return 0;
    
    int size = nums.size();
    int p1 = 0,p2 = size-1;
    int min = 0;
    
    //二分查找
    while(p1>p2)
    {
        //找到,p1p2相邻
        if(p2 - p1 == 1)
            break;
        
        int mid = (p1+p2)/2;
        //特殊情况: 有相同元素,不是单调递增
        if(nums[mid] == nums[p1] == nums[p2])
            return MinOrder(nums,p1,p2);
           
        //右边界找最大  
        if(nums[mid] >= nums[p1])
            p1 = mid;
        //左边界找最小
        else if(nums[mid] <= nums[p2])
            p2 = mid;
            
    }
    
    return nums[p2];  
}

int MinOrder(vector<int> nums,int begin,int end)
{
    int min = nums[begin]; 
    for(int i=begin+1;i<=end;++i)
    {
        if(nums[i]>nums[i+1])
          return nums[i+1];
    }
}
