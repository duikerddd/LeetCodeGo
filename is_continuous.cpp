//解法:1.将大小王看做0, 排序
//	   2.count统计0和空格数 0-=1 count+=v[i+1]-v[i]-1  
//	   3.count<=0   返回true ;  count>0 或者 重复,返回false 
class Solution{
public:
	bool IsContinuous(vector<int> v)
	{
		//无效输入
		if (v.size() != 5) return false;

		//排序
		sort(v.begin(), v.end());

		int count = 0;
		for (int i = 0; i < v.size()-1; ++i)
		{
			//0 count--
			if (v[i] == 0){
				count--;
				continue;
			}
			
			//重复 false
			if (v[i] == v[i + 1])
				return false;

			//空格 count+=两数差的数 1,4 :  3-1
			count += v[i + 1] - v[i] - 1;
			
		}

		if (count <= 0)
			return true;
		
		return false;
	}
};
