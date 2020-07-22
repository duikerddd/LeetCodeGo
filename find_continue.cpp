//输入一个正数s, 打印所有和为s的连续正数序列(至少两个数)

//例如 15 = 1+2+3+4+5 = 4+5+6 = 7+8  打印出:1~5 , 4~6 , 7~8

//解题思路: 双指针确定序列范围,在使用范围和与target比较
//解法: 1.创建变量start和end. start=1,end=2. 2.计算和,<target:end++,sum+=end; >target:sum-=start,start++;=,输出,sum-=start,start++. 3.一直重复到(target+1)/2.
void PrintOrder(int begin,int end)
{
    for(int i=begin;i<=end;++i)
        cout<<i;
    cout<<endl;    
}

void FindContinueSequence(int target)
{
    if(target<3) return;
    
    int start = 1;
    int end = 2;
    int max = (target+1)/2;
    int sum = 0;
    sum = start+end;
    
    while(end<=max)
    {
        if(sum<target)
        {
           end++;
           sum+=end;
        }
        else if(sum>target)
        {
            sum-=start;
            start++;
        }
        else
        {
            PrintOrder(start,end);
            sum-=start;
            start++;
        }
    }
}
