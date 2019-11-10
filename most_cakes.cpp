#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//题难点: 理解欧几里得距离,画图详解--其实就是原位置的横竖间隔一个位置都不能放
//暴力破解: 从第一个开始,填了就让对应的两个位置无效
int MostCakes(int m,int n)
{
    int count=0;
    vector<vector<int>> v(m,vector<int>(n,1));
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(v[i][j]==1)
            {
                ++count;
                if(i+2<m)  v[i+2][j]=0;
                if(j+2<n)  v[i][j+2]=0;
            }
        }
    }
    return count;
}

int main()
{
    int m,n;
    cin>>m>>n;
    cout<<MostCakes(m,n);
    return 0;
}
