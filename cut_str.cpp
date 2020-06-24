//剪切字符串
//input: str1: we are students. str2: aeiou 
//output: w r stdnts.

//解法: 1.使用哈希表记录要删除的位置 2.对第一个字符串push_back,遇到位置不push_back
//数据结构: 数组实现的哈希表


string cut_str;
string& CutFirstStr( string& s1,  string& s2)
{
      if(s1.empty() || s2.empty()) return "";
      
      //1.哈希表记录删除位置
      vector<int> hash(256,0);
      for(int i=0;i<s2.size();++i)
          hash[s2[i]]++;
          
      //2.除了标记位置,其余push_back
      for(int i=0;i<s1.size();++i)
      {
            if(hash[s1[i]]!=1)
                cut_str.push_back(s1[i]);
      }
      
      return cut_str;
}
