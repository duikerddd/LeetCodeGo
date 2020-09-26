class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
     //  0 1 2 3 4 5 6 7 8 9 10
     //0 
     //1
     //2
     //3 
     
     //dp[i][w]:前i个重量为w时的价值
     //dp[i][w] = max (dp[i-1][j-a[i]]+v[i] , dp[i-1][j])；  //放得下： 放/不放
     //dp[i][0] = 0, dp[0][j] = 0  
     //ret dp[i][w]
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        vector<vector<int>> dp(A.size()+1,vector<int>(m+1,0));
        
        for(int i=1;i<=A.size();++i)
        {
            for(int j=1;j<=m;++j)
            {
                if(A[i-1]<=j)
                   dp[i][j] = max(dp[i-1][j],dp[i-1][j-A[i-1]]+V[i-1]);
                else
                   dp[i][j] = dp[i-1][j];
                
            }
        }
        
        return dp[A.size()][m];
    }
};
