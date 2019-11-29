int Min(vector<int> nums)
{
    int size = nums.size();
    //p1,p2代表下标
    int p1 = 0;
    int p2 = size-1;
    while(p1>p2)
    {
         if(p1+1 == p2)
             break;
        int mid = (p1+p2)/2;
        
        //特殊情况: 三值相等
        if(nums[p1]==nums[p2] && nums[p1]==nums[mid])
            return MinOrder(nums,p1,p2);
        
        if(nums[p1]<=nums[mid])
            p1 = mid;
        else if(nums[p2]>=nums[mid])
            p2 = mid;    
    }
    return nums[p2];
}

//顺序查找
int MinOrder(vector<int> nums,int begin,int end)
{
     int result = nums[0];
     for(int i=begin;i<=end;++i)
     {
         if(nums[i]>nums[i+1])
             result = nums[i+1];
     }   
     return result;
}
