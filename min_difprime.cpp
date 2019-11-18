#include<iostream>
using namespace std;

bool IsPrime(int n)
{
    if(n==2)
        return true;
    for(int i=2;i<n/2;++i)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

//最小素数差
//从中间开始,两头递归,判断都是素数即可
void MinDifPrime(int n)
{
    int first,second;
    first=second=n/2;
    while(first>1 && second<n)
    {
        if(IsPrime(first)&&IsPrime(second))
        {
            cout<<first<<endl<<second<<endl;
            return;
        }
        first--;
        second++;
    }

}

int main()
{
    int n;
    while(cin>>n)
       MinDifPrime(n);
    return 0;
}
