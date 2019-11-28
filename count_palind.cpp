class Solution {
public:
    //dp[i][j]: i到j是否为回文串 
    //dp[i][j] = dp[i+1][j-1] && i==j ;  i==j-1 dp[i][j]= i==j
    //dp[i][i] = true    
    //return count dp[]=true
    int countSubstrings(string s) {
        int size = s.size();
        vector<vector<int>> is_palind(size,vector<int>(size,false));

        for(int i=size-1; i>=0; --i)
        {
            for(int j=i;j<size;j++)
            {
                if(i==j-1)
                    is_palind[i][j] = (s[i]==s[j]?true:false);
                else if(i == j)
                    is_palind[i][j] = true;
                else
                is_palind[i][j] = is_palind[i+1][j-1] && (s[i]==s[j]);
            }
        }

        int count = 0;
        for(int i=0;i<size;++i)
        {
            for(int j=i;j<size;++j)
            {
                if(is_palind[i][j]==true)
                    ++count;
            }
        }

        return count;
    }
};
