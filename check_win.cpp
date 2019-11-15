class Board {
public:
    //赢的条件: 横 竖 斜和为3
    bool checkWon(vector<vector<int> > board) {
        //斜
       if(board[0][0]+board[1][1]+board[2][2]==3) return true;
       if(board[2][0]+board[1][1]+board[0][2]==3) return true;
       //横竖
        for(int i=0;i<3;++i)
       {
           if(board[0][i]+board[1][i]+board[2][i]==3)
                           return true;
           if(board[i][0]+board[i][1]+board[i][2]==3)
                           return true;
       }
        
       return false;
    }
};
