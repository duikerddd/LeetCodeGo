#include<iostream>
#include<string>
#include<vector>
using namespace std;

//1.检查字典序 --- 1. ascii对比 string[i]>string[i+1] lexicographically=no
//2.检查长度 --- i.size()>i+1.size() lengths=no
int CheckWhatSort(vector<string>& v)
{
    int ret = 3;
    int n = v.size();
    for(int i=0;i<n-1;++i)
    {
        if(v[i]>v[i+1])
        {
            ret-=1;
            break;
        }
    }
    
    for(int i=0;i<n-1;++i)
    {
        if(v[i].size()>v[i+1].size())
        {
            ret-=2;
            break;
        }
    }
    
    return ret;
}


int main()
{
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;++i)
        cin>>v[i];
    
    int ret = CheckWhatSort(v);
    if(ret==3)
        cout<<"both";
    else if(ret==2)
        cout<<"lengths";
    else if(ret==1)
        cout<<"lexicographically";
    else
        cout<<"none";
    
    return 0;
}
