int Min(int l,int r)
{
    return l>=r?r:l;
}

int ComPre(string& ans,string& str)
{
    int i;
    int min = Min(ans.size(),str.size());
    for(i = 0;i<min;++i)
    {
        if(ans[i]!=str[i])
        {
            break;
        }
    }
    return i;
}


class Solution {
public:
    //拿出第一个子串,假设公共前缀长度为该子串长度
    //依次比较,遇到不同的就改变下标
    string longestCommonPrefix(vector<string>& strs) {        
        //空串
        if(strs.empty()) return string("");
        //一个不需要比较
        if(strs.size() == 1) return strs[0];
        
        string ans(strs[0]);
        //两个及以上比较
        for(int i = 1;i<strs.size();++i)
        {
             int sub = ComPre(ans,strs[i]);
             //已经没有公共前缀了
             if(sub == 0) 
                     return string("");
             ans = ans.substr(0,sub);
        }   
        return ans;
        
    }
};
