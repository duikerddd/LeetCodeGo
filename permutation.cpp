class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> str_arr;
        if(str.size() == 0)
            return str_arr;
        
        //全排列
        Permutation(str,result,0);
        //字典序输出
        sort(str_arr.begin(),str_arr.end());
        return str_arr;        
    }
    
    void Permutation(string& str,vector<string>& result,int begin)
    {
        //递归结束条件:指向最后一个元素,全部固定完毕,添加
        if(begin == str.size()-1) 
        {
            if(find(result.begin(),result.end(),str) == result.end())
            {
                // 如果result中不存在str，才添加；避免aa和aa重复添加的情况
                result.push_back(str);
            }
        }
        else
        {
            //第一个字母和所有位置都交换一次,固定第一个字母,重复上述操作
            for(int i=begin;i<str.size();++i)
            {
                swap(str[i],str[begin]);
                Permutation(str,result,begin+1);
                swap(str[i],str[begin]); // 复位，用以恢复之前字符串顺序，达到第一位依次跟其他位交换的目的
            }
        }
    }
};
