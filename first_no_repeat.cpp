char FirstNoRepeat(string& s)
{
    if(s.size()==0 || s.empty())  return 0;
    vector<int> table_size(256,0);
    
    for(int i=0;i<s.size();++i)
    {
        table_size[s[i]]++; 
    }
    for(int i=0;i<s.size();++i)
    {
        if(table_size[s[i]] == 1)
            return s[i];
    }
    return 0;
}
