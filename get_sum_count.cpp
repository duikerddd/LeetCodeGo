int getNSumCount(int n, int sum)
{
    //f(0,i) f(2,-i)  越界    
	if(n<1||sum<n||sum>6*n)
	{
		return 0;
	}
	if(n==1)
	{
		return  1;
	}
	int resCount=0;
	resCount=getNSumCount(n-1,sum-1)+getNSumCount(n-1,sum-2)+
			 getNSumCount(n-1,sum-3)+getNSumCount(n-1,sum-4)+
			 getNSumCount(n-1,sum-5)+getNSumCount(n-1,sum-6);
	return resCount;
}
