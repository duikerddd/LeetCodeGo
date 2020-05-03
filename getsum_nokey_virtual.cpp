//解法2: 利用多态模拟递归终止条件if,父类虚函数为终止条件,子类虚函数为递加
class A{
public:
	virtual int Sum(int n)
	{
		return 0;
	}
};

class B : public A{
public:
	virtual int Sum(int n)
	{
		A a;
		B b;
		A* p[2] = { &a, &b };
		return n + p[!!n]->Sum(n-1);  //(!!n) : n!=0 --> n=1  ---> !n=0 --> !!n=1
											//        n==0 --> n=0  ---> !n=1 --> !!n=0
	}
};

class Solution{
public:
	int GetSum(int n)
	{
		B b;
		return b.Sum(n);
	}
};
