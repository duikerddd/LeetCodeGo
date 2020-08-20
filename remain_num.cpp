//圆圈中的最后数字
	//0,1,...,n-1排成一圈,每次删掉第m个数字
	//0,1,2,3,4    顺序: 2,0,4,1,3


//解题思路: 使用链表,删除容易
//解法: 1.将元素放入链表 2.遍历到第三个元素删除,注意保存下一个的位置,最后一个会到前面模拟循环 3.直到只剩一个元素
int LastRemain(int n, int m)
{
	if (n < 1 || m < 1) return 0;

	list<int> l;
	for (int i = 0; i < n; ++i)
	{
		l.push_back(i);
	}

	auto it = l.begin();
	while (l.size()>1)
	{
		for (int i = 1; i < m; ++i)
		{
			it++; 
			if (it == l.end())
			{
				it = l.begin();
			}
		}
 
		
		auto cur = it;
		it++;

		//注意,it变化就要看是否越界
		if (it == l.end()) 
			it = l.begin();
		l.erase(cur);
	}

	return *it;
}
