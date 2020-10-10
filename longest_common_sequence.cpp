class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: The length of longest common subsequence of A and B
     */
     
     //双序列 ---> 使用二维数组
     
     //dp[i][j]: i,j时的最长公共子序列
     //dp[i][j] =   max(dp[i-1][j],dp[i-1][j])  i!=j
     //                     用         不用 
     //dp[i][j] = dp[i-1][j-1]+1  i==j 
     //init: dp[0][col]=0 dp[row][0]=0
     //ret: dp[m][n]
    
    int longestCommonSubsequence(string &A, string &B) {
        // write your code here
        vector<vector<int>> dp(A.size()+1,vector<int>(B.size()+1,0)) ;
        
        for(int i=1;i<=A.size();++i)
        {
            for(int j=1;j<=B.size();++j)
            {
                if(A[i-1]!=B[j-1])
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                else
                    dp[i][j] = dp[i-1][j-1]+1;
            }
        }
        
        return dp[A.size()][B.size()];
    }
};
