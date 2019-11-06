class Solution {
public:
    //动态规划
    //状态 F(i,j) : 到(i,j)的路径总数
    //状态递推 : 
    //  第一排,第一列只有一个方向,所以路径只能是0或1,如果有障碍,没路,没障碍,有路
    //  第一排: (0,j)      if(0,j)=1  F(0,i)=0  i>=j 
    //                     if(0,j)=0  F(0,j)=1
    //  第一列: (i,0)      if(i,0)=1  F(0,j)=0  j>=i   
    //                      if(i,0)=0 F(i,0)=1
    // if(i,j = 1) F(i,j) = 0;
    //  else   F(i,j) = F(i-1,j) + F(i,j-1);
    //初始状态:  F(0,0) = (0,0)   如果是1,直接返回0  如果是0,继续      
    //返回结果  F(m-1,n-1);
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        //准备
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long>> path_sum(m,vector<long>(n,0));
        
        //起点堵住,直接返回
        if(obstacleGrid[0][0]==1) 
            return 0;
        
        //初始状态
        path_sum[0][0] = 1;
        //递推 : 第一排,第一列
        for(int col=1;col<n;++col)
        {
            if(obstacleGrid[0][col] == 1)
                break;
            path_sum[0][col] = 1;
        }
        for(int row=1;row<m;++row)
        {
            if(obstacleGrid[row][0] == 1)
                break;
            path_sum[row][0] = 1;
        }
        
        //递推 :if(i,j = 1) F(i,j) = 0;
        //  else   F(i,j) = F(i-1,j) + F(i,j-1);
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;++j)
            {
                //有障碍,此处没路,为0
                if(obstacleGrid[i][j]==1)
                    path_sum[i][j] = 0;
                else
                //有路递推
                    path_sum[i][j] = path_sum[i-1][j] + path_sum[i][j-1];
            }
        }
        
        return path_sum[m-1][n-1];
    }
};
