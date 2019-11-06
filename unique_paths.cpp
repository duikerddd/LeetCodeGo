class Solution {
public:
    //动态规划
    //F(i,j) : 到达i,j点的路径数
    //递推公式 : F(i,j) = F(i-1,j) + F(i,j-1)
    //初始化 : 第一行 : F(0,j) = 1 第一列(i,0) = 1
    //返回结果:  F(m-1,n-1)
    int uniquePaths(int m, int n) {
        //无效输入
        if(m<1 || n<1)
        {
            return 0;
        }
        
        vector<vector<int>> path_sum(m,vector<int>(n,1));
        for(int i=1;i<m;++i)
        {
            for(int j=1;j<n;++j)
            {
                //F(i,j) = F(i-1,j) + F(i,j-1)
                path_sum[i][j] = path_sum[i-1][j] + path_sum[i][j-1];
            }
        }
        
        return path_sum[m-1][n-1];
    }
};
