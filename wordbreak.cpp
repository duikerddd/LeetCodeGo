//字符串分割
//string = "leetcode";
//dict ={"leet","code"};
//返回true,能被字典分割

//动态规划:
//F(i):前i个字符是否能被dict中的单词分割
//F(i) = j<i && F(j) && F(j+1,i)存在dict中
//F(0)=true;
//返回: F(n)
class Solution{
    bool WordBreak(string s,unorder_set<string>& dict)
    {
        //无效输入
        if(s.empty() || dict.empty())
            return false;
            
        int n = s.size();
        vector<bool>can_break(n+1,false);
        //F(i)初始化
        can_break[0] = true;
        
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                can_break[i] = can_break[j] && dict.find(s.substr(j,i-j)!=dict.end())
            }
        }
        
        return can_break[n];
    }
};

//优化: 计算出dict最长单词长度max
//      i与j距离>max,肯定找不到,直接跳过
class Solution{
    bool WordBreak(string s,unorder_set<string>& dict)
    {
        //无效输入
        if(s.empty() || dict.empty())
            return false;
         
        //dict中的max
        auto it = dict.begin();
        int max = 0;
        while(it!=dict.end())
        {
            if((*it).size()>max)
              max = (*it).size();
        }
         
        int n = s.size();
        vector<bool>can_break(n+1,false);
        //F(i)初始化
        can_break[0] = true;
        
        for(int i=0;i<n;++i)
        {
            for(int j=i-1;j>=0;--j)
            {
                if((i-j)>max)
                  break;
                  
                can_break[i] = can_break[j] && dict.find(s.substr(j,i-j)!=dict.end())
            }
        }
        
        return can_break[n];
    }
};
