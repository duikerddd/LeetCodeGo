class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: An integer
     */
     
     //dp[i]: 前i个选择里,到i的最小跳跃数   
     //dp[i] = min (dp[j] && v[j]>=(i-j))
     //init:dp[0] = 0; dp[1] = 0;
     //ret: dp[n]
     
    int jump(vector<int> &A) {
        // write your code here
        if(A.empty()) return 0;
        
        vector<int> dp(A.size()+1,-1);
        dp[0] = 0; dp[1] = 0;
        
        for(int i=2;i<=A.size();++i)
        {
            for(int j=1;j<i;++j)
            {
                if(dp[j]>=0 && A[j-1]>=(i-j))
                {
                    if(dp[i]!=-1){
                    dp[i] = min(dp[i],dp[j]+1);
                    continue;
                    }
                    dp[i] = dp[j]+1;
                }
            }
        }
        
        return dp[A.size()];
    }
};
