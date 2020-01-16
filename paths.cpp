//路径总数
//m*n网格,左上角到右下角路径数

//dp(i,j)到达 p(i,j)的路径数
//dp(i,j) = dp(i-1,j) + dp(i,j+1)
//初始化: dp(i,0) = dp(0,j) = 1;
//返回值: dp(m-1,n-1)

class Solution{
    public:
        int Paths(int m,int n)
        {
            //无效输入
            if(m<0 || n<0)
                return 0;
                
            vector<vector<int>> path(m,vector<int>(n,1));
            for(int i=1;i<m;++i)
            {
                for(int j=1;j<n;++j)
                {
                    path[i][j] = path[i-1][j] + path[i][j-1];
                }
            }
            
            return path[m-1][n-1];
        }
};
