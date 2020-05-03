typedef int (*func)(int);

int SumEnd(int n)
{
	return 0;
}

int Sum(int n)
{
	 func f[2] = { SumEnd, Sum };
	 return n + f[!!(n)](n - 1);

}

int GetSum(int n)
{
	return Sum(n);
}
