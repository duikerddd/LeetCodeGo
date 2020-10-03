class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers
     * @param target: An integer
     * @return: An integer
     */
     //方案数.
     //dp[n][w]: 前i个物品,为w的方案数
     //dp[n][w] =    dp[i-1][w] + dp[i-1][w-wi]+wi + 1(wi==j?)   
     //               不拿i拿满+      拿i拿满(前提能装下)     +   只拿i拿满 
     //ret: dp[n][w]
     //init: dp[i][0] = dp[0][i] = 0
     
    int backPackV(vector<int> &nums, int target) {
        // write your code here
        vector<vector<int>> dp(nums.size()+1,vector<int>(target+1,0));
        
        for(int i=1;i<=nums.size();++i)
        {
            for(int j=1;j<=target;++j)
            {
                dp[i][j] += dp[i-1][j];
                
                if(nums[i-1]<j)
                dp[i][j] += dp[i-1][j-nums[i-1]];
                
                if(nums[i-1]==j)
                    dp[i][j]++;
            }
        }
        
        return dp[nums.size()][target];
    }
};
