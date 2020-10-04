class Solution {
public:
    /**
     * @param A: An array of non-negative integers
     * @return: The maximum amount of money you can rob tonight
     */
     //dp[i]: 抢劫到i时的最大值
     //dp[i] = max(dp[i-1],dp[i-2]+num[i])  //拿/不拿
     //init: dp[0] = num[0];
     //ret: max dp[i]
    long long houseRobber(vector<int> &A) {
        // write your code here
        vector<long long> dp(A.size()+1);
        
        dp[0] = 0;
        dp[1] = A[0];
        
        for(int i=2;i<=A.size();++i)
        {
            dp[i] = max(dp[i-1],dp[i-2]+A[i-1]);
        }
        
        
        return dp[A.size()];
    }
};
