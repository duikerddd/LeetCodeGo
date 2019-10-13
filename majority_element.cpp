#include <algorithm>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.begin()+nums.size());
        return nums[nums.size()/2];
    }
};
