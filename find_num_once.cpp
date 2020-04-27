void FindNumOnce(int *data, int len, int *num1, int* num2)
{
	//无效输入
	if (data == NULL || len<2) return;

	//第一次异或
	int first_xor = 0;
	for (int i = 0; i<len; ++i)
	{
		first_xor ^= data[i];
	}
	//得到最后一位的1
	int first_one = 0;
	for (int i = 0; i < 32; ++i)
	{
		if ((first_xor>>i)&1 == 1)
			first_one = i;
	}
	//第二次异或
	for (int i = 0; i < len; ++i)
	{
		if ((data[i] >> first_one) & 1 == 1)
		{
			*num1 ^= data[i];
		}
		else
		{
			*num2 ^= data[i];
		}
	}
}
