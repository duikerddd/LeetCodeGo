//求1+..n 不用循环和判断



//解题思路: 利用构造函数和静态成员模拟循环
class Solution{
public:
	Solution()
	{
		n++;
		sum += n;
	}
	static int n;
	static int sum;
};
int Solution::n = 0;
int Solution::sum = 0;

//解题思路2: 利用多态的自动调用,实现递归,子类递归,父类终止
class A{
public:
	virtual int Sum(int n)
	{
		return 0;
	}
};

class B :public A
{
public:
	int Sum(int n)
	{
		A a;
		B b;
		A* p[2] = { &a, &b };
		return n + p[!!n]->Sum(n-1); //!!n 将n变成1/0的逻辑数   
	}
};


//解题思路3: 函数指针实现递归,类似上面
typedef int(*func)(int);
int SumEnd(int n)
{
	return 0;
}

int SumAdd(int n)
{
	func f[2] = { SumEnd , SumAdd };

	return n + f[!!n](n - 1);
}

int main()
{
	int n = 5;
	Solution*s = new Solution[n];
	cout << Solution::sum << endl;

	B b;
	cout<<b.Sum(5)<<endl;

	cout << SumAdd(5) << endl;
	
	return 0;
}
