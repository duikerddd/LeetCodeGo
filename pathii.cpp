//路径总数ii
//m*n方格  左上角到右下角 1为障碍

//dp(i,j): 到i,j的路径数
//dp(i,j) = dp(i-1,j) + dp(i,j-1) & or (0  ,  i,j == 1)
//init: dp(i,0) = 1 or i,0==1 dp(i,0)=0 i<m    dp(0,j) = 1 or 0,j==1 dp(0,j)=0  
//ret: dp(m-1,n-1)

class Solution{
    public:
        int PathWithObstacles(vector<vector<int>>& obs)
        {
            //无效输入
            if(obs.empty() || obs[0].empty)
                return 0;
                
            int m = obs.size();
            int n = obs[0].size();
            vector<vector<int>> path(m,vector<int>(n,0));
            //初始化
            for(int i=0;i<m;++i)
            {
                if(obs[i][0] == 1)
                    break;
                path[i][0] = 1;
            }
            for(int j=0;i<n;++j)
            {
                if(obs[0][j] == 1)
                    break;
                path[0][j] = 1;
            }
            //递推
            for(int i=0;i<m;++i)
            {
                for(int j=0;j<n;++j)
                {
                    if(obs[i][j]==1)
                    {
                        path[i][j] = 0;
                    }
                    else
                      path[i][j] = path[i-1][j] + path[i][j-1];
                }
            }
            
            return path[m-1][n-1];
        }
        
}; 
