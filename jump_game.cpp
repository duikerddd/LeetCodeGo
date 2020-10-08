class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: A boolean
     */
     //2 3 1 1 4
     //2 --> 3,1
     //3 --> 1,1,4  √
     //1 --> 1 
     //1 --> 4   √
     
     //dp[i][j]: 第i个位置是否能跳到的位置j  无后效性性质不满足
     //dp[i][j] = v[i]>=(j-i) && dp[i-k][i]==true  
     
     //dp[i]: 前i个选择里,是否能到i这个位置
     //dp[i] = dp[j] && v[j]>=(i-j)
     //init:dp[0] = 0; dp[1] = v[1];
     //ret: dp[n]
     
    bool canJump(vector<int> &A) {
        // write your code here
        if(A.empty()) return true;
        
        vector<bool> dp(A.size()+1,false);
        dp[0] = true; dp[1] = true;
        
        for(int i=2;i<=A.size();++i)
        {
            for(int j=1;j<i;++j)
            {
                if(dp[j] && A[j-1]>=(i-j))
                {
                    dp[i] = true;
                    continue;
                }
            }
        }
        
        return dp[A.size()];
    }
};
