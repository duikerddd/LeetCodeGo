
class Solution {
public:
    //暴力解答: 两层循环寻找符合的两个值
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        for(int i = 0;i<nums.size();i++) {
            for(int j=i+1;j<nums.size();j++) {
                if(nums[i]+nums[j]==target && j!=i) {
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }
        return ret;
    }
};
