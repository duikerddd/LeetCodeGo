//n个骰子的点数
//输入n,打印所有可能和s出现的概率

//解题思路:  很明显的一道动态规划问题
//解法:  dp[n][k]: n个骰子,和为k的次数
//       dp[n][k] = dp[n-1][k-1] + dp[n-1][k-2] + ... dp[n-1][k-6];
//       dp[1][k]=1   ret: 

int getNSumCountNotRecusion(int n, int* count){
    if(n<1) return 0;
    
    vector<vector<int>> count(n+1,vector<int>(n*6+1,0));
    
    for(int i=1;i<=6;i++)
    {
        count[1][i] = 1;
    }
    
    for(int i=2;i<=n;i++)
    {
        for(int j=i;j<=n*6;j++)
        {
            //这里会越界,需要判断
            //count[i][j] = count[i-1][j-1] + count[i-1][j-2] + count[i-1][j-3] + count[i-1][j-4] + count[i-1][j-5] + count[i-1][j-6]; 
            for(int k = 1;k <= 6;k++)
                {
                    if(j - k >= 0)
                    {
                        //注意这里是 +=
                        dp[i][j] += dp[i - 1][j - k];
                    }
                }
            cout<<i<<"个 和为"<<j<<"的次数为"<<dp[i][j]<<endl;
        }
    }
    
}
