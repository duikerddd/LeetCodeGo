class Solution{
public:
	static int n;
	static int sum;
	Solution()
	{
		n++;
		sum += n;
	}
};

int Solution::n = 0;
int Solution::sum = 0;

int GetSum(int n)
{
	Solution* p = new Solution[n];
	return p->sum;
}
