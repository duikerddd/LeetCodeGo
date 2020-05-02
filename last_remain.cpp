
class Solution{
public:
	int LastRemain(int n,int m)
	{
		//无效输入
		if (n < 1 || m < 1) return 0;

		//链表存储数据
		list<int> l;
		for (int i = 0; i < n; ++i)
		{
			l.push_back(i);
		}
		
		//删除数据
		auto it = l.begin();
		while (l.size()>1)
		{
			//走m步
			for (int i = 1; i < m; ++i)
			{
				it++;
				//到结尾指向头
				if (it == l.end())
					it = l.begin();
			}
			//存好下一个头
			auto  next = ++it;
			if (next == l.end())
				next = l.begin();
			//删除
			--it;
			l.erase(it);
			it = next;
		}
		return *it;
	}
};
