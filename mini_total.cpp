//给定三角矩阵mxn,找出最短路径
//动态规划
//F(i,j): 从i,j到最后一行的最短路径和
//F(i,j) = min(F(i+1,j),F(i+1,j+1)) + i,j
//初始化: F(m-1,i) = m-1,i
//结果: F(0,0)

class Solution{
   int MiniTotal(vector<vector<int>> triangle)
   {
        //无效输入
        if(triangle.empty())  return 0;
        
        int row = triangle.size();
        //f(i)和初始化
        vector<vector<int>> min_sum(triangle);
        for(int i=row-2;i>=0;i--)
        {
            for(int j=0;j<i;j++)
            {
                min_sum[i][j] = min(min_sum[i+1][j],min_sum[i+1][j+1]) + triangle[i][j];
            }
        }
        
        return min_sum[0][0];
   }
};
