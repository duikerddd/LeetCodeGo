class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
     
     //3 2 3 1 2   min  max  
     //3           3    0
     //3 2         2    0
     //3 2 3       2    1
     //3 2 3 1     1    1 
     //3 2 3 1 2   1    1
     
     //dp[i]:前i个最大值 
     //dp[i] = max(v[i]-min , max)
     
    int maxProfit(vector<int> &prices) {
        // write your code here
        vector<int> dp(prices.size()+1);
        dp[0]=0;dp[1]=prices[0];
        
        int maxs = 0;
        int min = prices[0];
        
        for(int i=2;i<=prices.size();i++)
        {
            dp[i] = max(prices[i-1]-min,maxs);
            if(dp[i]>maxs)
                maxs = dp[i];
            if(min>prices[i-1])
                min=prices[i-1];
        }
        
        return dp[prices.size()];
    }
};
