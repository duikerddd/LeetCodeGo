class Solution {
public:
    //方法一 : 按照规律,暴力解答
    //从左到右  小~大
    //  if nums[i] == target  return i;  
    //  if nums[i] < target  -->++i;
    //  if nums[i] > target   return i;
    //极端条件
    //没找到,出循环 --- return i+1;
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        for(;i<nums.size();++i)
        {
            if(nums[i]>=target) 
                    return i;
        }
        return i;
    }
};
