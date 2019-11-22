#include<iostream>
using namespace std;


//计数1的个数
//每一位&1==1 count++
//迭代 n>>1
int CountOne(int n)
{
    int count = 0;
    for(int i=0;i<32;++i)
    {
        if(((n>>i)&1)==1)
            count++;
    }
    return count;
}

int main()
{
    int n;
    while(cin>>n)
        cout<<CountOne(n)<<endl;
    return 0;
}
