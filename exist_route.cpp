//给定一个二维网格和一个单词，找出该单词是否存在于网格中。

//单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

//解题思路: dfs搜索路径 + 回溯 + 标记走过的路
class Solution {
public:
    bool dfs(vector<vector<char>>& board,string& word,int wordinx,int i,int j)
    {
        //越界,失败
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()) return false;
        //终止条件:单词不一样,失败
        if(board[i][j] != word[wordinx]) return false;
        //终止条件: 单词一样,且是最后一个单词,成功
        if(wordinx == word.size()-1) return true;
        
        //当前单词一样
        //标记当前节点走过
        char tmp = board[i][j];
        board[i][j] = '0';
        //遍历所有路线
        bool flag =  dfs(board,word,wordinx+1,i-1,j) || dfs(board,word,wordinx+1,i+1,j)\
                    || dfs(board,word,wordinx+1,i,j-1) || dfs(board,word,wordinx+1,i,j+1);
       
        //回溯
        board[i][j] = tmp;

        return flag;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();++i)
        {
            for(int j=0;j<board[0].size();++j)
            {
                if(dfs(board,word,0,i,j)==true) 
                    return true;
            }
        }
        return false;
    }
};
