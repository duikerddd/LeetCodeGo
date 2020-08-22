//不能被继承的类

//解题思路1: 私有父类的构造和析构,让子类无法完成对父类的构造和析构. 父类的创建则由静态函数在堆上创建
class Sealed{
public:
	static Sealed* Create()
	{
		return new Sealed();
	}

private:
	Sealed()
	{

	}
	~Sealed()
	{

	}
};

//解题思路2: 私有一个辅助类,让父类虚继承并成为他的友元, 友元让父类能够完成辅助类的构造析构, 虚继承会让子类先去调用虚基类,因为不是友元,所以子类无法完成创建
class Father;

class MakeSealed{
public:
	friend Father;
private:
	MakeSealed(){}
	~MakeSealed(){}
};

class Father : virtual public MakeSealed
{
public:
	Father(){}
	~Father(){}
};


int main()
{
	Father a;
	return 0;
}
