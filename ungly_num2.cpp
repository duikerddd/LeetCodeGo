long GetUN(int index)
{
	if (index<1)  return 0;

	vector<int> ungly_num(index, 1);
	ungly_num.push_back(1);
	int t2 = 0, t3 = 0, t5 = 0;   //三个队列头,为当前倍数最小值

	for (int i = 1; i<index; ++i)
	{
		//选取队头最小值
		ungly_num[i] = min(ungly_num[t2]*2, min(ungly_num[t3]*3, ungly_num[t5]*5));

		//最小值为出队元素,并查重
		if (ungly_num[i] == ungly_num[t2] * 2)	t2++;
		if (ungly_num[i] == ungly_num[t3] * 3)	t3++;
		if (ungly_num[i] == ungly_num[t5] * 5)	t5++;
	}
	return ungly_num[index - 1];
}
