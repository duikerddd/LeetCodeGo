#include<iostream>
using namespace std;

//最大连续1
//n>>1迭代,i&1判断当前位是否为1,count计数和max比较
int ByteMaxContinuous(int n)
{
    int max = 0;
    int count = 0;

    for(int i=n;i!=0;i=i>>1)
    {
        if((i&1)==0)
        {
            if(count>max)
                max = count;
            count = 0;
            continue;
        } 
        count++;
    }
    if(count>max)
        max = count;
    return max;
}


int main()
{
    int n;
    while(cin>>n)
        cout<<ByteMaxContinuous(n)<<endl;
    return 0;
}
