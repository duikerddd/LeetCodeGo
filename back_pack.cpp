//背包问题
//n个物品,m大小的背包
//S[i]:每个物品的大小
//V[i]:每个物品的价值
//装入的最大价值

//dp
//dp(i,j):装入前i个物品放入大小为j的背包所获得的最大价值
//装不下: 
//  dp(i,j) = dp(i-1,j)
//能装下:
//dp[i,j] = max( dp(i-1,j) , dp(i-1,j-s[i])+ v[i]) }
//               不装入第i个       装入第i个
//init: dp(i,0) = dp(0,j) = 0
//ret: dp(n,m)

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
                //装不下: 
                if(s[i-1] > j)
                  
                  ret_back[i][j] = max( ret_back[i-1][j] , ret_back[i-1][j-s[i]]+v[i]);
              }
          }
          
    }
};
