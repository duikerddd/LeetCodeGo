#include<algorithm>

class Solution {
public:
    //动态规划
    //      状态: F(i,j) 到(i,j)的最小路径 
    //      递推: F(i,j) = Min(F(i-1,j),F(i,j-1))+(i,j);
    //      特殊递推: F(0,j) = F(0,j-1) + (0,j)
    //               F(i,0) = F(i-1,0) + (i,0)
    //      初始状态: F(0,0) = (0,0)
    //      边界条件: m>0 n>0
    //      返回值 : F(m-1,n-1)
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //无效输入
        if(m<1 || n<1)
                return 0;
        
        vector<vector<int>> min_path(m,vector<int>(n,0));
        min_path[0][0] = grid[0][0];
        //特殊递推
        for(int i=1;i<m;++i)
        {
            min_path[i][0] = min_path[i-1][0]+grid[i][0]; 
        }
        for(int i=1;i<n;++i)
        {
            min_path[0][i] = min_path[0][i-1]+grid[0][i];
        }
        //递推
        for(int i=1;i<m;++i)
        {
            for(int j=1;j<n;++j)
            {
                //递推: F(i,j) = Min(F(i-1,j),F(i,j-1))+(i,j);
                min_path[i][j] = min(min_path[i-1][j],min_path[i][j-1])+grid[i][j];
            }
        }
        
        return min_path[m-1][n-1];
                    
    }
};
