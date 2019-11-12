#include<iostream>

using namespace std;
//思路: 先Fibo加到刚好超越n的位置,F1>n,F0<n
//MIN(F1-N,N-F0)
int MinFibo(int n)
{
    int f0=0;
    int f1=1;
    int tmp;
    while(n>f1)
    {
        tmp = f1+f0;
        f0 = f1;
        f1 = tmp;
    }
    int dif1 = f1-n;
    int dif2 = n-f0;
    return dif1>dif2?dif2:dif1;
}


int main()
{
    int n;
    cin>>n;
    
    cout<<MinFibo(n);
    return 0;
}
