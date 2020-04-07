bool IsAnagram(string& s1,string& s2)
{
    //无效输入
    if(s1.empty() || s2.empty() || s1.size()!=s2.size()) return false;
    
    vector<int> count_char(256,0);
    //计数
    for(int i=0;i<s1.size();++i)
    {
        count_char[s1[i]]++;
    }
    //比较
    for(int i=0;i<s2.size();++i)
    {
        count_char[s2[i]]--;
    }
    //判断
    for(int i=0;i<256;++i)
    {
        if(count_char[i]!=0)
            return false;
    }
    return true;
}
