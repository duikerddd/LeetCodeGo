class Solution {
public:
    /**
     * @param s: A string
     * @param wordSet: A dictionary of words dict
     * @return: A boolean
     */
     
     /*
     l   
     li
     lint √ 
     lintc
     lintcod
     lintcode √
     */
     
     //dp[i]: 以i结尾是否能被划分成单词
     //dp[i]= dp[j] && dp[j+1,i) is word 
     //init: dp[0]=1 
     //ret:dp[n]
     
    bool wordBreak(string &s, unordered_set<string> &wordSet) {
        // write your code here
        vector<bool> dp(s.size()+1,false);
        dp[0] = true;
        
        for(int i=1;i<=s.size();++i)
        {
            for(int j=0;j<i;++j)
            {
                if(dp[j] &&   
                find(wordSet.begin(),wordSet.end(),s.substr(j,i-j))!=wordSet.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return(dp[s.size()]);
    }
};
