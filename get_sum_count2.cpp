//动态规划
//F(n, k) : n个骰子落地后, 合为k的次数
//F(n, k) = F(n - 1, k - 1) + F(n - 1, k - 2) + F(n - 1, k - 3) + F(n - 1, k - 4) + F(n - 1, k - 5) + F(n - 1, k - 6)
//初始化 : F(1, 1) = 1 F(1, 2) = 1 F(1, 3) = 1 F(1, 4) = 1 F(1, 5) = 1 F(1, 6) = 1
//  返回值 : F(n, ki)

void getNSumCountNotRecusion(int n){
	//动态规划,dp第一个参数代表第n次置骰子,第二个参数代表骰子的点数之和.整个dp就是第n次置骰子 某一个点数出现的次数.
	//第一行没有骰子都为0. 第一列总和0全为0
	vector<vector<int>>dp(n + 1, vector<int>(n * 6 + 1, 0));

	//初始化第一行
	for (int i = 1; i <= 6; i++)
	{
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++)
	{
		//第n次骰子,最小数为n
		for (int j = i; j <= n * 6; j++)
		{
			//上一状态和 sum - k 
			for (int k = 1; k <= 6; k++)
			{
				//sum - k : n-1骰子的sum 保证>=0才存在,才不会越界
				//如果j-k==0 则从上面看也是0
				if (j - k >= 0)
				{
					//注意这里是 +=
					dp[i][j] += dp[i - 1][j - k];
				}
			}
		}
	}
	for (int j = n; j <= n * 6; ++j)
		cout << j << "出现次数" << dp[n][j] << endl;
}
