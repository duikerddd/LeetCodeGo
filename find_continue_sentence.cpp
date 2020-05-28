void PrintOrder(int small,int big)
{
	for (int i = small; i <= big; ++i)
	{
		cout << i << " ";
	}
	cout  << endl;
}

void FindContinueSequence(int sum)
{
	//无效输入
	if (sum < 3) return;

	//双指针: 自然数序列,大小即下标
	int small = 1;
	int big = 2;
	int curSum = 3;
	//序列移动
	int border = (sum + 1 )/ 2;
	while(small < border)
	{
		//== 输出
		if (curSum==sum)
			PrintOrder(small, big);
		
		//>  减小
		//减小后再判断是否相等 直到<或者超界
		while(curSum>sum && small<border)
		{
			curSum -= small;
			small++;

			if (curSum == sum)
				PrintOrder(small, big);
		}


		//</前面数已经看完 增大
		big++;
		curSum += big;
	}

}
