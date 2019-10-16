#include<algorithm>

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int realk = k%nums.size(); 
       
        //三次反转
        reverse(nums.begin(),nums.end()-realk);
        reverse(nums.end()-realk,nums.end());
        reverse(nums.begin(),nums.end());
    }
};
