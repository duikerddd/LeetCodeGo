//动态规划

//解题思路: 以递归的思路, 自下而上
//    dp[i][j]: 当前玩家能拿到的最高分(差值) 
//    dp[i][j] = max {nums[i]-dp[i+1][j] , nums[j]-dp[i][j-1]}
//    i=j dp[i][j]=nums[i]
//    return : dp[0][nums.size[]-1]
class Solution{
public:

    bool PredictTheWinner(vector<int>& nums)
    {
            int n = nums.size();
            vector<vector<int>> dp(n,vector<int>(n,0));

            //初始化
            for(int i=0;i<n;++i)
            {
                dp[i][i] = nums[i];
            }

            //动态规划
            for(int i=n-2;i>=0;--i)
            {
                for(int j=i+1;j<n;++j)
                {
                    dp[i][j] = max(nums[i]-dp[i+1][j],nums[j]-dp[i][j-1]);
                }
            }

            //返回值
            return dp[0][n-1]>=0;

    }
};
