
void getNSumCountNotRecusion(int n){
	//动态规划,dp第一个参数代表第n次置骰子,第二个参数代表骰子的点数之和.整个dp就是第n次置骰子 某一个点数出现的次数.
	//第一行没有骰子都为0. 第一列总和0全为0
	vector<int> dp(n * 6 + 1, 0);
	
	for (int i = 1; i <= 6; ++i)
	{
		dp[i] = 1;
	}

	
	for (int i = 2; i <= n; i++)
	{
		//第n次骰子,最小数为n
		//从后往前遍历
		//这里必须重置位置1的次数,因为二维数组默认那些为0,而一维数组开始都是1
		for (int j = n*6; j >= 1; j--)
		{
			//tmp计算前面的和再赋值,如果直接原数组+=,会把以前的值也加上
			int tmp = 0;
			//上一状态和 sum - k 
			for (int k = 1; k <= 6; k++)
			{
				//sum - k : n-1骰子的sum 保证>=0才存在,才不会越界
				//如果j-k==0 则从上面看也是0
				if (j - k >= 0)
				{
					//注意这里是 +=
					tmp+=dp[j-k];
				}
			}
			dp[j] = tmp;
		}
	}
	for (int j = n; j <= n * 6; ++j)
		cout << j << "出现次数" << dp[j] << endl;
}

