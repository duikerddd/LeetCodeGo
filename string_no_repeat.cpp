string str_no_repeat;
string& StringNoRepeat(string s)
{
    //无效输入
    if(s.size()==0 || s.empty())  return s;
    vector<bool> repeat(256,false);
    //标记,并去重标记过的
    for(int i=0;i<s.size();++i)
    {
        if(repeat[s[i]]==false)
        {
            str_no_repeat.push_back(s[i]);
            repeat[s[i]] = true;
        }
    }
    return str_no_repeat;
}
