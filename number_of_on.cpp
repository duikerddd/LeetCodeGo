//解法1: n右移,计算每一位的1  缺陷: 循环次数局限于int,如果是long还得改
int NumberOfOne(int n)
{
    int count = 0;
    for(int i=0;i<32;++i)
    {
        if(((n>>i)&1) == 1)
            count++;
    }
    return count;
}

//解法2: 用flag左移检测n的每一位
int NumberOfOne(int n)
{
    int count = 0;
    int flag = 1;
    while(flag)
    {
        if(n&&flag) count++;
        flag<<=1;
    }
    return count;
}

//解法3: 消1法 n&(n-1)  时间复杂度O(1)
int NumberOfOne(int n)
{
    int count = 0;
    while(n)
    {
        n=n&(n-1);
        count++;
    }
    return count;
}
