class Solution {
public:
    //无效输入 : 空
    //从后往前找结尾,开头
    int lengthOfLastWord(string s) {
        
        int count=0;
        int end = s.size()-1;
        //第一个字符=end
        //第一个空格=start
        
        while(end>=0 && s[end]==' ') 
            --end;
        //只有空格
        if(end<0)
            return 0;
        int start = end;
        while(start>=0 && s[start]!=' ')
            --start;
            
        return end-start;
        
    }
};
