//问题: 矩阵顺时针找终点.
//解题思路: 右下左上转圈, 转一圈缩范围,直到全部遍历完
int FindMax(vector<vector<int> > matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    
    int left = 0,right = col-1;
    int top = 0,bottom = row-1;
    
    int target = 0;
    while(left<=right && top<=bottom)
    {
        for(int i=left;i<=right;++i)
                target = matrix[top][i];
                
        for(int i=top+1;i<=bottom;++i)
                target = matrix[i][right];
        
        //记得特殊边界
        if(top!=bottom)
        {
            for(int i=right-1;i>=left;--i)
                target = matrix[bottom][i];
        }
        
         if(left!=right)
        {
            for(int i=bottom-1;i>=top+1;--i)
                target = matrix[i][left];
        }
        
        left++;right--;
        top++;bottom--;     
    }
    
    return target;
}
