bool Find(vector<vector<int>> matrix,int target)
{
    int row = 0 ;
    int col = matrix[0].size()-1;
    while(row<=matrix.size() && col>=0)
    {
        if(matrix[row][col]>target) 
            --col;
        else if(matrox[row][col]<target) 
            ++row;
        else 
            return true;
    }    
    return false;
}
