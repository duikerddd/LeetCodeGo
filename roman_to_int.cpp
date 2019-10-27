

class Solution {
public:
    //用哈希表映射字符,处理特殊条件:前字母<后字母==前字母变负数
    int romanToInt(string s) {
        map<char,int> hash;
        hash['I'] = 1;
        hash['V'] = 5;
        hash['X'] = 10;
        hash['L'] = 50;
        hash['C'] = 100;
        hash['D'] = 500;
        hash['M'] = 1000;
        
        int sum = 0;
        for(int i = 0;i<s.size();++i)
        {
            if(hash[s[i]] < hash[s[i+1]])
            {
                sum-=hash[s[i]];
                continue;
            }
            sum+=hash[s[i]];
        }
        
        return sum;
    }
};
