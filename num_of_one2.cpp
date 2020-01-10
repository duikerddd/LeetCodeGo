//数学推导出每位出现1次数的规律 O(lgn)
//1.该位==0 高位决定 当前位1出现次数=高位*该位数值
//2.该位>1   高位决定 当前位1出现次数=(高位+1)*该位数值
//3.该位==1 高低位决定 当前位1出现次数=高位*该位数值 + 低位数 + (本位)1
int NumOfOneBetweenN(int n)
{
    int count = 0;
    int i = 1;
    int cur = 0,after = 0,before = 0;
    
    while((n/i)!=0)
    {
        cur = (n/i)%10;
        before = n/(i*10);
        after = n - (n/i)*i;
        
        if(cur>1)
            count += (before+1)*i;
        else if(cur==0)
            count += before*i;
        else
            count += before*i + after + 1;
            
        i*=10;                  
    }
    return count;
}
