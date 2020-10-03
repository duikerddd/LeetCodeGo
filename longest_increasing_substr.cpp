class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
     
     //dp[i]: 以i为结尾的最大长度
     //dp[i] =  max(dp[k]) + 1;      0<k<i && num[k]<num[i] 
     //        寻找前面最长的子序列衔接
     //dp[0] = 0; dp[1] = 1;
     //ret: max dp[i]
     
     int longestIncreasingSubsequence(vector<int> &nums) {
        // write your code here
        if(nums.empty()) return 0;
        
        vector<int> dp(nums.size(),0);
        
        dp[0] = 1;
        for(int i=1;i<nums.size();++i)
        {
            int cnt = 1;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    cnt = max(cnt,dp[j]+1);
                }
            }
            dp[i] = cnt;
        }
        
        int max_len = 1;
        for(int i=0;i<dp.size();++i)
        {
            if(dp[i]>max_len) max_len=dp[i];
        }
        return max_len;
    }
};
