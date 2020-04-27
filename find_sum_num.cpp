bool FindNumSum(int *data,int len,int sum,int* num1,int* num2)
{
	//无效输入
	if (data == NULL || len < 2) return false;

	//定义双指针
	int start = 0;
	int end = len - 1;
	while (start < end)
	{
		if (data[start] + data[end] == sum)
		{
			*num1 = data[start];
			*num2 = data[end];
			return true;
		}
		else if (data[start] + data[end] < sum)
		{
			++start;
		}
		else
		{
			--end;
		}
	}
	return false;
}
