class Solution {
public:
    //dp[i]: 前i个单词能否被拆分成单词
    //dp[i] = dp[j] && [j+1,i] is word
    //dp[0] = true;
    

    bool wordBreak(string s, vector<string>& wordDict) {
          vector<bool> dp(s.size()+1);
          dp[0] = true;

          for(int i=1;i<=s.size();i++)
          {
              for(int j=0;j<=i;j++)
              {
                    if(dp[j]==true && find(wordDict.begin(),wordDict.end(),s.substr(j,i-j))!=wordDict.end() )
                    {
                        dp[i] = true;
                    }
              }
          }

          return dp[s.size()];
    }
};
