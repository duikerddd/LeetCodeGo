class Solution {
public:
    /**
     * @param s: A string
     * @return: An integer
     */
     
     //aab 
     //a = min(1,0) = 0 
     //aa min(0+1,0)=0 
     //aab min(0+1,x)=1 
     
     //dp[i]: 前i个单词需要分割的最小次数
     //dp[i] =  min {  dp[j] && s[j+1,i] is palind } j<i  
     //init: dp[0]=-1  指的是s整个为倒装的时候
     //ret: dp[n]
     
      bool IsPalind(string& s,int begin,int end)
     {
         int left = begin;
         int right = end;
         
         while(left<right)
         {
             if(s[left]!=s[right])
            {
                return false;        
            }
            left++;right--;
         }
         
         return true;
     }
     
    int minCut(string &s) {
        // write your code here
        std::vector<int> dp(s.size()+1,-1);
        dp[0] = -1;
        
        for(int i=1;i<=s.size();++i)
        {
            for(int j=0;j<i;++j){
                if(IsPalind(s,j,i-1))
                {
                    if(dp[i]==-1)
                    {
                        dp[i] = dp[j]+1;
                        continue;
                    }
                    dp[i] = min(dp[i],dp[j]+1);
                }
            }
           
        }
        
        return dp[s.size()];
    } 
    
};
