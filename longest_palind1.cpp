class Solution {
public:
    //动态规划
    // F(i,j): i到j是否为回文字符串
    // 递推: F(i,j) = F(i+1,j-1)==1 && i==j
    //      特殊 if(j-i==1) i==j  
    // 初始状态: F(i,i)=1    
    // 返回结果: MAX(F(i,j))
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==0)
        {
            return "";
        }
       
        vector<vector<int>> longest_palind(n,vector<int>(n,0));
        
        int start = 0;
        int end = 0;
        //初始化--一个字符和两个字符
        for(int i=0;i<n;++i){
            longest_palind[i][i]=1;

            if(i+1<n && s[i]==s[i+1])
            {
                longest_palind[i][i+1]=1;
                start=i;
                end=i+1;    
            }
        }
        
         // 递推: F(i,j) = F(i+1,j-1)==1 && i==j
         //      特殊 if(j-i==1) i==j  
        for(int j=2;j<n;++j)
        {
            for(int i=0;i<j;++i)
            {
                //递推
                if(longest_palind[i+1][j-1] && s[i]==s[j])
                {
                    longest_palind[i][j] = 1;
                    if((j-i)>(end-start)){
                        start = i;
                        end = j;
                    }       
                }
            }
        }
        
       return s.substr(start,end-start+1); 
         
    }
};
