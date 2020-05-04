class Solution{
public:
	void Swap(int& num1,int& num2)
	{
		//基于加减法(溢出可能)
		// a = a+b; b = a - b; a = a - b;
		//三次异或
		// a = a^b; b = a^b; a=a^b;
		// 10^01=11 11^01=10 10^11=01
		num1 ^= num2;
		num2 ^= num1;
		num1 ^= num2;
	}
};
