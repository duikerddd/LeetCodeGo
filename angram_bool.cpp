//变位词: 字符顺序不一样,但是出现的字符一样

//解法: 使用哈希表记录一个单词的次数, 用另一个单词抵消哈希表的次数,看是否全为0

bool IsAnagram(string& s1,string& s2)
{
    if(s1.size()!=s2.size()) return false;
    
    vector<int> hash(256,0);
    
    for(int i=0;i<s1.size();++i)
        hash[s1[i]]++;
        
    for(int i=0;i<s2.size();++i)
        hash[s2[i]]--;
        
    for(int i=0;i<256;++i)
    {
        if(hash[i]!=0) return false;
    }
    return true;
}
