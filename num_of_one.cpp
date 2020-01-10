//对每个数字都求出1的次数,时间效率低
int NumOfOneBetweenN(int n)
{
    int sum = 0;
    for(int i=1;i<n;++i)
        sum += NumOfOne(i);
    return sum;    
}

int NumOfOne(int i)
{
    int sumi = 0;
    while(i)
    {
        if(i%10 == 1)
            sumi++;
        i/=10;    
    }
    return sumi;
}
