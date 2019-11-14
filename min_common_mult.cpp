#include<iostream>

using namespace std;

//先找到已知的最大最小公倍数(循环边界) -- n = a*b
//a*2 ,*3 ...*b-1 %b ==0 
//b*2 ,*3 ...*a-1 %a ==0 
int MinCommonMult(int a,int b)
{
    int min_ret = a*b;
    for(int i=1;i<b-1;++i)
    {
        if((a*i)%b==0)
        {
            min_ret = a*i;
            break;
        }
            
    }
    for(int i=1;i<a-1;++i)
    {
        if((b*i)%a==0)
        {
            if(min_ret>(b*i))
            min_ret = b*i;
            
            break;
        }
    }
    return min_ret;
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<MinCommonMult(a,b);
    
    return 0;
}
