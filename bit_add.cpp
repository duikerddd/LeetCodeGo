
//不用加减乘除做加法

//解题思路: 使用计算机的逻辑语言--> 位运算实现
//解法: 1. 不进位加法 n1^n2  (0^0=0 1^1=1 0^1=1)  2.统计进位 n1&n2 得到1说明要进位,左移 3.继续加 
class Solution{
public:
	int Add(int num1, int num2)
	{
		while (num2)
		{
			int a = num1 ^ num2;
			int carry = (num1 & num2) << 1;
			num1 = a;
			num2 = carry;
		}
		return num1;
	}
};
