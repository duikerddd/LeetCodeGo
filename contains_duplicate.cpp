#include<algorithm>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //排除不满足条件数组
        if(nums.size()<2)
        {
            return false;
        }
        //注意i不能到最后一个,会访问越界
        for(int i=0;i<nums.size()-1;++i)
        {
            if(nums[i]==nums[i+1])
            {
                return true;
            }
        }
        return false;
    }
};
