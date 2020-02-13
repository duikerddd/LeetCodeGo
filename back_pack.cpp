//背包问题
//n个物品,m大小的背包
//S[i]:每个物品的大小
//V[i]:每个物品的价值
//装入的最大价值

//dp
//dp(i,j):装入前i个物品放入大小为j的背包所获得的最大价值
//装不下,即装入i-1个的最大值: 
//  dp(i,j) = dp(i-1,j)
//能装下,比较装入i-1个的最大值和装入i个的最大值(其实就是看第i个是否能发挥更大的价值):
//dp[i,j] = max( dp(i-1,j) , dp(i-1,j-s[i])+ v[i]) }
//               不装入第i个       装入第i个
//init: dp(i,0) = dp(0,j) = 0
//ret: dp(n,m)
/* 
*假设n = 3  s=2,3,1 v=1,2,5 m=5 
*  i=1      dp(1,0)=0 (1,1)=0 (1,2)=1 (1,3)=1 (1,4)=1 (1,5)=1   
*  i=2      dp(2,0)=0 (2,1)=2 (2,2)=2 (2,3)=3 (2,4)=3 (2,5)=3
*  i=3      dp(3,0)=0 (3,1)=2 (3,2)=2 (3,3)=3 (3,4)=3 (3,5)=5
*/

class Solution{
public:
    int BackPack(int m,vector<int> s,vector<int> v)
    {
          if(s.empty() || v.empty())  return 0;
          
          int i = s.size() + 1;  //前i个
          int j = m + 1;  //大小
          vector<vector<int>> ret_back(i,vector<int>(j,0));
          
          for(int i=1;i<n;++i)
          {
              for(int j=1;j!=m;++j)
              {
                //装不下,i-1是因为索引从0开始 
                if(s[i-1] > j)
                  ret_back[i][j] = ret_back[i-1][j];
                //能装下
                else
                  ret_back[i][j] = max( ret_back[i-1][j] , ret_back[i-1][j-s[i]]+v[i]);
              }
          }
     return ret_back[i][j];
    }
};

//优化: dp数组每次只用i-1行的值,可以优化为一维数组
