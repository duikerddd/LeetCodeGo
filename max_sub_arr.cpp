#include<algorithm>

class Solution {
public:
    //动态规划
    //状态: F(i) --- 以array[i]结尾的最长子系列和
    //递推公式 : F(i) = max(F(i-1)+array[i] , array[i])
    //初始值 : F(0) = array[0];
    //结果 : F(i)中的最大值
    int maxSubArray(vector<int>& nums) {
        
        vector<int> F(nums.size(),0);
        F[0] = nums[0];
        for(int i=1;i<nums.size();++i)
        {
            F[i] = max(F[i-1]+nums[i],nums[i]);
        }
        int maxSum = F[0];
        for(int i=1;i<nums.size();++i)
        {
            if(maxSum<F[i])
            {
                maxSum = F[i];
            }
        }
        return maxSum;
    }
};
