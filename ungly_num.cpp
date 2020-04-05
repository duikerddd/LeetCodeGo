bool IsUN(int num)
{
	while (num % 5 == 0)
		num /= 5;
	while (num % 3 == 0)
		num /= 3;
	while (num % 2 == 0)
		num /= 2;

	return num == 1 ? true : false;
}

long GetUN(int index)
{
	if (index<1) return 0;

	int num = 0;
	int find_count = 0;
	while (index != 0)
	{
		++num;
		if (IsUN(num))
			--index;

	}

	return num;
}
