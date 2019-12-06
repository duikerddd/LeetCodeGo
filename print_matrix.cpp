//一圈一圈打印
vector<int> printMatrix(vector<vector<int> > matrix) {
        int row = matrix.size();
        int col = matrix.size();
        vector<int> result;
        //无效输入
        if(row<1 || col<1)
            return result;
        int left = 0,right = col-1;  //圈的左右边界
        int top = 0,bottom = row-1;  //圈的上下边界
        while(left<=right && top<=bottom)  //临界条件:圈内有数
        {
            //从左往右
              for(int i=left;i<=right;i++){
                  result.push_back(matrix[top][i]);
              }
            //从上往下
              for(int i=top+1;i<=bottom;i++){
                  result.push_back(matrix[i][right]);
              }
            //从右往左 --- 相等说明只有一行
            if(top!=bottom){
                  for(int i=right-1;i<=left;i--){
                      result.push_back(matrix[bottom][i]);
                  }
              }
            //从下往上  --- 相等说明只有一列
             if(left!=right){
                  for(int i=bottom-1;i<=top;i++){
                      result.push_back(matrix[i][left]);
                  }
              }
            //下一圈
            left++;
            right--;
            top++;
            bottom--;
        }
            
}
