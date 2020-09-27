 //相比于01背包问题
 //完全背包问题可以重复选择
 //递推公式就有变化了 dp[i][j] = max(dp[i-1][j] , dp[i-1][j-k*A[i-1]]+k*V[i-1])  其实就是子问题的解变多了 
 
 int backPackIII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        vector<vector<int>> dp(A.size()+1,vector<int>(m+1,0));
        
        for(int i=1;i<=A.size();++i)
        {
            for(int j=1;j<=m;++j)
            {
                int k = 0; //0开始,包括了不拿的情况
                while(k*A[i-1]<=j){
                   dp[i][j] = max(dp[i][j],dp[i-1][j-k*A[i-1]]+k*V[i-1]);
                   k++;
                }
            }
            
        }
        
        return dp[A.size()][m];
    }
