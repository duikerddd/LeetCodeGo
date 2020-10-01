class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integerk*wi  * @return: An integer
     */
     //方案数.
     //dp[n][w]: 前i个物品,为w的方案数
     //dp[n][w] =  ∑  dp[i-1][w] + dp[i-1][w-k*wi]+k*wi   不拿i+拿i+单独拿i到满
     //         += 1                            k*wi==j
     //ret: dp[n][w]
     //init: dp[i][0] = dp[0][i] = 0
    
    int backPackIV(vector<int> &nums, int target) {
        // write your code here
        vector<vector<int>> dp(nums.size()+1,vector<int>(target+1,0));
        
        for(int i=1;i<=nums.size();++i)
        {
            for(int j=1;j<=target;++j)
            {
                int k = 0;
                
                while(k*nums[i-1] <= j)
                {
                    
                    dp[i][j]+=dp[i-1][j-k*nums[i-1]];
                    
                    if(k*nums[i-1]==j)
                    {
                        dp[i][j]++;
                    }
                    k++;
                    
                }
            }
        }
        
        return dp[nums.size()][target];
        
    }
};
