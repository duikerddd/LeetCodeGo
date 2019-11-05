
class Solution {
public:
    //动态规划
    //F(i) : 前i个单词是否能被成功拆分
    //递推公式 : F(i) = j<i && F(j) && substr(j+1,i)单词能被查找到 (前面j个单词能被成功分割,并且j+1,i也在字典中)
    //初始状态 : F(0) = true
    //返回结果 : F(n)
    bool wordBreak(string s, vector<string>& wordDict) {
        //无效输入,有一个为空
        if(s.empty() || wordDict.empty())
        {
            return false;
        }
        
        unordered_set<string> uset(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> can_break(n+1);
        can_break[0] = true;
        
        for(int i=1;i<=n;++i)
        {
            //F(i) = j<i && F(j) && substr(j+1,i)单词能被查找到
            for(int j=0;j<i;++j)
            {
                //                            第j+1个索引为j,substr第一个参数为下标索引
                if(can_break[j]==true && uset.count(s.substr(j,i-j)))
                {
                    can_break[i] = true;
                    break;
                }
            }
        }
        
        return can_break[n];
    }
};
