//最短路径
//m*n网格  左上角到右下角

//dp
//F(i,j): i,j的最短路径
//F(i,j) = min(F(i-1,j),F(i,j-1)) + i,j
//init: F(i,0) = i,0 + F(i-1,0)  F(0,j) = 0,j + F(0,j-1)
//ret: F(m-1,n-1)
class Solution{
    int MinPath(vector<vector<int>> &grid)
    {
        if(grid.empty() || grid[0].empty())
            return 0;
            
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> min_path(row,vector<int>(col,0));
        min_paht[0][0] = grid[0][0];
        for(int i=1;i<row;++i)
        {
            min_paht[i][0] = min_path[i-1][0] + grid[i][0];
        }
        for(int i=1;i<col;++i)
        {
            min_paht[0][i] = min_path[0][i-1] grid[0][i];
        }
        for(int i=0;i<row;++i)
        {
            for(int j=0;j<col;++j)
            {
                min_paht[i][j] = min(min_paht[i-1][j],min_paht[i][j-1]) + grid[i][j];
            }
        }
        
        return min_path[row-1][col-1];
    }
};
