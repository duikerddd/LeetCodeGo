class Solution {
public:
    /**
     * @param nums: An array of non-negative integers.
     * @return: The maximum amount of money you can rob tonight
     */
     //dp[i]: 打劫到第i家时的最大数目 (最后一个房子与第一个房子相邻)(原有序列分成了两个)
     //       有第一个房子参与的计算,最后一个房子不能参与;有最后一个房子参与的计算,与之相反
     //dp1[i] = max (dp[i-1],dp[i-2]+vi)   1~n-1
     //dp2[i] = max (dp[i-1],dp[i-2]+vi)   2~n                                   
     //init: dp1[0]=0,dp1[1]=v1
     //intt: dp1[0]=0,dp2[1]=v2
     
    
    int houseRobber2(vector<int> &nums) {
        // write your code here
        if(nums.size()==1) return nums[0];
        
        vector<int> dp1(nums.size());
        vector<int> dp2(nums.size());
        
        dp1[0]=0;dp1[1]=nums[0];
        dp2[0]=0;dp2[1]=nums[1];
        
        // 1 2 3
        // 0 1 2
        // 2 3 5
        for(int i=2;i<nums.size();++i)
        {
            dp1[i] = max(dp1[i-1],dp1[i-2]+nums[i-1]);
        }
        // 2 3 4
        // 2 3 4
        // 3 5 7
        for(int i=2;i<nums.size();++i)
        {
            dp2[i] = max(dp2[i-1],dp2[i-2]+nums[i]);
        }
        
        if(dp1[nums.size()-1] > dp2[nums.size()-1])
        return dp1[nums.size()-1];
        
        return dp2[nums.size()-1];
        
    }
};
