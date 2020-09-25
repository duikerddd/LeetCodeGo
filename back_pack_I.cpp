class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
     //装的最多 size=10
     //[3,4,8,5]   :  [4,5]  dp[4][9]=9 第四行临界值
     //[3,4,8]     :  [8]    dp[3][8]=8 第三行临界值
     //[3,4]       :  [3,4]  dp[2][7]=7 第二行临界值
     //[3]         :  [3]    dp[1][3]=3 第一行临界值 
     
     //dp[i][j]: 前i个中,j容量时放入的最大值
     //dp[i][j] = max(dp[i-1][j-mi]+v[i],dp[i][j-1]) ---放得下A[i]: 1.腾地方,放入A[i] 2.不放
     //             dp[i][j-1]                       --- 放不下A[i]: 不放 
     //dp[i][0] = 0. dp[0][i] = 0.
     //ret: dp[i][j]
   
    int backPack(int m, vector<int> &A) {
        // write your code here
        vector<vector<int>> dp(A.size()+1,vector<int>(m+1,0));
        
        for(int i=1;i<=A.size();++i)
        {
            for(int j=1;j<=m;++j)
            {
                if(j>=A[i-1])
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j-A[i-1]]+A[i-1]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[A.size()][m];
    }
};
