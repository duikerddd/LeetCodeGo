class Solution{
public:
	
	//10进制加法: 5+7=12 拆分: 5+7=2 不进位  2+进位值10=12
	//位运算: ^不进位加法 , &<<1进位数 循环知直到进位为0
	int Add(int num1,int num2)
	{
		while (num2 != 0)
		{
			int a = num1^num2;
			int carry = (num1&num2) << 1;
			num1 = a;
			num2 = carry;
		}
		return num1;
	}

	
};
