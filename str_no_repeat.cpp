//删除重复字符

//google --> gole
//解法: 1.使用哈希表记录次数 2.位置为0放入结果,并变为1. 为1不放

string str_no_repeat;
string& StringNoRepeat(string s)
{
    if(s.empty()) return "";
    
    vector<bool> hash(256,false);
    for(int i=0;i<s.size();++i)
    {
        if(hash[s[i]] == false)
        {
            str_no_repeat.push_back(s[i])
            hash[s[i]] = true;
        }
    }
    
    return str_no_repeat;
}
